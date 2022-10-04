CXX = g++
CFLAGS = -std=c++11

all: play_game

debug: CFLAGS += -g
debug: play_game

player.o: player.cpp
	$(CXX) $(CFLAGS) -c player.cpp

team.o: team.cpp
	$(CXX) $(CFLAGS) -c team.cpp

play_game.o: play_game.cpp
	$(CXX) $(CFLAGS) -c play_game.cpp

play_game: play_game.cpp team.cpp player.cpp
	$(CXX) $(CFLAGS) play_game.cpp -o play_game


clean:
	rm -f *.o play_game
