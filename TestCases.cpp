//
// Created by Preston Hunter on 10/9/2022.
//

#include <iostream>
#include "Card.h"
#include "OrganizedStack.h"
#include "DrawPile.h"
#include "Pile.h"
#include "HelperFunctions.h"

using std::cout;
using std::endl;



bool testCard(){
    Card c(1, 1, true);
    if (c.toString() == "1 of CLUBS")
        return true;
    return false;
}

bool testVectorOfCardsEquality(){
    vector<Card> v1 = vector<Card>();
    vector<Card> v2 = vector<Card>();

    Card c(1, 3, true);
    Card c2(2, 3, false);
    Card c3(1,3,false);
    Card c4(3, 5, true);

    Card c5(2, 3, true);
    Card c6(3,3,true);

    v1.push_back(c);
    v1.push_back(c2);
    v2.push_back(c3);
    v2.push_back(c4);

    if (cardVectorsEqual(v1,v2))
        return false;

    //Reset v2
    v2 = vector<Card>();
    v2.push_back(c);
    v2.push_back(c2);

    //Vectors should be equal so this should evaluate to false and not trigger if statement
    if (!cardVectorsEqual(v1,v2))
        return false;

    return true;
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
    // Values of o1 and o2
    // cout << endl << o1 << endl << o2 << endl;

    bool s = o1 == o2;

    if (!s){
        return false;
    }
    return true;

}


bool testDrawPileEquality(){
    DrawPile d1 = DrawPile();
    DrawPile d2 = DrawPile();

    Card c(10, 1, true);
    Card c2(11, 2, true);
    Card c3(12,3,true);
    Card c4(13, 4, true);

    //add two different cards to each pile
    d1.addInitialCard(c);
    d1.addInitialCard(c2);

    bool equal = d1 == d2;
    //They should not be equal. If they are then an error has occurred
    if (equal)
        return false;

    d1.addInitialCard(c2);
    d1.addInitialCard(c3);
    d1.addInitialCard(c4);

    //Make the cards list in each equal
    d2.setCards(d1.getCards());
    equal = d1 == d2;
    if (!equal)
        return false;

    return true;
}

bool testPileEquality(){
    Pile p1 = Pile();
    Pile p2 = Pile();

    Card c(10, 1, true);
    Card c2(10, 1, false);

    Card c3(11,1,false);
    Card c4(11,2,true);
    Card c5(11, 1, true);

    //add two different cards to each pile, but only difference is revealed state
    p1.addCard(c);
    p2.addCard(c2);

    bool equal = p1 == p2;
    //They should not be equal. If they are then an error has occurred
    if (equal)
        return false;

    //Try to add an unrevealed card (it wont work)
    p1.addCardBasedOnTopCard(c3);
    //Try to card with wrong file (it wont work)
    p1.addCardBasedOnTopCard(c4);
    //Add correct card
    p1.addCardBasedOnTopCard(c5);

    //Make the cards list in each equal
    //Reset p2 cards
    p2.setCards(vector<Card>());

    //add cards to p2 to make it equal to p1
    p2.addCard(c);
    p2.addCardBasedOnTopCard(c5);

    equal = p1 == p2;
    if (!equal)
        return false;

    return true;
}

int test() {
    std::cout << "Hello, Test World!" << std::boolalpha <<std::endl << std::endl;

    cout << "Vector of cards comparison success: " << testVectorOfCardsEquality() << std::endl;
    cout << "Card test success: " << testCard() << endl;
    cout << "Card equality test success: " << testCardEquality() << endl;
    cout << "Organized stack equality test success: " << testOrganizedStackEquality() << endl;
    cout << "DrawPile equality test success: " << testDrawPileEquality() << endl;
    cout << "Pile equality test success: " << testPileEquality() << endl;
    return 0;
}
