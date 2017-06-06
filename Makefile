ifeq ($(OS),Windows_NT)
    OS_detected = Windows
else
    OS_detected = $(shell uname -s)
endif

CC = g++
CFLAGS = -Wall -c -I$(INCLUDEDIR) -L$(LIBDIR) -std=gnu++0x -g

ifeq ($(OS_detected), Windows)
	LDFLAGS += -lglfw3 -lopengl32 -lgdi32 -lglew32
	RM = rm -f
else
	LDFLAGS += -lglfw -lGL -lGLEW
	RM = rm -rf
endif



BINARYDIR = bin
BUILDDIR = build
INCLUDEDIR = include
LIBDIR = lib
SOURCEDIR = src

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))

output : $(OBJECTS)
	$(CC) -o $(BINARYDIR)/$@ $^ -Wall $(LDFLAGS)

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)


clean:
	$(RM) $(OBJECTS) $(BINARYDIR)/output