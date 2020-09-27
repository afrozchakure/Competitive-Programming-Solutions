#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int day_actual, month_actual, year_actual;
    int day_expected, month_expected, year_expected;

    cin>> day_actual >> month_actual >> year_actual;
    cin>> day_expected >> month_expected >> year_expected;
    int fine = 0;

    // Returned after the due day 
    if(day_actual > day_expected && month_actual == month_expected && year_actual == year_expected)
    {
        fine = 15 * (day_actual - day_expected);
    }

    // Returned after the due month
    else if(month_actual > month_expected && year_actual == year_expected)
    {
        fine = 500 * (month_actual - month_expected);
    }

    // Returned after the due year
    else if(year_actual > year_expected)
    {
        fine = 10000;
    }

    // When fine is 0
    else
    {
        fine = 0;
    }
    cout<<fine<<endl;


    return 0;
}
