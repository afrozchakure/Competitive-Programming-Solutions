#include <string>
using namespace std;

std::string rot13(std::string source)
{
    std::string transformed;
    for (size_t i = 0; i < source.size(); ++i)
    {
        if (isalpha(source[i]))
        {
            if ((tolower(source[i]) - 'a') < 13)
            {
                transformed.append(1, source[i] + 13);
            }
            else
            {
                transformed.append(1, source[i] - 13);
            }
        }
        else
        {
            transformed.append(1, source[i]);
        }
    }
    return transformed;
}