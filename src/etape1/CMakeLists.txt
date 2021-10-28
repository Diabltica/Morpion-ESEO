cmake_minimum_required(VERSION 3.20)
project(C_ESEO C)

set(CMAKE_C_STANDARD 99)

add_executable(C_ESEO main.c board.c board.h board_view.h board_view_text.c game.c game.h player_manager.h player_manager_mock.c tictactoe_errors.h tictactoe_erros.c)