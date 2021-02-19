class Solution {
public:
    string convert(string& s, int numRows) {
        if (s.size() == numRows || numRows == 1) {
			return s;
		}
        string zig("");
        int r = numRows;
        int j = 0, iter = 0;
        
        for(int i=0;i<numRows;i++){
        j=i;    // 1
        iter = 0;
        r = numRows-i;  // 2
        if(j<s.size()){
            zig+=s[j];   
        }
        while(j<s.size()){ // while j is not out of bounds
            if(i == 0 || i== numRows-1){
                // Up and Up
                j += (numRows-1) + (numRows-2) + 1;
                if(j<s.size()){
                    zig+=s[j];   
                }
            }
            else{
                if(iter%2 == 0){
                    // Up we go   
                    j += (r-1)+(r-2)+1; // 7 (2)
                    if(j<s.size()){
                        zig+=s[j];
                    }
                }else{
                    // Down we go
                    j += i+(i-1)+1; // 9 (2)
                    if(j<s.size()){
                        zig+=s[j];   
                    }
                }
            }
            iter++;
        }
        }     
    return zig;
    }
};


/*

ABCDEF, 3 

A E  
BDF
C

[A][1][E]
[B][D][F]
[C][1][1]

PAYPALISHIRING - 14
[P][1][A][1][H][1][N]   //  3+1 interval
[A][P][L][S][I][I][G]   //  1+1
[Y][1][I][1][R][1][1]   //  3+1

blocks - 21

3 => 1
4 => 2
n => n-2

index + [(r-1) + (r-2) + 1]
    
[P][0][0][0][0][R]    // 9+1
[A][0][0][0][I][I]    // 7+1
[Y][0][0][H][0][N]    // 
[P][0][S][0][0][G]
[A][I][0][0][0][0]
[L][0][0][0][0][0]

for(i:r){
    j=i;
    r = numRows - i;
    if(j<s.size()){
      zig+=s[j];   
    }
    for(j:inf){ // while j is not out of bounds
        if(j == 0 || j== r-1){
            // Up and Up
            // j + [(r-1) + (r-2) + 1];
        }
        else{
            if(j%2 == 0){
                // Up we go   
                j + [(r-1)+(r-2)+1];
            }else{
                // Down we go
                j + [i+(i-1)+1];
            }
        }
    }
}


*/

