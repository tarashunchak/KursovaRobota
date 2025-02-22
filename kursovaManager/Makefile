# Назва фінального виконуваного файлу
TARGET = my_program

# Компілятор і прапори
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Файли проєкту
SRC = main.cpp user.cpp person.cpp admin.cpp auth.cpp manager.cpp manager_controller.cpp managerDB.cpp \
      tariff.cpp tarifDB.cpp tariff_manager.cpp SIM.cpp phonebook.cpp mobile.cpp mobile_manager.cpp call_history.cpp\
      customer.cpp customerDB.cpp customer_manager.cpp request.cpp request_containers.cpp request_details.cpp request_manager.cpp \
      massage.cpp chat.cpp chatDB.cpp chat_manager.cpp ConsoleUI.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

# Правила
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Включення залежностей
-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)

