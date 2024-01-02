/*
sequence containers
-> array
-> vector
-> dequeu(not allocated contiguous memory)
-> forward_list
-> list

associative containers(balanced trees)
->  set
->  map
->  multimap
->  multiset

unordered associative containers
->  unordered set
->  unordered map
above are implemented using hash tables
->  unordered multiset
-> unordered multimap

container adaptors
-> stack 
-> queue
-> priority queue



### if we create an array using int arr[]={1,2,3,4,5}; and use the sizeof operator on it it will give the size of 4*5
but if we write a separate function and pass the array to that function then we are going to get the size of the pointer which will be 8



*/

#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<queue>
int main(){
    
    //###########################   ARRAY   #################################################
    //Declare an array of size 5 
    std::array<int,5> myArray;

    //fill an array with specific values
    myArray.fill(10);

    //access element at the specific index with bounds checking
    myArray.at(3);

    ////access the first element
    myArray.front();
    
    //get the element at the back of the array
    myArray.back();

    //check if the array is empty
    myArray.empty();

    //size get the size of the array
    myArray.size();

    //note-> array is fixed size container and if you remove one of the elements from the array then it wont' reduce the size of the array



    //###########################   VECTOR  #################################################

    //vector support dynamic resizing
    std::vector<int> myVector;

    //you can initialize vector with values or using an array of copy constructor
    std::vector<int> myVector2={1,2,3};
    int numbers[]={1,2,3,4,5};
    std::vector<int> myVector3(numbers,numbers+4);
    
    //you can access the elements using at operator
    //you can push elements at the back using push_back
    //you can pop the elements form the back using pop_back
    //size() gives the number of elements
    //capacity gives the number of elements it can currently hold
    //clear() is used to clear all the elements from the vector



    //###########################   DEQUE  #################################################
    std::deque<int> myDeque;
    //you can initialize the deque similar to a vector as stated above and different points for deque are
    /**
     * at() 
     * push_front()
     * push_back
     * pop_front()
     * pop_back()
     * size()
     * empty()
     * clear()
     */

//###########################   PRIORITY QUEUE   #################################################
/**
 * by default the highest values is at the top of the priority queue
 * 
 * priority_queue<int,vector<int>,greater<int>>;
 * 
 * now if you want to use a custom compare function here
 * use-> 
 * class compare{
 * public:
 *      bool operator()(int a,int b){
 *          return a<b; 
 *      }
 *
 * };
 * priority_queue<int,vector<int>,compare> qu;
 * 
 * 
 * or use
 * 
 * auto customComparator=[](int a,int b){return a>b;}
 * std::priority_queue<int,std::vector<int>, decltype(customComparator)> myCustomPriorityQueue(customComparator);
 */

}