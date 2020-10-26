# Geminis
Computer Graphics 2019-20

Please, go to the [Wiki](https://github.com/ZgzInfinity/Geminis/wiki) in order to be able to see the work done in the different
phases  and projects of the course 

# Project Phases

Theme | End date| Status 
------| --------------------| ------
Geometry |14-10-2019 | ![tic_correcto](https://i.ibb.co/48JQg0R/tic-1.png)
Imaging  |29-10-2019 | ![tic_correcto](https://i.ibb.co/48JQg0R/tic-1.png)
Ray Tracing |27-11-2019 |![tic_correcto](https://i.ibb.co/48JQg0R/tic-1.png)
Path Tracing | 03-02-2020 | ![tic_correcto](https://i.ibb.co/48JQg0R/tic-1.png)
Photon Mapping | 03-02-2020 | ![tic_correcto](https://i.ibb.co/48JQg0R/tic-1.png)

# Compilation and execution

The repository contains a set of folders where the code is located. Each folder is a project of the course and can be 
compiled in a independent wa due to there is a makefile for each one.

In order to compile the projects, you must be in the directory and introduce the following commands in your terminal:

* Geometry:

```
$> make clean
$> make 
$> bin/geometry
```

&nbsp;

* Tone Mapping:

```
$> make clean
$> make 
$> bin/toneMapping media/ <image_file>
```
&nbsp;


* Ray Tracing:

```
$> make clean
$> make 
$> bin/rayTracing <rays per pixel> <width of image> <height of image> <path of the file>
```
&nbsp;


* Path Tracing:

```
$> make clean
$> make 
$> bin/pathTracing <rays per pixel> <width of image> <height of image> <scene_code> <path of the file>
```
&nbsp;


* Photon Mapping:

This code can´t be executed from terminal directly because is code obtanied from the teachers of the subject. This code
has a set precompiled libraries for visual studio editor, version of 2013. You must install the IDE in order to compile 
and execute it.

# Authors

* [Victor Peñasco](https://github.com/vpec) - 741294
* [Rubén Rodríguez](https://github.com/ZgzInfinity) - 737215



