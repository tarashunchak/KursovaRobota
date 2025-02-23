TARGET = my_program

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iincludes

SRC_DIR = src
INCLUDES_DIR = includes

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)
MAIN_SRC = main.cpp
MAIN_OBJ = main.o

DEPS = $(OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.d $(MAIN_OBJ) $(MAIN_OBJ:.o=.d) $(TARGET)

