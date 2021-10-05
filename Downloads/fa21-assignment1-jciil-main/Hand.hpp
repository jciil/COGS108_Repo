//
//  Hand.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <iostream>
#include "Card.hpp"

namespace ECE17 {

  class Hand {
  public:
      Hand();
    
    //STUDENT: implement this class from assigment...
      
    //this will show a hand on the console...
    friend std::ostream& operator<<(std::ostream &anOutput,const Hand &aHand);

  };

}

#endif /* Hand_hpp */
