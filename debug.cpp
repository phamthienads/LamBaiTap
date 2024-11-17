// Debugging1.cpp : This file contains syntax errors and has an additional issue.
// It also has no comments. You need to fix the errors and add comments
// Also make sure to test it more than once.
#include <iostream>
#include <ctime>

using namespace std; // Thiếu ;

int main(){

  srand(time(0)); // Thiếu )
  
  string prizes[] = { "coin", "wand", "compass", "map", "key" }; // Thay '' thành "
  
  int rand_num = rand() % 5; // Thay 6 thành 5 vì mảng prizes có 5 phần tử
  
  cout << "Congratulations! You have won a " << prizes[rand_num] << endl;

}
