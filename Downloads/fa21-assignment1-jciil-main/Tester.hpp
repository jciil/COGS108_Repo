//
//  Tester.hpp
//  RGAssignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Tester_h
#define Tester_h

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <typeinfo>
#include <string>
#include "Card.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"

const int kDeckSize{52};
const int kSuccess{0};
const int kConstructorError{100};
const int kCopyConstructorError{200};
const int kAssignmentError{300};
const int kContainsError{400};
const int kCountError{500};
const int kShuffleError{600};

namespace ECE17 {

  int testCards(std::ostream &anOutput) {
    Card theCard1; //default ctor, should be ace of clubs
    Card theCard2{Faces::ace, Suits::clubs}; //non-default ctor
    
    if(!(theCard1==theCard2)) {
      std::cout << "card ctor error\n";
      return kConstructorError;
    }
      
    Card theCard3{theCard2}; //copy ctor...

    if(!(theCard2==theCard3)) {
      std::cout << "card copy-ctor error\n";
      return kCopyConstructorError;
    }

    Card theCard4{Faces::ace, Suits::hearts}; //ctor
    theCard3=theCard4;
    
    if(!(theCard3==theCard4)) {
      std::cout << "card assignment error\n";
      return kAssignmentError;
    }

    return kSuccess;
  }

  //----------------------------------------------

  int testHand(std::ostream &anOutput) {
    Hand theHand1;
    Card theCard;
    Deck theDeck1;
    
    const size_t kHandSize{5};
    for(size_t i=0;i<kHandSize;i++) {
      theDeck1.draw(theCard);
      theHand1.addCard(theCard);
    }

    std::stringstream theOut1;
    theOut1 << theHand1;
    std::string theStr1=theOut1.str();

    Hand theHand2(theHand1);
    std::stringstream theOut2;
    theOut2 << theHand2;
    std::string theStr2=theOut2.str();

    if(theStr1!=theStr2) {
      std::cout << "hand copy-ctor error\n";
      return kCopyConstructorError;
    }
          
    Hand theHand3;
    theHand3=theHand1;
    std::stringstream theOut3;
    theOut3 << theHand3;
    std::string theStr3=theOut3.str();

    if(theStr1!=theStr3) {
      std::cout << "hand assignment error\n";
      return kCopyConstructorError;
    }
    
    if(!theHand1.contains(theCard)) {
      std::cout << "hand contains() error\n";
      return kContainsError;
    }

    if(kHandSize!=theHand1.count()) {
      std::cout << "hand count() error\n";
      return kCountError;
    }
    
    return kSuccess;
  }

  //----------------------------------------------

  int testDeck(std::ostream &anOutput) {
    
    Deck theDeck1;
    Card theCard; //drop this...
    theDeck1.draw(theCard);
        
    size_t theSize=theDeck1.count();
    if(1!=kDeckSize-theSize) {
      std::cout << "deck initialization error\n";
      return kCountError;
    }
    
    Deck theDeck2(theDeck1);
    
    std::stringstream theOut1;
    theOut1 << theDeck1;
    std::string theStr1=theOut1.str();

    std::stringstream theOut2;
    theOut2 << theDeck2;
    std::string theStr2=theOut2.str();

    if((theStr1!=theStr2)|| (kDeckSize-theDeck2.count()!=1)) {
      std::cout << "deck copy-ctor error\n";
      return kCopyConstructorError;
    }
    
    theDeck2.shuffle();
    std::stringstream theOut3;
    theOut3 << theDeck2;
    std::string theStr3=theOut3.str();

    if(theStr2==theStr3) {
      std::cout << "deck shuffle error\n";
      return kShuffleError;
    }
    
    Deck theDeck3;
    theDeck3=theDeck1;
    if(theDeck1.count()!=theDeck3.count()) {
      std::cout << "deck assignment error\n";
      return kAssignmentError;
    }

    return kSuccess;
  }

  //----------------------------------------------

  int testPlayer(std::ostream &anOutput) {
    Player thePlayer1("Truong Nguyen");
    Player thePlayer2(thePlayer1);
    
    std::stringstream theOut1;
    theOut1 << thePlayer1;
    std::string theStr1=theOut1.str();

    std::stringstream theOut2;
    theOut2 << thePlayer2;

    if(theStr1!=theOut2.str()) {
      std::cout << "player copy-ctor error\n";
      return kCopyConstructorError;
    }
    
    Player thePlayer3;
    thePlayer3=thePlayer1;

    std::stringstream theOut3;
    theOut3 << thePlayer3;
    if(theStr1!=theOut3.str()) {
      std::cout << "player assignment error\n";
      return kAssignmentError;
    }
    
    return kSuccess;
  }


  //----------------------------------------------

  int testGame(std::ostream &anOutput) {
    return kSuccess;
  }

}
#endif /* Tester_h */
