#include <iostream>
#include "Card.h"
#include "OrganizedStack.h"
#include "TestCases.h"
#include "HelperFunctions.h"
using std::cout;
using std::endl;
int main() {

    vector<Card> c = vector<Card>();
    Card c1(1, 2, true);
    Card c2(2, 2, true);

    c.push_back(c2);
    c.push_back(c1);
    vector<Card> d = vector<Card>();
    d.push_back(Card(c2));
    d.push_back(Card(c1));
    cout << cardVectorsEqual(c,d);
    // test();

    return 0;
}
