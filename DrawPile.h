//
// Created by Preston Hunter on 10/8/2022.
//

#ifndef SOLITAIRE_SOLVER_DRAWPILE_H
#define SOLITAIRE_SOLVER_DRAWPILE_H
#include "vector"
#include "Card.h"
#include "optional"
using std::optional;
using std::make_optional;
using std::vector;


class DrawPile {
private:
    // all the cards in the draw pile of solitaire
    vector<Card> cards = vector<Card>();
    int numCard = 0;
    //Represents what Card user/program is viewing from DrawPiles cards
    int currentIndex = 0;

public:
    const vector<Card> &getCards() const;
    void setCards(const vector<Card> &cards);

    int getNumCard() const;
    void setNumCard(int numCard);

    optional<Card> getCardAtCurrentIndex();
    optional<Card> getCardAtIndex(int ind);
    void removeCardAtCurrentIndex();
    void incrementCurrentIndex();
    void decrementCurrentIndex();

    void addInitialCard(const Card& c);

    string toString() const;

    friend bool operator == (const DrawPile& lhs, const DrawPile& rhs);
    friend bool operator != (const DrawPile& lhs, const DrawPile& rhs);
    friend ostream& operator << (ostream& outs, const DrawPile d);

};


#endif //SOLITAIRE_SOLVER_DRAWPILE_H
