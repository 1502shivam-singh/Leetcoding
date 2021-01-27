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

//  make distace between headPtr and tailPtr equal to n (in case in creating this distance the pointer nulls, iterate till node is not nullptr)
//  if headPtr is not null, move both tail and head untill head is null. When head is at null, you are the nth pos from end
//   when headPtr->next is null make, tailPtr->next = tailPtr->next->next;

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
