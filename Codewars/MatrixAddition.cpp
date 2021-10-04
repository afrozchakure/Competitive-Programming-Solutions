std::vector<std::vector<int>> matrixAddition(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b)
{
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            a[i][j] += b[i][j];
    return a;
}