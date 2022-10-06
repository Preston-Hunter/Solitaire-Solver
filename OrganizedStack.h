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
    explicit OrganizedStack(cardFile f);
};


#endif //SOLITAIRE_SOLVER_ORGANIZEDSTACK_H
