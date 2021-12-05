cmake_minimum_required(VERSION 3.20)

project(Morpion_ESEO C)

set(CMAKE_C_STANDARD 11)

include_directories(src/etape1
        src/test_tictactoe)

add_compile_definitions(CONFIG_SDLUI=1)
add_compile_definitions(CONFIG_PLAYER_MANAGER_SDL=1)

add_executable(Morpion_ESEO
        src/etape1/board.c
        src/etape1/board.h
        src/etape1/board_view.h
        src/etape1/board_view_text.c
        src/etape1/game.c
        src/etape1/game.h
        src/etape1/main.c
        src/etape1/player_manager.h
        #        src/etape1/player_manager_mock.c
        src/etape1/tictactoe_errors.h
        src/etape1/tictactoe_erros.c
        src/etape3/board_view_sdl.c
        src/etape3/player_manager_sdl.c)#Comment to run unit test

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(Morpion_ESEO ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

#Uncomment to run unit test
#
#
#add_executable(Morpio_ESEO
#               src/etape1/board.c
#               src/test_tictactoe/main.c
#               src/test_tictactoe/test_CheckEndOfGame.c
#               src/test_tictactoe/test_CheckEndOfGame.h)#Uncomment to run unit test
#
