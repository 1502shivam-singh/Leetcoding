class Solution {
public:
    stack<char> brackets;
    
    bool isValid(string s) {
        for(auto i:s){
            if(i=='[' || (i=='('|| i=='{' )){
                brackets.push(i);
            }
            else if(i=='}' && (!brackets.empty() && brackets.top() == '{')){
                       brackets.pop();
            }
            else if(i==')' && (!brackets.empty() && brackets.top() == '(')){
                       brackets.pop();
            }
            else if(i==']' && (!brackets.empty() && brackets.top() == '[')){
                brackets.pop(); 
            }
            else{
                brackets.push(i);
            }
        }
        if(brackets.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
