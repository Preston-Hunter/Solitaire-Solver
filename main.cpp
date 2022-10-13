#include <iostream>
#include "Card.h"
#include "SolitaireGameLogic.h"
#include "TestCases.h"
#include "random"
#include <ctime>
#include "OrganizedStack.h"
#include "HelperFunctions.h"
#include "algorithm"
using std::shuffle;

using std::cout;
using std::endl;
int main() {
    OrganizedStack o = OrganizedStack(DIAMONDS);
    cout << char(4) << endl;

    SolitaireGameLogic sol = SolitaireGameLogic();
    vector<Card> vec = sol.createDeck();
    o.setCards(vec);
    //cout << o.toString() << endl;

    cout << sol.toString() << endl;

    //test();


    return 0;
}
