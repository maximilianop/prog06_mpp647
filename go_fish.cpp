//
// Created by Yussef on 4/11/2019.
//

#include <iostream>
#include <fstream>
#include "card.h"
#include "player.h"
#include <istream>
#include <time.h>
#include <cstdlib>
#include "deck.h"


using namespace std;

int main(){
        cout << endl << "--shuffle test--" << endl; // just testing if shuffle works

        Deck a;

        cout << "Original:" << endl;
        a.showdeck();

        a.shuffle();
        cout << "After Shuffle:" << endl;
        a.showdeck();

        a.shuffle();
        cout << "Shuffle again:" << endl;
        a.showdeck();

        cout << "\n "  << endl;



        cout <<"--gametime!--" << endl; // actual game

        Deck b;
        Player max("Max");
        Player yus("Yussef");

        b.shuffle();

        for (int i=0; i<7; i++){  // cards are being dealt
                max.addCard(b.dealCard());
                yus.addCard(b.dealCard());
        }

        cout << "Max's Hand: " << max.showHand() << endl;
        cout << "Yussef's Hand: " << yus.showHand() << endl;

        Card Y1; //card from hand
        Card Y2; //books
        Card M1; //card from hand
        Card M2; // books
        Card B1;
        Card B2;

        while( ((yus.getHandSize()!=0 || max.getHandSize()!=0)) && (b.size() != 0)) { // basically loop game till someone doesnt have any more cards
                int i=0;
                //Yussef's turn**********************

                Y1 = yus.chooseCardFromHand();

                while (i==0) {
                        Y1 = yus.chooseCardFromHand();
                        cout << "Yussef asks: do you have a " << Y1.rankString(Y1.getRank())  <<"?"<< endl;
                        if (max.cardInHand(Y1)) {  // checks if max has the card in his hand
                                cout << "Max: Yes I have a " << Y1.getRank() << endl;
                                while(max.cardInHand(Y1)) { // basically a loop that will check all the ranks opponents has and give them up till none remaining
                                        Y1 = max.removeCardFromHand(Y1);
                                        yus.addCard(Y1);
                                }

                        }
                        else {
                                cout << "Max: Go fish" << endl;
                                if (b.size() != 0) {  // yussef has to get a card from the deck only if deck is not empty
                                        yus.addCard(b.dealCard());
                                }
                                i++;
                        }
                }



                //now Max's turn********************

                i = 0;
                M1 = max.chooseCardFromHand();

                while(i ==0) {
                        M1 = max.chooseCardFromHand();
                        cout<<"Max asks: do you have a " << M1.rankString(M1.getRank()) <<"?"<<endl;
                        if (yus.cardInHand(M1)) { // checks to see if yussef has the card in hand
                                cout << "Yussef: Yes I have a " << M1.getRank() << endl;
                                while(yus.cardInHand(M1)) { // will give up all the cards of that rank till none left
                                        M1 = yus.removeCardFromHand(M1);
                                        max.addCard(M1);
                                }

                        }
                        else {
                                cout << "Yussef: Go fish" << endl;
                                if (b.size() != 0) {
                                        max.addCard(b.dealCard());
                                        // max has to get a card from the deck only if deck is not empty

                                }
                                i++;
                        }
                }

                cout << "Max's Hand: " << max.showHand() << endl;
                cout << "Yussef's Hand: " << yus.showHand() << endl;


                while (max.checkHandForBook(B1, B2)) {
                    max.bookCards(B1, B2);
                }
                while (yus.checkHandForBook(B1, B2)) {
                    yus.bookCards(B1, B2);
                }

                cout << "Max's Books: " << max.showBooks() << endl;
                cout << "Yussef's Hand:" << yus.showBooks() << endl;



        }













}


