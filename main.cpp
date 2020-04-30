
#include <string>
#include <sstream>
#include "Sorts.h"
#include "Searches.h"
using namespace std;

vector<string> split(const string& s, char delimiter);

int main(int argc, char** argv){
  int i, num, a;
  vector<int> result;
  string input;
  vector<string> str;
  vector<int> intTest;
  cout << "Please type in a list of numbers you want to search in or sort. (Please seperate each number by a ','. You can have spaces or no spaces." << endl;
  getline(cin, input);
  cout << endl;
 
  str = split(input, ',');

  for(i = 0; (unsigned int)i < str.size(); i++){
    int size = atoi(str.at(i).c_str());
    intTest.push_back(size);
  }

  cout << "Please select which sort or search you want." << endl;
  cout << "1. Linear Search" << endl;
  cout << "2. Binary Search" << endl;
  cout << "3. Merge Sort" << endl;
  cout << "4. Quick Sort" << endl;
  while(num != 1 && num != 2 && num != 3 && num != 4){
    cin >> num;
    cout << endl;
    if(num != 1 && num != 2 && num != 3 && num != 4){
      cout << "Please use 1, 2, 3, or 4." << endl;
    }
  }
  
  if(num == 1 || num == 2){
    cout << "Please select what number you want to search for." << endl;
    cin >> num;
    if (num == 1){
      a = linearSearch(intTest, num);
    }
    else{
      a = binarySearch(intTest, num);
    }
    if(a != -1){
      cout << "First instance of number was found to be in index: " << a + 1 << endl << endl;
    }
    else{
      cout << "Number was not found" << endl << endl;
    }
  }
  else if(num == 3 || num == 4){
    if(num == 3){
      result = mergeSort(intTest);
    }
    else{
      result = quickSort(intTest);
    }
    cout << "Resuting list:" << endl;
    for(i = 0; (unsigned int) i < result.size(); i++){
      if(((unsigned int) i + 1) == result.size()){
        cout << result[i];
      }
      else{
        cout << result[i] << ", ";
      }
    }
    cout << endl;
  }

  return 0;
}

// Splits a string on a delimiter
vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
