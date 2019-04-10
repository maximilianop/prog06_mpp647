//
// created by Maximiliano Perez and
//
#include "deck.h"
#include "time.h"

void Deck::swap(Card &c1, Card &c2) {
    Card holder = c1;
    c1 = c2;
    c2 = holder;
}

Deck::Deck(){
    srand(time(NULL));
    myIndex = 0;
    for (int suit = Card::spades; suit <= Card::clubs; suit++){
        for (int j = 0; j < 13; j++){
            Card::Suit s;
            switch(suit){
                case 0:
                    s = Card::spades;
                    break;
                case 1:
                    s = Card::hearts;
                    break;
                case 2:
                    s = Card::diamonds;
                    break;
                case 3:
                    s = Card::clubs;
                    break;
            }
            Card newCard(j, s);
            myCards[myIndex] = newCard;
            myIndex++;
        }
    }
    myIndex = 0;
}

void Deck::shuffle(){
    for (int i = 0; i < size()*size(); i++){
        int p1 = rand()%size();
        int p2 = rand()%size();
        Card temp1;
        Card temp2;

        for (int j = 0; j < p1; j++) temp1 = myCards[j];
        for (int j = 0; j < p2; j++) temp2 = myCards[j];

        swap(temp1, temp2);
    }
}

Card Deck::dealCard(){
    Card c = myCards[myIndex];
    myIndex++;
    return c;
}

int Deck::size() const {
    int size = 0;

    for (int i = myIndex; i < SIZE; i++){
        size++;
    }
    return size;
}