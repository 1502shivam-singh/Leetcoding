//All headers are supposed to be included as on the LeetCode platform 

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<int> store;
        int pos_LL=0;
     //priority_queue<min> heap;
        std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
     //while(..){
        while(){    //condition to update
            for(int i=0;i<lists.size(),i++){
                if(unfunction(lists[i],pos_LL)!=NULL){
                heap.push(unfunction(lists[i],pos_LL));}
            }
            while(!heap.empty()){
                store.push_back(heap.head);
                heap.pop();
            }
            pos_LL++;
        }
        ListNode*start = make_LL(store);
        return start
     //loop .. k times{
      //  store.push(unfunction(listNode[i]->val,pos_LL));
       // }
     //while(heap.isempty){
     //hvector.push(heap.head);
     //heap.pop();
        //}
     //}
     
    }
    
    ListNode* make_LL(std::vector<int>& vec);{
        std::vector<ListNode*> ptrs;
        int size=vec.size();
        ListNode end=ListNode(vec[size-1]);
        ptrs.push_back(&end);
        int ptr_in=0;
        for(int i=size-2;i>=0;i--){
            end=ListNode(vec[i],ptrs[ptr_in]);
            ptrs.push_back(&end);
            ptr_in++;
        }
        return ptrs[ptrs.size()-1];
    }
    
    int unfunction(ListNode* node,int pos){
        int value;
        for(int i=0;i<=pos;i++){
            if(node!=nullptr){
            value=node->val;
            node=node->next;}
            else value=NULL;
        }
        return value;
    }
};
