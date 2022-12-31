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

Deck::Deck(int size)
{
    std::vector<Card> temp (size);
    cards = temp;
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

// findBisect only works on a sorted deck
int Deck::findBisect(const Card &card) const
{
    int lo {0};
    int hi {int(cards.size()) - 1};
    while (lo <= hi)
    {
        int mid {lo + (hi - lo) / 2};
        if (cards[mid] == card) return mid;
        if (cards[mid] < card)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}

Deck Deck::subdeck(int lo, int hi) const
{
    Deck sub (hi - lo + 1);
    for (int i = 0; i < sub.cards.size(); i++)
    {
        sub.cards[i] = cards[lo + i];
    }
    return sub;
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

std::vector<Deck> Deck::deal
 (
  const int n_hands, const int hand_size
  ) const {
      if (n_hands * hand_size > cards.size())
      {
          std::cout << "Deck size exception: not enough cards in deck.\n";
          std::cout << "\t\tn_hands = " << n_hands << '\n';
          std::cout << "\t\thand_size = " << hand_size << '\n';
          std::cout << "\t\tdeck_size = " << cards.size() << "\n\n";
          std::cout << "Returning original deck.";
          std::vector<Deck> orig (1, *this);
          return orig;
      }
      std::vector<Deck> dealt_hands (n_hands + 1);
      for (int i = 0; i < n_hands; i++)
      {
          dealt_hands[i] = subdeck(i * hand_size, (i + 1) * hand_size - 1);
      }
      dealt_hands[n_hands]
        = subdeck(
                  n_hands * hand_size,
                  int(cards.size())
                  );
      return dealt_hands;
  }
