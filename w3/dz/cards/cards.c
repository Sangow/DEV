typedef enum {
    ace,
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
    king
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