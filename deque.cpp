#include "deque.h"
#include <iostream>

using namespace std;


deque::deque() {

  int mapsize = 5; 
  int blocksize = 5;
  
  int **blockmap = new int*[
			    mapsize];
  for(int i = 0; i < mapsize; i++) {

    blockmap[i] = new int[blocksize];
    
  }

  for(int i = 0; i < mapsize; i++) {
    for(int j = 0; j < blocksize; j++){

      blockmap[i][j] = 1;
      
    }
  }
  
  // int first_block = 0;
  // int first_element = 0; 





}


void deque::print() {

  for(int i = 0; i < mapsize; i++) {

    for(int j = 0; j < blocksize; j++) {


      cout << blockmap[i][j] << " ";
    }

    cout << endl; 

  }


}

deque::~deque() {


  for(int i = 0; i < mapsize; i++) {

    delete [] blockmap[i]; 


  }

  delete [] blockmap; 


}

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
    if (blockmap[first_block] == NULL) {
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
    if (blockmap[last_block] == NULL) {
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

void deque::pop_front() {

  // Check is deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
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

void deque::pop_back() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
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

int& deque::front() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
  }

  // Return first element
  return blockmap[first_block][first_element];
}

int& deque::back() {

  // Check if deque is empty
  if (empty()) {
    cout << "ERROR: deque is empty\n";
  }

  // Return last element
  return blockmap[last_block][last_element];
}

bool deque::empty() {

  // Check if deque has any elements
  return deque_size == 0;

}

const int& deque::operator[](int index) {

  // Check if valid index was entered
  if (index < 0 || index >= deque_size) {
    cout << "ERROR: invalid index\n";
  }

  // Calculate the overall index for the element
  int global_index = first_block + index;

  // Find block and position in the block 
  int block_offset = global_index / BLOCK_SIZE;
  int position_offset = global_index % BLOCK_SIZE;

  return blockmap[first_block + block_offset][position_offset]
}

void deque::resize_map(bool resize) {

  int new_map_size = mapsize * 2;
  int** new_blockmap = new int*[new_map_size];

  // Set everything to NULL
  for (int i = 0; i < new_map_size; i++) {
    new_blockmap[i] = NULL;
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
