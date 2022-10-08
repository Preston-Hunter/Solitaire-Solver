//
// Created by Preston Hunter on 10/5/2022.
//

#ifndef SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
#define SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
#include "OrganizedStack.h"
#include "Card.h"
#include "Pile.h"

class SolitaireGameState {

private:
    //Initialize the organized stacks, which start empty and filled by player actions
    OrganizedStack diamondStack = OrganizedStack(DIAMONDS);
    OrganizedStack clubSack = OrganizedStack(CLUBS);
    OrganizedStack heartStack = OrganizedStack(HEARTS);
    OrganizedStack spadeStack = OrganizedStack(SPADES);

    //Initialize the Piles, starting empty and will be filled later to their initial state by program
    Pile p1 = Pile();
    Pile p2 = Pile();
    Pile p3 = Pile();
    Pile p4 = Pile();
    Pile p5 = Pile();
    Pile p6 = Pile();
    Pile p7 = Pile();



};


#endif //SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
