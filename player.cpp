//
// Created by Yussef on 4/11/2019.
//

#include <istream>
#include <time.h>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"



int Player::getHandSize() const {
return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

void Player::addCard(Card c) {
    myHand.push_back(c) ;
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

}



Card Player::chooseCardFromHand() const {
    srand(time(NULL));
    int i ;
    i= rand()%myHand.size();
    return(myHand[i]);
}

bool Player::cardInHand(Card c) const {
    for(int i=0; i<getHandSize(); i++){
        if(myHand[i].getRank() == c.getRank())
            return true;
    }

    return false;
}

Card Player::removeCardFromHand(Card c) {
    Card temp;
    int temp2;
    int i=0;
    int j;

    for(i=0;i<getHandSize();i++){
        if(c.getRank()== myHand[i].getRank() ){
            temp = myHand[i];
            temp2 =i;
            for(j=i+1; j<getHandSize();j++){
                myHand[temp2]=myHand[j];
                temp2++;
            }
            myHand.pop_back();
            return(temp);
        }
    }

}

string Player::showHand() const {
    string hands;
    for(int i=0; i<getHandSize();i++){
        if(i!=getHandSize()-1) {


            hands += myHand[i].toString() + ",";
        }
        else{
            hands += myHand[i].toString();
            return hands;
        }
    }
}

string Player::showBooks() const {
    string books;
    for(int i=0; i<getBookSize();i++){
        if(i!=getBookSize()-1) {
            books += myBook[i].toString() + ",";
        }
        else{
            books = myBook[i].toString();
            return books;
        }
    }
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size(); i++) {
        for (int j = i + 1; j < myHand.size(); j++){
            if (myHand[i] == myHand[j]){
                c1 = myHand[i];
                c2 = myHand[j];
                myHand.erase(myHand.begin() + i);
                myHand.erase(myHand.begin() + j-1);
                return true;
            }
        }
    }
    return false;
}
