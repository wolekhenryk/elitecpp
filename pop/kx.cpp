#include <iostream>

using namespace std;

int main() {
  int tab[1000], len, m;
  cin >> len;

  for (int i = 0; i < len; i++) {
    cin >> tab[i];
  }

  //Liczba operacji, które nalezy wykonac
  cin >> m;

  for (int i = 0; i < m; i++) {
    char o;
    int x1, x2;
    cin >> o >> x1;

    //Zamiana elementów tablicy x1 => x2
    int operationCount = 0;
    if (o == 'c') {
      cin >> x2;
      for (int j = 0; j < len; j++) {
        if (tab[j] == x1) {
          tab[j] = x2;
          operationCount++;
        }
      }
      cout << operationCount << endl;
    }

    //Minimalna liczba podzielna przez k (x1)
    if (o == 'n') {
      bool czyWyznaczona = false;
      int result = 2000000000;
      for (int j = 0; j < len; j++) {
        if (tab[j] % x1 == 0) {
          czyWyznaczona = true;
          if (result > tab[j]) {
            result = tab[j];
          }
        }
      }
      if (czyWyznaczona == true) {
        cout << result << endl;
      } else {
        cout << "#" << endl;
      }
    }

    //Maksymalna wartosc podtablicy
    if (o == 'm') {
      cin >> x2;
      x1--;
      x2--;
      
      //Poza tablicą z lewej lub prawej strony
      if (x1 < 0 && x2 < 0) {
        cout << "#" << endl;
      } else if (x1 > x2) {
        cout << "#" << endl;
      } else if (x1 > len && x2 > len) {
        cout << "#" << endl;
      } else {
        if (x1 < 0)
        {
          x1 = 0;
        }
        if (x2 > len)
        {
          x2 = len;
        }
        //cout << "Szukam max na przedziale [" << x1 << " " << x2 << "] Dlugosc wynosi " << len << endl;
        //Szukamy maxa
        int max_val = -2000000000;
        for (int r = x1; r <= x2; r++) {
          if (tab[r] > max_val) {
            max_val = tab[r];
          }
        }
        cout << max_val << endl;
      }
    }
  }

}