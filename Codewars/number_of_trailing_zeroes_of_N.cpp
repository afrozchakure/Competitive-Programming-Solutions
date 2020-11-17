long zeros(long n)
{
    long result{};
    int divisor = 5;
    while (n > divisor)
    {
        result += n / divisor;
        divisor *= 5;
    }
    return result;
}