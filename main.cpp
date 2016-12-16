#include <iostream>
#include <string>
#include <array>

#include "card_deck.h"

using namespace std;

enum Action {
NEW_DECK = 49,
TAKE_CARD_TOP,
PUT_CARD_TOP,
INSERT_CARD_BOTTOM,
SHOW_DECK,
QUIT
};

int menu();

int main(int argc, char** argv) {
    bool run = true;
    
    int ret;
    int card = 1;
    int top = 19;
    
    unsigned char *cards = new unsigned char [top+1];
    
    init_card_deck(cards, top);
    
    do {
        ret = menu();
        
        switch (ret) {
            case NEW_DECK:
                init_card_deck(cards, top);
                cout << "Neues Deck wurde angelegt" << endl << endl;
                break;
            
            case TAKE_CARD_TOP:
                card = take_card_top(cards, top);
                cout << card << endl << endl;
                break;
            
            case PUT_CARD_TOP:
                put_card_top(cards, top, card);
                break;
            
            case INSERT_CARD_BOTTOM:
                insert_card_bottom(cards, top, card);
                break;
                
            case SHOW_DECK:
                for (int i = 0; i <= top; i++) {
                    if (cards[i] != 0) 
                        cout << static_cast<int>(cards[i]) << " ";
                }
                cout << endl << endl;
                break;
            
            case QUIT:
                run = false;
                break;
            
            default:
                run = true;
                break;
        }
        if (card == 0)
            run = false;
    } while (run);
    
    cout << "Spiel wurde beendet" << endl << endl;
    delete [] cards;
    cout << "Speicher wurde freigegeben" << endl;
    return 0;
}

int menu() {
    string inp;

    cout << "[1] Kartenspiel neu anlegen" << endl;
    cout << "[2] Eine Karte entnemen" << endl;
    cout << "[3] Karte auf den Stapel zurücklegen" << endl;
    cout << "[4] Karte unten in den Stapel einordnen" << endl;
    cout << "[5] Kartenspiel anzeigen" << endl;
    cout << "[6] Beenden" << endl;
    cout << "Ihre Wahl: ";

    cin >> inp;

    cout << endl;

    if (inp[0] < '1' || inp[0] > '6' || inp[1] != '\0') {
        cerr << "Fehlerhafte Eingabe!" << endl << endl;
        return -1;
    } else
        return static_cast<Action>(inp[0]);
}