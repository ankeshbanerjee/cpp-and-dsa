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
// bring the last node from the end to the front k times
// TC = O(N * K) -> N for each traversal and N*K for the traversing K times
// SC = O(1)

// optimized approach ->
// point to notice -> if k == length of the list
// it returns the same list
// more specifically, if k is the multiple of the length of the list, then the list remains same
// use this property. 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases
        if (head == NULL || head->next == NULL || k==0)
            return head;

        // count the length of list
        ListNode* curr = head;
        int len = 1;
        while(curr->next){
            curr = curr->next;
            len++;
        }

        // go till that node
        curr->next = head;
        k %= len;
        for (int i=1; i<=len-k; i++)
            curr = curr->next;

        // make the node head and break connection
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
// TC = O(N) + O(N-(N % K))
// SC = O(1)