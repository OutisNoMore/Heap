/**********************************************************
* AUTHOR   : Jaemok Lee and Jacky Chen
* LAB #6   : Heaps
* CLASS    : CS 008
* SECTION  : MW 6:30 - 8:35 pm
* DUE DATE : 04/29/2021
******************************************************************/

#include <iostream>

#include "Heap.h"
#include "Pixel.h"

/***********************************************************
* Class CompareMin
*_________________________________________________________
* This templated class implements a minimum value comparator. 
* There is only 1 function.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Allows for comparison between 2 values, true is 
*   returned if the value to the left is less than the other.
***********************************************************/
template <typename T>
class CompareMin{
public:
    bool operator()(T i1, T i2)
    {
       if (i1 < i2) return true;
       return false;
    }
};

/***********************************************************
* Class CompareMax
*_________________________________________________________
* This templated class implements a maximum value comparator. 
* There is only 1 function in the class.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Allows for comparison between 2 values, true is 
*   returned if the value to the left is greater than the 
*   other
***********************************************************/
template <typename T>
class CompareMax{
public:
    bool operator()(T i1, T i2)
    {
       if (i1 > i2) return true;
       return false;
    }
};
/************************************************************
*
* Dynamic Array Heap
*___________________________________________________________
* This program implements a templated heap data structure using
*   a dynamic array. The user can insert, delete, and print
*   values while maintaining the proper heap order as
*   specified by a comparator.
*___________________________________________________________
* INPUTS:
*   Any data type to store
*   Comparator - to specify min or max heap
*
* OUTPUTS:
*   The user can print the values of the heap in preorder and
*   peek at the value at the root node.
*************************************************************/
int main() {
try{
  std::cout << "Conducting tests on a Minimum Value Heap with given values" << std::endl;
  Heap<int, CompareMin<int>> myHeap;


  std::cout << "Heap should be empty: ";
  myHeap.is_empty() ? std::cout << "Empty" : std::cout << "Not empty";
  std::cout << std::endl;

  std::cout << "Insert" << std::endl;
  myHeap.insert(67);
  myHeap.insert(88);
  myHeap.insert(77);
  myHeap.insert(52);
  myHeap.insert(44);
  myHeap.insert(11);
  myHeap.insert(66);
  myHeap.insert(93);
  std::cout << std::endl;
  
  std::cout << "Root node(should be 11): " << myHeap.peek() << std::endl;
  std::cout << "Size(should be 8): " << myHeap.size() << std::endl;

  std::cout << "Remove" << std::endl;  
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  std::cout << std::endl;

  std::cout << "Conducting tests on a Maximum Value Heap with given values" << std::endl;
  Heap<int, CompareMax<int>> myHeap2;

  std::cout << "Insert" << std::endl;
  myHeap2.insert(67);
  myHeap2.insert(88);
  myHeap2.insert(77);
  myHeap2.insert(52);
  myHeap2.insert(44);
  myHeap2.insert(11);
  myHeap2.insert(66);
  myHeap2.insert(93);
  std::cout << std::endl;

  std::cout << "Testing Copy Constructor" << std::endl;
  std::cout << "Original heap: ";
  myHeap2.preorder();
  std::cout << std::endl;
  Heap<int, CompareMax<int>> test(myHeap2);
  std::cout << "Copied heap: ";
  test.preorder();
  std::cout << std::endl;

  std::cout << "Testing assignment operator" << std::endl;
  std::cout << "Original heap: ";
  myHeap2.preorder();
  std::cout << std::endl;
  Heap<int, CompareMax<int>> test2;
  test2 = myHeap2;
  std::cout << "Assigned heap: ";
  test2.preorder();
  std::cout << std::endl;

  std::cout << "Root node(should be 93): " << myHeap2.peek() << std::endl << std::endl;

  std::cout << "Remove" << std::endl;
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  myHeap2.remove();
  std::cout << std::endl;

  std::cout << "Checking Heapify" << std::endl;
  int anArray[8] = {67, 88, 77, 52, 44, 11, 66, 93};
  
  std::cout << "Original Array: ";
  myHeap2.preorder(anArray, 8);
  std::cout << std::endl;

  myHeap2.heapify(anArray, 8);
  std::cout << "\nArray converted to Max Heap: ";
  myHeap2.preorder(anArray, 8);
  std::cout << std::endl;

  std::cout << "Custom data type - pixel class" << std::endl;
  std::cout << "Sort by darkest shade at root" << std::endl << std::endl;
  // Min heap or darkest color at root node
  pixel myPixel(255, 255, 255, "white");
  Heap<pixel, CompareMin<pixel>> pixels;

  std::cout << "Insert" << std::endl;
  pixels.insert(pixel(255, 255 ,255, "white"));
  pixels.insert(pixel(0, 0, 0, "black"));      
  pixels.insert(pixel(128, 0, 128, "purple")); 
  pixels.insert(pixel(165, 42, 42, "brown"));  
  pixels.insert(pixel(255, 165, 0, "orange")); 
  pixels.insert(pixel(255, 255, 0, "yellow")); 
  pixels.insert(pixel(255, 229, 180, "peach"));
  pixels.insert(pixel(144, 238, 144, "light green"));
  std::cout << std::endl;

  std::cout << "Root node(should be black): " << pixels.peek() << std::endl;
  std::cout << std::endl;

  std::cout << "Remove" << std::endl;
  pixels.remove();
  pixels.remove();
  pixels.remove();
  pixels.remove();
  pixels.remove();
  pixels.remove();
  pixels.remove();
  pixels.remove();
  std::cout << std::endl;

  std::cout << "Sort by lightest shade at root" << std::endl << std::endl; 
  // Max heap or lightest color at root node
  Heap<pixel, CompareMax<pixel>> pixels2;
  std::cout << "Insert" << std::endl;
  pixels2.insert(pixel(255, 255 ,255, "white"));
  pixels2.insert(pixel(0, 0, 0, "black"));      
  pixels2.insert(pixel(128, 0, 128, "purple")); 
  pixels2.insert(pixel(165, 42, 42, "brown"));  
  pixels2.insert(pixel(255, 165, 0, "orange")); 
  pixels2.insert(pixel(255, 255, 0, "yellow")); 
  pixels2.insert(pixel(255, 229, 180, "peach"));
  pixels2.insert(pixel(144, 238, 144, "light green"));
  std::cout << std::endl;

  std::cout << "Root node(should be white): " << pixels2.peek() << std::endl << std::endl;

  std::cout << "Remove" << std::endl;
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  pixels2.remove();
  std::cout << std::endl; 
  } catch(const char* msg){
    std::cout << msg << std::endl;
  }
}
