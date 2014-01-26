#Makefile for GravityGame

PATH_TO_MAKE = /home/kevin/Development/Gravity

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -L$(PATH_TO_MAKE)/lib -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

SRCMAIN = Game.cpp Manager.cpp

INPUT_DIR = input
SRCINPUT = InputManager.cpp

RESOURCE_DIR = resource
SRCRESOURCE = ResourceManager.cpp

WORLD_DIR = world
SRCWORLD = Actor.cpp ActorContainer.cpp ActorData.cpp Scene.cpp WorldManager.cpp \
		EntityManager.cpp

SCENE_DIR = scenes
SRCSCENE = TestScene.cpp

ACTOR_DIR = actors
SRCACTOR = Player.cpp SpriteCan.cpp

SOURCES = $(SRCMAIN) \
		$(SRCINPUT:%=$(INPUT_DIR)/%) \
		$(SRCRESOURCE:%=$(RESOURCE_DIR)/%) \
		$(SRCWORLD:%=$(WORLD_DIR)/%) \
		$(SRCSCENE:%=$(SCENE_DIR)/%) \
		$(SRCACTOR:%=$(ACTOR_DIR)/%)

OBJECTS = $(SOURCES:%.cpp=%.o)

OBJ = $(OBJECTS:%=$(OBJ_DIR)/%)
			
			
gravity: dir $(OBJ)
	$(CXX) $(OBJ) -o $(BIN_DIR)/gravity $(LDFLAGS)


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(PATH_TO_MAKE)/$(INCLUDE_DIR) -c $< -o $@

.PHONY: clean dir

dir: 
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(INPUT_DIR)
	mkdir -p $(OBJ_DIR)/$(RESOURCE_DIR)
	mkdir -p $(OBJ_DIR)/$(WORLD_DIR)
	mkdir -p $(OBJ_DIR)/$(SCENE_DIR)
	mkdir -p $(OBJ_DIR)/$(ACTOR_DIR)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
