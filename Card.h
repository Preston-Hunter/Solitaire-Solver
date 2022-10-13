//
// Created by Preston Hunter on 10/5/2022.
//

#ifndef SOLITAIRE_SOLVER_CARD_H
#define SOLITAIRE_SOLVER_CARD_H
#include "string"
#include "iostream"
#include "vector"
using std::ostream;
using std::string;
using std::vector;
enum cardFile{CLUBS, DIAMONDS, HEARTS, SPADES, NULLCARD};
enum cardColor{RED, BLACK, NULLCOLOR};

string fileToString(cardFile f);
string rankToString(int r);
string rankToSimpleString(int r);

class Card {
private:
    int rank;
    cardFile file;
    bool revealed;
    cardColor color;
public:
    cardColor getColor() const;

    void setColor(cardColor color);

public:
    Card(int rank, int file, bool rev);
    Card(int rank, cardFile file, bool rev);
    Card(Card const &toCopy);
    Card();



    int getRank() const;
    void setRank(int rank);

    cardFile getFile() const;
    void setFile(int f);
    void setFile(cardFile f);

    bool isRevealed() const;
    void setRevealed(bool revealed);

    cardColor fileToColor(cardFile f);

    string toStringBasic() const;
    string toString() const;
    friend ostream& operator << (ostream& outs, const Card& card);

    friend bool operator == (const Card& lhs, const Card& rhs);
    friend bool operator != (const Card& lhs, const Card& rhs);

};


#endif //SOLITAIRE_SOLVER_CARD_H
