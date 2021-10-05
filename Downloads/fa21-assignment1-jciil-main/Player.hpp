//
//  Player.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string> 
#include "Hand.hpp"

namespace ECE17 {

  class Player {
  public:
    Player();
    //STUDENT: implement this class from assigment...
    
  protected:
    std::string name;
    Hand        hand;    
  };

}

#endif /* Player_hpp */
