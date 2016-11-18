#include "PinHit.h"
//TODO: comment this file

PinHit::PinHit() {
  m_pin = -1;
  m_hits = 0;
}

PinHit::PinHit(int key, int value) {
  m_pin = key;
  m_hits = value;
}

void PinHit::SetKey(int pin) {
  m_pin = pin;
}

int PinHit::GetKey() const {
  return m_pin;
}

int PinHit::GetValue() const {
  return m_hits;
}

void PinHit::IncrementHits() {
  m_hits++;
}

int PinHit::CompareTo(const PinHit &other) const {
  if (m_hits > other.m_hits) {
    return 1;
  }
  else if (m_hits == other.m_hits) {
    return 0;
  }
  else {
    return -1;
  }
}

bool PinHit::operator==(const PinHit &other) {
  if (m_pin == other.m_pin) {
    return true;
  }
  else {
    return false;
  }
}

