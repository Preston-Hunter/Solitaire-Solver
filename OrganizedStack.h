//
// Created by Preston Hunter on 10/5/2022.
//

#ifndef SOLITAIRE_SOLVER_ORGANIZEDSTACK_H
#define SOLITAIRE_SOLVER_ORGANIZEDSTACK_H
#include "Card.h"
#include <vector>
using std::vector;

class OrganizedStack {
private:
    cardFile file;
    vector<Card> cards = vector<Card>();
public:

    cardFile getFile() const;
    void setFile(cardFile file);

    const vector<Card> &getCards() const;
    void setCards(const vector<Card> &cards);

    explicit OrganizedStack(cardFile f);
    void addCard(Card c);
    void removeTopCard();
    Card copyTopCard();
    string toString();
    bool addCardByFileAndRank(const Card& c);
    Card removeAndReturnTopCard();

    friend bool operator != (const OrganizedStack& lhs, const OrganizedStack& rhs);
    friend bool operator == (const OrganizedStack& lhs, const OrganizedStack& rhs);
    friend ostream& operator << (ostream& outs, OrganizedStack& org);

};


#endif //SOLITAIRE_SOLVER_ORGANIZEDSTACK_H
