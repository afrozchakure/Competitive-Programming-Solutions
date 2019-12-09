/*
A jail has a number of prisoners and a number of treats to pass out to them. 
Their jailer decides the fairest way to divide the treats is to seat the prisoners 
around a circular table in sequentially numbered chairs. A chair number will be drawn from a hat. 
Beginning with the prisoner in that chair, one candy will be handed to each prisoner sequentially 
around the table until all have been distributed.

The jailer is playing a little joke, though. The last piece of candy looks like all the others, 
but it tastes awful. Determine the chair number occupied by the prisoner who will receive that candy.

For example, there are 4 prisoners and 6 pieces of candy. The prisoners arrange themselves in seats 
numbered 1 to 4. Let's suppose two is drawn from the hat. Prisoners receive candy at positions 2,3,4,1,2,3. 
The prisoner to be warned sits in chair number 3. 

Function Description

Complete the saveThePrisoner function in the editor below. 
It should return an integer representing the chair number of the prisoner to warn.

saveThePrisoner has the following parameter(s):

    n: an integer, the number of prisoners
    m: an integer, the number of sweets
    s: an integer, the chair number to begin passing out sweets from

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {

// n: an integer, the number of prisoners
// m: an integer, the number of sweets
// s: an integer, the chair number to begin passing out sweets from

    // Method - 1

    int i;
    i = ((m % n) + (s - 1))%n;
    if(i == 0)
    {
        return n;
    }
    return i;

/*
    Method - 2

    int count = 0;
    int i = s;
    while(count != m)
    {
        for(; i<=n; i++)
        {
            cout<<i<<"\n";
            count ++;
                if(i == n && count != m)
                {
                    i = 0;
                }
                if(count == m)
                {
                    return i;
                    break;
                }
        }
        cout<<"\n\n";
    
    }
*/
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);  

        int m = stoi(nms[1]);  // No. of sweets

        int s = stoi(nms[2]);  // Chair no. to begin passing out sweets from

        int result = saveThePrisoner(n, m, s);  

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
Output Format
For each test case, print the chair number of the prisoner who receives 
the awful treat on a new line.

Sample Input 0
2
5 2 1
5 2 2

Sample Output 0
2
3

Explanation 0
In first query, there are n = 5 prisoners and m = 2 sweets. Distribution starts at seat number s=1. 
Prisoners in seats numbere 1 and 2 get sweets. Warn prisoner 2.
In the second query, distribution starts at seat 2 so prisoners in seats 2 and 3 get sweets. Warn prisoner 3.

Sample Input 1
2
7 19 2
3 7 3

Sample Output 1
6
3

Explanation 1
In the first test case, there are n = 7 prisoners, m = 19 sweets and they 
are passed out starting at chair s = 2. The candies go all around twice and 
there are 5 more candies passed to each prisoner from seat 2 to seat 6.

In the second test case, there are n = 3 prisoners, m = 7 candies and they are passed out starting at seat s=3. 
They go around twice, and there is one more to pass out to the prisoner at seat 3. 
*/