//All necessary headers considered included as of Leetcode platform

class Solution {
public:
    string longestPalindrome(const string& s);  //Solution function
};

string Solution::longestPalindrome(const string& s){
    int n = s.size(), ptr1=0, ptr2=0, flag=0;
	int k = 0, l = 0, e = 0, len = 0;
		for (int i = 0; i < n; i++) {
			e = s.size() - 1;
            flag=e;
			k = i; l = e;
			while (k <= e) {
				if (s[k] == s[e]) { k++, e--; }
				else {
					if (k >= i) {
						k = i;
						flag--;
						l = flag;
						e = flag;
					}
				}
			}
				if((l-i+1)>=len){
					ptr1 = i;
					ptr2 = l;
					len = l - i + 1;
				}
	}
	return s.substr(ptr1, (ptr2 - ptr1 + 1));      
}
