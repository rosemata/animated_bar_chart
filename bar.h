// bar.h
// TO DO:  this file is responsible for initializing the bar name, value and category

#include <iostream>
#include <string>
#include "myrandom.h"  // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
  string name;
  string category;
  int value;

  // Private member variables for a Bar object
  // TO DO:  Define private member variables for this class
  // NOTE: You should not be allocating memory on the heap for this class.
 public:
  // default constructor:
  Bar() {
    name = "";
    category = "";
    value = 0;
    // TO DO:  Write this constructor.
  }

  // a second constructor:
  //
  // Parameter passed in constructor Bar object.
  //
  Bar(string name, int value, string category) {
    // TO DO:  Write this constructor.
    this->name = name;
    this->value = value;
    this->category = category;
  }

  // destructor:
  virtual ~Bar() {
    // TO DO:  Write this destructor or leave empty if not needed.
  }

  // getName:
  string getName() {
    // TO DO:  Write this function.
    return name;
  }

  // getValue:
  int getValue() {
    // TO DO:  Write this function.
    return value;
  }

  // getCategory:
  string getCategory() {
    // TO DO:  Write this function.
    return category;
  }

  // operators
  // TO DO:  Write these operators.  This allows you to compare two Bar
  // objects.  Comparison should be based on the Bar's value.  For example:
  bool operator<(const Bar &other) const { return value < other.value; }

  bool operator<=(const Bar &other) const {
    return value <= other.value;  // TO DO:  update this, it is only here so
                                  // code compiles.
  }

  bool operator>(const Bar &other) const {
    return value > other.value;  // TO DO:  update this, it is only here so code
                                 // compiles.
  }

  bool operator>=(const Bar &other) const {
    return value >= other.value;  // TO DO:  update this, it is only here so
                                  // code compiles.
  }
};
