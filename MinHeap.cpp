#ifndef PROJ4_MINHEAP_CPP
#define PROJ4_MINHEAP_CPP

//
// Created by Admin on 11/18/2016.
//

#include "MinHeap.h"

template<class T, int m_size>
MinHeap<T, m_size>::MinHeap() {
  this->maxSize = m_size;

  this->m_array = new PinHit[m_size + 1];
  this->currentSize = 0;
}




#endif