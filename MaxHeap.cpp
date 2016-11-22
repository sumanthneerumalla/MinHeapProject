#ifndef PROJ4_MAXHEAP_CPP
#define PROJ4_MAXHEAP_CPP
//
// Created by Admin on 11/18/2016.
//

#include "MaxHeap.h"

template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap() {
  this->maxSize = m_size;

  this->m_array = new PinHit[m_size + 1];
  this->currentSize = 0;
}

template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateUp(int index) {
  for( this->m_array[ 0 ] = this->m_array[0]; this->m_array[0].CompareTo( this->m_array[ index / 2 ] ) > 0; index /= 2 )
  { this->m_array[ index ] = this->m_array[0]; }
}

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
#endif