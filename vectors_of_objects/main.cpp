//
//  main.cpp
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "cards.h"

int main(int argc, const char * argv[]) {
//    std::vector<Card> deck {buildDeck()};
//    for (int i = 0; i < 10; i++) {
//        deck[rand() % 52].print();
//    }
    Deck deck;
    deck.shuffle();
    deck.print();
    
    return 0;
}
