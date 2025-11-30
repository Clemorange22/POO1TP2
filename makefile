CXX = g++ # Compilateur C++
CXXFLAGS = -g -ansi -pedantic -Wall -std=c++11 # Flags à passer au compilo

TARGET_EXEC := trajets

BUILD_DIR := build# Dossier temporaire pour la compilation
SRC_DIR := src# Dossier source

# Trouve tous les chemins des .cpp dans le dossier source
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Chemin de tous les .o dans $(BUILD_DIR): src/Trajet.cpp -> build/src/Trajet.o
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) # Édition des liens
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	ln -s $@ ./$(TARGET_EXEC)

# Règle de compilation : build/.../something.o dépend de src/.../something.cpp
$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: run clean all
run: all # Lance directement le programme après compilation
	./$(TARGET_EXEC)

clean:
	rm -rf $(BUILD_DIR)
	rm -f ./$(TARGET_EXEC)

# TODO : Tests