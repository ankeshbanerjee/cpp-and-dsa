#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force ->
class Solution {
private:
    int countNodes (ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL)
            return NULL;
        int nodes = countNodes(head);
        // deleting the head
        if (nodes == n)
            return head->next;
        ListNode* temp = head;
        int cnt = 1;
        while(cnt != nodes-n){
            temp = temp->next;
            cnt++;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        nodeToDelete->next = NULL;
        delete(nodeToDelete);
        return head;
    }
};
// TC = O(N) + O(N)
// SC = O(1)

// optimized approach ->
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        for (int i=1; i<=n; i++)
            fast = fast->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDel = slow->next;
        slow->next = slow->next->next;
        nodeToDel->next = NULL;
        delete(nodeToDel);
        return start->next;
    }
};