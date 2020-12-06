#include <regex>

int countSmileys(std::vector<std::string> arr)
{
    int count = 0;
    for (auto elem : arr)
    {
        if (std::regex_match(elem, std::regex("[:;][-~]?[)D]")))
            ++count;
    }
    return count;
}