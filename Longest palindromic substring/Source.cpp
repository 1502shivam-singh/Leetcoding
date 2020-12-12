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

/*
Another neater solution using dynamic programming

Divide into smaller strings.

Reach smallest string, build up now forming a palindrome (if formed)

Map the substring (a std::pair<int,int> for start and end index) to 0 (if not palindrome) or 1 (if palindrome)

Check if the length is greater, if true replace it using the preexisting palindromes in the table 

bab + bcb = X   (Unequal palindromes won't make a palindrome)
bab + bab = 0   (Equal palindromes will make a palindrome)
So, O(n) check for comparing string

palindrome + not palidrome = X 
non palindrom + not palindrome = 0 or X

// Pseudo code
std::unordered_map<std::pair<int,int>, bool> hash;
int start = 0, end = 0
void functionLP(str, s, e)
{
    if(s != e)
    {
        functionLP(str, 0, s);
        functionLP(str, s+1, e);
    }
    else 
    {
        hash[std::pair<int,int>(s,s)] = 1;
    }
    if(hash[<0,s>]==0 && hash[<s+1,e>]==0)
    {
        // Check for palindrome in s,e
        // if yes then reassign start and end, after comparing current length
        // else let them stay unchanged, and mark this pair in hash as 0
    }
    else if(hash[<0,s>]==1 && hash[<s+1,e>]==0) // Or its opposite
    {
        hash[<s,e>] = 0;
    }
    else
    {
        // check both strings for equality (<0,s> <s,e>), 
        // mark hash 1 for this if equal and reassign strt and end (after checking length)
        // else let them stay unchanged, and mark this pair in hash as 0. 
    }   
}

call functionLP in longestPalindrome
*/
