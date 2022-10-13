//
// Created by Preston Hunter on 10/9/2022.
//

#ifndef SOLITAIRE_SOLVER_SOLITAIREGAMELOGIC_H
#define SOLITAIRE_SOLVER_SOLITAIREGAMELOGIC_H
#include "OrganizedStack.h"
#include "Pile.h"
#include "DrawPile.h"


class SolitaireGameLogic {
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

    vector<Pile> allPiles = vector<Pile>();

    //Create Draw Pile
    DrawPile drawPile = DrawPile();

    int numTurns = 0;
public:

    SolitaireGameLogic();
    void initializeGame();
    static vector<Card> createDeck();

    bool moveTopCardFromPileToOrgStack(Pile p, OrganizedStack org);
    bool moveTopCardFromOrgStackToPile(OrganizedStack org, Pile p);
    bool moveCardFromDrawToOrg(DrawPile draw, OrganizedStack org);
    bool moveCardFromDrawToPile(DrawPile draw, Pile p);
    bool canCardBePlacedOnTopOfOtherCard(const Card& toBePlaced, const Card& beingPlacedOn);

};


#endif //SOLITAIRE_SOLVER_SOLITAIREGAMELOGIC_H
