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
//Iterative approach    
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

//Recursive approach
node* reverseListR(node* head) {	//O(n) approach with O(n) space used by function stack
	if (head != NULL) {
		if (head->next == NULL) {
			return head;		/*The head for the reversed list, that is stored in rhead pointer on 
								every function call stack pop and return as is.*/
		}
		node* rhead = reverseListR(head->next);
			head->next->next = head;	//Reversing pointers
			head->next = NULL;
		return rhead;	
	}
	else {
		return NULL;
	}
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
