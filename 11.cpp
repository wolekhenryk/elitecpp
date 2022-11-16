#include <iostream>
#include <cmath>

using namespace std;
//Pole trójkąta
int main() {
  double a, b, c, p, pole;
  cin >> a >> b >> c;
  p = (a + b + c) / 2;
  pole = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << pole << endl;
  return 0;
}