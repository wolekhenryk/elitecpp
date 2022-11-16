#include <iostream>

using namespace std;

int main() {
  int userInput, prev;
  cin >> userInput;
  while (1){
    prev = userInput;
    cin >> userInput;
    if (prev == userInput) {
      break;
    }
  }
  
  
  return 0;
}