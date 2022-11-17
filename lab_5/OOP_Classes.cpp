#include <iostream>
#include <stdlib.h>

using namespace std;

class Player {
  public:
    int score;

    /**
     * @brief Construct a new Player object
     * 
     */
    Player() {
      this->score = 0;
    }

    /**
     * @brief Update player score with a new one
     * 
     * @param newScore 
     */
    void changeScore(int newScore) {
      this->score = newScore;
    }
};

class Coords {
  public:
    int x;
    int y;

    /**
     * @brief Construct a new Coords object
     */
    Coords() {
      this->x = 0;
      this->y = 0;
    }
    /**
     * @brief Construct a new Coords object with parameters
     * 
     * @param x_cor 
     * @param y_cor 
     */
    Coords(int x_cor, int y_cor) {
      this->x = x_cor;
      this->y = y_cor;
    }
};

class DynArray {
  public:
    int rows;
    int cols;
    int *elements;

    /**
     * @brief Construct a new Dyn Array object
     */
    DynArray() {
      this->elements = NULL;
      this->rows = 0;
      this->cols = 0;
    }

    /**
     * @brief Construct a new Dyn Array object with parameters, set initially all values to 0
     * 
     * @param rc row count
     * @param cc column count
     */
    DynArray(int rc, int cc) {
      this->elements = (int*) malloc(rc * cc * sizeof(int));
      //Check if memory has been allocated
      if (this->elements == NULL) {
        cout << "Not enough RAM" << endl;
      }
      this->rows = rc;
      this->cols = cc;

      //Set all elements to 0 when an object is created
      for (int i = 0; i < this->rows * this->cols; i++) {
        elements[i] = 0;
      }
    }

    /**
     * @brief This function allows to modify the data inside the 2D array.
     * 
     * @param pos A Coords class object, has x_cor and y_cor
     * @return int* (it's very important)
     */
    int * operator [] (Coords pos) {
      return &elements[pos.x * cols + pos.y];
    }

    /**
     * @brief Destroy the Dyn Array object and free memory block
     */
    ~DynArray() {
      free(this);
    }
};

/**
 * @brief Overloading the << operator allows to display current cursor coordinater easily
 * 
 * @param out 
 * @param pos 
 * @return ostream& 
 */
ostream& operator << (ostream& out, Coords pos) {
  out << "[x_cor, y_cor] => [" << pos.x << ", " << pos.y << "]";
  return out;
}

/**
 * @brief Function to print a square board
 * 
 * @param board 
 */
void printBoard(DynArray board) {
  for (int i = 0; i < board.rows; i++) {
    for (int j = 0; j < board.cols; j++) {
      cout << *board[{j, i}] << " ";
    }
    cout << endl;
  }
}

/**
 * @brief Example driver code to demonstrate accessing and modification data inside of my array
 * 
 * @return int 
 */
int main() {
  Coords pos;
  int boardSize;
  cout << "Size of your GO board: ";
  cin >> boardSize;
  DynArray goBoard(boardSize, boardSize);
  while (1) {
    int userInputBoardValue;
    cout << "use '0' to exit program and display your newly created GO board!" << endl;
    cout << "Now, provide coordinates [x, y] seperated by space" << endl;
    cin >> pos.x >> pos.y;
    cout << pos << endl;
    cout << "Desired value on this place: ";
    cin >> userInputBoardValue;
    if (userInputBoardValue == 0) {
      break;
    }
    *goBoard[pos] = userInputBoardValue;
  }
  printBoard(goBoard);

  return 0;
}