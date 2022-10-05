//
// Created by Preston Hunter on 10/5/2022.
//

#ifndef SOLITAIRE_SOLVER_CARD_H
#define SOLITAIRE_SOLVER_CARD_H
#include "string"
#include "iostream"
using std::ostream;
using std::string;

enum File{CLUBS, DIAMONDS, HEARTS, SPADES};

string fileToString(File f);
string rankToString(int r);


class Card {
private:
    int rank;
    File file;
    bool revealed;

public:
    int getRank() const;

    void setRank(int rank);

    File getFile() const;

    void setFile(int f);

    bool isRevealed() const;

    void setRevealed(bool revealed);
    string toString();


    Card(int rank, int file, bool rev);

    friend bool operator == (Card& lhs, Card& rhs);
    friend ostream& operator << (ostream& outs, Card& card);

};


#endif //SOLITAIRE_SOLVER_CARD_H
