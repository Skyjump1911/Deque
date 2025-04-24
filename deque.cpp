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
