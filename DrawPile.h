//
// Created by Preston Hunter on 10/8/2022.
//

#ifndef SOLITAIRE_SOLVER_DRAWPILE_H
#define SOLITAIRE_SOLVER_DRAWPILE_H
#include "vector"
#include "Card.h"
using std::vector;


class DrawPile {
private:
    // all the cards in the draw pile of solitaire
    vector<Card> cards = vector<Card>();
    int numCard;
    //Represents what Card user/program is viewing from DrawPiles cards
    int currentIndex = 0;

public:
    const vector<Card> &getCards() const;
    void setCards(const vector<Card> &cards);

    int getNumCard() const;
    void setNumCard(int numCard);

    void removeCardAtCurrentIndex();
    void incrementCurrentIndex();
    void decrementCurrentIndex();
};


#endif //SOLITAIRE_SOLVER_DRAWPILE_H
