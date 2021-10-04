#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string S;
    cin >> S;
    try {
        cout<<stoi(S)<<endl;
    }
    catch(invalid_argument &e) 
    {
        cout<<"Bad String\n" ;
    }  
    // catch(out_of_range const &e)
    return 0;
}

// Learn about try - catch block in cpp language
// Need to pass the exception name along with the arguement &e
