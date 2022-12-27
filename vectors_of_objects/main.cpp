//
//  main.cpp
//  vectors_of_objects
//
//  Created by Richard Derryberry on 12/26/22.
//

#include <iostream>
#include <string>
#include "cards.h"

int main(int argc, const char * argv[]) {
    Card three_of_clubs (0, 3);
    Card four_of_clubs (0, 4);
    Card ace_of_clubs (0, 1);
    Card jack_of_hearts(2, 11);
    
    if (three_of_clubs < four_of_clubs) {
        three_of_clubs.print();
        std::cout << "is less than\n";
        four_of_clubs.print();
        std::cout << std::endl;
    }
    
    if (three_of_clubs < ace_of_clubs) {
        three_of_clubs.print();
        std::cout << "is less than\n";
        ace_of_clubs.print();
        std::cout << std::endl;
    }
    
    if (jack_of_hearts > ace_of_clubs) {
        jack_of_hearts.print();
        std::cout << "is greater than\n";
        ace_of_clubs.print();
        std::cout << std::endl;
    }
    
    return 0;
}
