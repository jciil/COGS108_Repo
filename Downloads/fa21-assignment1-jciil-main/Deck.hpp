//
//  Deck.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>

namespace ECE17 {

  class Deck {
  public:
      Deck(); //This will be the default constructor
    
    //STUDENT: implement this class and methods as outlined in the readme...
    
    //this method will print the deck to the terminal
    friend std::ostream& operator<<(std::ostream &anOutput,
                                    const Deck &aDeck);

  };

}

#endif /* Deck_hpp */
