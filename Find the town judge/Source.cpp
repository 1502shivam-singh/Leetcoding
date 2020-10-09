class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0 && N>1){
            return -1;  //Exit if array empty and more than 1 people in town
        }
        
        unordered_map<int, pair<int,int>> map; 
        int change=0, Tperson=1;
        for(int i=0;i<trust.size();i++){
            map[trust[i][1]].first++;
            map[trust[i][0]].second++;
        }
        for(int i=1;i<=N;i++){
            if(map[i].first==N-1 && map[i].second==0){
                change++;
                Tperson = i;
            }
        }
        if(change==1){
            return Tperson;
        }
        else{
            return -1;
        }
    }
};
