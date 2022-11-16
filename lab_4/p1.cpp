#include <iostream>
#include <stdlib.h>

using namespace std;

void readUserData(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }
}

void removeDuplicates(int arr[], int len, int target[]) {
  int howManyInTargetArr = 0;
  int j = 0;
  for (int i = 0; i < len; i++) {
    int curr_element = arr[i];
    for (j = 0; j < len; j++) {
      if (target[j] == curr_element) {
        break;
      }
    }
    if (j == len - 1) {
      target[howManyInTargetArr] = curr_element;
      howManyInTargetArr++;
    } 
  }
}

int main() {
  int len, *tab = NULL, *tab2 = NULL;
  cout << "Ilość liczb: ";
  cin >> len;
  tab = (int*) malloc(len * sizeof(int));
  tab2 = (int*) malloc(len * sizeof(int));

  if (tab == NULL || tab2 == NULL) {
    cout << "Brak pamięci" << endl;
    return 1;
  }
  
  //Wczytujemy
  readUserData(tab, len);

  //Usuwamy duplikaty
  removeDuplicates(tab, len, tab2);
  
  for (int i = 0; i < len; i++) {
    cout << tab2[i] << " ";
  }
  
  
  return 0;
}