# Deque
This is the repo for the deque group assignment. 


What is a deque?

Deque stands for a double ended queue. Essentially, it is a 2D array which stores values. There is an STL deque object, but for this assignment, we were tasked with making our own version. Our version is pretty much the same, as it allows access to the front and end of the deque, just like the STL one does. Howver, the STL deque has a built in [] function which allows element access. Ours does too, but we had to make it. We don't have more niche STL functions, like the clear() function, but for the most part our assignmnet copies the main behaviors of the STL deque. In the main.cpp, we have included some test cases to demonstrate these funcitonalities.

Essentially, what we have is a 2d array (but the user doesn't know that) which just acts like (to the user's eyes) a big one-d array. We can add elements, and delete elements, and access random elements using the [] operator. In addition to this, we can check to see if the deque is empty or if it has stuff inside of it, as well as check to see how long the deque is. 

This assignment was a collab between Noah Melton and Sam Toney. Melton started off by making the .h and .cpp files, and making the constructor/destructor and print function. Toney worked on some other functions and then merged with Melton. Melton then went through and added documentation for everything that didn't already have it and worked on this README file.

Notes: I had a bug that Dr. Bradley helped me sort out with the destructor, and I also consulted Caleb Curry and CSExplained's youtube channels for information about deques and some 2d dynamic array review.
Finally, I had an issue merging and pulling Sam's commits, so I consulted chatgpt to figure out how to do that so we would be on the same version of the shared code. 