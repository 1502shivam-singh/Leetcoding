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
    private:
        int pos = 0;
        ListNode * headPtr = nullptr;
        ListNode * storeHead = nullptr;
        ListNode * beforeDelete = nullptr;
        ListNode * afterDelete = nullptr;
        ListNode * storePtr = nullptr;
        int place = 0;
    public:
        ListNode * removeNthFromEnd(ListNode * head, int n) {
            headPtr = head;
            storeHead = head;
            recurseTraverse(head, n);
            return storeHead;
        }

        void recurseTraverse(ListNode* ptr,int n) {
            pos++;
 
            if (ptr -> next != nullptr) {
                storePtr = ptr;
                storePtr = storePtr->next;
                recurse(storePtr,n);
            } else {
                place = pos - n;
            }
            if (place != 0) {
                if (pos == place + 2) {
                    afterDelete = ptr;
                }
                if (pos == place) {
                    ptr -> next = afterDelete;
                }
            } else {
                storeHead = headPtr -> next;
            }
            pos--;
        }

};
