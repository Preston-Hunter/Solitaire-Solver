//
// Created by Preston Hunter on 10/9/2022.
//

#include <ctime>
#include "SolitaireClassInteractions.h"
#include "algorithm"
#include "random"
#include "optional"
using std::optional;
using std::shuffle;


SolitaireClassInteractions::SolitaireClassInteractions() {
    allPiles.push_back(p1);
    allPiles.push_back(p2);
    allPiles.push_back(p3);
    allPiles.push_back(p4);
    allPiles.push_back(p5);
    allPiles.push_back(p6);
    allPiles.push_back(p7);

    allOrgStacks.push_back(clubStack);
    allOrgStacks.push_back(diamondStack);
    allOrgStacks.push_back(heartStack);
    allOrgStacks.push_back(spadeStack);





    initializeGame();
}

void SolitaireClassInteractions::initializeGame() {
    vector<Card> allCards = createDeck();
    std::srand(std::time(nullptr));
    //todo change source of randomness
    shuffle(allCards.begin(), allCards.end(), std::default_random_engine(std::rand()));

    int currentCardIndex = 0;

    //Fill Piles
    //1 Card goes in p1, 2 in p2, etc until p7
    for(int i = 0; i < 7; i++){
        int numCardsToAdd = i + 1;
        for (int j = 0; j < numCardsToAdd; j++){
            allPiles[i].addCard(allCards[currentCardIndex]);
            currentCardIndex++;
        }
        allPiles[i].revealTopCard();
    }

    //Rest of cards go in loose draw pile
    for (; currentCardIndex < allCards.size(); currentCardIndex++){
        drawPile.addInitialCard(allCards[currentCardIndex]);
        drawPile.revealTopCard();
    }

    //Game is now initialized

}

vector<Card> SolitaireClassInteractions::createDeck(){
    vector<Card> cards = vector<Card>();
    for (int rank = 1; rank <= 13; rank++) {
        for (int file = 1; file <= 4; file++) {
            cards.push_back(Card(rank, file, false));
        }
    }
    return cards;
}


bool SolitaireClassInteractions::moveTopCardFromPileToOrgStack(Pile p, OrganizedStack org) {
    if(!p.getCards().empty()){
        bool added = org.addCardByFileAndRank(*p.getTopCard());
        //If the topcard was able to be added, remove it from pile and reveal the new topcard
        if (added){
            p.removeTopCard();
            p.revealTopCard();
            return true;
        }
        //otherwise card was not added organized stack org, so return false as method performed nothing
    }

    return false;
}

bool SolitaireClassInteractions::moveTopCardFromOrgStackToPile(OrganizedStack org, Pile p) {
    if(!org.getCards().empty()){
        //todo copyTopCard method is inconsistent with pile's getTopCard. consider refactoring later
        bool added = p.addCardBasedOnTopCard(org.copyTopCard());
        //If the topcard was able to be added, remove it from pile and reveal the new topcard
        if (added){
            org.removeTopCard();
            return true;
        }
        //otherwise card was not added to pile p, so return false as method performed nothing
    }
    return false;
}

bool SolitaireClassInteractions::moveCardFromDrawToOrg(DrawPile draw, OrganizedStack org) {
    if(!draw.getCards().empty()){
        bool added = org.addCardByFileAndRank(*draw.getCardAtCurrentIndex());
        if (added){
            draw.removeCardAtCurrentIndex();
            return true;
        }
    }
    return false;
}

bool SolitaireClassInteractions::moveCardFromDrawToPile(DrawPile draw, Pile p) {
    if(!draw.getCards().empty()){
        bool added = p.addCardBasedOnTopCard(*draw.getCardAtCurrentIndex());
        if (added){
            draw.removeCardAtCurrentIndex();
            return true;
        }
    }
    return false;
}




bool SolitaireClassInteractions::moveCardFromDrawAtIndexToOrg(DrawPile draw, OrganizedStack org, int ind) {
    if(!draw.getCards().empty()){
        bool added = org.addCardByFileAndRank(*draw.getCardAtIndex(ind));
        if (added){
            draw.removeCardAtCurrentIndex();
            return true;
        }
    }
    return false;
}

bool SolitaireClassInteractions::moveCardFromDrawAtIndexToToPile(DrawPile draw, Pile p, int ind) {
    if(!draw.getCards().empty()){
        bool added = p.addCardBasedOnTopCard(*draw.getCardAtIndex(ind));
        if (added){
            draw.removeCardAtCurrentIndex();
            return true;
        }
    }
    return false;
}


bool SolitaireClassInteractions::canCardBePlacedOnTopOfOtherCard(const Card& toBePlaced, const Card& beingPlacedOn) {
    if (toBePlaced.getColor() == beingPlacedOn.getColor())
        return false;
    if (toBePlaced.getRank() + 1 != beingPlacedOn.getRank())
        return false;
    return true;
}


string SolitaireClassInteractions::toString() const{
    string str = "------Organized Stacks-----\n";
    for (int i = 0; i < allOrgStacks.size(); i++){
        str += fileToString(allOrgStacks[i].getFile()) + ": " +  allOrgStacks[i].toString() + "\n";
    }

    str += "------DrawPile-----\n";
    str += drawPile.toString() + "\n";

    str += "------Piles-----\n";
    for (int i = 0; i < allPiles.size(); i++){
        str += allPiles[i].toString() + "\n";
    }

    return str;
}

ostream& operator << (ostream& outs, const SolitaireClassInteractions& sol){
    outs << sol.toString();
    return outs;
}
