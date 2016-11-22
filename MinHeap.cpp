#ifndef PROJ4_MINHEAP_CPP
#define PROJ4_MINHEAP_CPP

//
// Created by Admin on 11/18/2016.
//

#include "MinHeap.h"

template<class T, int m_size>
MinHeap<T, m_size>::MinHeap() {
  this->maxSize = m_size;

  this->m_array = new T[m_size + 1];
  this->currentSize = 0;
}

//Copy Constructor
template<class T, int m_size>
MinHeap<T, m_size>::MinHeap(const Heap<T, m_size> &origHeap) {

  //copy over other Heaps static data
  this->currentSize = origHeap.getSize();
  this->maxSize = origHeap.getMaxSize();

  //create a new array of the same max and copy over data
  this->m_array = new T[this->maxSize];
  for (int i = 1; i < this->currentSize + 1; i++) {
    this->m_array[i] = origHeap.m_array[i];
  }
}

template<class T, int m_size>
void MinHeap<T, m_size>::PercolateUp(int index) {
  for (this->m_array[0] = this->m_array[0]; this->m_array[0].CompareTo(this->m_array[index / 2]) < 0; index /= 2) {
    this->m_array[index] = this->m_array[0];
  }
}

template<class T, int m_size>
void MinHeap<T, m_size>::PercolateDown(int index) {
  int child;
  T tmp = this->m_array[index];

  for (; index * 2 <= this->currentSize; index = child) {
    child = index * 2;
    if (child != this->currentSize && this->m_array[child + 1].CompareTo(this->m_array[child]) < 0) {
      child++;
    }
    if (this->m_array[child].CompareTo(tmp) > 0) { this->m_array[index] = this->m_array[child]; }
    else { break; }
  }
  this->m_array[index] = tmp;
}

template<class T, int m_size>
MinHeap<T,m_size>::~MinHeap(){
  delete [] this->m_array;
};

#endif