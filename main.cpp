#include <iostream>
#include "Card.h"
#include "OrganizedStack.h"
using std::cout;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Card c(1, 2, true);
    Card c2(2, 2, true);
    OrganizedStack org(DIAMONDS);
    org.addCardByFileAndRank(c);
    org.addCardByFileAndRank(c2);
    cout << org;
    return 0;
}
