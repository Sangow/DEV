typedef enum {
    two,
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

typedef struct {
    Rank rank;
    Suit suit;
} Card;
