#include <iostream>
#include <string>
#include "triple.h"

// Sample Function #1
std::string triple(std::string word) {
  return word + " " + word + " " + word;
}

// Sample Function #2
std::string twice(std::string word) {
  return word + " " + word;
}

// Sample Function #3
std::string once(std::string word) {
  return word;
}