#include <iostream>
#include <vector>

using namespace std;

// Function to display the game board
void displayBoard(vector<vector<char>>& board) {
  cout << "---------  " << endl;
  for (int i = 0; i < 3; i++) {
    cout << "|";
    for (int j = 0; j < 3; j++) {
      cout << " " << board[i][j] << " |";
    }
    cout << endl << "---------  " << endl;
  }
}

// Function to check if a player has won
bool checkWin(vector<vector<char>>& board, char player) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

// Function to check if the game is a draw
bool checkDraw(vector<vector<char>>& board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

// Function to get player's move
void getPlayerMove(vector<vector<char>>& board, char player) {
  int row, col;

  cout << "Player " << player << ", enter your move (row <spacebar> col): ";
  cin >> row >> col;

  // Check if the move is valid
  if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
    cout << "Invalid move. Please try again." << endl;
    getPlayerMove(board, player);
    return;
  }

  board[row - 1][col - 1] = player;
}

int main() {
  // Initialize the game board
  vector<vector<char>> board(3, vector<char>(3, ' '));

  // Set the current player
  char currentPlayer = 'X';

  // Game loop
  while (true) {
    // Display the board
    displayBoard(board);

    // Get the player's move
    getPlayerMove(board, currentPlayer);

    // Check for win
    if (checkWin(board, currentPlayer)) {
      displayBoard(board);
      cout << "Player " << currentPlayer << " wins!" << endl;
      break;
    }

    // Check for draw
    if (checkDraw(board)) {
      displayBoard(board);
      cout << "It's a draw!" << endl;
      break;
    }

    // Switch players
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  return 0;
}