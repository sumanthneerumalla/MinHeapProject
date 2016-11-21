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
  PinHit();
  PinHit(int key, int value);
  void SetKey(int pin);
  int GetKey() const;
  int GetValue() const;
  void IncrementHits();
  int CompareTo(const PinHit &other) const;
  bool operator==(const PinHit &other);
  bool operator>(const PinHit &other);
  bool operator<(const PinHit &other);

 private:

  int m_pin, m_hits;
};

#endif /* PinHit_H_ */