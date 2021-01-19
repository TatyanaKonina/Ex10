// Copyright 2020 Konina Tatiana
#include "MyStack.h"
#include "postfix.h"
#include <map>
#include <string>

std::string infix2postfix(std::string infix) {
  std::map<char, int> priority = { {'(', 0}, {')', 1}, {'+', 2},
                                 {'-', 2}, {'*', 3}, {'/', 3} };
  std::string all_operations = "+-*/";
  MyStack<char> operations(200);
  std::string out;
  for (int i = 0; i < infix.size(); ++i) {
    if (infix[i] == ' ')
      continue;
    if (all_operations.find(infix[i]) != std::string::npos) {
      if (operations.isEmpty() || operations.get() == '(') {
        operations.push(infix[i]);
      } else if (priority[infix[i]] > priority[operations.get()]) {
        operations.push(infix[i]);
      } else {
        while (!(operations.isEmpty())  &&
               (priority[operations.get()] >= priority[infix[i]])) {
          if (operations.get() == ')') break;
          out += operations.get();
          out += ' ';
          operations.pop();
        }
        operations.push(infix[i]);
      }
    } else if (infix[i] == '(') {
      operations.push(infix[i]);
    } else if (infix[i] == ')') {
      while (operations.get() != '(') {
        out += operations.get();
        out += ' ';
        operations.pop();
      }
      operations.pop();
    } else {
      out += infix[i];
      if (!((i + 1 <= infix.size() && (isdigit(infix[i + 1]) || infix[i + 1] == '.')))) {
        out += ' ';
      }
    }
  }
  while (!operations.isEmpty()) {
    out += operations.get();
    out += ' ';
    operations.pop();
  }
  out.resize(out.size() - 1);
  return out;
}
