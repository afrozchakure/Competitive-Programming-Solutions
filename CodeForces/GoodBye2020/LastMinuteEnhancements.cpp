#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> n_int;
        while (n--)
        {
            int x;
            cin >> x;

            n_int.push_back(x);
        }
        set<int> s;
        // cout << "\nDifferent Number : " << endl;

        for (int i = 0; i < n_int.size(); i++)
        {
            // First Code
            if (i == 0)
            {
                s.insert(n_int[0]);
                // cout << n_int[0] << " ";
            }

            // // Last Element
            // if (i == n_int.size() - 1)
            //     break;

            // If both elments are equal
            else if (n_int[i] == n_int[i + 1])
            {
                // if the element in not in set
                if (s.find(n_int[i]) == s.end())
                {
                    // cout << n_int[i] << " ";
                    s.insert(n_int[i]);
                }
                // if element is in set
                else
                {
                    n_int[i] = n_int[i] + 1;
                    // cout << n_int[i] << " ";
                    s.insert(n_int[i]);
                }
            }

            // if both elements are not equal and element not in set
            else if (s.find(n_int[i]) != s.end())
            {
                n_int[i] = n_int[i] + 1;
                s.insert(n_int[i]);
                // cout << n_int[i] << " ";
            }

            // If elements are not equal and not in the set
            else if (s.find(n_int[i]) == s.end())
            {
                s.insert(n_int[i]);
                // cout << n_int[i] << " ";
            }

            // else if ((i + 1) == n_int.size() - 1)
            // {
            //     if (s.find(n_int[i + 1]) != s.end())
            //     {
            //         n_int[i + 1] = n_int[i + 1] + 1;
            //         s.insert(n_int[i + 1] + 1);
            //         cout << n_int[i + 1] << " ";
            //     }
            //     else if (s.find(n_int[i + 1]) == s.end())
            //     {
            //         s.insert(n_int[i + 1]);
            //         cout << n_int[i + 1] << " ";
            //     }

            //     break;
            // }
        }
        cout << s.size() << endl;
        // cout << "\n";
        // set<int>::iterator i;
        // for (i = s.begin(); i != s.end(); i++)
        //     cout << *i << " ";
    }
    return 0;
}