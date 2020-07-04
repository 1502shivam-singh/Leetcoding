//All header files considered added as on the Leetcode platform
class Solution {
private:
    int check=0;
public:
    bool checkPossibility(vector<int>& nums);       //Solution function definition below 
};

bool Solution::checkPossibility(vector<int>& nums) {    //Function definition
        for(int i=0;i<nums.size()-1;i++){
            if(!(nums[i]<=nums[i+1])){
                if(i>0){
                    if(nums[i+1]>=nums[i-1]){
                        nums[i]=nums[i-1];
                        check++;
                    }
                    else{
                        nums[i+1]=nums[i];
                        check++;
                    }
                }
                else{nums[i]=nums[i+1];check++;}
            }
        }
  if(check>1){return false;}
  else{return true;}
}
