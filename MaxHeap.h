//File:    MaxHeap.h
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the declaration of the Maxheap class

#ifndef PROJ4_MAXHEAP_H
#define PROJ4_MAXHEAP_H
#include "Heap.h"

template<class T, int m_size>
class MaxHeap : public Heap<T, m_size> {
 public:
  //default constructor
  MaxHeap();

  //Copy Constructor
  MaxHeap(const Heap<T, m_size> &origHeap);

  //function used to percolate a specific location up the array
  void PercolateUp(int index);

  //function used to percolate a specific location up the array
  void PercolateDown(int index);

  //Destructor
  ~MaxHeap();
};

#include "MaxHeap.cpp"
#endif //PROJ4_MAXHEAP_H
