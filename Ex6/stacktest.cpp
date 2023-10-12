// stacktest.cpp: code to test sstack implementation

#include "sstack.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

void test_basic_operation() {
  StringStack stk;
  stk.push("work at library");
  stk.push("rest");
  stk.push("attend csc2210");
  stk.push("eat lunch");
  stk.push("go to lab");
  stk.push("eat breakfast");

  // check pops work
  assert(!stk.empty());
  assert(stk.pop() == "eat breakfast");
  assert(stk.pop() == "go to lab");
  assert(stk.pop() == "eat lunch");
  assert(stk.pop() == "attend csc2210");
  assert(stk.pop() == "rest");
  assert(stk.pop() == "work at library");
  assert(stk.empty());
}

void test_push_and_pop() {
  StringStack s;
  s.push("a");
  s.push("b");
  s.push("c");
  assert(s.pop() == "c");
  assert(s.pop() == "b");
  assert(s.pop() == "a");
  assert(s.empty());
  s.push("d");
  s.push("e");
  s.push("f");
  assert(!s.empty());
  assert(s.pop() == "f");
  assert(s.pop() == "e");
  s.push("g");
  assert(s.pop() == "g");
  assert(s.pop() == "d");
  assert(s.empty());
}

void test_clear() {
  StringStack s;
  s.push("one");
  assert(!s.empty());
  s.clear();
  assert(s.empty());
}

int main() {
  test_basic_operation();
  test_push_and_pop();
  test_clear();
  cout << "All tests pass." << endl;
  return 0;
}