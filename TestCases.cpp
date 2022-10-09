//
// Created by Preston Hunter on 10/9/2022.
//

#include <iostream>
#include "Card.h"
#include "OrganizedStack.h"
#include "DrawPile.h"
#include "Pile.h"
using std::cout;
using std::endl;



bool testCard(){
    Card c(1, 1, true);
    Card c2(2, 2, true);
    cout << c << endl;
    cout << c2 << endl;
    return true;
}

int test() {
    std::cout << "Hello, World!" << std::endl;

    cout << "Card test success" << testCard() << endl;

    Card c(1, 2, true);
    Card c2(2, 2, true);
    OrganizedStack org(DIAMONDS);
    org.addCardByFileAndRank(c);
    org.addCardByFileAndRank(c2);
    cout << org << endl;
    Card g = org.removeAndReturnTopCard();
    cout << org << endl;
    cout << g;
    return 0;
}
