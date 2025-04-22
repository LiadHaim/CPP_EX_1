CXX = clang++
CXXFLAGS = -std=c++2a -Wall -Wextra -g


SRC = main.cpp Graph.cpp ALGO.cpp Pointer.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = tests.cpp Graph.cpp ALGO.cpp Pointer.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

TARGET = prog
TEST_TARGET = tests

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)