/**
 * @file deque.cpp
 * @author Noah Melton and Sam Toney
 * @date 2025-04-24
 * @brief Header file for deque program.
 * 
 * Holds a deque class for use in the Deque Program.
 */

#include "deque.h"
#include <iostream>

using namespace std;



/**
 * the default constructor
 *
 * @pre Nothing has to be done beforehand; this is the constructor. Itsets up the member variables. 
 * @post the member variables are intitialized 
 * 
 */
deque::deque() {

  //The map dimensions
  mapsize = INITIAL_MAP_SIZE;
  blockmap = new int*[mapsize];

  // Initialize all the blocks to null at first
  for (int i = 0; i < mapsize; i++) {
    blockmap[i] = nullptr;
  }

  // Start in the middle of the blockmap, which will allow growth
  first_block = mapsize / 2;
  last_block = first_block;

  // Make starting positions the middle of the block, for the same reason as
  // above
  first_element = BLOCK_SIZE / 2;
  last_element = first_element - 1;

  // Initialize deque_size 
  deque_size = 0;

  // Allocate memory for the first block
  blockmap[first_block] = new int[BLOCK_SIZE];
}



/**
 * this is the print function, which prints out the data
 *
 * @pre This functions needs a deque to have stuff in it, or else printing out an empty deque is useless
 * @return void No return type, just prints out stuff
 * @post the stuff inside the deque is printed out so we can see it
 * 
 */
void deque::print() {

  if (!empty()) {
    cout << "Deque Data:\n\n";

    for (int i = 0; i < deque_size; i++) {
      cout << (*this)[i] << " ";
    }

    cout << endl;
  }

}


/**
 * the destructor
 *
 * @pre A constructed deque
 * @post the deque is iterated through, and destroyed piece by piece
 * 
 */
deque::~deque() {

  for (int i = 0; i < mapsize; i++) {
    if (blockmap[i] != nullptr) {
      delete[] blockmap[i];
    }
  }
  delete[] blockmap;
}


/**
 * this function pushes the number into the deque
 *
 * @param const int& number the number we are trying to insert into the deque
 * @pre We need a deque object that we can push into
 * @return void no return type, this function just puts stuff inside the deque
 * @post the number we want to push in is put into the deque at the front
 * 
 */
void deque::push_front(const int& number) {

  // Check if we need to move to the previous block
  if (first_element == 0) {
    
    // Check if we need to resize the map
    if (first_block == 0) {
      resize_map(true);
    }

    // Move to previous block
    first_block--;

    // Allocate memory for the new block if necessary
    if (blockmap[first_block] == nullptr) {
      blockmap[first_block] = new int [BLOCK_SIZE];
    }

    // Move to the end of the new block
    first_element = BLOCK_SIZE - 1;

  } else {
    // Move position back
    first_element--;
  }

  // Store number and update deque_size
  blockmap[first_block][first_element] = number;
  deque_size++;
}


/**
 * this is the push back function
 *
 * @param const int& number the number we are pushing into the deque
 * @pre this function needs a deque it can push back into
 * @return void no return type=--this function just inserts a number at the end of the deque
 * @post the number is inserted into the deque, at the end of it
 * 
 */
void deque::push_back(const int& number) {

  // Check if we need to move to the next block
  if (last_element == BLOCK_SIZE - 1) {
    
    // Check if we need to resize the map
    if (last_block == mapsize - 1) {
      resize_map(false);
    }

    // Move to the next block
    last_block++;

    // Allocate memory for the new block if necessary
    if (blockmap[last_block] == nullptr) {
      blockmap[last_block] = new int[BLOCK_SIZE];
    }

    // Set position at the start of the new block
    last_element = 0;
    
  } else {
    // Move position forward
    last_element++;
  }

  // Store number and update deque_size
  blockmap[last_block][last_element] = number;
  deque_size++;
}


/**
 * this is the pop front function, it just removes elements from the front of the deque
 *
 * @pre you need a deque object with stuff already inside of it in order to be able to remove stuff from the front of the deque
 * @return void No return type, just removes the front element
 * @post the front element is removed. This shortens the deqye
 * 
 */
void deque::pop_front() {

  // Check is deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
    exit(1);
  }

  // Move first position forward 
  first_element++;

  // Check if the position is at the end of the block and move to next block if needed
  if (first_element == BLOCK_SIZE) {
    first_block++;
    first_element = 0;
  }

  deque_size--;

}


/**
 * this function does the reverse of the pop front, it pops off of the back
 *
 * @pre a deque with stuff inside of it is needed
 * @return void no return type, this function just kills off the last deque elemnet
 * @post the last element in the deque is removed
 * 
 */
void deque::pop_back() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
    exit(1);
  }

  // Move last position backward
  last_element--;

  // Check if the position is at the front of the block and move to the previous block if needed
  if (last_element < 0) {
    last_block--;
    last_element = BLOCK_SIZE - 1;
  }

  deque_size--;
}


/**
 * this funciton returns a copy of the element which is at the front of the deque
 *
 * @pre this function needs a populated deque
 * @return int& a reference to the int at the front of the array
 * @post the front element in the deque is returned. Nothing about the deque changes though 
 * 
 */
int& deque::front() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
    exit(1);
  }

  // Return first element
  return blockmap[first_block][first_element];
}


/**
 * the back funciton 
 *
 * @pre this function just needs a populated deque
 * @return int& a reference to the number at the end of the deque
 * @post the number is returned, but nothing is changed as far as the deque itself is concerned
 * 
 */
int& deque::back() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
    exit(1);
  }

  // Return last element
  return blockmap[last_block][last_element];
}


/**
 * this is the check for empty function 
 *
 * @pre N/A
 * @return bool this just returns a true or false if the deque is empty or full
 * @post N/A
 * 
 */
bool deque::empty() {

  // Check if deque has any elements
  return deque_size == 0;

}


/**
 * this is the deque size funciton 
 *
 * @pre A deque object
 * @return int the legth of the dequq
 * @post the size is returned but nothing inherent to the deque itself actually changes
 * 
 */
int deque::size() {
  return deque_size;
}


/**
 * this is the overloaded operator
 *
 * @param int index the index which we are trying to see inside the deque
 * @pre a populated deque is needed
 * @return const the value at the index we are looking at
 * @post the index is returned 
 * 
 */
const int& deque::operator[](int index) {

  // Check if valid index was entered
  if (index < 0 || index >= deque_size) {
    cout << "ERROR: invalid index\n";
  }

  // Calculate the overall index for the element
  int logical_index = first_element + index;

  // Find block and position in the block 
  int block_offset = logical_index / BLOCK_SIZE;
  int position_offset = logical_index % BLOCK_SIZE;

  return blockmap[first_block + block_offset][position_offset];
}


/**
 * this is the map resize funciton 
 *
void deque::resize_map(bool resize) {

  int new_map_size = mapsize * 2;
  int** new_blockmap = new int*[new_map_size];

  // Set everything to NULL
  for (int i = 0; i < new_map_size; i++) {
    new_blockmap[i] = nullptr;
  }

  // Calculate position of new first block
  int new_first_block = 0;
  if (resize) {
    new_first_block = (new_map_size - mapsize) / 2 + first_block;
  } else {
    new_first_block = (new_map_size - mapsize) + first_block;
  }
  
  // Copy data to the new map
  for (int i = first_block; i <= last_block; i++) {
    new_blockmap[new_first_block + (i - first_block)] = blockmap[i];
  }
  
  // Update blocks
  last_block = new_first_block + (last_block - first_block);
  first_block = new_first_block;
  
  // Update map and block info
  delete[] blockmap;
  blockmap = new_blockmap;
  mapsize = new_map_size;
  
}
