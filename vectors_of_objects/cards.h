//
//  cards.h
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#ifndef cards_h
#define cards_h

#include <stdio.h>

struct Card {
    // instance variables
    int suit;
    int rank;
    
    // constructors
    Card ();
    Card (int s, int r);
    
    // operators
    bool operator==(const Card &other) const;
    bool operator!=(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator<(const Card &other) const;
    bool operator>=(const Card &other) const;
    bool operator<=(const Card &other) const;
    
    // methods
    void print () const;
};

#endif /* cards_h */
