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
        ListNode * removeNthFromEnd(ListNode * head, int n) {
            ListNode * ptr = head;
            ListNode * storeHead = head;
            int pos = 0;

            while (ptr != nullptr) {
                ptr = ptr - > next;
                pos++;
            }

            int place = pos - n;
            pos = 0;

            if (place != 0) {
                ListNode * beforeDelete = nullptr;
                ListNode * afterDelete = nullptr;
                while (head != nullptr) {
                    pos++;
                    if (pos == place) {
                        beforeDelete = head;
                    }
                    if (pos == place + 2) {
                        afterDelete = head;
                    }
                    head = head - > next;
                }

                beforeDelete - > next = afterDelete;
            } else {
                storeHead = storeHead - > next;
            }
            return storeHead;

        }
};
