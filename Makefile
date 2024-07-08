# all: 
# 	g++ src\main.cpp -Ilibrary\include -Llibrary\lib -w "-Wl,-subsystem,windows" -lmingw32 -lSDL2main -lSDL2 -o main
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Ilibrary\include

# Linker flags
LDFLAGS = -Llibrary\lib -w 
LDLIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Target executable
TARGET = main

# Source files
SRCS = src\main.cpp src\gameloop.cpp src\background.cpp src\mainMenu.cpp src\object.cpp src\button.cpp src\texture.cpp src\gameplay.cpp src\bird.cpp
SRC1 = src\pipe.cpp src\gameover.cpp

# Object files
OBJS = $(SRCS) $(SRC1)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LDLIBS)

# Rule to build object files
# %.exe: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -exe $@

# Rule to clean the build
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
