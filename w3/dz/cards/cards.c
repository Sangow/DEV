#include <stdio.h>

typedef enum {
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
} Rank;

typedef enum {
    clubs,
    diamonds,
    hearts,
    spades
} Suit;

typedef enum {
    yup,
    nope
} Trump;

typedef struct {
    Rank rank;
    Suit suit;
    Trump trump;
} Card;

void printCard(Card *card) {
    switch (card->suit) {
        case 0: 
            printf("%d of clubs\n", card->rank);
            break;
        case 1:
            printf("%d of diamonds\n", card->rank);
            break;
        case 2:
            printf("%d of hearts\n", card->rank);
            break;
        case 3:
            printf("%d of spades\n", card->rank);
            break;
    }
}

int isBigger(Card *c1, Card *c2) {
    return c1->rank > c2->rank;
}

void main() {
    Card card1 = {ace, clubs, nope};
    Card card2 = {five, diamonds, yup};

    printCard(&card1);
    if ( isBigger(&card1, &card2) ) {
        printf("card1 isBigger than card2\n");
    } else {
        printf("card2 isBigger than card1\n");
    }
}