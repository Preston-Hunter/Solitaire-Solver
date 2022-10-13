cmake_minimum_required(VERSION 3.17)
project(solitaire_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(solitaire_solver main.cpp Card.h Card.cpp SolitaireGameState.cpp SolitaireGameState.h
        OrganizedStack.cpp OrganizedStack.h Pile.cpp Pile.h DrawPile.cpp DrawPile.h SolitaireGameLogic.h SolitaireGameLogic.cpp
        TestCases.cpp TestCases.h HelperFunctions.h HelperFunctions.cpp)