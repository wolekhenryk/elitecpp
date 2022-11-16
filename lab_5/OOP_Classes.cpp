#include <iostream>

using namespace std;

class Matrix {
  public:
    int a, b, c, d;
  
  /**
   * @brief We can create an empty matrix, or assign it values
   * 
   * @param param_11 
   * @param param_12 
   * @param param_21 
   * @param param_22 
   */
  Matrix(int param_11, int param_12, int param_21, int param_22) {
    this->a = param_11;
    this->b = param_12;
    this->c = param_21;
    this->d = param_22;
  }

  /**
   * @brief Empty matrix - default constructor
   * 
   */
  Matrix() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->d = 0;
  }

  /**
   * @brief Calculate determinant of a given matrix
   * 
   * @return int 
   */
  int calcDet() {
    return (this->a * this->d) - (this->b * this->c);
  }

  /**
   * @brief Multiply matrix by a constant number
   * 
   * @param n 
   */
  void constMult(int n) {
    this->a *= n;
    this->b *= n;
    this->c *= n;
    this->d *= n;
  }

  /**
   * @brief Adding two matrices
   * 
   * @param newMatrix 
   * @return Matrix 
   */

  Matrix operator + (Matrix newMatrix) {
    Matrix res(this->a + newMatrix.a, this->b + newMatrix.b, this->c + newMatrix.c, this->d + newMatrix.d);
    return res;
  }

  /**
   * @brief Multiply two matrices 2x2
   * 
   * @param newMatrix 
   * @return Matrix 
   */
  Matrix operator * (Matrix newMatrix) {
    int c_11 = (this->a * newMatrix.a) + (this->b * newMatrix.c);
    int c_12 = (this->a * newMatrix.b) + (this->b * newMatrix.d);
    int c_21 = (this->c * newMatrix.a) + (this->d * newMatrix.c);
    int c_22 = (this->c * newMatrix.b) + (this->d * newMatrix.d);

    //Create new matrix
    Matrix res(c_11, c_12, c_21, c_22);
    return res;
  }
};

/**
 * @brief 
 * 
 * @param out 
 * @param m2 
 * @return ostream& 
 */
ostream& operator << (ostream& out, Matrix m2) {
  return out << "[" << m2.a << " " << m2.b << "]\n[" << m2.c << " " << m2.d << "]" << endl;
}

int main() {
  Matrix m1(1, 5, 8, 6), m2(8, 9, 4, 6);
  cout << m1 * m2;
}