/**
 * BME 122 2023
 * Assignment 2
 * Group 26
 * Aaron Jumarang, Wallace Lee, John Matti, Aric Quan
*/
#include <iostream>
#include <stack>
using namespace std;


/**
 * Struct: Queen
 * Custom datatype to hold the x and y position of a Queen
*/
struct Queen {
    int x;
    int y;
};



/**
 * A function that checks if a queen at position x and y is safe from other queens
 * It copies the current stack, iterates through each queen in the stack to check if the desired
 * queen is not being attacked.
 * @param x The x position of the desired queen
 * @param y The y position of the desired queen
 * @param n The value of N
 * @param queens The current stack of queens
 * @return True if the desired queen is safe, False if the desired queen is not safe
*/
bool isSafe(int x, int y, int n, stack<Queen> &queens) {

    //Copies stack so that the main stack is not affected
    stack<Queen> temp = queens;

    //Iterates through each queen in the stack
    while(!temp.empty()) {

        //Placeholder to hold the top queen
        Queen topQueen = temp.top();

        //Checks if the current queen is in the same column of the top queen
        if (topQueen.x == x){
            return false;
        }

        //Checks if the current queen is in the same diagonal of the top queen
        else {

            //Checks the backwards diagonal (Towards top left)
            int tempX = x, tempY = y;

            //Loops until it reaches the top left corner or out of bounds
            while(tempX >= 0 && tempY >= 0){
                if(tempX == topQueen.x && tempY == topQueen.y){
                    //If the current queen is in the same diagonal of the top queen, return false
                    return false;
                }
                
                //Go back one place in the diagonal (towards top left)
                --tempX;
                --tempY;
            }

            //Checks forward diagonal (Towards top right)
            tempX = x, tempY = y;

            ///Loops until it reaches the top right corner or out of bounds
            while(tempX < n && tempY >= 0){
                //If the current queen is in the same diagonal of the top queen, return false
                if(tempX == topQueen.x && tempY == topQueen.y){
                    return false;
                }
                //Go forward one place in the diagonal (towards top right)
                ++tempX;
                --tempY;
            }

        }

        //Pops the top queen out of the stack
        temp.pop();
    }

    //If nothing fails, return true meaning the desired queen is safe
    return true;
}



/**
 * A recursive function that solves the queens positions
 * Since the function is recursive, it will use backtracking. Meaning that it will go down each row, and if a queen
 * cannot be properly placed, it will go back and go to the next position.
 * @param row The row where the queen will be placed
 * @param n The value of N
 * @param queens The current stack of queens
 * @return True if the queen is valid and can be placed, False if the placed queen is invalid
*/
bool solve(int row, int n, stack<Queen> &queens) {

    //Base Case: If the row exceeds N, that means that all queens are properly placed in each row
    if(row == n){
        return true;
    }

    //Loops through each column to check if a queen can be placed somewhere
    for( int i = 0; i < n; ++i ){

        //Checks if the queen can be placed at this current row at current column
        if(isSafe(i, row, n, queens)) {

            //Creates a temporary queen to be added to the stack
            Queen tempQueen;

            //Holds the current x,y positions
            tempQueen.x = i;
            tempQueen.y = row;

            //Pushes the queen to the stack
            queens.push(tempQueen);

            //Recursively calls the function down the rows, will return True if a valid path is found
            if(solve(row+1, n, queens)) {

                //A valid path is found
                return true;
            }

            //If no valid path cannot be found, it removes the queen from the stack
            queens.pop();
        }
    }

    //Returns false if no queen can be placed in any column
    return false;
}



/**
 * Prints the board of queens
 * @param n The value of N
 * @param queens The current stack of queens
*/
void printBoard(int n, stack<Queen> &queens) {

    //Creates a 2-D array and initialize each value to 0
    int** board = new int*[n];
    for(int i = 0; i < n; ++i){
        board[i] = new int[n];
        for(int j = 0; j < n; ++j){
            board[i][j] = 0;
        }
    }

    //Goes through the stack and places the queen to the array
    while(!queens.empty()) {
        Queen top = queens.top();
        board[top.x][top.y] = 1;
        queens.pop();
    }


    //Prints the board
    for(int i = 0; i < n; ++i){

        //Prints the ceiling
        for(int j = 0; j < n; ++j){
            cout << " ---";
        }
        cout << endl;

        //Prints the pieces
        for(int j = 0; j < n; ++j){

            //If queen is not present, print empty space
            if(board[i][j] == 0){
                cout << "|   ";
            }

            //If queen is present, print a Q
            else{
                cout << "| Q ";
            }
        }
        cout << "|" << endl;
    }

    //Prints the floor
    for(int j = 0; j < n; ++j){
        cout << " ---";
    }

    //New line
    cout << endl;
}



////////////////////////////////
///////     TEST       /////////
////////////////////////////////
int main() {

    //Asks user for a N value
    int n;
    cout << "Enter the value of N: " << endl;
    cin >> n;

    //Creates an empty stack of queens
    stack<Queen> queens;

    //Calls the solve function to check for a valid path
    if (solve(0, n, queens)){

        //If a valid path is found, print the board
        printBoard(n, queens);
    }

    //If no valid path is found, print no solutions
    else{
        cout << "There are no solutions" << endl;
    }

    return 0;
}