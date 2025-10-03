all: SnakeGame

SnakeGame: apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o
	g++ -o Snake.exe apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o

apple.o:
	g++ apple.cpp -o apple.o -c

board.o:
	g++ board.cpp -o board.o -c

direction.o:
	g++ direction.cpp -o direction.o -c

game_engine.o:
	g++ game_engine.cpp -o game_engine.o -c

painter.o:
	g++ painter.cpp -o painter.o -c

point.o:
	g++ point.cpp -o point.o -c

snake.o:
	g++ snake.cpp -o snake.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	del  *.o *.exe
