class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse from left to right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* lastNodeBeforeReverse = prev;
        ListNode* tailOfReversed = curr;

        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Connect the parts
        lastNodeBeforeReverse->next = prev;
        tailOfReversed->next = curr;

        // Step 4: Return new head
        return dummy->next;
    }
};
