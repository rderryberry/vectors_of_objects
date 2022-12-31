//
//  cards.h
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#ifndef cards_h
#define cards_h

#include <vector>
#include <stdio.h>

// Suit and rank

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank {
    TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};

// Card struct

struct Card {
    // instance variables
    Suit suit;
    Rank rank;
    
    // constructors
    Card ();
    Card (Suit s, Rank r);
    
    // operators
    bool operator==(const Card &other) const;
    bool operator!=(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator<(const Card &other) const;
    bool operator>=(const Card &other) const;
    bool operator<=(const Card &other) const;
    
    // methods
    std::string suit_str () const;
    std::string rank_str () const;
    void print () const;
};

// Deck struct

struct Deck {
    // instance variables
    std::vector<Card> cards;
    
    // constructors
    Deck();
    Deck(int size);
    
    // methods
    void print () const;
    int find (const Card &card) const;
    int findBisect (const Card &card) const;
    
    Deck subdeck (int lo, int hi) const;
    
    void shuffle (const uint seed = 42);
    std::vector<Deck> deal (const int n_hands, const int hand_size) const;
};


#endif /* cards_h */
