#include <iostream>
#include <stdlib.h>

using namespace std;

//Zamiana
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

//Sortowanie (chujowe, ale działa)
void bubblesort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

//Mediana
double calculateMeanValue(int arr[], int len) {
  if(len % 2 == 0) {
    return (arr[(len / 2) - 1] + arr[len / 2]) * 0.5;
  } else {
    return arr[(len / 2) - 1] * 1.0;
  }
}

//Program do liczenia mediany i chuj
int main() {
  //Inicjalizacja, wczytanie, alokacja pamięci
  int *tab = NULL, len;
  cin >> len;
  tab = (int*) malloc( len * sizeof(int));
  for (int i = 0; i < len; i++) {
    cin >> tab[i];
  }

  //Posortowanie tablicy
  bubblesort(tab, len);

  //Wypisanie i dowidzenia
  cout << "Mediana wynosi " << calculateMeanValue(tab, len) << endl;

  return 0;
}