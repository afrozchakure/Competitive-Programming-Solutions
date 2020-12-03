class Solution {
public:
    int titleToNumber(string s) {
        long result = 0;
	int N = s.size();
	for(int i=0; i<N; i++)
	{
	    result = result * 26 + - s[i] - '@';
	}
	return result;
    }
};

// Ascii value of '@' is 64
