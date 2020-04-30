/*
 * Name: Ryan Auger
 * Date Submitted: 2/15/2019
 * Lab Section: 2
 * Assignment Name: Searcheing and Sorting
 */
#pragma once

#include <vector>
using namespace std;

template <class T>
/*
Purpose:
  this is just a simple search where we start at the beginning of the vector and go through every item until the right one is found
Inputs:
  data: the vector that supposedly contains the element we are looking for
  target: the element we are looking for
Outputs:
  i: the index of the element we have found
  -1: if the element is not in the vector we return this
*/
int linearSearch(std::vector<T> data, T target){
  int i;
  for(i = 0; (unsigned int)i < data.size(); i++){
    if(data[i] == target){
      return i;
    }
  }
  return -1;
}


template <class T>
/*
Purpose:
  the purpose of this function is to get the middle of the vector and see if the middle value is then than or greater than the
  target. if it is then we either ignore the left or right and pick a new middle until the middle equals the target
Inputs:
  data: the vector that supposedly contains the element we are looking for
  target: the element we are looking for
Outputs:
  middle: the index of the element we have found
  -1: if the element is not in the vector we return this
*/
//this was influeced by geeksforgeeks
int binarySearch(vector<T> data, T target){
  typename vector<T>::iterator first = data.begin();
  typename vector<T>::iterator last = data.end() - 1;
  typename vector<T>::iterator middle = data.begin() + (data.size() / 2);

  //this < or = in this while loop helps with if there are multiple instances of the same element
  while(first <= last){
    //this is the middle and is updated every time first or last is changed
    middle = data.begin() + ((distance(data.begin(), first) + distance(data.begin(), last)) / 2);

    //return the index if the middle equals the target
    if(*middle == target){
      return distance(data.begin(), middle);
    }
    //if target is on the left side of the middle ignore the right side
    else if(*middle > target){
      last = middle - 1;
    }
    //if the target is on the right side of the middle then ignore the left side
    else if(*middle < target){
      first = middle + 1;
    }
  }
  return -1;
}
