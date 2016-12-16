#include <random>
#include <iostream>

#include "card_deck.h"

using namespace std;

void init_card_deck(unsigned char *cards, int &top) {
    
    random_device rd;
    default_random_engine e1(rd());
    uniform_int_distribution<unsigned char> uniform_dist(1, 20);
    top = 19;

    for (int i = 0; i <= top; i++)
        cards[i] = 0;

    for (int i{}; i <= top; ++i) {
        int next{uniform_dist(e1)};

        int hc = 0;
        while (hc <= top) {
            if (next == cards[hc]) {
                next = {uniform_dist(e1)};
                hc = 0;
            } else
                hc++;
        }
        cards[i] = next;
    }
}

int take_card_top(unsigned char *cards, int &top) {
    if (top != -1) {
        int curr = cards[top];
        cards[top] = 0;
        top--;
        return curr;
    } else
        return 0;
}

bool put_card_top(unsigned char *cards, int &top, int card) {
    if (top < 19 && cards[top] != card && cards[0] != card) {
        top++;
        cards[top] = card;
        return true;
    } else
        return false;
}

bool insert_card_bottom(unsigned char* cards, int& top, int card) {
    if (top < 19 && cards[0] != card && cards[top] != card) {
        for (int i = top; i >= 0; i--)
            cards[i + 1] = cards[i];
        top++;
        cards[0] = card;
        return true;
    } else
        return false;
}