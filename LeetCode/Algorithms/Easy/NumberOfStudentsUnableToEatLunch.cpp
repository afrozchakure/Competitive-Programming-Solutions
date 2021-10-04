class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int count = students.size();
        int size = 0;
        while (students.size())
        {
            if (students.front() == sandwiches.front())
            {
                sandwiches.erase(sandwiches.begin());
                students.erase(students.begin());
                count--;
            }
            else
            {
                int first = students.front();
                students.erase(students.begin());
                students.push_back(first);
                size++;
            }

            if (size >= 1000)
            {
                return count;
            }
        }
        return count;
    }
};