#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 250

using namespace std;

double average(int arr[]) {
  double result;
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    sum += arr[i];
  }
  return (sum*1.0)/(SIZE*1.0);
}

int howManyAboveAverage(int arr[]) {
  int count = 0;
  double avg = average(arr);
  for (int i = 0; i < SIZE; i++) {
    if (arr[i] > avg) {
      count++;
    }
  }
  return count;
}

int main() {
  const double ratings[] = {2, 3, 3.5, 4, 4.5, 5, 5.5};
  //Inicjalizacja pustej tablicy o 7 elemenach "stat"
  int results[SIZE], stat[7] = {}, i;
  srand(time(NULL));

  for (int i = 0; i < SIZE; i++) {
    results[i] = rand()%7;
  }

  //Dopisanie do każdego indeksu(oceny) odpowiadającej jej liczbie wystąpień
  for (int i = 0; i < SIZE; i++) {
    stat[results[i]]++;
  }
  
  for (int i = 0; i < 7; i++) {
    cout << ratings[i] << " => " << stat[i] << endl; 
  }

  cout << average(results) << endl;
  cout << howManyAboveAverage(results);


}