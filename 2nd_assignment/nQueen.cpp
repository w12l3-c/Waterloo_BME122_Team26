#include <iostream>
#include <stack>

using namespace std;

struct queen{
    int x;
    int y;
    queen(int i, int j){
        x = i;
        y = j;
    };
};

int** createboard(int** board, const int n){
    for (int i = 0; i < n; i++){
        board[i] = new int [n];
        for (int j=0; j < n; j++){
            board[i][j] = 0;
        }
    }
    return board;
}

int** resetboard(int** board, const int n){
    for (int i = 0; i < n; i++){
        for (int j=0; j < n; j++){
            board[i][j] = 0;
        }
    }
    return board;
}

void printboard(int** board, int n){
    // print the 2D array
    cout << "The board is: " << endl;
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool repeatanswer(){

}

bool check(int** &board, int n, int i, int j, stack<queen> &placement){
    
    if (!placement.empty()){
        queen tempQ = placement.top();
    }
    //cout << "Now at " << i << " & " << j << endl;

    // int i = tempQ.x;
    // int j = tempQ.y;

    // check the row
    // cout << "where row" << endl;
    for(int k = j+1; k < n; k++){
        if(board[i][k] == 1){
            // cout << "row occupied" << endl;
            return false;
        }
    }

    // check the column
    // cout << "where col" << endl;
    for(int k = i-1; k >= 0; k--){
        if(board[k][j] == 1){
            // cout << "col occupied" << endl;
            return false;
        }
    }
    
    // check the up right diagonal
    // cout << "where R diag" << endl;
    int times = i;
    int k = i;
    int l = j;
    for (int o = times; o > 0; o--){
        k -= 1;
        l += 1;
        if (k < 0 || l >= n){
            break;
        }
        if(board[k][l] == 1){
            // cout << "R diag occupied" << endl;
            return false;
        }
    }
    
    // check the up left diagonal
    // cout << "where L diag" << endl;
    k = i;
    l = j;
    for(int o = times; o > 0; o--){
        k -= 1;
        l -= 1;
        if (k < 0 || l < 0){
            break;
        }
        if(board[k][l] == 1){
            // cout << "L diag occupied" << endl;
            return false;
        }
    }

    return true;
}

bool nQueenRecur(int** &board, int i, int jnot, int n, stack<queen> &placement){
    if (i == n){
        return true;
    }
    for (int j=jnot; j < n; j++){
        if (check(board, n, i, j, placement)){
            queen Q = queen(i, j);
            placement.push(Q);
            // cout << "Queen place at " << j << " & " << i << endl;
            // cout << "push success" << endl;
            board[i][j] = 1;
            // printboard(board, n);

            if (nQueenRecur(board, i+1, 0, n, placement)){
                return true;
            }
            
            // cout << "Queen remove at " << j << " & " << i << endl;
            board[i][j] = 0;
            placement.pop();
        }
    }
    return false;
}

void emptyPlacement(stack<queen> &placement){
    while(!placement.empty()){
        placement.pop();
    }
}

bool comparePlacement(){

}

void nQueen(int num){
    stack<queen> placement; // store the placement of the queens only for column as each row should have 1 queen
    stack<stack<queen>> solutions;
    int** board = new int* [num];
    board = createboard(board, num);
    int counter = 1;
    bool hasqueen = false;
    int a = 1;
    int b = 0;

    for(int j=0; j<num; j++){
        if (nQueenRecur(board, 0, j, num, placement) == false){
            cout << "No solutions" << endl;
        }
        else {
            solutions.push(placement);
            emptyPlacement(placement);
            cout << endl << "After placing the queens: " << endl;
            printboard(board, num);
            board = resetboard(board, num);
        }
    }
    cout << "No solutions" << endl;

    return;
}

int main(){
    int n = 0;
    
    cout << "Please enter the n number of queens in the nxn board: ";
    cin >> n;
    cout << endl;
    nQueen(n);

    return 0;
}
//    0 1 2 3 4 5 6 7
// 0: 0 0 0 0 0 0 0 0 
// 1: 0 0 0 0 0 0 0 0 
// 2: 0 0 0 0 0 0 0 0
// 3: 0 0 0 0 0 0 0 0
// 4: 0 0 0 0 1 0 0 0
