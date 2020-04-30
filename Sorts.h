/*
 * Name: Ryan Auger
 * Date Submitted: 2/15/2019
 * Lab Section: 2
 * Assignment Name: Searching and Sorting
 */
#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <time.h>
using namespace std;


template <class T>
/*
Purpose:
  The purpose of this function is to divide a vector recursivley until the base case is hit
  and after start building it back up while sorting it
Inputs:
  lst: the vector that needs to be sorted
Outputs:
  sorted: the vector that has been sorted
*/
vector<T> mergeSort(vector<T> lst){
  typename vector<T>::iterator middle = lst.begin() + (lst.size() / 2);
  typename vector<T>::iterator right_iterator = lst.end() - 1;
  vector<T> left;
  vector<T> right;
  vector<T> sorted;
  unsigned int l = 0, r = 0;
  int i;

  //BASE CASE
  //will exit the function when we get to where the vector is just one element
  if(lst.size() <= 1){
    return lst;
  }

  //this puts the left half of the vector lst into a new vector
  for(i = 0; lst[i] != *middle; i++){
    left.push_back(lst[i]);
  }

  //this puts the right half of the vector lst into a new vector
  right_iterator = middle;
  while(right_iterator != lst.end()){
    right.push_back(lst[distance(lst.begin(),right_iterator)]);
    right_iterator++;
  }

  //this is where the recursion happens
  //we call mergeSort on the left and right vectors
  left = mergeSort(left);
  right = mergeSort(right);

  //this section of code is to build back up the original vector in order
  //this part was influenced by geeksforgeeks

  //this while loop is for if the left and right vector are the same size
  //we compare the left and right vectors to see if the left element
  //is greater then or equal or less then or equal to the right element
  //and push back onto the vector
  while(l < left.size() && r < right.size()){
    if(left[l] >= right[r]){
      sorted.push_back(right[r]);
      r++;
    }
    else if(left[l] <= right[r]){
      sorted.push_back(left[l]);
      l++;
    }
  }
  //this while loop catches any remaining elements in the right vector
  //and it will not get into this while loop if there is only one element
  //in that vector
  while(r < right.size()){
    sorted.push_back(right[r]);
    r++;
  }
  //this while loop catches any remaining elements in the left vector
  //and it will not get into this while loop if there is only one element
  //in that vector
  while(l < left.size()){
    sorted.push_back(left[l]);
    l++;
  }

  return sorted;
}

template <class T>
/*
Purpose:
  the purpose of this function is to pick a random pivot and set everything that is less then that pivot
  to the left of the pivot and everthing greater then the pivot to the right of the pivot then split and recurse
  through until the vector is sorted then push back onto a new vector
Inputs:
  lst: the vector that needs to be sorted
Outputs:
  sorted: the vector that has been sorted
*/
vector<T> quickSort(vector<T> lst){
  srand(time(NULL));
  int max = lst.size();
  int min = 0;
  typename vector<T>::iterator piv = lst.begin() + (rand()%(max + min));
  typename vector<T>::iterator left_iterator = lst.begin();
  typename vector<T>::iterator right_iterator = (lst.end() - 1);
  vector<T> sorted;
  vector<T> left;
  vector<T> right;

  int i;

  //BASE CASE
  if(lst.size() <= 1)
    return lst;

  //the left_iterator and right_iterator are pointers to the beginning and end of the vector respectively
  //if the pointers hit each other then we do not enter this while loop
  while(left_iterator < right_iterator){
    //first we check the left_iterator value and if it is greater then the pivot we go on to check the right_iterator
    if((*left_iterator) >= (*piv)){
      //if the right_iterator's value is less then the pivot we fall into this if statement
      if((*right_iterator) <= (*piv)){
        //we go and swap the left_iterator's and right_iterator's value
        swap(*left_iterator, *right_iterator);
        //this if else statement is here to move the pivot pointer with the pivot if it moves
        if(left_iterator == piv){
          piv = right_iterator;
          right_iterator = lst.end()-1;
          left_iterator = lst.begin();
        }
        else if(right_iterator == piv){
          piv = left_iterator;
          right_iterator = lst.end()-1;
          left_iterator = lst.begin();
        }
      }
      else
        //this is if the right_iterator is not less then the pivot we decrement down
        right_iterator--;
    }
    else
      //this is if the left_iterator is not greater then the pivot we increment up
      left_iterator++;
  }

  //splits the vector into left and right halves but doesn't include the pivot
  for(i = 0; lst[i] != *piv; i++){
    left.push_back(lst[i]);
  }

  right_iterator = piv+1;
  while(right_iterator != lst.end()){
    right.push_back(lst[distance(lst.begin(),right_iterator)]);
    right_iterator++;
  }

  //if pivot is all the way to the left and left is empty do not enter if statement
  if(left.size() != 0)
    left = quickSort(left);

  //if pivot is all the way to the right and right is empty do not enter if statement
  if(right.size() != 0)
    right = quickSort(right);

  //push backs the sorted elements from the left vector onto a new vector called sorted
  for(i = 0; (unsigned int)i < left.size(); i++){
    sorted.push_back(left[i]);
  }

  //pushes back the pivot
  sorted.push_back(*piv);

  //push backs the sorted elements from the right vector onto a new vector called sorted
  for(i = 0; (unsigned int)i < right.size(); i++){
    sorted.push_back(right[i]);
  }

  return sorted;

}
