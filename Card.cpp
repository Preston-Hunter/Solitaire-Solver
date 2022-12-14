//
// Created by Preston Hunter on 10/5/2022.
//

#include "Card.h"
#include "string"
#include "iostream"
using std::ostream;
using std::string;
using std::cout;

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
    this->revealed = toCopy.revealed;
}

Card::Card(){
    file = NULLCARD;
    color = NULLCOLOR;
    rank = 0;
    revealed = true;
}

string fileToSimpleString(cardFile f){
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

string fileToString(cardFile f){
    string file = "";
    switch (f) {
        case (SPADES):
            file = char(6);
            break;
        case (HEARTS):
            file = char(3);
            break;
        case (DIAMONDS):
            file = char(4);
            break;
        case (CLUBS):
            file = char(5);
            break;
        default:
            file = "?";

    }
    return file;
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

string rankToSimpleString(int r){
    if (r > 0 && r < 11)
        return std::to_string(r);
    else if (r == 13)
        return "K";
    else if (r == 12)
        return "Q";
    else if (r == 11)
        return "J";
    else
        return "0";
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
    setColor(fileToColor(file));

}


void Card::setFile(cardFile f) {
    this->file = f;
    setColor(fileToColor(file));
}

bool Card::isRevealed() const {
    return revealed;
}

void Card::setRevealed(bool revealed) {
    Card::revealed = revealed;
}



string Card::toString() const{
    string str = "";
    if (!isRevealed())
        return "??";

    string file = fileToString(this->file);

    str += rankToSimpleString(getRank()) + file;
    return str;
}

string Card::toStringShowAll() const{
    string str = "";

    string file = fileToString(this->file);

    str += rankToSimpleString(getRank()) + file;
    return str;
}

string Card::toStringBasic() const{
    string str = "";
    str += rankToString(getRank()) + " of " + fileToSimpleString(getFile());
    return str;
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

bool operator == (const Card& lhs, const Card& rhs){
    if ((lhs.getRank() == rhs.getRank()) && (lhs.getFile() == rhs.getFile()) && (lhs.isRevealed() == rhs.isRevealed()))
        return true;
    return false;
}

bool operator!=(const Card &lhs, const Card &rhs) {
    if ((lhs.getRank() == rhs.getRank()) && (lhs.getFile() == rhs.getFile()) && (lhs.isRevealed() == rhs.isRevealed()))
        return false;
    return true;
}

ostream& operator << (ostream& outs,const Card& card){
    outs << card.toString();
    return outs;
}




