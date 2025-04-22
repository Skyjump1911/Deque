/**
 * @file deque.h
 * @author Noah Melton
 * @date 2025-04-22
 * @brief this is the header file for the deque class
 * 
 * this is where we declare the functions which the deque class will use
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>



/**
 * the deque class
 *
 * @class deque deque.h "Deque/deque.h"
 * @brief this class is a double ended queue, where we can add and remove items from both the beginning and the end of the queue. 
 *
 */
class deque {


 public:

  deque();

  ~deque();

  void push_front(int number);
  
  void push_back(int number);

  void pop_front();

  void pop_back(); 

  void front();

  void back();

  bool empty();

  int size();






}
