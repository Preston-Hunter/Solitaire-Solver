//
// Created by Preston Hunter on 10/5/2022.
//

#include "OrganizedStack.h"
#include "iostream"
#include "HelperFunctions.h"
using std::cout;
using std::endl;


cardFile OrganizedStack::getFile() const {
    return file;
}

void OrganizedStack::setFile(cardFile file) {
    OrganizedStack::file = file;
}

const vector<Card> &OrganizedStack::getCards() const {
    return cards;
}

void OrganizedStack::setCards(const vector<Card> &cards) {
    OrganizedStack::cards = cards;
}



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



string OrganizedStack::toString() const{
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
        else if (cards.empty())
            return false;
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

bool operator == (const OrganizedStack& lhs, const OrganizedStack& rhs){
    //weird error
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()) && (lhs.getFile() == rhs.getFile())) {
        cout << "evalled to true" << endl;
        return true;
    }
    return false;
}
bool operator != (const OrganizedStack& lhs, const OrganizedStack& rhs){
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()) && lhs.getFile() == rhs.getFile())
        return false;
    return true;
}


ostream& operator << (ostream& outs, const OrganizedStack& org){
    outs << org.toString();
    return outs;
}

