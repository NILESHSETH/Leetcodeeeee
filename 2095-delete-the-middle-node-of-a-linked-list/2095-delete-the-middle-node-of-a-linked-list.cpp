class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        if(head == NULL || head->next == NULL) return NULL;
        while (fast != NULL && fast->next != NULL) {
            prev= slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev-> next = prev->next->next;
    
        return head;

    }
};