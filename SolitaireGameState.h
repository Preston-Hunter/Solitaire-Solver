//
// Created by Preston Hunter on 10/5/2022.
//

#ifndef SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
#define SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
#include "OrganizedStack.h"
#include "Card.h"


class SolitaireGameState {

private:
    OrganizedStack diamondStack = OrganizedStack(DIAMONDS);
    OrganizedStack clubSack = OrganizedStack(CLUBS);
    OrganizedStack heartStack = OrganizedStack(HEARTS);
    OrganizedStack spadeStack = OrganizedStack(SPADES);


};


#endif //SOLITAIRE_SOLVER_SOLITAIREGAMESTATE_H
