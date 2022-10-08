#include <iostream>
#include "Card.h"
#include "OrganizedStack.h"
using std::cout;
using std::endl;
int main() {
    std::cout << "Hello, World!" << std::endl;
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
