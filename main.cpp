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
    //cout << o.toString() << endl;
    cout << char(4) << endl;

    SolitaireGameLogic sol = SolitaireGameLogic();
    vector<Card> vec = sol.createDeck();
    for(Card & i : vec){
        cout << i << endl;
    }
    test();


    return 0;
}
