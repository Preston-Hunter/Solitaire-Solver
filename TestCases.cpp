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
    if (c.toString() == "1 of CLUBS")
        return true;
    return false;
}

bool testCardEquality(){
    Card c(1, 1, true);
    Card c2(2, 3, true);
    if (c == c2)
        return false;
    c.setRank(2);
    c2.setFile(1);
    if(!(c == c2))
        return false;
    if (c.getColor() != c2.getColor())
        return false;

    return true;
}

int test() {
    std::cout << "Hello, World!" << std::boolalpha <<std::endl;

    cout << "Card test success: " << testCard() << endl;
    cout << "Card equality test success: " << testCardEquality() << endl;
    cout << "Organized stack equality test success: " << "" << endl;
    cout << "DrawPile equality test success: " << "" << endl;
    cout << "Pile equality test success: " << "" << endl;

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
