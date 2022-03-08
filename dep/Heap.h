#ifndef _HEAP_H
#define _HEAP_H

#include <iostream>
#include <algorithm>
#include <iterator>

const int SIZE = 100;

template <typename E, typename C> // element and comparator
class Heap {                      // heap interface
  public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
    Heap();                   // default constructor
    Heap(const Heap& source); // copy constructor
    ~Heap();                  // destructor

  /**************
   ** MUTATORS **
   **************/
    Heap& operator=(const Heap& source); // overloaded assignment operator
		void insert(E value);                // insert new data
		E remove();                          // remove root data
    void heapify(E anArray[], int size); // function to create a heap out of a given array of elements (in other words heapify)

  /***************
   ** ACCESSORS **
   ***************/
    E peek();							                      // retrieve but don't remove root data
		int size() const {return count;};           // return size of heap
		bool is_empty() const {return count == 0;}; // check if heap is empty
    void preorder(E arr[], int size) const;     // print array in preorder
    void preorder() const;                      // print heap
			
	private:  // private member functions
  /*********************
   ** MUTATOR HELPERS **
   *********************/
		void expand();							                        //resize the array
    void copyHelper(const Heap& source, int node);      // copy or assign from a heap
    void bubbleUp(int node=0);                          // bubble up elements
    void bubbleDown(E anArray[], int size, int node=0); // bubble down elements
    void buildHeap(E anArray[], int size, int node=0);  // build heap from heapify

  /**********************
   ** ACCESSOR HELPERS **
   **********************/
    void preorderTraversal(E arr[], int size, int node) const; // helper to print heap

  private:			  //private member variables
    int count;    // points to next empty node
    C comparator; // allows for min or max heap
    E* heapArray; // array of data types
};



/***********************************************************
* Heap()
*_________________________________________________________
* Constructor; initializes variable data
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* n/a
*
* POST-CONDITIONS
*     initializes heapArray to array of set SIZE 
* and count to 0
***********************************************************/
template <typename E, typename C>
Heap<E, C>::Heap(){
  heapArray = new E[SIZE];
  count = 0;
}


/***********************************************************
* ~Heap()
*_________________________________________________________
* Destructor; deletes all dynamically allocated memory
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* n/a
*
* POST-CONDITIONS
*     deletes and frees dynamically allocated memory of 
* heapArray
***********************************************************/
template <typename E, typename C>
Heap<E, C>::~Heap(){
  delete [] heapArray;
}

/***********************************************************
* Heap(const Heap& source)
*_________________________________________________________
* This is the constructor with parameter arguments
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* const Heap& source: heap to copy data from
*
* POST-CONDITIONS
*     copies data from source to heapArray and sets count 
* equal to the number of items in source
***********************************************************/
template <typename E, typename C>
Heap<E, C>::Heap(const Heap& source) // heap to copy from
{
  heapArray = new E[SIZE];
  count = source.size();
  copyHelper(source, 0);
}


/***********************************************************
* copyHelper(const Heap& source, int node)
*_________________________________________________________
* This function is called within functions to traverse
* a heap in order to copy the elements, beginning at
* a specified node
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* const Heap source: heap to copy data from
* int node: node to begein traversal from
*
* POST-CONDITIONS
*     copies data from source to heapArray and then
* traverses to the right and left branch of the heap
* recurrsively
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::copyHelper(const Heap& source, // heap to copy from
                            int node)           // node to begin from
{
  if(node >= source.size()){
    return;
  }

  this->heapArray[node] = source.heapArray[node];

  int left = 2*node + 1;
  if(left < count){
    copyHelper(source, left);
  }

  int right = 2*node + 2;
  if(right < count){
    copyHelper(source, right);
  }
}

/***********************************************************
* operator=( const Heap& source )
*_________________________________________________________
* Overloaded assignment operator; Copies one heap
* to the heap that called this operator (left hand side)
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* const Heap source: heap to copy data from
*
* POST-CONDITIONS
*     copies data from source to heapArray via copyHelper
* starting from the root node.
***********************************************************/
template <typename E, typename C>
Heap<E, C>& Heap<E, C>::operator=(const Heap& source) // heap to copy from
{
  count = source.size();
  copyHelper(source, 0);

  return *this;
}

/***********************************************************
* bubbleUp(int node)
*_________________________________________________________
* This function traverses the heap from the most 
* recently added node of the heap, making sure the 
* heap order was not violated when inserting in a 
* new node. Utilizes a comparator to determine whether
* root should be min or max.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* int node: most recently inserted node
*
* POST-CONDITIONS
*     traverses heap from most recently inserted node,
* swapping the child and parent node if the comparator
* returns a value of true. Stops if comparator returns false
* or all nodes have been visited
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::bubbleUp(int node) // node to bubbleUp
{
  int parent = (node-1)/2; // get parent node
  if(node != 0 && comparator(heapArray[node], heapArray[parent])){
    std::swap(heapArray[node], heapArray[parent]);
    // go up one level
    bubbleUp(parent);
  }
}

/***********************************************************
* insert(E value)
*_________________________________________________________
* Inputs specified value into heap with the next available 
* spot with a left most branch priority.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* E value: value of type E to input into heap
*
* POST-CONDITIONS
*     inserts new value into heap, and calls bubbleUp to 
* check for and fix any violations of heap that may have 
* occurred in the process.
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::insert(E value) // value to insert
{
  if(count == SIZE){
    expand();
  }

  heapArray[count++] = value;
  bubbleUp(count-1);
}
/***********************************************************
* remove()
*_________________________________________________________
* removes the root of the heap and replaces it with the 
* most recently added node.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* n/a
*
* POST-CONDITIONS
*     removes the value of the root and replaces it 
* with the value of the most recently added node, then 
* calls bubbleDown to check heap for violations of the 
* heap-order property and fixes them.
***********************************************************/
template <typename E, typename C>
E Heap<E, C>::remove()
{
  heapArray[0] = heapArray[--count];
  //call bubble to validate heap here 
  //(pass in comparator to afffect if heap will have
  // min root or max root)
  this->bubbleDown(heapArray, count, 0);
  return heapArray[count];
}

/***********************************************************
* bubbledown(int node)
*_________________________________________________________
* This function traverses the heap starting from the 
* root of the heap, making sure that the
* heap order was not violated when removing the root 
* during the remove function. Utilizes a comparator 
* to determine whether root should be min or max.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* int node: node to start from(defaults to root)
*
* POST-CONDITIONS
*     traverses heap from root or specified node,
* swapping the child and parent node if the comparator
* returns a value of true. Stops if comparator returns false
* or all nodes have been visited
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::bubbleDown(E anArray[], // heap as an array
                            int size,    // sizze of array heap
                            int node)    // node to bubble down
{
  int leftChild = 2*node + 1;
  int rightChild = 2*node + 2;
  int compare;

  if(leftChild >= size && rightChild >= size){
    // no children do nothing
    return;
  }
  else if(leftChild < size && rightChild < size){
    // 2 children, find the correct child
    comparator(anArray[leftChild], anArray[rightChild]) ? compare = leftChild : compare = rightChild;
  }
  else if(leftChild < size){
    // only left child exists
    compare = leftChild;
  }
  else{
    //only right child exists
    compare = rightChild;
  }
  // Swap with the correct child
  std::swap(anArray[node], anArray[compare]);
  // continue building down
  this->bubbleDown(anArray, size, compare);
}

/***********************************************************
* peek()
*_________________________________________________________
* This method returns the value stored at the root of the 
* heap
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* n/a
*
* POST-CONDITIONS
*     returns the value of the heap if it exist, and throws 
* an error otherwise.
***********************************************************/
template <typename E, typename C>
E Heap<E, C>::peek()
{
  if(is_empty()){
    throw "Heap is Empty";
  }

  return heapArray[0];
}

/***********************************************************
* heapify(E anArray[], int size)
*_________________________________________________________
* This method converts an array of type E into a 
* heap
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* E anArray[]:array to convert into a heap
* int size: size of the array type
*
* POST-CONDITIONS
*     organizes the array inot a heap that follows the 
* heap order property. 
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::heapify(E anArray[], // heap as array
                         int size)    // size of heap
{
  int node = (size-2)/2; // start from middle of tree
  while(node >= 0){
    buildHeap(anArray, size, node--);
  }
}

/***********************************************************
* buildHeap(int node)
*_________________________________________________________
* This function traverses the heap starting ffrom the given 
* node, making sure that the heap has the proper order.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   int node: node to start from(defaults to root)
*
* POST-CONDITIONS
*   traverses heap from root or specified node,
*   swapping the child and parent node if the comparator
*   returns a value of true. Stops if comparator returns false
*   or all nodes have been visited
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::buildHeap(E anArray[],
                           int size,
                           int node)
{
  int leftChild = 2*node + 1;
  int rightChild = 2*node + 2;
  int compare;

  if(leftChild >= size && rightChild >= size){
    // no children do nothing
    return;
  }
  else if(leftChild < size && rightChild < size){
    // 2 children, find the correct child
    comparator(anArray[leftChild], anArray[rightChild]) ? compare = leftChild : compare = rightChild;
  }
  else if(leftChild < size){
    // only left child exists
    compare = leftChild;
  }
  else{
    //only right child exists
    compare = rightChild;
  }
  if(comparator(anArray[compare], anArray[node])){
    // Swap with the correct child
    std::swap(anArray[node], anArray[compare]);
  }
  // continue building down
  this->buildHeap(anArray, size, compare);
}

/***********************************************************
* preorder(E arr[], int size)
*_________________________________________________________
* This method prints out the contents of the array in 
* preorder.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* E anArr[]:array to print values of 
* int size: size of the array 
*
* POST-CONDITIONS
*     checks if array is empty, else passes the array 
* to preorderTraversal which will do the actual printing 
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::preorder(E arr[],        // heap as array
                          int size) const // size of array
{
  if(size == 0){
    std::cout << "Heap is empty!" << std::endl;
  } else{
  preorderTraversal(arr, size, 0);
  std::cout << std::endl;
  }
}

/***********************************************************
* preorder()
*_________________________________________________________
* This method prints out the contents of the heap
*_________________________________________________________
* PRE-CONDITIONS
* none
*
* POST-CONDITIONS
*     checks if array is empty, else passes the array 
* to preorderTraversal which will do the actual printing 
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::preorder() const 
{
  if(is_empty()){
    std::cout << "Heap is empty!" << std::endl;
  } else{
  preorderTraversal(heapArray, count, 0);
  std::cout << std::endl;
  }
}


/***********************************************************
* preorderTraversal(E arr[], int size, int node) 
*_________________________________________________________
* This method prints out the contents of the heap
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* E anArr[]:array to print values of 
* int size: size of the array 
* int node: node to print value of 
*
* POST-CONDITIONS
*     checks if node is the end of array, if so, returns 
* out of the function, else function proceeds to print
* left side of the heap recursively before printing out 
* right hand side of the heap recurrsively.
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::preorderTraversal(E arr[],  // heap as array
                                   int size, // size of heap
                                   int node) // node start from
const {
  if(node >= size){
    return;
  }

  std::cout << arr[node] << " ";
  
  int left = 2*node + 1;
  if(left < size){
    preorderTraversal(arr, size, left);
  }

  int right = 2*node + 2;
  if(right < size){
    preorderTraversal(arr, size, right);
  }
}

/***********************************************************
* expand() 
*_________________________________________________________
* This method increases the allocated memory of an array
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* n/a
*
* POST-CONDITIONS
*     creates a temporary new dynamically allocated array 
* with twice the size of the current heap, and copies all 
* elements of current heap to new heap. The old heap is 
* then deleted and pointed to the new heap.
***********************************************************/
template <typename E, typename C>
void Heap<E, C>::expand()
{
  E* temp = new E[count*2];
  std::copy(heapArray, &heapArray[count-1], temp);
  count = count * 2;

  delete [] heapArray;
  heapArray = temp;
  temp = nullptr;
}

#endif // _HEAP_H
