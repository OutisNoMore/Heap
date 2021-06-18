/**********************************************************
* AUTHOR   : Jaemok Lee and Jacky Chen
* LAB #6   : Heaps
* CLASS    : CS 008
* SECTION  : MW 6:30 - 8:35 pm
* DUE DATE : 04/29/2021
******************************************************************/

#include <iostream>

#include "Heap.h"

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


/***********************************************************
* Class pixel
*_________________________________________________________
* This is a custom data type that stores the rgb color
* of a pixel. The distance of the pixel from black is 
* calculated and used to roughly estimate how dark of 
* a shade the color is.
*_________________________________________________________
* INPUTS
*   _red (int)    // IN - red value of color
*   _green (int)  // IN - green value of color
*   _blue (int)   // IN - blue value of color
*   _name (std::string) // IN - color name
*
* POST-CONDITIONS
*   Distance between color and black is calculated.
***********************************************************/
class pixel{
private:
  int _red;   // IN - red value of color
  int _green; // IN - green value of color
  int _blue;  // IN - blue value of color
  double _distance; // IN - measures distance from black (0, 0, 0)
  std::string _color; // IN - common name of color\

public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
   
/**********************************************************
 *
 * CONSTRUCTOR pixel
 *_________________________________________________________
 * This is the default constructor. All values are set to 0
 * or null.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This will initialize all values to 0 or null
 ***********************************************************/
  pixel(): _red(0), _green(0), _blue(0), _distance(0.0), _color("NULL"){};

/**********************************************************
 *
 * CONSTRUCTOR pixel
 *_________________________________________________________
 * This constructor receives rgb values and the name of
 * the color.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need pre-defined values:
 *    r (int) // IN - red value of color
 *    g (int) // IN - green value of color
 *    b (int) // IN - blue value of color
 *    color (Std::string) // IN - name of color
 *
 * POST-CONDITIONS
 *   This function will set all data to the given values.
 *   The distance of the color from black is also calculated.
 ***********************************************************/
  pixel(int r, int g, int b, std::string color){
    _red = r;
    _green = g;
    _blue = b;
    _distance = r*r + g*g + b*b;
    _color = color;
  } 

  /***************
   ** ACCESSORS **
   ***************/

/**********************************************************
 *
 * ACCESSOR operator<(const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a pixel and
 * compares the distances. True is returned if the calling
 * pixel is darker.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return true if the calling pixel is
 *   closer to black, or darker than the other pixel.
 ***********************************************************/
  bool operator<(const pixel& p){
    return this->_distance < p._distance;
  }

  
/**********************************************************
 *
 * ACCESSOR operator>(const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a pixel and
 * compares the distances. True is returned if the calling
 * pixel is lighter.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return true if the calling pixel is
 *   farther to black, or lighter than the other pixel.
 ***********************************************************/
  bool operator>(const pixel& p){
    return this->_distance > p._distance;
  }  

  
/**********************************************************
 *
 * ACCESSOR operator<<(std::ostream& os, const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a stream output
 * operator and a reference to a pixel. The name of the
 * color of the pixel is output.
 *_________________________________________________________
 * PRE-CONDITIONS
 *  os (std::ostream&) // IN - reference to stream output
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return the name of the
 *   color of the pixel.
 ***********************************************************/
  friend std::ostream& operator<<(std::ostream& os, const pixel& p){
    os << "(" << p._color << ")";
    return os;
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
