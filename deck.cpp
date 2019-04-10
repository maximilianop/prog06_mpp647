//
// created by Maximiliano Perez and
//
#include "deck.h"

Deck::Deck(){
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
            }
            Card newCard(j, s);
            myCards[myIndex] = newCard;
        }
    }
}

Deck::