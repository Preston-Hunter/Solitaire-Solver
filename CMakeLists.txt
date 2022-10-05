cmake_minimum_required(VERSION 3.17)
project(solitaire_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(solitaire_solver main.cpp Card.h Card.cpp SolitaireGameState.cpp SolitaireGameState.h
        OrganizedStack.cpp OrganizedStack.h)