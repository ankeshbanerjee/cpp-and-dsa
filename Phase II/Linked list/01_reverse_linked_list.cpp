#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive code
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode * rightHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rightHead;
    }
};
// TC = O(N)
// SC = O(N)

// iterative soln.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
};
// TC = O(N)
// SC = O(1)