# set compiler and compile options
EXEC = graphics
CXX = g++             # use the GNU C++ compiler
OPTS = -O2 -Wall -g   # use some optimization, report all warnings and enable debugging
CFLAGS = $(OPTS)      # add compile flags
LDFLAGS =             # specify link flags here

# set a list of directories
INCDIR =./include
OBJDIR = ./obj
BINDIR = ./bin
SRCDIR = ./src

# set the include folder where the .h files reside
CFLAGS += -I$(INCDIR) -I$(SRCDIR)

MAINSOURCES = main.cpp Point.cpp Direction.cpp SharedOps.cpp Planet.cpp Matrix3.cpp Matrix4.cpp PlanetaryStation.cpp InterplanetaryConnection.cpp
TESTSOURCES = test/PointUnitTest.cpp test/DirectionUnitTest.cpp test/SharedOpsUnitTest.cpp test/PlanetUnitTest.cpp test/Matrix3UnitTest.cpp test/Matrix4UnitTest.cpp test/PlanetaryStationUnitTest.cpp test/InterplanetaryConnectionUnitTest.cpp test/UnitTestMain.cpp

# add here the source files for the compilation
SOURCES = $(MAINSOURCES) $(TESTSOURCES)

# create the obj variable by substituting the extension of the sources
# and adding a path
_OBJ = $(SOURCES:.cpp=.o)
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJ)
	$(CXX) -o $(BINDIR)/$(EXEC) $(OBJ) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

clean:
	rm -vf $(BINDIR)/$(EXEC) $(OBJ)