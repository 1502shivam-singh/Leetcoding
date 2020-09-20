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
    
    //Faster solution in linear time and constant space
    
ListNode* reverseList(ListNode* head) {   //Solution function
    if(head != nullptr){ 
        ListNode* h1 = nullptr;
        ListNode* sh = head;
        ListNode* node = sh->next;
        while(node!=nullptr){
            sh->next = h1;
            h1 = sh;
            sh =node;
            node = node->next;
        }
        sh->next = h1;
        return sh;
     }
    else{return nullptr;}
}
    
   /* Slower brute force approach
   
    void exchange(ListNode* ptr1, ListNode* ptr2){
        int hold = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = hold;
    }
    
    ListNode* reverseList(ListNode* head) {   //Solution function
        if(head != nullptr){
        ListNode* startHold = head;
        int size = 0;
        while(startHold != nullptr){
            size++;
            startHold=startHold->next;
        }
        startHold = head;
        
        while(size>0){
            ListNode* Hold2 = startHold;
            for(int i=0;i<size-1;i++){
                Hold2 = Hold2->next;
            }
            exchange(startHold, Hold2);
            size-=2;
            startHold = startHold->next;
        }
        return head;
        }
        else{return nullptr;}
    }*/
};
