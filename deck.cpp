//
// created by Maximiliano Perez
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
        for (int j = 1; j < 14; j++){
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

        swap(myCards[p1], myCards[p2]);
    }
}

Card Deck::dealCard(){
    if (myIndex < SIZE){
        Card c = myCards[myIndex];
        myIndex++;
        return c;
    }

    Card blank(0, Card::hearts);
    return blank;
}

int Deck::size() const {
    return (SIZE - myIndex);
}

void Deck::showdeck(){
    for (int i=0; i<SIZE; i++){
        cout << myCards[i].toString() << " ";
    }
    cout << endl;
}
