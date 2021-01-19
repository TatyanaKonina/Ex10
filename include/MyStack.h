// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>
template <typename T>
class MyStack {
 private:
  T* stackPtr;
  int size;
  int top;

 public:
  explicit MyStack(int size) : top(-1) {
    this->stackPtr = new T[size];
    this->size = size;
  }
  MyStack() {
    this->size = 0;
    this->top = -1;
    this->stackPtr = nullptr;
  }
  ~MyStack() {
    delete[] stackPtr;
  }
  MyStack(const MyStack& object) {
    this->size = object.size;
    this->top = object.top;
    this->stackPtr = new T[object.size];
    for (unsigned i = 0; i < object.size; ++i)
      this->stackPtr[i] = object.stackPtr[i];
  }
  T get()const {
    if (top != -1)
      return stackPtr[top];
    throw "ERROR";
  }
  bool push(const T value) {
    if (top == size - 1)
      return false;
    stackPtr[++top] = value;
    return true;
  }
  bool pop() {
    if (top == -1)
      return false;
    stackPtr[top--] = 0;
    return true;
  }
  bool isFull() const {
    return top == size - 1;
  }
  bool isEmpty() const {
    return top == -1;
  }
  void printStack() {
    for (int i = size - 1; i >= 0; i--)
      std::cout << stackPtr[i] << std::endl;
  }
};

#endif  // INCLUDE_MYSTACK_H_
