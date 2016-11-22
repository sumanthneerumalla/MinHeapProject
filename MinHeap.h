//
// Created by Admin on 11/18/2016.
//

#ifndef PROJ4_MINHEAP_H
#define PROJ4_MINHEAP_H
#include "Heap.h"

template<class T, int m_size> class MinHeap : public Heap<T,m_size> {
 public:
  MinHeap(const Heap<T, m_size> &origHeap);
  void PercolateUp(int index);
  void PercolateDown(int index);
  MinHeap();
};

#include "MinHeap.cpp"
#endif //PROJ4_MINHEAP_H
