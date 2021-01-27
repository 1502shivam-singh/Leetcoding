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
        int place = 0;
    public:
        ListNode * removeNthFromEnd(ListNode * head, int n) {
            ListNode* headPtr = head;
            ListNode* tailPtr = head;
            ListNode* storeHead = head;
            while (headPtr != nullptr && place < n) {
                headPtr = headPtr -> next;
                place++;
            }
            if (headPtr != nullptr) {
                while (headPtr != nullptr) {
                    if(headPtr->next == nullptr){
                        tailPtr->next = tailPtr->next->next;
                    }
                    headPtr = headPtr -> next;
                    tailPtr = tailPtr -> next;
                }
            } else {
                storeHead = tailPtr -> next;
            }
            return storeHead;
        }

};
