//
// Created by Preston Hunter on 10/7/2022.
//

#ifndef SOLITAIRE_SOLVER_PILE_H
#define SOLITAIRE_SOLVER_PILE_H
#include <vector>
#include "Card.h"



using std::vector;


class Pile {
private:
    vector<Card> cards = vector<Card>();
public:
    const vector<Card> &getCards() const;

    void setCards(const vector<Card> &cards);

public:
    void addCard(Card c);
    bool addCardBasedOnTopCard(const Card& c);
    static bool canCardBePlacedOnTopOfOtherCard(const Card& toBePlaced, const Card& beingPlacedOn);
    //A sub-stack is a selection of cards that start from anywhere in pile to the top card, where all cards must be revealed
    bool moveSubStackFromThisPileToOther(Pile other, int start);
    bool areCardsRevealedInRangeInclusive(int i, int j);
    bool removeCardsInRangeFromItoTop(int i);
    bool revealTopCard();
    bool copySubStackOntoAnotherPile(Pile copyOnto, int start);
    string toString();

    friend ostream& operator << (ostream& outs, Pile& p);
};


#endif //SOLITAIRE_SOLVER_PILE_H
