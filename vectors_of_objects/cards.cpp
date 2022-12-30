//
//  cards.cpp
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cards.h"

// Card struct

//constructors
Card::Card()
{
    suit = CLUBS;
    rank = TWO;
}

Card::Card(Suit s, Rank r)
{
    suit = s;
    rank = r;
}

// operators
bool Card::operator==(const Card &other) const
{
    return (suit == other.suit && rank == other.rank);
}

bool Card::operator!=(const Card &other) const
{
    return !(*this == other);
}

bool Card::operator>(const Card &other) const
{
    if (suit == other.suit)
    {
        return rank > other.rank;
    }
    else
    {
        return suit > other.suit;
    }
}

bool Card::operator<(const Card &other) const
{
    if (suit == other.suit)
    {
        return rank < other.rank;
    }
    else
    {
        return suit < other.suit;
    }
}

bool Card::operator>=(const Card &other) const
{
    return !(*this < other);
}

bool Card::operator<=(const Card &other) const
{
    return !(*this > other);
}

// methods
std::string Card::suit_str () const
{
    switch (suit) {
        case CLUBS: return "Clubs";
            break;
        case DIAMONDS: return "Diamonds";
            break;
        case HEARTS: return "Hearts";
            break;
        case SPADES: return "Spades";
            
        default: return "Not a valid suit";
            break;
    }
}

std::string Card::rank_str () const
{
    switch (rank) {
        case TWO: return "Two";
            break;
        case THREE: return "Three";
            break;
        case FOUR: return "Four";
            break;
        case FIVE: return "Five";
            break;
        case SIX: return "Six";
            break;
        case SEVEN: return "Seven";
            break;
        case EIGHT: return "Eight";
            break;
        case NINE: return "Nine";
            break;
        case TEN: return "Ten";
            break;
        case JACK: return "Jack";
            break;
        case QUEEN: return "Queen";
            break;
        case KING: return "King";
            break;
        case ACE: return "Ace";
            break;
            
        default: return "Not a valid rank";
            break;
    }
}

void Card::print () const
{
    Card card = *this;
    std::cout << card.rank_str() << " of " << card.suit_str() << '\n';
}

// Deck struct

// constructors
Deck::Deck()
{
    std::vector<Card> temp (52);
    cards = temp;
    
    int i {0};
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1))
    {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank + 1))
        {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

// methods
void Deck::print () const
{
    for (int i = 0; i < cards.size(); i++) {
        cards[i].print();
    }
}

int Deck::find (const Card &card) const
{
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == card) return i;
    }
    return -1;
}

int randomInt(int hi, int lo) {
    return lo + (rand() % (hi - lo));
}

void Deck::shuffle(const uint seed)
{
    srand(seed);
    for (int i = 0; i < cards.size(); i++)
    {
        int swap_index = randomInt(int(cards.size()), i);
        Card temp = cards[i];
        cards[i] = cards[swap_index];
        cards[swap_index] = temp;
    }
}
