//File:    Heap.cpp
// Project: CMSC 202 Project 4, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    11/20/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the implementation of the parent Heap class

#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"
#include "PinHit.h"
#include <stdio.h>

//default constructor
//Pre:None
//Post:Pointer to this object, since its a constructor
template<class T, int m_size>
Heap<T, m_size>::Heap() {
  maxSize = m_size;

  m_array = new T[m_size + 1];
  currentSize = 0;
}

//Copy Constructor
//Pre: Takes in the heap to be copied
//Post:Pointer to this object, since its a constructor
template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size> &origHeap) {

  //copy over other Heaps static data
  currentSize = origHeap.currentSize;
  maxSize = origHeap.maxSize;

  //create a new array of the same max and copy over data
  m_array = new T[maxSize];
  for (int i = 1; i < currentSize + 1; i++) {
    m_array[i] = origHeap.m_array[i];
  }
}

//The contains method returns true if the needle is found in the Heap.
//Pre: Takes in the item that being searched for
//Post:Returns true if the heap contains the item searched for, false otherwise
template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T &needle) const {
  for (int i = 1; i < currentSize + 1; i++) {//size is suppose to be the size of heap
    if (m_array[i] == needle) {
      return true;
    }
    else {
      return false;
    }
  }
}

//The contains method returns an object pointer of type T if the needle is in the Heap.
//Pre: The object that you are searching
//Post:Returns a const pointer to the item that was being searched for
template<class T, int m_size>
const T *Heap<T, m_size>::Find(const T &needle) const {

  for (int i = 1; i < currentSize + 1; i++) {//size is suppose to be the size of heap
    if (m_array[i] == needle) {
      return &m_array[i];
    }
  }
}

//Removes and returns a min/max value T (by reference) from the heap.
//Pre:None
//Post:Returns the item that was at the top of the heap
template<class T, int m_size>
T &Heap<T, m_size>::Remove() {
  //store the root in the 0 location instead of using a static variable
  m_array[0] = m_array[1];

  if (isEmpty()) {
    T *temp = &m_array[0];
    temp->SetKey(-999);
    return *temp;
  }

  m_array[1] = m_array[currentSize ];
//  m_array[currentSize-1] = T(m_array[currentSize-1].GetValue(), 0);
  currentSize--;
  PercolateDown(1);
  return m_array[0];
}

//Given a T, insert will insert the new object into the heap. If needed, the object will percolate up.
//Pre:Takes in the address of the T object to insert
//Post:None
template<class T, int m_size>
void Heap<T, m_size>::Insert(T &insertable) {

  if (currentSize== m_size) {
    std::cout << "Heap has been filled" << std::endl;
  }
  int hole = currentSize++;
  m_array[0] = insertable;
  PercolateUp(currentSize);


  // now put our new value into the right place
  m_array[hole] = insertable;

}

//This method is used internally on insert.
//The heap version of this is virtual so it is empty
//Pre:Takes in an int of the index to start percolation at
//Post:None
template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {
  for (this->m_array[0] = this->m_array[0]; this->m_array[0].CompareTo(this->m_array[index / 2]) > 0; index /= 2) {
    this->m_array[index] = this->m_array[0];
  }
}

//This method is used internally on insert.
//Pre:Takes in an int of the index to start percolation at
//Post:None
template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) {
  int child;
  T tmp = this->m_array[index];

  for (; index * 2 <= this->currentSize; index = child) {
    child = index * 2;
    if (child != this->currentSize && this->m_array[child + 1].CompareTo(this->m_array[child]) > 0) {
      child++;
    }
    if (this->m_array[child].CompareTo(tmp) > 0) { this->m_array[index] = this->m_array[child]; }
    else { break; }
  }
  this->m_array[index] = tmp;

}

//Pre:None
//Post:Deletes the dynamically allocated memory
template<class T, int m_size>
Heap<T, m_size>::~Heap() {
  delete[] m_array;
};

//Pre: None
//Post:Returns true or false
template<class T, int m_size>
bool Heap<T, m_size>::isEmpty() {
  if (currentSize == 0) {
    return true;
  }
  return false;
}

//Pre:None
//Post:Returns the size of the heap
template<class T, int m_size>
int Heap<T, m_size>::getSize() const {
  return currentSize;
};

//Pre:None
//Post: Returns an int of the max size of the heap
template<class T, int m_size>
int Heap<T, m_size>::getMaxSize() const {
  return currentSize;
};
#endif