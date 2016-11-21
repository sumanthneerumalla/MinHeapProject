//
// Created by Admin on 11/18/2016.
//

#ifndef PROJ4_MINHEAP_H
#define PROJ4_MINHEAP_H
#include "Heap.h"

template<class T, int m_size> class MinHeap : public Heap<T,m_size> {
  void PercolateUp(int index);
  void PercolateDown(int index);
};

#include "MinHeap.cpp"
#endif //PROJ4_MINHEAP_H
