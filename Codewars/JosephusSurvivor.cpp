int josephusSurvivor(int n, int k)
{
    // your code here
    int return_result = 1;
    for (int i = 1; i <= n; ++i)
    {
        return_result = (return_result + k - 1) % i + 1;
    }
    return return_result;
}