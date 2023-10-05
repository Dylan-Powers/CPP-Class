//
// Created by powersd on 9/21/2023.
//

#include <iostream>
using namespace std;

extern "C" long add100(long in);

__asm__(
"add100:\n"
// 32-bit version
//"  mov %ecx, %eax\n" // ecx is the first parameter, edx is the second, after that it uses the stack
//"  add $100, %eax\n"
// 64-bit version:
"  mov %rdi, %rax\n"
"  add $100, %rax\n"
"  ret \n"
);

int main() {
  int integer = add100(1);
  cout << integer;
  return 0;
}
