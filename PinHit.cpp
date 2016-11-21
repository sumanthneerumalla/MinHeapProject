//File:    PinHit.cpp
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file contains the implementation of the PinHit class

#include "PinHit.h"
//TODO: comment this file

//default constructor for the PinHit class
PinHit::PinHit() {
  m_pin = -1;
  m_hits = 0;
}

//alternate constructor for the PinHit class
//Pre: takes in the value of the key, and its frequency
//Post: Its a constructor so it returns a pointer to this object
PinHit::PinHit(int key, int value) {
  m_pin = key;
  m_hits = value;
}

//SetKey: Sets the value of the pin
//Pre: Takes in the value of the pin
//Post: void
void PinHit::SetKey(int pin) {
  m_pin = pin;
}

//GetKey: returns the value of the key of this PinHit object
//Pre: takes in no arguments
//Post: returns an int of the value of the pin
int PinHit::GetKey() const {
  return m_pin;
}

//GetValue: returns the value of the key of this PinHit object
//Pre: takes in no arguments
//Post: returns an int of the value of the number of pinhits of this pin
int PinHit::GetValue() const {
  return m_hits;
}

//IncrementHits: Increments the number of hits of this PinHit
//Pre: takes in no arguments
//Post: void
void PinHit::IncrementHits() {
  m_hits++;
}

//CompareTo: compares this object to the one passed in
//Pre: address of the other PinHit object
//Post: returns 0,-1,or 1 based on the value of PinHits being compared
int PinHit::CompareTo(const PinHit &other) const {
  if (m_hits > other.m_hits) {
    return 1;
  }
  else if (m_hits == other.m_hits) {
    return 0;
  }
  else {
    return -1;
  }
}

//overloaded comparison operator
//Pre: Takes in the address of the other PinHit class
//Post: returns true or false based on the m_pin values
bool PinHit::operator==(const PinHit &other) {
  if (m_pin == other.m_pin) {
    return true;
  }
  else {
    return false;
  }
}

//overloaded comparison operator
//Pre: Takes in the address of the other PinHit class
//Post: returns true or false based on the m_pin values
bool PinHit::operator>(const PinHit &other) {
  if (m_pin > other.m_pin) {
    return true;
  }
  else {
    return false;
  }
}

//overloaded comparison operator
//Pre: Takes in the address of the other PinHit class
//Post: returns true or false based on the m_pin values
bool PinHit::operator<(const PinHit &other) {
  if (m_pin < other.m_pin) {
    return true;
  }
  else {
    return false;
  }
}