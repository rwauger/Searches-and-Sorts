#include <iostream>
#include "Sorts.h"
#include "Searches.h"
using namespace std;

int main(){
  int i;

  vector<int> intTest {200,-5,32,432,-23,5,8,9};
  int a = linearSearch(intTest, 5);

  for(i = 0; (unsigned int)i < intTest.size(); i++){
    cout << intTest[i] << " ";
  }
  cout << endl << a;
  cout << endl;

  return 0;
}
