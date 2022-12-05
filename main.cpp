// Devin Hill
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 50;
void print_array(int num[], int size, int small);

int main() {
  int count = 0;
  int num[MAX];
  int line = 0;
  ifstream myfile ("final.txt");
  int small = 999999;
  
  if (myfile.is_open()){
    
    while (myfile >> line){
      num[count] = line;
      count++;
      if((line < small) && (line % 2 != 0)){
      small = line;
        }
    }
    myfile.close();
  }
  else {
  cout << "Unable to open file"; 
    }

  cout << endl;
  cout << endl;
  
  cout << "The smallest odd integer is " << small << endl;
  cout << "Subtracting " << small << " from all the integers results in the array" << endl;
    print_array(num, count, small);
}

void print_array(int num[], int size, int small){
  cout << "     ";
  for (int i = 0; i < size - 1; i++){
    num[i] = num[i] - small;
    cout << num[i] << " ";
  }
}


