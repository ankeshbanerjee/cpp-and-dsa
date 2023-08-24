#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute approach ->
// traverse the list
// store the values in a vector
// check if the vector is palindromic or not
// TC = O(N)
// SC = O(N)

// optimized approach
// find the first mid.
// reverse the rest half of the list
// compare between the two halves
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // O(N/2)
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);  // O(N/2)
        slow = slow->next;
        // O(N/2)
        while (slow){
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
// TC = O(N/2) + O(N/2) + O(N/2)
// SC = O(1)
// in this approach ->
// the last half of the list is modified.
// so, if the interviewer asks to regain the original list.
// do the same thing -> first, find the mid (O(N/2)). Then, reverse the rest half of the list (O(N/2))
// so, this will require another O(N/2) + O(N/2) time complexity