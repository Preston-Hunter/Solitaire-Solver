#include <iostream>
#include "Card.h"
#include "SolitaireClassInteractions.h"
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
    SolitaireClassInteractions sol = SolitaireClassInteractions();
    cout << sol.toString() << endl;

    //test();


    return 0;
}
