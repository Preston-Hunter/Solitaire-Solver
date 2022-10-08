//
// Created by Preston Hunter on 10/5/2022.
//

#include "OrganizedStack.h"
#include "iostream"
using std::cout;
using std::endl;

OrganizedStack::OrganizedStack(cardFile f) {
    this->file = f;
}

bool OrganizedStack::addCard(Card c) {
    cards.push_back(c);
    return true;
}

void OrganizedStack::removeTopCard() {
    cards.pop_back();
}

Card OrganizedStack::copyTopCard() {
    if (!cards.empty())
        return Card(cards[cards.size()-1]);
    //return null card
    return Card(0, NULLCARD, true);
}



string OrganizedStack::toString(){
    string str = "";
    for (int i = 0; i < cards.size(); i++){
        str += cards[i].toString() + " | ";
    }
    //why does this still run without a crash when i dont include this return statement?
    return str;
}

ostream& operator << (ostream& outs, OrganizedStack& org){
    outs << org.toString();
    return outs;
}

bool OrganizedStack::addCardByFileAndRank(const Card& c) {
    if (c.getFile() == this->file){
        if (c.getRank() == 1 && cards.empty())
            addCard(c);
        else if (c.getRank() - cards[cards.size()-1].getRank() == 1)
            addCard(c);
        else
            return false;
        return true;
    }
    return false;
}
