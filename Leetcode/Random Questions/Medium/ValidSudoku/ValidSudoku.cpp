// Follow the java solution

// Short solution in CPP
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[3][3][9] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int number = board[i][j] - '1';
                    if (rows[number][j]++)
                        return 0;
                    if (cols[i][number]++)
                        return 0;
                    if (blocks[i / 3][j / 3][number]++)
                        return false;
                }
            }
        }
        return true;
    }
};

// Time Complexity - O(n) -> iterating over the entire board
// Space Complexity - O(n) -> using arrays to store value

// Long Solution in CPP
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows = 9;
        int cols = 9;
        for (int i = 0; i < rows; i++)
        {
            int res1 = valid_rows(i, board);
            int res2 = valid_cols(i, board);
            if (res1 < 1 || res2 < 1)
                return false;
        }
        int res3 = valid_subsquares(board);
        if (res3 < 1)
            return false;
        return true;
    }
    int valid_rows(int rows, vector<vector<char>> &board)
    {
        set<int> s;
        for (int i = 0; i < 9; i++)
        {
            // To check if value is between 1 and 9
            if ((board[rows][i] < '1' || board[rows][i] > '9') && board[rows][i] != '.')
            {
                cout << "Value outside 0 and 9 in rows" << endl;
                return -1;
            }

            // Check for duplicate values
            else
            {
                if (board[rows][i] != '.')
                {
                    if (s.insert(board[rows][i]).second == false)
                    {
                        cout << "Duplicate values in rows" << endl;
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    int valid_cols(int cols, vector<vector<char>> &board)
    {
        set<int> s;
        for (int i = 0; i < 9; i++)
        {
            if ((board[i][cols] < '1' || board[i][cols] > '9') && board[i][cols] != '.')
            {
                cout << "Value outside 0 and 9 in cols" << endl;
                return -1;
            }
            else
            {
                if (board[i][cols] != '.')
                {
                    if (s.insert(board[i][cols]).second == false)
                    {
                        cout << "Same element in cols" << endl;
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    int valid_subsquares(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i = i + 3)
        {
            for (int j = 0; j < 9; j = j + 3)
            {
                set<int> s;
                for (int r = i; r < i + 3; r++)
                {
                    for (int c = j; c < j + 3; c++)
                    {
                        if ((board[r][c] < '1' || board[r][c] > '9') && board[r][c] != '.')
                        {
                            cout << "Value outside 0 and 9 in subsquares" << endl;
                            return -1;
                        }
                        // Check for duplicate elements
                        else
                        {
                            if (board[r][c] != '.')
                            {
                                if (s.insert(board[r][c]).second == false)
                                {
                                    cout << "Same element in subsquares" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
};
