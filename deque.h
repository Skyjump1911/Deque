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

private:

  static const int INITIAL_MAP_SIZE = 8;
  static const int BLOCK_SIZE = 16;
  

  int **blockmap;
  int size;
  int mapsize;
  int blocksize;
  int first_block;
  int first_element;
  int last_block;
  int last_element;
  int deque_size;

  /**

how to find the row from a user index:
row = first_block + ((first_element + i ) / blocksize)
that is integer division btw

finding the column from index:

col = (first_element + i ) % blocksize;


   **/

  // Helper Methods
  void resize_map(bool resize);



  

 public:

  deque();

  ~deque();

  void push_front(const int& number);
  
  void push_back(const int& number);

  void pop_front();

  void pop_back(); 

  int& front();

  int& back();

  bool empty();

  //  int size();

  void print();
  
  //not sure at all if this is how you even declare this right now
  // int& operator[](deque& object); 





};
#endif
