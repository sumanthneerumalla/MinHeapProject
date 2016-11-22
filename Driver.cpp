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

//forward declare so I can define it below main
void printGreeting();

std::vector<PinHit> ReadPins(char *fileName, int *totalHits);

template<class T, int m_size>
Heap<T, m_size> *BuildHeap(std::vector<T> PinHits, int slots);

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size> *heap, std::vector<T> PinHits, int totalHits);

int main(int argc, char *argv[]) {

  printGreeting();
  std::string name = argv[1];
  heapType = argv[2];
  int myNum = 0;
  std::vector<PinHit> pinHitVector = ReadPins(&name[0], &myNum);

//  std::cout << "number of hits is: " << myNum << std::endl;

  //use the Build Heap function to build a heap using the vector
  const int heapSize = pinHitVector.size() ;
  Heap<PinHit, 10000>* myHeap = BuildHeap<PinHit, 10000>(pinHitVector, heapSize);
  int temp = myHeap->getSize();
//  for (int i = 0; i <temp ; ++i) {
//    if (!myHeap->isEmpty()) {
//      PinHit nextPin = myHeap->Remove();
//      std::cout<< "Pin id: "<< nextPin.GetKey()<< " with "<< nextPin.GetValue() << " hits"<< std::endl;
//    }
//    else{
//      std::cout<< "stack is empty"<<std::endl;
//    }
//  }

  int numHacks = Hack<PinHit,10000>(myHeap,pinHitVector,myNum);
  std::cout<< "Number of pins hacked: "<< numHacks << std::endl;
  delete myHeap;
  return EXIT_SUCCESS;
}

// prints your name and section
void printGreeting() {
  std::cout << "Sumanth Neerumalla, Section 05" << std::endl;
}

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
  Heap<T, m_size> *myHeap ;

  if (heapType == "--min") {
    myHeap = new MinHeap<T, m_size>();
  }
  else if (heapType == "--max") {
    myHeap = new MaxHeap<T, m_size>();
  }
  else {
    myHeap = new Heap<T, m_size>();
  }

  for (int i = 0; i < slots; ++i) {
    int numHits = PinHits[i].GetValue();
    //insert the PinHit object only if it has hits
    if(numHits!=0) {
      myHeap->Insert(PinHits[i]);
    }
  }
  return myHeap;
}

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size> *heap, std::vector<T> PinHits, int totalHits) {

  int UPPER_BOUND = totalHits; // used for failsafes

  /*
  * His fictional bank with fictional cards and
  * "normal pins" will allow you to incorrectly attempt
  * to access his card 3 times per hour. You have from
  * the start of the assignment to the end to hack as
  * many accounts as possible (14 days * 24 hr/day * 3
  * attempts/hr = 1008 attempts per card)
  */
  int MAX_ATTEMPTS = 1008;

  int hackAttemptsLeft = MAX_ATTEMPTS;
  int successfulHacks = 0;

  srand(time(NULL)); // seeds our random generator with the current time
  int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits
  //randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
  int curHits = 0; // our variable for crawling
  int randomIndex = -1; // the index where our new random pinhit lives
  int newHits = 0; // number of hits in new "random" pin
  int failSafe = 0; // always good to have one of these in what could be an infinite loop

  /*
  * Linearly searches through PinHits until
  * we've accrued enough hits to reach our random hits
  * which will then determine the next pin to try to hack.
  * We use newHits to make sure we don't pick a random pin
  * that's not in our heap.
  */
  PinHit curPinHit;
  while (newHits == 0 && failSafe < UPPER_BOUND) {

    for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
      curHits += PinHits[i].GetValue();
      randomIndex = i;
    }
    // should have found the random pin by now
    curPinHit = PinHits[randomIndex];
    newHits = curPinHit.GetValue(); // make sure it's actually in our heap
    std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
    failSafe++;
  }

  // let's make a copy of the heap so we don't modify the original.
  Heap<T, m_size> *heapCopy;

  if (heapType == "--min") {
    heapCopy = new MinHeap<T, m_size>(*heap);
  }
  else if (heapType == "--max") {
    heapCopy = new MaxHeap<T, m_size>(*heap);
  }
  else {
    heapCopy = new Heap<T, m_size>(*heap);
  }

  failSafe = 0;

  PinHit defaultPin;

  // exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
  int MAX_NUM_HACKS = 10000;

  while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS) {

    // grabs our root
    PinHit topOfHeap = heapCopy->Remove();
    if (topOfHeap == defaultPin)
      break;

//    std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

    if (hackAttemptsLeft == 1)
      std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

    hackAttemptsLeft--;

    // account was hacked!
    if (topOfHeap == curPinHit) {
      std::cout << "We got them!" << std::endl;
      successfulHacks++;

      // reset our heap
      if (heapType == "--min") {
        heapCopy = new MinHeap<T, m_size>(*heap);
      }
      else if (heapType == "--max") {
        heapCopy = new MaxHeap<T, m_size>(*heap);
      }
      else {
        heapCopy = new Heap<T, m_size>(*heap);
      }

      // reset
      hackAttemptsLeft = MAX_ATTEMPTS;
      randomNumHits = rand() % totalHits;
      curHits = 0;
      randomIndex = -1;
      newHits = 0;
      failSafe = 0;
      while (newHits == 0 && failSafe < UPPER_BOUND) {

        for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
          curHits += PinHits[i].GetValue();
          randomIndex = i;
        }
        // should have found the random pin by now
        curPinHit = PinHits[randomIndex];
        newHits = curPinHit.GetValue(); // make sure it's actually in our heap
        std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
        failSafe++;
      }

      std::cout << "Valid Random Pin: " << curPinHit.GetKey() << " found!" << std::endl;
    }
  }

  return successfulHacks;

}
