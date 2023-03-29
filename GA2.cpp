#include <iostream>
#include <cstdlib>
#include <stack>


using namespace std;

const int maximum = 100;
int N;
int b[maximum][maximum];
struct possible{
    int x;
    int y;
};
stack<possible> solutions;

void print()
{
    for (int i = 0; i< N; i++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << b[i][x] << " ";
        }
        cout << endl;
    }
}


//check to determine if position is valid
bool good (int row, int coln)
{
    int temp1, temp2 = 0;
    //column and rows
    for (int i = 0; i < N; i++)
    {
        //check column
        if (b[i][coln] == 1)
        {
            return false;
        }
        // //check row
        // if (b[row][i] == 1)
        // {
        //     temp2 ++;
        //     if (temp2 == 2)
        //     {
        //         cout << "row error" << endl;
        //         return false;
        //     }
        // }
    }

    //check diagonals
    for (int i = row -1, l = coln -1; i >= 0 && l >=0 -1; i--,l--)
    {  
        //diagonal up and to the left
        if (b[i][l] == 1)
        {
            cout << "upper left error" << endl;
            return false;
        }
    }

    // for (int i = row +1, l = coln +1; i, l < N; i++,l++ )
    // {  
    //     //diagonal down and to the right
    //     if (b[i][l])
    //     {
    //         cout << "lower right error" << endl;
    //         return false;
    //     }
    // }

    for (int i = row -1, l = coln +1; l < N && i >= 0; i--,l++)
    {  
        //diagonal up and to the right
        if (b[i][l] == 1)
        {
            cout << "upper right error" << endl;
            return false;
        }
    }

    // for (int i = row +1, l = coln -1; i < N, l != -1; l--,i++ )
    // {  
    //     //diagonal down and to the left
    //     if (b[i][l])
    //     {
    //         cout << "lower left error" << endl;
    //         return false;
    //     }
    // }

    //all conditions are met
    return true;
}

bool solve(int row, int n)
{

    //base case 1; we have a solution
    if (row == n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        // print();
        //cout << " " << endl;
        //print();
        //cout << good(row, i) << endl;
        //cout << row << i << endl;
        // cout << "" << endl;

        if (good(row, i))
        {
            b[row][i] = 1;
            possible temp;
            temp.x = row;
            temp.y = i;
            solutions.push(temp);
            if (solve(row+1, n))
            {
                // cout << "try successful" << endl;
                return true;
            }
            else
            {
                solutions.pop();
            }
            
        }
        b[row][i] = 0;
    }
 
    return false;

}

int getValue(int **&y)
{
    return y[0][0];
}
int main ()
{
    // int ** i = new int*[10];
    // for (int n = 0; n < 10; n++)
    // {
    //     i[n] = new int [10];
    // }
    // i[0][0] = 1;
    // cout << i[0][0] << endl;
    // cout << getValue(i);
    
    cout << "Please enter the size NxN of the chess board you would like: ";
    cin >> N;

    for(int i = 0; i < maximum; ++i){
        for(int j = 0; j < maximum; ++j){
            b[i][j] = 0;
        }
    }
    
    if (solve(0,N))
    {
        cout << "Here is the solution:" << endl;
        print();
    }
    else{
        cout << "There are no solutions for this code" << endl;
        return -1;
    }

    


    return 0;
}

