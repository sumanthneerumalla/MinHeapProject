//
// Created by Admin on 11/20/2016.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#include "PinHit.h"
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

// global variable for type of heap
std::string heapType = "--max";


// implement these two functions
std::vector<PinHit> ReadPins(char *fileName, int *totalHits) {
  std::ifstream inputFile;
  std::string line;
  inputFile.open(fileName, std::ios::in);

  if (inputFile.fail()) {
    std::cout << "The file was not successfully opened." << std::endl;
    exit(1);
  }

  //create a vector of size 10000 PinHits with the range of keys and values set to 0
  std::vector<PinHit> pinHitVector;
  for (int i = 0; i < 10000; ++i) {
    pinHitVector.push_back(PinHit(i, 0));
  }

  //Use a while loop to iterate through file and update each PinHit value
  int nextPin;
  int count = 0;
  while (std::getline(inputFile, line)) {
    nextPin = atoi(&line[0]);
    pinHitVector[nextPin].IncrementHits();
    count++;
  }

  //update the total number of PinHits in this file
  *totalHits = count;
  return pinHitVector;
}

template<class T, int m_size>
Heap<T, m_size> *BuildHeap(std::vector<T> PinHits, int slots) {

}


int main(int argc, char *argv[]) {

  std::string name = argv[1];

  int myNum = 0;
  std::vector<PinHit> pinHitVector = ReadPins(&name[0], &myNum);

  std::cout<< "File: "<< name<< "contains: "<< myNum<< " lines."<< std::endl;

  Heap<T, m_size> *myHeap;

  if (heapType == "--min") {
    myHeap = new MinHeap<T, m_size>(*heap);
  }
  else if (heapType == "--max") {
    myHeap = new MaxHeap<T, m_size>(*heap);
  }
  else {
    myHeap = new Heap<T, m_size>(*heap);
  }

  for (int i = 0; i < pinHitVector.size(); ++i) {
    myHeap->Insert(pinHitVector.pop_back());

  }

  return EXIT_SUCCESS;
}

