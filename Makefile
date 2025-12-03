INCLUDES=-IC:/msys64/mingw64/include
LIBS=-LC:/msys64/mingw64/lib
TEST_FLAGS=-pthread -lgtest -lgtest_main -lgmock -lgmock_main
CPPFLAGS=-Wall -Werror -Wextra -std=c++20
TEST_SRC=$(wildcard tests/*.cpp) testsMain.cpp

snake_library.a:
	g++ SnakeCore/apple.cpp -c
	g++ SnakeCore/board.cpp -c
	g++ SnakeCore/direction.cpp -c
	g++ SnakeCore/game_engine.cpp -c
	g++ SnakeCore/painter.cpp -c
	g++ SnakeCore/point.cpp -c
	g++ SnakeCore/snake.cpp -c
	ar rc $@ apple.o board.o direction.o game_engine.o painter.o point.o snake.o
	ranlib $@

clean:
	del /Q *.o 2>nul || true
	del /Q snake_library.a 2>nul || true
	del /Q *.exe 2>nul || true


test: snake_library.a
	g++ -c $(CPPFLAGS) $(INCLUDES) tests/tests.cpp -o tests.o $(TEST_FLAGS)
	g++ $(CPPFLAGS) $(INCLUDES) tests.o snake_library.a -o unit_tests $(TEST_FLAGS) $(LIBS) -Wl,-subsystem,console


