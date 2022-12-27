//
//  cards.cpp
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#include <iostream>
#include <vector>
#include <string>
#include "cards.h"

//constructors
Card::Card()
{
    suit = 0;
    rank = 0;
}

Card::Card(int s, int r)
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
        if (rank != 1)
        {
            return rank > other.rank;
        }
        else
        {
            return other.rank != 1;
        }
        
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
        if (other.rank == 1)
        {
            return rank != 1;
        }
        else
        {
            return rank < other.rank;
        }
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
void Card::print () const
{
    std::vector<std::string> suits (4);
    suits[0] = "Clubs";
    suits[1] = "Diamonds";
    suits[2] = "Hearts";
    suits[3] = "Spades";
    
    std::vector<std::string> ranks (14);
    ranks[0] = "";
    ranks[1] = "Ace";
    for (int i = 2; i < 11; i++) {
        ranks[i] = std::to_string(i);
    }
    ranks[11] = "Jack";
    ranks[12] = "Queen";
    ranks[13] = "King";
    
    std::cout << ranks[rank] << " of " << suits[suit] << '\n';
}
