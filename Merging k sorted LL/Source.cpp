//All headers are supposed to be included as on the LeetCode platform still added

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
#include<algorithm>
#include<queue>

class Solution {
public:
    std::vector<int> store;
    ListNode* start;
    std::vector<ListNode*> ptrs;
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) ;
    ListNode* make_LL(std::vector<int>& vec);

};

ListNode* Solution::make_LL(std::vector<int>& vec){  
        int size=vec.size();
        ListNode* end=new ListNode(vec[size-1]);
        ptrs.push_back(end);
        int ptr_in=0;
        for(int i=size-2;i>=0;i--){
            end=new ListNode(vec[i],ptrs[ptr_in]);
            ptrs.push_back(end);
            ptr_in++;
        }
       // delete end;
        return ptrs[ptrs.size()-1];
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {

     //priority_queue<min> heap;
        if(!lists.empty()){
        std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
     //while(..){
    for(int i=0;i<lists.size();i++){
        start=lists[i];
        if(start!=nullptr){
        while(start!=nullptr){
            heap.push(start->val);
            start=start->next;
            }
        }
    }
    while(!heap.empty()){
        store.push_back(heap.top());
        heap.pop();
    }
        if(!store.empty()){
        ListNode*start = make_LL(store);
        return start;}
            else{return nullptr;}
     //while(heap.isempty){
     //hvector.push(heap.head);
     //heap.pop();
        //}
     //}
     }
        else{return nullptr;}
    }
