#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"
#include "PinHit.h"
#include <stdio.h>

//default constructor
template<class T, int m_size>
Heap<T, m_size>::Heap() {
  maxSize = m_size;

  m_array = new PinHit[m_size + 1];
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
  for (int i = 1; i < currentSize + 1; i++) {
    m_array[i] = origHeap.m_array[i];
  }
}

//The contains method returns true if the needle is found in the Heap.
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

//The contains method returns an object pointer of type T if the needle is in the Heap. This function may take up to O(n). (Hint: this uses PinHits operator==)
template<class T, int m_size>
const T *Heap<T, m_size>::Find(const T &needle) const {

  for (int i = 1; i < currentSize +1; i++) {//size is suppose to be the size of heap
    if (m_array[i] == needle) {
      return &m_array[i];
    }
  }
}

// /Removes and returns a min/max value T (by reference) from the heap. In the process of removal, the heap is updated to maintain heap order.
//This function should run in O(log n).
template<class T, int m_size>
T &Heap<T, m_size>::Remove() {

  //store the root in the 0 location instead of using a static variable
  m_array[0] = m_array[1];
  int mySize = m_size;

	    if( isEmpty() )
        {
          PinHit temp = m_array[0];
          temp.SetKey(-999);
          return temp;
        }

  m_array[1] = m_array[mySize--];
  currentSize--;
  PercolateDown(1);
  return m_array[0];

}

//Given a T, insert will insert the new object into the heap. If needed, the object will percolate up. This function should run in O(n).
template<class T, int m_size>
void Heap<T, m_size>::Insert(T &insertable) {

  int mySize = currentSize;
  std::cout << "Size of array is "<< mySize<< std::endl;

  if (mySize == m_size ) {
    std::cout << "Heap has been filled" << std::endl;
  }

  //increment mySize before inserting so we use the 0 location as a storage location
  int indexLocation = ++mySize;
  m_array[indexLocation] = insertable;

  // Percolate up
  int hole = ++currentSize;
  for( m_array[ 0 ] = insertable; insertable.CompareTo( m_array[ hole / 2 ] ) < 0; hole /= 2 )
  { m_array[ hole ] = m_array[ hole / 2 ]; }

  // now put our new value into the right place
  m_array[ hole ] = insertable;

  //use the percolate function instead of doing it inside of this function
//  PercolateUp(indexLocation);
  currentSize++;

}

//This method is used internally on insert. This function should run in O(log n)
template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {
  int myTemp;
  T tmp = m_array[index];

  for (; index / 2 >= maxSize; index = myTemp) {

    myTemp = index / 2;
    if (myTemp != maxSize && m_array[myTemp + 1] > m_array[myTemp])
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

  for (; index * 2 < maxSize; index = myTemp) {
    myTemp = index * 2;
    if (myTemp != maxSize && m_array[myTemp + 1] < m_array[myTemp])
      myTemp++;
    if (m_array[myTemp] < tmp) {
      m_array[index] = m_array[myTemp];1;
    }

    else {
      break;
    }
  }
  m_array[index] = tmp;

}

template<class T, int m_size>
Heap<T,m_size>::~Heap(){
  delete [] m_array;
};

template<class T, int m_size>
bool Heap<T, m_size>::isEmpty() {
  if (currentSize ==0 ){
    return true;
  }
  return false;
}

template<class T, int m_size>
int Heap<T, m_size>::getSize() {
  return currentSize;
};
#endif