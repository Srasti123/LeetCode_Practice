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
// Function to reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}
// Check if the list is palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    // Step 1: Find the middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Step 2: Reverse second half
    ListNode* secondHalf = reverse(slow->next);
    // Step 3: Compare first and second halves
    ListNode* firstHalf = head;
    ListNode* second = secondHalf;
    while (second) {
        if (firstHalf->val != second->val)
            return false;
        firstHalf = firstHalf->next;
        second = second->next;
    }
    return true;
}
};
