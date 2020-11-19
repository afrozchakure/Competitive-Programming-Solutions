#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> puzzle(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> puzzle[i];
    }

    sort(puzzle.begin(), puzzle.end());
    int min_count = puzzle[m - 1] - puzzle[0];

    for (int k = 0; k <= (m - n); k++)
    {
        if (min_count > (puzzle[n + k - 1] - puzzle[k]))
            min_count = puzzle[n + k - 1] - puzzle[k];
        cout << min_count << endl;
    }
    cout << min_count << endl;
    return 0;
}