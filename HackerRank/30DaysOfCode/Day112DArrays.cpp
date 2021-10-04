#include <bits/stdc++.h>

using namespace std;

int comparator(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int sum = INT_MIN;
    int answer = INT_MIN;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            int top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            int middle = arr[i+1][j+1];
            int down = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            sum = top + middle + down;
            answer = comparator(sum, answer);
        }
        sum =0;
    }
    cout<<answer<<endl;
    return 0;
}


// Break the problem into separate pieces and then apply for loop to solve the problem :D Simple thha be
// Make sure to handle the Case when all values are negative, that is why use sum = INT_MIN and answer = INT_MIN
// See the wanted output 

/*
Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output

19

Explanation

A contains the following hourglasses:

1 1 1   1 1 0   1 0 0   0 0 0
  1       0       0       0
1 1 1   1 1 0   1 0 0   0 0 0

0 1 0   1 0 0   0 0 0   0 0 0
  1       1       0       0
0 0 2   0 2 4   2 4 4   4 4 0

1 1 1   1 1 0   1 0 0   0 0 0
  0       2       4       4
0 0 0   0 0 2   0 2 0   2 0 0

0 0 2   0 2 4   2 4 4   4 4 0
  0       0       2       0
0 0 1   0 1 2   1 2 4   2 4 0

The hourglass with the maximum sum (19) is:

2 4 4
  2
1 2 4


The above representation has 4 x 4 boxes so i and j values are between 0 to 4 and later you can work on finding the sum of 
values within the 2 for loops using top, middle and down
*/
