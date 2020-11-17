class Solution
{
public:
    bool visited[1000][1000];
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        // visited = new bool[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (word[0] == board[i][j] && searchWord(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }

    bool searchWord(int i, int j, int index, vector<vector<char>> &board, string word)
    {
        // when the index reaches the word size, it means
        // all elements before it, it found a match, hence return true
        if (index == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
            return false;

        visited[i][j] = true;

        if (
            searchWord(i + 1, j, index + 1, board, word) ||
            searchWord(i - 1, j, index + 1, board, word) ||
            searchWord(i, j - 1, index + 1, board, word) ||
            searchWord(i, j + 1, index + 1, board, word))
            return true;

        visited[i][j] = false;

        return false;
    }
};
