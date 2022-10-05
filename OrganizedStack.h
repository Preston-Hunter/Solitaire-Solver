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
    File file;
    vector<Card> cards = vector<Card>();
public:
    OrganizedStack(File f);
};


#endif //SOLITAIRE_SOLVER_ORGANIZEDSTACK_H
