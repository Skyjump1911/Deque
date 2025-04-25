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


/**
 * this is the push front function
 *
 * @param const int& number the number we are tyring to push to the front of the deque
 * @pre you need an deque object to be able to push into
 * @return void the item is pushed into the deque, but nothing is returned
 * @post the item is inserted to the front of the dequ
 * 
 */
  void push_front(const int& number);
  

/**
 * this is the push back function
 *
 * @param const int& number the number we are pushing to the back of the deque
 * @pre you need a deque to be able to push the number into 
 * @return void no return, the number is just put onto the end of the deque
 * @post the item is added to the end of the deque
 * 
 */
  void push_back(const int& number);


/**
 * this is the pop front function, which removes the first deque element
 *
 * @pre a deque object is needed, and it has to have things inside of it for this to work
 * @return void the first  element is removed from the deque
 * @post the first element gets removed, but nothing else changes
 * 
 */
  void pop_front();


/**
 * this is the pop back function 
 *
 * @pre this needs a deque with things stored inside of ti
 * @return void no return type, the last element is removed--that's all
 * @post the last element is removed from the deque
 * 
 */
  void pop_back(); 


/**
 * this is the front finder function 
 *
 * @pre this function needs to be able to access a deque object
 * @return int& the number which resides at the front of the deque
 * @post the number is returned, but nothing about the deque changes
 * 
 */
  int& front();


/**
 * this is the back finder funciton 
 *
 * @pre this function needs a deque in order to work 
 * @return int& this is the number which is stored at the end of the deque
 * @post the number at the end of the deque is returned, and nothing else changes
 * 
 */
  int& back();


/**
 * the empty check funciton 
 *
 * @pre N/A
 * @return bool a true or false value indicating whether or not the deque in question is full or empty 
 * @post N/A
 * 
 */
  bool empty();


/**
 * this is the size of funciton 
 *
 * @pre N/A
 * @return int the size of the deque
 * @post the deque size is returned, but nothing else changes 
 * 
 */
  int size();


/**
 * this is the print function 
 *
 * @pre n/A
 * @return void this funciton just prints out stuff, it doesn't return anything
 * @post the contents are printed out 
 * 
 */
  void print();
  

/**
 * this is the overloaded [] operator which allows us to access deque elements like we would a normal array
 *
 * @param int index the index we want to see
 * @pre a populated deque 
 * @return const this returns the element which we are trying to see
 * @post N/A
 * 
 */
  const int& operator[](int index);
  
};
#endif
