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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Add the first node of every linked list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to result
            current->next = smallest;
            current = current->next;

            // Add next node from same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};