//File:    PinHit.h
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the declaration of the MinHeap class

#ifndef PROJ4_MINHEAP_H
#define PROJ4_MINHEAP_H
#include "Heap.h"

template<class T, int m_size> class MinHeap : public Heap<T,m_size> {
 public:

  //default constructor
  MinHeap();

  //Copy Constructor
  MinHeap(const Heap<T, m_size> &origHeap);

  //function used to percolate a specific location up the array
  void PercolateUp(int index);

  //function used to percolate a specific location up the array
  void PercolateDown(int index);

  //Destructor
  ~MinHeap();
};

#include "MinHeap.cpp"
#endif //PROJ4_MINHEAP_H
