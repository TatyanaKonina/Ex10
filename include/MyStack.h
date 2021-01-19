// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>
template <typename T>
class MyStack {
private:
  T* stackPtr;  // указатель на стек
  int size;  // размер стека
  int top;  // вершина стека

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
      return false;  // стек полон
    stackPtr[++top] = value;  // помещаем элемент в стек
    return true;
  }
  // поместить элемент в стек
  bool pop() {
    if (top == -1)
      return false;  // стек пуст
    stackPtr[top--] = 0;  // удаляем элемент из стека
    return true;  // успешное выполнение операции
  }
  // удалить из стека элемент
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
