# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Executable name
TARGET = $(BIN_DIR)/battleship

# Source files (excluding testMain.cpp)
SRCS = $(filter-out $(SRC_DIR)/testMain.cpp, $(wildcard $(SRC_DIR)/*.cpp))

# Object files (place them in obj/)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule: Compile the program
all: $(TARGET)

# Linking
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile each .cpp into .o, placing object files in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Force recompilation
rebuild: clean all

# Separate rule for test executable
test: $(OBJ_DIR)/testMain.o $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJ_DIR)/testMain.o -o $(BIN_DIR)/testBattleship

# Compile testMain separately
$(OBJ_DIR)/testMain.o: $(SRC_DIR)/testMain.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
