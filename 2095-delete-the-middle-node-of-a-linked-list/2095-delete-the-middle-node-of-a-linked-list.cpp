// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         // Edge case: only one node
//         if (!head || !head->next) return nullptr;

//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = nullptr;

//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // Delete middle node
//         prev->next = slow->next;

//         return head;
//     }
// };


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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) ++len;

        if (len / 2 == 0) return head->next;
        
        ListNode* p = head;
        for (int i = 0; i < len / 2 - 1; ++i) p = p->next;

        p->next = p->next->next;
        return head;
    }
};