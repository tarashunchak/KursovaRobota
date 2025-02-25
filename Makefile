INCLUDES_DIR = includes

# Файли проєкту
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)
MAIN_SRC = main.cpp
MAIN_OBJ = main.o

# Залежності
DEPS = $(OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

# Флаги компілятора
CXXFLAGS += -I$(INCLUDES_DIR)

# Ім'я програми (має бути визначене)
TARGET = my_program

# Правила
all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компіляція .cpp -> .o для src/
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Компіляція main.cpp
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Включення залежностей
-include $(DEPS)

# Очищення
clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.d $(MAIN_OBJ) $(MAIN_OBJ:.o=.d) $(TARGET)

