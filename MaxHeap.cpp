//File:    MaxHeap.cpp
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the implementation of the MaxHeap class

#ifndef PROJ4_MAXHEAP_CPP
#define PROJ4_MAXHEAP_CPP

#include "MaxHeap.h"

//default constructor
//Pre:None
//Post:Pointer to this object, since its a constructor
template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap() {
  this->maxSize = m_size;

  this->m_array = new T[m_size + 1];
  this->currentSize = 0;
}

//Copy Constructor
//Pre: Takes in the heap to be copied
//Post:Pointer to this object, since its a constructor
template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap(const Heap<T, m_size> &origHeap) {

  //copy over other Heaps static data
  this->currentSize = origHeap.getSize();
  this->maxSize = origHeap.getMaxSize();

  //create a new array of the same max and copy over data
  this->m_array = new T[this->maxSize];
  for (int i = 1; i < this->currentSize + 1; i++) {
    this->m_array[i] = origHeap.m_array[i];
  }
}

//PercolateUp: Used to percolate a specific location up the array
//Pre:Takes in an int of the index to start percolation at
//Post:None
template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateUp(int index) {
  for( this->m_array[ 0 ] = this->m_array[0]; this->m_array[0].CompareTo( this->m_array[ index / 2 ] ) > 0; index /= 2 )
  { this->m_array[ index ] = this->m_array[0]; }
}

//PercolateDown: Used to percolate a specific location up the array
//Pre:Takes in an int of the index to start percolation at
//Post:None
template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateDown(int index) {
  int child;
  T tmp = this->m_array[index];

  for (; index * 2 <= this->currentSize; index = child) {
    child = index * 2;
    if (child != this->currentSize && this->m_array[child + 1].CompareTo( this->m_array[child]) >0){
      child++;}
    if (this->m_array[child].CompareTo(tmp) >0) { this->m_array[index] = this->m_array[child]; }
    else { break; }
  }
  this->m_array[index] = tmp;
}

//Destructor
//Pre:None
//Post:Deletes the dynamically allocated memory
template<class T, int m_size>
MaxHeap<T,m_size>::~MaxHeap(){
  delete [] this->m_array;
};
#endif