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

bool testOrganizedStackEquality(){

    OrganizedStack o1 = OrganizedStack(HEARTS);
    OrganizedStack o2 = OrganizedStack(SPADES);

    Card c(1, 3, true);
    Card c2(2, 3, true);
    Card c3(3,3,true);
    //Try to add card of improper file to organizedStack of hearts
    bool success = o1.addCardByFileAndRank(c2);
    if (success)
        return false;
    //try to add card of improper rank to organizedStack of spades
    success =  o2.addCardByFileAndRank(Card(2, SPADES, true));
    if (success)
        return false;
    o1.addCardByFileAndRank(c);
    o1.addCardByFileAndRank(c2);
    o1.addCardByFileAndRank(c3);

    o2.setFile(HEARTS);
    o2.addCardByFileAndRank(c);
    o2.addCardByFileAndRank(c2);
    o2.addCardByFileAndRank(c3);
    cout << o1 << endl << o2 << endl;

    bool s = o1 == o2;

    if (!s){
        cout << "uhh" << endl;
        return false;
    }
    return true;

}

int test() {
    std::cout << "Hello, World!" << std::boolalpha <<std::endl;

    cout << "Card test success: " << testCard() << endl;
    cout << "Card equality test success: " << testCardEquality() << endl;
    cout << "Organized stack equality test success: " << testOrganizedStackEquality() << endl;
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
//    cout << g;
    return 0;
}
