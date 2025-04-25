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

void deque::push_front(const int& number) {}

void deque::resize_map(bool resize) {

  int new_map_size = map_size * 2;
  int** new_blockmap = new int*[new_map_size];

  // Set everything to NULL
  for (int i = 0; i < new_map_size; i++) {
    new_blockmap[i] = NULL;
  }

  // Calculate position of new first block
  int new_first_block = 0;
  if (resize) {
    new_first_block = (new_map_size - map_size) / 2 + first_block;
  } else {
    new_first_block = (new_map_size - map_size) + first_block;
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
  map_size = new_map_size;
  
}
