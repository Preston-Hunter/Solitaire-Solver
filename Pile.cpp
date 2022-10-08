//
// Created by Preston Hunter on 10/7/2022.
//

#include "Pile.h"
#include "Card.h"
//todo make error handling
void Pile::addCard(Card c) {
    cards.push_back(c);
}

bool Pile::addCardBasedOnTopCard(const Card& c) {

    if (!canCardBePlacedOnTopOfOtherCard(c, cards[cards.size() - 1]))
        return false;

    addCard(c);
    return true;
}
/**this method moves a substack from one pile object to another
 *
 * @param other the pile which we are moving the SubStack to be on top of
 * @param start the index which starts the SubStack in this->cards
 * @return whether the operation succeeded or not
 */
bool Pile::moveSubStackFromThisPileToOther(Pile other, int start) {

    //This returns false if either start index is not in bounds, or it is an illegal move
    bool success = copySubStackOntoAnotherPile(other, start);

    //if unsuccessful return false
    if (!success)
        return false;
    //Otherwise continue with normal solitaire game. remove the Substack from the starting pile (this->pile) and reveal topcard if it exists
    //Remove cards from this->cards
    removeCardsInRangeFromItoTop(start);
    //reveal the top card in this->cards
    revealTopCard();
    return true;
}

bool Pile::areCardsRevealedInRangeInclusive(int i, int j) {
    // check i and j are indices in cards, and j>=i
    if (i > cards.size() - 1 || j > cards.size() - 1 || j < i || i < 0){
        return false;
    }

    for (int ind = i; ind <= j; ind++ ){
        if (!cards[ind].isRevealed()){
            return false;
        }
    }
    return true;


}

bool Pile::removeCardsInRangeFromItoTop(int i) {
    if (cards.size()-1 >= i){
        cards.resize(i+1);
        return true;
    }
    return false;


}

//reveals the top card in a pile
bool Pile::revealTopCard() {
    if (!cards.empty()){
        cards[cards.size() - 1].setRevealed(true);
        return true;
    }
    return false;
}

//Bounds are inclusive
bool Pile::copySubStackOntoAnotherPile(Pile copyOnto, int start) {
    //a substack always goes to the topcard
    int end = cards.size() - 1;

    //Check bounds are within range
    if (start > cards.size() - 1 || end > cards.size() - 1 || end < start || start < 0){
        return false;
    }
    //Check if initial card can be placed on Topcard of copyOnto
    if (!canCardBePlacedOnTopOfOtherCard(cards[start], copyOnto.getCards()[copyOnto.getCards().size() - 1]))
        return false;

    // Copy all cards from cards on top of copyOnto
    for (int ind = start; ind <= end; ind++){
        copyOnto.addCard(cards[ind]);
    }

    return true;
}

bool Pile::canCardBePlacedOnTopOfOtherCard(const Card& toBePlaced, const Card& beingPlacedOn) {
    if (toBePlaced.getColor() == beingPlacedOn.getColor())
        return false;
    if (toBePlaced.getRank() + 1 != beingPlacedOn.getRank())
        return false;
    return true;
}

const vector<Card> &Pile::getCards() const {
    return cards;
}

void Pile::setCards(const vector<Card> &cards) {
    Pile::cards = cards;
}

string Pile::toString() {
    string str = "";
    for (int i = 0; i < cards.size(); i++){
        str += cards[i].toString() + " | ";
    }
    //why does this still run without a crash when i dont include this return statement?
    return str;
}

ostream& operator << (ostream& outs, Pile& p){
    outs << p.toString();
    return outs;
}