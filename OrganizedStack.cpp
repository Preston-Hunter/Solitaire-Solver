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

void OrganizedStack::addCard(Card c) {
    cards.push_back(c);
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

Card OrganizedStack::removeAndReturnTopCard() {
    if (!cards.empty()){
        Card copy = copyTopCard();
        removeTopCard();
        return copy;
    }
    // if no cards in stack return null card
    else
        return Card(0, NULLCARD, true);
}

ostream& operator << (ostream& outs, OrganizedStack& org){
    outs << org.toString();
    return outs;
}