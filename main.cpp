#include "deque.h"
#include <iostream>

using namespace std;

int main() {

    deque test;

    cout << "Pushing elements to front...\n\n";
    
    for (int i = 5; i >= 1; i--) {
      test.push_front(i);
    }

    cout << "Pushing elements to the back...\n\n";

    for (int i = 6; i <= 10; i++) {
      test.push_back(i);
    }

    test.print();
    
  return 0;
}
