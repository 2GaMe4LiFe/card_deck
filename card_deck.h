#ifndef CARD_DECK_H
#define CARD_DECK_H

void init_card_deck(unsigned char *cards, int &top);
int take_card_top(unsigned char *cards, int &top);
bool put_card_top(unsigned char *cards, int &top, int card);
bool insert_card_bottom(unsigned char* cards, int& top, int card);

#endif // CARD_DECK_H

