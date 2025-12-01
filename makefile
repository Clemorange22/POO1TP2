# Compilateur C++
CXX = g++

# Options à passer au compilateur
CXXFLAGS = -g -ansi -pedantic -Wall -std=c++11

# Options du préprocesseur : inclure le dossier 'src' pour que les tests trouvent les headers.
CPPFLAGS = -I$(SRC_DIR)

TARGET_EXEC := trajets

TEST_EXEC := testsTrajets

# Dossier temporaire pour la compilation
BUILD_DIR := build

# Dossier source
SRC_DIR := src

# Dossier contenant les tests unitaires
TEST_DIR := tests

# Trouve tous les chemins des .cpp dans le dossier source
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Chemin de tous les .o dans $(BUILD_DIR) : src/Trajet.cpp -> build/src/Trajet.o
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Objets du programme sans le main (à utiliser pour l'exécutable de test).
OBJS_NO_MAIN := $(filter-out $(BUILD_DIR)/$(SRC_DIR)/main.o,$(OBJS))

# Trouve tous les chemins des .cpp dans le dossier tests
TESTS := $(shell find $(TEST_DIR) -name '*.cpp')

# Chemin de tous les .o des tests dans $(BUILD_DIR).
TESTSO := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TESTS))


all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC)


$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) # Édition des liens.
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	rm -f ./$(TARGET_EXEC)
	ln -s $@ ./$(TARGET_EXEC)



$(BUILD_DIR)/$(TEST_EXEC): $(OBJS_NO_MAIN) $(TESTSO) # Édition des liens pour l'exécutable de test.
	$(CXX) $(OBJS_NO_MAIN) $(TESTSO) -o $@ $(LDFLAGS)
	rm -f ./$(TEST_EXEC)
	ln -s $@ ./$(TEST_EXEC)


# Règle de compilation : build/.../something.o dépend de .../something.cpp.
$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: run clean all
run: all # Lance le programme après compilation.
	./$(TARGET_EXEC)

tests: all
	./$(TEST_EXEC)
clean:
	rm -rf $(BUILD_DIR)
	rm -f ./$(TARGET_EXEC)
	rm -f ./$(TEST_EXEC)

