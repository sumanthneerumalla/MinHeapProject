//
// Created by Admin on 11/18/2016.
//

#ifndef PROJ4_MAXHEAP_H
#define PROJ4_MAXHEAP_H
#include "Heap.h"

template<class T, int m_size>
class MaxHeap : public Heap<T,m_size>{
 public:
  void PercolateUp(int index);
  void PercolateDown(int index);
  MaxHeap();
};

#include "MaxHeap.cpp"
#endif //PROJ4_MAXHEAP_H
