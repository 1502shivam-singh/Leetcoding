    #include<iostream>
    #include<cmath>
    #include<vector>
     
    int main() {
    	int num;
    	double val, ref;
    	std::vector<double> arr;
    	std::cin >> num;	//Data input
    	for (int i = 0; i<num; i++) {
    		std::cin >> val;
    		arr.push_back(val);	//Data input
    	}
    	for (int i = 0; i<num; i++) {
    		if (std::modf((arr[i]-4)/4, &ref) == 0.0) { std::cout << "YES\n"; }	//Solution uses finding fractional part of (arr[i]-4)/4 and checking whether it is zero or not
    		else { std::cout << "NO\n"; }
    	}
    }
