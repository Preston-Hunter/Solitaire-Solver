//
// Created by Preston Hunter on 10/7/2022.
//

#ifndef SOLITAIRE_SOLVER_PILE_H
#define SOLITAIRE_SOLVER_PILE_H
#include <vector>
#include "Card.h"
#include <optional>
using std::vector;
using std::optional;

//A sub-stack is a selection of cards that start from anywhere in pile to the top card, where all cards must be revealed
// Topcard is the Card object with highest index in cards

class Pile {
private:
    vector<Card> cards = vector<Card>();
public:
    const vector<Card> &getCards() const;
    void setCards(const vector<Card> &cards);
    void addCard(Card c);
    bool addCardBasedOnTopCard(const Card& c);

    bool moveSubStackFromThisPileToOther(Pile other, int start);
    bool revealTopCard();
    bool removeTopCard();
    //Use optionals to return a single object type, leaves room for error return when cards list is empty
    optional<Card> getTopCard();

    //helper methods
    bool removeCardsInRangeFromItoTop(int i);
    bool copySubStackOntoAnotherPile(Pile copyOnto, int start);
    static bool canCardBePlacedOnTopOfOtherCard(const Card& toBePlaced, const Card& beingPlacedOn);
    bool areCardsRevealedInRangeInclusive(int i, int j);


    string toString() const;
    friend bool operator != (const Pile& lhs, const Pile& rhs);
    friend bool operator == (const Pile& lhs, const Pile& rhs);

    friend ostream& operator << (ostream& outs, const Pile& p);
};


#endif //SOLITAIRE_SOLVER_PILE_H
