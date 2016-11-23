//File:    Heap.h
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the declaration of the parent Heap class

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>

template<class T, int m_size>
class Heap {

 public:

  // required functions by UML
  Heap();
  Heap(const Heap<T, m_size> &origHeap);
  bool Contains(const T &needle) const;
  const T *Find(const T &needle) const;
  T &Remove();
  void Insert(T &insertable);
  virtual void PercolateUp(int index);
  virtual void PercolateDown(int index);

  // student-made functions below
  ~Heap();
  bool isEmpty();
  int getSize() const;
  int getMaxSize() const;

  // UML-required member variables
  T *m_array;
 protected:
  // student-made member variables
  int currentSize;
  int maxSize;
};

#include "Heap.cpp"
#endif /* HEAP_H_ */
