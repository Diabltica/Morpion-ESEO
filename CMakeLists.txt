cmake_minimum_required(VERSION 3.20)
project(Morpion_ESEO C)

set(CMAKE_C_STANDARD 11)

include_directories(src/etape1
                    src/test_tictactoe)

add_executable(Morpion_ESEO
               src/etape1/board.c
               src/etape1/board.h
               src/etape1/board_view.h
               src/etape1/board_view_text.c
               src/etape1/game.c
               src/etape1/game.h
               src/etape1/main.c
               src/etape1/player_manager.h
               src/etape1/player_manager_mock.c
               src/etape1/tictactoe_errors.h
               src/etape1/tictactoe_erros.c)#Comment to run unit test

# add_executable(Morpio_ESEO
#               src/etape1/board.c
#               src/test_tictactoe/main.c
#               src/test_tictactoe/test_CheckEndOfGame.c
#               src/test_tictactoe/test_CheckEndOfGame.h)#Uncomment to run unit test