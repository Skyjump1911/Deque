/**
 * @file deque.h
 * @author Noah Melton and Sam Toney
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

private:

  static const int INITIAL_MAP_SIZE = 8;
  static const int BLOCK_SIZE = 16;  

  int **blockmap;
  int mapsize;
  int blocksize;
  int first_block;
  int first_element;
  int last_block;
  int last_element;
  int deque_size;

  /**
//note for the math
how to find the row from a user index:
row = first_block + ((first_element + i ) / blocksize)
that is integer division btw

finding the column from index:

col = (first_element + i ) % blocksize;


   **/

  // Helper Methods

/**
 * this is the resize function for the map
 *
 * @param bool resize a true or false value for the resize
 * @pre you need a map to resize
 * @return void no return type, it just resizes the map
 * @post the map is resized to hold more elements
 * 
 */
  void resize_map(bool resize);

 public:


/**
 * this is the deque constructor
 *
 * @pre N/A
 * @post a deque object is made
 * 
 */
  deque();


/**
 * the deque destructor
 *
 * @pre you need a deque first in order to be able to destroy it
 * @post the deque is destroyed
 * 
 */
  ~deque();

  void push_front(const int& number);
  
  void push_back(const int& number);

  void pop_front();

  void pop_back(); 

  int& front();

  int& back();

  bool empty();

  int size();

  void print();
  
  const int& operator[](int index);
  
};
#endif
