//
// Created by Maximiliano Perez and
//

#include "card.h"

using namespace std;

//creates ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

//creates card given rank and suit
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

//returns card in string form
string Card::toString() const {
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    string card = rank + suit;
    return card;
}

//returns bool based on suit comparison
bool Card::sameSuitAs(const Card& c) const {
    if (c.mySuit == mySuit) return true;
    return false;
}

int Card::getRank() const{
   return myRank;
}

string Card::suitString(Suit s) const {
    string suit;
    if (mySuit == spades) suit = "s";
    if (mySuit == hearts) suit = "h";
    if (mySuit == diamonds) suit = "d";
    if (mySuit == clubs) suit = "c";
    return suit;
}

string Card::rankString(int r) const {
    string rank;
    switch (r) {
        case 1:
            rank = "A";
            return rank;
        case 11:
            rank = "J";
            return rank;
        case 12:
            rank = "Q";
            return rank;
        case 13:
            rank = "K";
            return rank;
        default:
            rank = to_string(r);
            return rank;
    }
}

bool Card::operator ==(const Card &rhs) const {
    if (myRank == rhs.myRank) {
        if (mySuit == rhs.mySuit) return true;
    }
    return false;
}

bool Card::operator != (const Card &rhs) const {
    if (myRank != rhs.myRank){
        if (mySuit != rhs.mySuit) return true;
    }
    return false;
}

ostream& operator<<(ostream& out, const Card& c){
    out << c.toString() << endl;
    return out;
}