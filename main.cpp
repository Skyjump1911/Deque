#include "deque.h"
#include <iostream>

using namespace std;

int main() {

    deque test;

    cout << "Pushing elements to front...\n\n";
    
    for (int i = 1000; i >= 1; i--) {
      test.push_front(i);
    }

    cout << "Pushing elements to the back...\n\n";

    for (int i = 1001; i <= 2000; i++) {
      test.push_back(i);
    }

    cout << "First element: " << test.front() << endl;
    cout << "Last element: " << test.back() << endl;
    cout << "Element at index 500: " << test[500] << endl << endl;

    cout << "Popping 3 elements from front and back...\n\n";
    test.pop_front();
    test.pop_front();
    test.pop_front();
    test.pop_back();
    test.pop_back();
    test.pop_back();

    cout << "New first element: " << test.front() << endl;
    cout << "New last element: " << test.back() << endl;
    cout << "Element at index 500: " << test[500] << endl << endl;

    
    test.print();

    cout << endl << endl;

    
  return 0;
}
