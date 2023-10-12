// sstack.cpp: implementation of simple string stack

#include "sstack.h"
#include <string>

using namespace std;

StringStack::StringStack() {
  top = nullptr;
}

bool StringStack::empty() const {
  return top == nullptr;
}

void StringStack::push(std::string new_item) {
  if (!top) {
    top = new StackNode(new_item);
  } else {
    StackNode *temp = top;
    top = new StackNode(new_item);
    top->setNext(temp);
  }
}

std::string StringStack::pop() {
  std::string string = top->item();
  top = top->next();
  return string;
}

void StringStack::clear() {
  top = nullptr;
}
