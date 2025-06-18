
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr!=nullptr){
            ListNode* next = curr->next; // store next 
            curr->next = prev; //reverse current node pointer
            prev = curr;  // move prev ahead
            curr = next;  // move curr ahead
        }
        return prev;
    }

};