ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp-> next = prev;///here i have changed the temp->next
            prev = temp;
            temp = front;/// and here i am using the same --thats why i am getting the bad ans 
        }
        head = prev;
        return head;
    }
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 

        ListNode* newhead = reverseList(slow->next);//-> slow -> is also coneectrted to the last element of this reversed linked list means there is now any connectoin dffrenece btw the slow and the the interger after slow...only the link after the mid is reversed and we can get the new node name called newhead
        ListNode*first = head;
        ListNode*second = newhead;
        while(second != NULL){
            if(first->val != second->val){
                reverseList(newhead);// now again reeversing the liked list -> so the ogiginal data will not alter at last
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newhead);
        return true ;
        // stack<int>st;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != NULL){
        //     if(st.top() != temp->val) return false;
        //     st.pop();
        //     temp= temp->next;
        // }
        // return true;
    
    }
};