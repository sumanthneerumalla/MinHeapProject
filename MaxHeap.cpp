#ifndef PROJ4_MAXHEAP_CPP
#define PROJ4_MAXHEAP_CPP
//
// Created by Admin on 11/18/2016.
//

#include "MaxHeap.h"
//template<class T, int m_size>
//void MaxHeap<T, m_size>::PercolateUp(int index) {
//  //no need to implement
//}

template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateDown(int index) {
  int child;
  T tmp = this->m_array[index];

  for (; index * 2 <= this->currentSize; index = child) {
    child = index * 2;
    if (child != this->currentSize && this->m_array[child + 1] < this->m_array[child])
      child++;
    if (this->m_array[child] < tmp) { this->m_array[index] = this->m_array[child]; }
    else { break; }
  }
  this->m_array[index] = tmp;
}
#endif