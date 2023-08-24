#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force approach ->
// TC = O(N) + O(N/2)
class Solution {
private:
    int countNodes(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int nodes = countNodes(head);
        int mid;
        mid = nodes/2 + 1;
        ListNode* temp = head;
        for (int i=1; i<mid; i++)
            temp = temp->next;
        
        return temp;
    }
};

// optimized approach -> tortoise method
// fast tortoise and slow tortoise
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// TC = O(N/2)