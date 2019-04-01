cmake_minimum_required(VERSION 3.13)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_2 main.cpp Card.cpp Card.h Bet.cpp Bet.h Hand.cpp Hand.h BetHistory.cpp BetHistory.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AlphaPlayer.cpp AlphaPlayer.h BetaPlayer.cpp BetaPlayer.h Game.cpp Game.h)