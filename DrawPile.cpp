//
// Created by Preston Hunter on 10/8/2022.
//

#include "DrawPile.h"
#include "HelperFunctions.h"
#include "optional"
using std::optional;
using std::make_optional;

const vector<Card> &DrawPile::getCards() const {
    return cards;
}

void DrawPile::setCards(const vector<Card> &cards) {
    DrawPile::cards = cards;
    numCard = cards.size();
}

int DrawPile::getNumCard() const {
    return numCard;
}

void DrawPile::setNumCard(int numCard) {
    DrawPile::numCard = numCard;
}

void DrawPile::removeCardAtCurrentIndex() {
    cards.erase(cards.begin() + currentIndex);
    decrementCurrentIndex();
    //Note when list is empty, current index wll be -1
    numCard--;
}


optional<Card> DrawPile::getCardAtCurrentIndex() {
    //Check it is in bounds
    if (!cards.empty())
        return make_optional(cards[currentIndex]);
    return std::nullopt;
}


optional<Card> DrawPile::getCardAtIndex(int ind){
    //Check it is in bounds
    if (ind < cards.size() && ind >= 0)
        return make_optional(cards[ind]);
    return std::nullopt;
}

/**Goes to next index in cards. If nextIndex is out of bounds (1 after last index)
 * go back to beginning index of cards (0)
 */
void DrawPile::incrementCurrentIndex() {
    if (!cards.empty()) {
        currentIndex += 1;
        currentIndex % cards.size();
    }
    //if no cards in drawPile we dont need to increment the current index as there are no cards to look at
}
/**Goes to previous index in cards. If prevIndex is out of bounds (1 before first index)
 * go back to ending index of cards (cards.size() - 1)
 */
void DrawPile::decrementCurrentIndex() {
    if (!cards.empty()) {
        currentIndex -= 1;
        currentIndex % cards.size();
    }
    //if no cards in drawPile we set it to 0 just to cover any edge cases
    // that may arise from calling this from removeCardAtCurrentIndex
    currentIndex = 0;
}


string DrawPile::toString() const{
    string str = "";
    for (int i = 0; i < cards.size(); i++){
        str += cards[i].toString() + " | ";
    }
    //why does this still run without a crash when i dont include this return statement?
    return str;
}

bool operator == (const DrawPile& lhs, const DrawPile& rhs){
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()))
        return true;
    return false;
}

bool operator != (const DrawPile& lhs, const DrawPile& rhs){
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()))
        return false;
    return true;
}

ostream& operator << (ostream& outs, const DrawPile d){
    outs << d.toString();
    return outs;
}

//todo go thru code and determine if all push backs should use copy constructor
void DrawPile::addInitialCard(const Card& c) {
    cards.push_back(Card(c));
    numCard++;
}

