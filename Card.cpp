//
// Created by Preston Hunter on 10/5/2022.
//

#include "Card.h"
#include "string"
#include "iostream"
using std::ostream;
using std::string;
using std::cout;



string fileToString(cardFile f){
    string str = "";
    if (f == CLUBS){
        str = "CLUBS";
    }
    else if (f == DIAMONDS)
        str = "DIAMONDS";
    else if (f == HEARTS)
        str = "HEARTS";
    else if (f==SPADES)
        str = "SPADES";
    else
        str = "SPADES";
    return str;
}


string rankToString(int r){
    if (r > 0 && r < 11)
        return std::to_string(r);
    else if (r == 13)
        return "KING";
    else if (r == 12)
        return "QUEEN";
    else if (r == 11)
        return "JACK";
    else
        return "NULL";
}


Card::Card(int rank, int file, bool rev) {
    this->rank = rank;
    this->setFile(file);
    revealed = rev;
    this->color = fileToColor(getFile());
}

Card::Card(int rank, cardFile file, bool rev) {
    this->rank = rank;
    this->setFile(file);
    revealed = rev;
    this->color = fileToColor(getFile());
}

Card::Card(const Card &toCopy) {
    this->file = toCopy.file;
    this->rank = toCopy.rank;
    this->color = toCopy.color;
}

Card::Card(){
    file = NULLCARD;
    color = NULLCOLOR;
    rank = 0;
}

int Card::getRank() const {
    return rank;
}

void Card::setRank(int rank) {
    Card::rank = rank;
}

cardFile Card::getFile() const {
    return file;
}

void Card::setFile(int f) {
    if (f == 1){
        file = CLUBS;
    }
    else if (f == 2)
        file = DIAMONDS;
    else if (f == 3)
        file = HEARTS;
    else if (f==4)
        file = SPADES;
    else
        file = SPADES;

}


void Card::setFile(cardFile f) {
    this->file = f;
}

bool Card::isRevealed() const {
    return revealed;
}

void Card::setRevealed(bool revealed) {
    Card::revealed = revealed;
}



string Card::toString(){
    string str = "";
    str += rankToString(getRank()) + " of " + fileToString(getFile());
    return str;
}


bool operator == (Card& lhs, Card& rhs){
    if ((lhs.rank == rhs.rank) && (lhs.file == rhs.file) && (lhs.revealed == rhs.revealed))
        return true;
    return false;
}

ostream& operator << (ostream& outs, Card& card){
    outs << card.toString();
    return outs;
}


cardColor Card::fileToColor(cardFile f){
    if (file == CLUBS || file == SPADES)
        return BLACK;
    if (file == HEARTS || file == DIAMONDS)
        return RED;
    return NULLCOLOR;
}


cardColor Card::getColor() const {
    return color;
}

void Card::setColor(cardColor c) {
    Card::color = c;
}


