#include <iostream>
#include "Card.h"
using std::cout;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Card c(10, 1, true);
    Card c2(11, 2, true);
    cout << c;
    return 0;
}
