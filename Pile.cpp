//
// Created by Preston Hunter on 10/7/2022.
//

#include "Pile.h"
#include "Card.h"
#include "HelperFunctions.h"
//todo make error handling
void Pile::addCard(Card c) {
    cards.push_back(c);
}

bool Pile::addCardBasedOnTopCard(const Card& c) {

    //Dont add card if it is not revealed
    if (!c.isRevealed())
        return false;

    if (cards.empty()){
        //If c is a king then can be placed in empty pile
        if (c.getRank() != 13)
            return false;
    }
    else {
        if (!canCardBePlacedOnTopOfOtherCard(c, cards[cards.size() - 1]))
            return false;
    }
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

    //This returns false if either start index is not in bounds, or it is an illegal move and will not peform the copy
    // if false
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


//removes top card if it exists
bool Pile::removeTopCard() {
    if (!cards.empty()){
        removeCardsInRangeFromItoTop(cards.size() - 1);
        return true;
    }
    return false;
}

//Bounds are inclusive
bool Pile::copySubStackOntoAnotherPile(Pile copyOnto, int start) {
    //a substack always goes to the topcard, which has the last index available in cards
    int end = cards.size() - 1;

    //Check bounds are within range
    if (start > cards.size() - 1 || end > cards.size() - 1 || end < start || start < 0){
        return false;
    }

    //If copyOnto is empty, then only a king can be placed on it
    if (copyOnto.getCards().empty()){
        if (cards[start].getRank() != 13)
            return false;
        //If this if statement isn't triggered, then cards[start] is a king. So the substack that starts on it
        // can be copied to copyOnto
    }
    else {
        //Check if initial card can be placed on Topcard of copyOnto (which exists as copyOnto.cards is not empty)
        if (!canCardBePlacedOnTopOfOtherCard(cards[start], copyOnto.getCards()[copyOnto.getCards().size() - 1]))
            return false;
        //Check that initial card is revealed. If not then we do not move it
        // if we wanted to be extra we would check all cards in the range. but due to how solitaire is initialized
        // (as a game and programmatically) it will never be the case that a revealed card has an unrevealed card on top of it
        // and that a revealed card has another revealed card on top of it that legally cant be placed on top of
        // said card
        if (!cards[start].isRevealed())
            return false;
    }
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
    if (!toBePlaced.isRevealed() || !beingPlacedOn.isRevealed())
        return false;
    return true;
}


optional<Card> Pile::getTopCard(){
    if (cards.empty())
        return std::nullopt;
    return std::make_optional(cards[cards.size() - 1]);
}

const vector<Card> &Pile::getCards() const {
    return cards;
}

void Pile::setCards(const vector<Card> &cards) {
    Pile::cards = cards;
}

string Pile::toString() const{
    string str = "";
    for (int i = 0; i < cards.size(); i++){
        str += cards[i].toString() + " | ";
    }
    //why does this still run without a crash when i dont include this return statement?
    return str;
}

bool operator == (const Pile& lhs, const Pile& rhs){
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()))
        return true;
    return false;
}

bool operator != (const Pile& lhs, const Pile& rhs){
    if (cardVectorsEqual(lhs.getCards(), rhs.getCards()))
        return false;
    return true;
}


ostream& operator << (ostream& outs, const Pile& p){
    outs << p.toString();
    return outs;
}

