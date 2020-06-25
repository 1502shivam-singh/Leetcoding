#include<iostream>
#include<conio.h>
#include<string>
#include<unordered_map>

int longest_sub_string(std::string);

int main() {
	std::string string("tmmzuxt");
	std::cout << longest_sub_string(string);
	_getch();
}

int longest_sub_string(std::string string)  //Solution code
{
	int j = 0,size=0,i=0;
	char* ptr1 = &string[i];
	char* ptr2 = nullptr;
	std::unordered_map<char,int> h_table;
	while (j!=string.size()) {
		if (h_table.find(string[j]) == h_table.end()) {
			ptr2 = &string[j];
			if(j==string.size()-1){ if (((ptr2 - ptr1) + 1) >= size) { size = (ptr2 - ptr1) + 1; } }
		}
		else if((h_table.find(string[j]) != h_table.end()) && (h_table[string[j]]>=i) ) {
			if (((ptr2 - ptr1)+1) >= size) { size = (ptr2 - ptr1)+1; }
			i = h_table[string[j]] + 1;
			ptr1 = &string[i];
			ptr2 = &string[j];
			h_table.erase(string[j]);
		}
		h_table.insert({ string[j],j });
		j++;
	}
	return size;
}
