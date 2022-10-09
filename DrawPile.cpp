//
// Created by Preston Hunter on 10/8/2022.
//

#include "DrawPile.h"

const vector<Card> &DrawPile::getCards() const {
    return cards;
}

void DrawPile::setCards(const vector<Card> &cards) {
    DrawPile::cards = cards;
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