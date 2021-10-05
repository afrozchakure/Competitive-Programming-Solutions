int solution(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 3; i++)
    {
        if (3 * i < number)
            sum += 3 * i;
        if (5 * i < number)
            sum += 5 * i;
        if (15 * i < number)
            sum -= 15 * i;
    }
    return sum;
}