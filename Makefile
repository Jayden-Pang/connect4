FLAGS = -pedantic-errors -std=c++11

ai_move.o: ai_move.cpp ai_move.h input_move.h winning_check.h
	g++ $(FLAGS) -c $<

input_move.o: input_move.cpp input_move.h
	g++ $(FLAGS) -c $<

print_board.o: print_board.cpp print_board.h
	g++ $(FLAGS) -c $<

game_manager.o: game_manager.cpp game_manager.h print_board.h ai_move.h input_move.h winning_check.h save_load.h
	g++ $(FLAGS) -c $<

winning_check.o: winning_check.cpp winning_check.h
	g++ $(FLAGS) -c $<

save_load.o: save_load.cpp save_load.h
	g++ $(FLAGS) -c $<

connect4.o: connect4.cpp game_manager.h print_board.h save_load.h
	g++ $(FLAGS) -c $<

connect4: connect4.o ai_move.o input_move.o print_board.o game_manager.o winning_check.o save_load.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f connect4 *.o

.PHONY: clean
