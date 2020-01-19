/*********************************************************************************
Copyright (C) 2014 Adrian Jarabo (ajarabo@unizar.es)
Copyright (C) 2014 Diego Gutierrez (diegog@unizar.es)
All rights reserved.

This is an educational Ray Tracer developed for the course 'Informatica Grafica'
(Computer Graphics) tought at Universidad de Zaragoza (Spain). As such, it does not 
intend to be fast or general, but just to provide an educational tool for undergraduate
students. 

This software is provided as is, and any express or implied warranties are disclaimed.
In no event shall copyright holders be liable for any damage.
**********************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath> 

#include <random>
#include <chrono>
#include "PhotonMapping.h"
#include "World.h"
#include "Intersection.h"
#include "Ray.h"
#include "BSDF.h"
#include "Phong.h"

//*********************************************************************
// Compute the photons by tracing the Ray 'r' from the light source
// through the scene, and by storing the intersections with matter
// in the lists 'xx_photons', storing the diffuse (global) and caustic
// photons respectively. For efficiency, both are computed at the same
// time, since computing them separately would result into a lost of
// several samples marked as caustic or diffuse.
// Same goes with the boolean 'direct', that specifies if direct 
// photons (from light to surface) are being stored or not. 
// The initial traced photon has energy defined by the tristimulus
// 'p', that accounts for the emitted power of the light source.
// The function will return true when there are more photons (caustic
// or diffuse) to be shot, and false otherwise.
//---------------------------------------------------------------------
bool PhotonMapping::trace_ray(const Ray& r, const Vector3 &p, 
			   std::list<Photon> &global_photons, std::list<Photon> &caustic_photons, bool direct, bool direct_only)
{
#ifndef MAX_PHOTON_ITERATIONS
#define MAX_PHOTON_ITERATIONS 20
#endif



	//Check if max number of shots done...
	if( ++m_nb_current_shots > m_max_nb_shots )
	{
		return false;
	}
	
	// Compute irradiance photon's energy
	Vector3 energy(p);
	
	Ray photon_ray(r);
	photon_ray.shift();

	bool is_caustic_particle = false;

	//Iterate the path
	while(1)
	{
		// Throw ray and update current_it
		Intersection it;
		world->first_intersection(photon_ray, it);

		if( !it.did_hit() )
			break;

		//Check if has hit a delta material...
		if( it.intersected()->material()->is_delta() )
		{
			// If delta material, then is caustic...
			// Don't store the photon!
			is_caustic_particle = true;
		}
		else if (photon_ray.get_level() > 0 || direct || direct_only )
		{
			//If non-delta material, store the photon!
			if( is_caustic_particle )	
			{				
				//If caustic particle, store in caustics
				if( caustic_photons.size() < m_nb_caustic_photons )
					caustic_photons.push_back( Photon(it.get_position(), photon_ray.get_direction(), energy ));
			}
			else						
			{
				//If non-caustic particle, store in global
				if( global_photons.size() < m_nb_global_photons )
					global_photons.push_back( Photon(it.get_position(), photon_ray.get_direction(), energy ));
			}
			is_caustic_particle = false;
		}	
		
		Real pdf;

		Vector3 surf_albedo = it.intersected()->material()->get_albedo(it);
		Real avg_surf_albedo = surf_albedo.avg();

		Real epsilon2 = static_cast<Real>(rand())/static_cast<Real>(RAND_MAX);
		while (epsilon2 < 0.)
			epsilon2 = static_cast<Real>(rand())/static_cast<Real>(RAND_MAX);
		
		if (epsilon2 > avg_surf_albedo || photon_ray.get_level() > MAX_PHOTON_ITERATIONS ) 
			break;
		
		if (direct_only && !is_caustic_particle && photon_ray.get_level() > 1)
			break;

		// Random walk's next step
		// Get sampled direction plus pdf, and update attenuation
		it.intersected()->material()->get_outgoing_sample_ray(it, photon_ray, pdf );

		// Shade...
		energy = energy*surf_albedo;
		if( !it.intersected()->material()->is_delta() )
			energy *= dot_abs(it.get_normal(), photon_ray.get_direction())/3.14159;		

		energy = energy /(pdf*avg_surf_albedo);
	}
	
	if( caustic_photons.size() == m_nb_caustic_photons && 
		global_photons.size() == m_nb_global_photons )
	{
		m_max_nb_shots = m_nb_current_shots-1;
		return false;
	}
	return true;
}

//*********************************************************************
// TODO: Implement the preprocess step of photon mapping,
// where the photons are traced through the scene. To do it,
// you need to follow these steps for each shoot:
//  1 - Sample a world's light source in the scene to create
//		the initial direct photon from the light source.
//	2 - Trace the photon through the scene storing the inter-
//		sections between the photons and matter. You can use
//		the function 'trace_ray' for this purpose.
//	3 - Finally, once all the photons have been shot, you'll
//		need to build the photon maps, that will be used later
//		for rendering. 
//		NOTE: Careful with function
//---------------------------------------------------------------------
void PhotonMapping::preprocess()
{
	// Aleatory number for the rays and russian roulette
	float xCoord, yCoord, zCoord;

	Vector3 rayDir;

	// List of global photons
	std::list<Photon> global_photons;
	// List of caustic photons
	std::list<Photon> caustic_photons;

	//
	bool keepContinue = true;

	// Generation random numbers
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	while (keepContinue){
		// Iteration throw the different lights of the scene
		for (auto const& lightSource : world->light_source_list){
			// Generation of the random values
			xCoord = uniform_real_distribution<float>(-1, 1)(rng);
			yCoord = uniform_real_distribution<float>(-1, 1)(rng);
			zCoord = uniform_real_distribution<float>(-1, 1)(rng);

			// Calculation of the random point of the cube
			Vector3 randomPoint = Vector3(lightSource->get_position().data[0] + xCoord,
				lightSource->get_position().data[1] + yCoord,
				lightSource->get_position().data[2] + zCoord);

			// Get the direction of the ray
			rayDir = randomPoint - lightSource->get_position();

			// Check if the ray is good
			if (rayDir.length() > 1.f){
				continue;
			}

			// Call to traceray function
			Ray ray = Ray(lightSource->get_position(), rayDir.normalize());

			// Trace the ray
			// Flux adapted to the number of photons and PDF
			keepContinue = trace_ray(ray, world->light_source_list.size() * lightSource->get_intensities() * 4 * M_PI / m_nb_photons, global_photons, caustic_photons, false, false);
		}
	}
	// Store global photons in the KDTree
	for (auto const& photon : global_photons){
		m_global_map.store(std::vector<Real>(photon.position.data, photon.position.data + 3), photon);
	}
	// Balance the global photon Kdtree
	m_global_map.balance();

	// Check if there are caustic objects in the scene
	if (!caustic_photons.empty()){
		// Store caustic photons in the KDTree
		for (auto const& photon : caustic_photons){
			m_caustics_map.store(std::vector<Real>(photon.position.data, photon.position.data + 3), photon);
		}
		// Balance the caustic photon Kdtree
		m_caustics_map.balance();
	}
}

//*********************************************************************
// TODO: Implement the function that computes the rendering equation 
// using radiance estimation with photon mapping, using the photon
// maps computed as a proprocess. Note that you will need to handle
// both direct and global illumination, together with recursive the 
// recursive evaluation of delta materials. For an optimal implemen-
// tation you should be able to do it iteratively.
// In principle, the class is prepared to perform radiance estimation
// using k-nearest neighbors ('m_nb_photons') to define the bandwidth
// of the kernel.
//---------------------------------------------------------------------
Vector3 PhotonMapping::shade(Intersection &it0)const
{
	Vector3 L(0);
	Vector3 W(1);
	
	Intersection it(it0);

	// Reflect and refract until a diffuse surface is found, then show its albedo...
	int nb_bounces = 0;
	// MAX_NB_BOUNCES defined in ./SmallRT/include/globals.h
	while (it.intersected()->material()->is_delta() && ++nb_bounces < MAX_NB_BOUNCES)
	{
		Ray r; float pdf;
		it.intersected()->material()->get_outgoing_sample_ray(it, r, pdf);
		W = W * it.intersected()->material()->get_albedo(it) / pdf;

		r.shift();
		world->first_intersection(r, it);
	}

	
	for (auto const& lightSource : world->light_source_list){
		if (lightSource->is_visible(it.get_position())){
			Vector3 power = lightSource->get_intensities();
			Vector3 connection = lightSource->get_position() - it.get_position();
			
			
			L += (power / connection.length2()) * (it.intersected()->material()->get_albedo(it) / M_PI) *
												  (dot_abs(it.get_normal(), connection.normalize()));
		}
	}
	
	
		
	
	// Direct light contribution
	// L = it.intersected()->material()->get_albedo(it);
	// L = L * W;
	
	// Lambertian material
	Vector3 p = it.get_position();
	std::vector<const KDTree<Photon, 3>::Node*> photonsGlobal, photonsCaustic;
	Real max_distance;
	// Find the k nearest photons
	m_global_map.find(std::vector<Real>(p.data, p.data + 3), m_nb_photons, photonsGlobal, max_distance);

	// Calculation of the final radiance estimation
	Real globalRadEstR = 0.0, globalRadEstG = 0.0, globalRadEstB = 0.0;

	float filteringFactor;

	Vector3 globalRadEst(0);
	Vector3 causticRadEst(0);



	// Iteration through the global photons
	for (auto const& photonNode : photonsGlobal){
		// Cast like photon
		Photon photon = photonNode->data();
		// Get diffuse coefficient for each channel
		float kdR = it.intersected()->material()->get_albedo(it).data[0];
		float kdG = it.intersected()->material()->get_albedo(it).data[1];
		float kdB = it.intersected()->material()->get_albedo(it).data[2];

		// Get specular coefficient
		float ks = it.intersected()->material()->get_specular(it);

		filteringFactor = 1 - sqrtf(pow(it.get_position().data[0] - photon.position.data[0], 2) +
			pow(it.get_position().data[1] - photon.position.data[1], 2) +
			pow(it.get_position().data[2] - photon.position.data[2], 2)) / max_distance;

		// Phong p = (Phong) it.intersected()->material()->;

		// float shininess = 

		// +ks * ((shininess + 2) / (2 * M_PI)) * pow(dot_abs(photon.direction.normalize(), - (it.get_ray().get_direction().normalize()), it);

		globalRadEstR += ((kdR / M_PI) * photon.flux.data[0]) * filteringFactor;
		globalRadEstG += ((kdG / M_PI) * photon.flux.data[1]) * filteringFactor;
		globalRadEstB += ((kdB / M_PI) * photon.flux.data[2]) * filteringFactor;
	}
	globalRadEstR /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);
	globalRadEstR /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);
	globalRadEstB /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);

	globalRadEst = Vector3(globalRadEstR, globalRadEstR, globalRadEstB);
	
	globalRadEst = globalRadEst * (it.intersected()->material()->get_albedo(it) / M_PI);


	// Calculation of the final radiance estimation
	Real causticRadEstR = 0.0, causticRadEstG = 0.0, causticRadEstB = 0.0;

	// Check if the KDtree of caustic objects is empty
	if (!m_caustics_map.is_empty()){
		// Find the k nearest photons
		m_caustics_map.find(std::vector<Real>(p.data, p.data + 3), m_nb_photons, photonsGlobal, max_distance);

		// Iteration through the caustic photons
		for (auto const& photonNode : photonsCaustic){
			// Cast like photon
			Photon photon = photonNode->data();
			// Get diffuse coefficient for each channel
			float kdR = it.intersected()->material()->get_albedo(it).data[0];
			float kdG = it.intersected()->material()->get_albedo(it).data[1];
			float kdB = it.intersected()->material()->get_albedo(it).data[2];

			// Get specular coefficient
			float ks = it.intersected()->material()->get_specular(it);

			// 
			filteringFactor = 1 - sqrtf(pow(it.get_position().data[0] - photon.position.data[0], 2) +
											  pow(it.get_position().data[1] - photon.position.data[1], 2) +
											  pow(it.get_position().data[2] - photon.position.data[2], 2)) / max_distance;

			// +ks * ((shininess + 2) / (2 * M_PI)) * pow(dot_abs(it.get_normal(), )shininess);

			causticRadEstR += ((kdR / M_PI) * photon.flux.data[0]) * filteringFactor;
			causticRadEstG += ((kdG / M_PI) * photon.flux.data[1]) * filteringFactor;
			causticRadEstB += ((kdB / M_PI) * photon.flux.data[2]) * filteringFactor;
		}
		causticRadEstR /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);
		causticRadEstG /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);
		causticRadEstB /= ((1 - 2 / 3.f) * max_distance * max_distance * M_PI);

		causticRadEst = Vector3(causticRadEstR, causticRadEstG, causticRadEstB);
		causticRadEst = causticRadEst * (it.intersected()->material()->get_albedo(it) / M_PI);
	}
	cout <<"Direct" << endl;
	cout << L.data[0] << " " << L.data[1] << " " << L.data[2] << endl;
	cout <<"Global" << endl;
	cout << globalRadEst.data[0] << " " << globalRadEst.data[1] << " " << globalRadEst.data[2] << endl;


	// Add the contribution of global illumination
	L = L + globalRadEst + causticRadEst;
	
	// cout << L.data[0] << " " << L.data[1] << " " << L.data[2] << endl;
	

	// L.normalize();
	

	return L;
	
	//**********************************************************************
	// The following piece of code is included here for two reasons: first
	// it works as a 'hello world' code to check that everthing compiles 
	// just fine, and second, to illustrate some of the functions that you 
	// will need when doing the work. Goes without saying: remove the 
	// pieces of code that you won't be using.
	//
	unsigned int debug_mode = 5;

	switch (debug_mode)
	{
	case 1:
		// ----------------------------------------------------------------
		// Display Albedo Only
		L = it.intersected()->material()->get_albedo(it);
		break;
	case 2:
		// ----------------------------------------------------------------
		// Display Normal Buffer
		L = it.get_normal();
		break;
	case 3:
		// ----------------------------------------------------------------
		// Display whether the material is specular (or refractive) 
		L = Vector3(it.intersected()->material()->is_delta());
		break;

	case 4:
		// ----------------------------------------------------------------
		// Display incoming illumination from light(0)
		L = world->light(0).get_incoming_light(it.get_position());
		break;

	case 5:
		// ----------------------------------------------------------------
		// Display incoming direction from light(0)
		L = world->light(0).get_incoming_direction(it.get_position());
		break;

	case 6:
		// ----------------------------------------------------------------
		// Check Visibility from light(0)
		if (world->light(0).is_visible(it.get_position()))
			L = Vector3(1.);
		break;
	case 7:
		// ----------------------------------------------------------------
		// Reflect and refract until a diffuse surface is found, then show its albedo...
		int nb_bounces = 0;
		// MAX_NB_BOUNCES defined in ./SmallRT/include/globals.h
		while( it.intersected()->material()->is_delta() && ++nb_bounces < MAX_NB_BOUNCES)
		{
			Ray r; float pdf;
			it.intersected()->material()->get_outgoing_sample_ray(it, r, pdf );		
			W = W * it.intersected()->material()->get_albedo(it)/pdf;
			
			r.shift();
			world->first_intersection(r, it);
		}
		L = it.intersected()->material()->get_albedo(it);

	}
	// End of exampled code
	//**********************************************************************

	return L*W;
}