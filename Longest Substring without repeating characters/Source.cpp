//All headers necessary are already considered included as in the leetcode platform

class Solution {
private:
	std::unordered_map<char,int> h_table;
public:
    int lengthOfLongestSubstring(const string& s);  //Solution function
    int maxoff(int,int);
};

int Solution::maxoff(int a, int b)
{
	return a >= b ? a : b;
}

int Solution::lengthOfLongestSubstring(const string& s) {
	int size = s.size(),j=0,i=0,len=0;
	while (j!=size)
	{
		if (h_table.find(s[j]) != h_table.end()) {
			i = maxoff(i, h_table[s[j]]);
			h_table.erase(s[j]);
		}
		len = maxoff(len, j - i + 1);
		h_table.insert({ s[j],j + 1 });
		j++;
	}
	return len;
}
