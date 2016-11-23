//File:    PinHit.h
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file contains the declaration of the PinHit class

#ifndef PINHIT_H_
#define PINHIT_H_

class PinHit {

 public:
  //Default Constructor
  PinHit();

  //Alternate Constructor
  PinHit(int key, int value);

  //Setter function for value of pin
  void SetKey(int pin);

  //Getter function for key of pin
  int GetKey() const;

  //Getter function for Value of pin
  int GetValue() const;

  //Function used to increment keys of pin
  void IncrementHits();

  //Function used to compare pinhits to each other
  int CompareTo(const PinHit &other) const;

  //Overloaded comparison operator
  bool operator==(const PinHit &other);


 private:

  //Member variable of this PinHit class
  int m_pin, m_hits;
};

#endif /* PinHit_H_ */