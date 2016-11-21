#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"
#include <stdio.h>

//default constructor
template<class T, int m_size>
Heap<T, m_size>::Heap() {
  maxSize = m_size;

  m_array = new int[m_size];
  currentSize = 0;
}

//Copy Constructor
template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size> &origHeap) {

  //copy over other Heaps static data
  currentSize = origHeap.currentSize;
  maxSize = origHeap.maxSize;

  //create a new array of the same max and copy over data
  m_array = new int[maxSize];
  for (int i = 0; i < currentSize; i++) {
    m_array[i] = origHeap.m_array[i];
  }
}

//The contains method returns true if the needle is found in the Heap.
template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T &needle) const {
  for (int i = 0; i < currentSize; i++) {//size is suppose to be the size of heap
    if (m_array[i] == needle) {
      return true;
    }
    else {
      return false;
    }
  }
}

//The contains method returns an object pointer of type T if the needle is in the Heap. This function may take up to O(n). (Hint: this uses PinHits operator==)
template<class T, int m_size>
const T *Heap<T, m_size>::Find(const T &needle) const {

  for (int i = 0; i < currentSize; i++) {//size is suppose to be the size of heap
    if (m_array[i] == needle) {
      return &m_array[i];
    }
  }
}

// /Removes and returns a min/max value T (by reference) from the heap. In the process of removal, the heap is updated to maintain heap order.
//This function should run in O(log n).
template<class T, int m_size>
T &Heap<T, m_size>::Remove() {

  int mySize = m_size;

//	    if( isempty() )
//            throw UnderflowException();

  m_array[1] = m_array[mySize--];
  PercolateDown(1);

}

//Given a T, insert will insert the new object into the heap. If needed, the object will percolate up. This function should run in O(n).
template<class T, int m_size>
void Heap<T, m_size>::Insert(T &insertable) {

  int mySize = currentSize;

  if (mySize == m_size - 1) {
//    m_array.resize(m_array.size() * 2);
    //throw underflow exception here?
    std::cout << "Heap has been filled" << std::endl;
  }

//  for (; indexLocation >= 1 && insertable < m_array[indexLocation / 2]; indexLocation /= 2)
//  {
//    m_array[indexLocation] = m_array[indexLocation / 2]; }// swap, from child to parent

  int indexLocation = ++mySize;
  m_array[indexLocation] = insertable;

  //use the percolate function instead of doing it inside of this function
  PercolateUp(indexLocation);
  currentSize++;

}

//This method is used internally on insert. This function should run in O(log n)
template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {
  int myTemp;
  T tmp = m_array[index];

  for (; index / 2 >= m_size; index = myTemp) {

    myTemp = index / 2;
    if (myTemp != m_size && m_array[myTemp + 1] > m_array[myTemp])
      myTemp++;

    if (m_array[myTemp] > tmp) {
      m_array[index] = m_array[myTemp];
    }

    else {
      break;
    }
  }
  m_array[index] = tmp;
}

//This method is used internally on insert. This function should run in O(log n)
template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) {
  int myTemp;
  T tmp = m_array[index];

  for (; index * 2 <= m_size; index = myTemp) {
    myTemp = index * 2;
    if (myTemp != m_size && m_array[myTemp + 1] < m_array[myTemp])
      myTemp++;
    if (m_array[myTemp] < tmp) {
      m_array[index] = m_array[myTemp];
    }

    else {
      break;
    }
  }
  m_array[index] = tmp;

}
#endif