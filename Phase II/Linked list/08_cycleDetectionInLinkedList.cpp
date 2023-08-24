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
// hashing the nodes
// TC = O(N)
// SC = O(N) (map)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode *temp = head;
        while(temp){
            if (visited[temp] == 1)
                return true;
            visited[temp] = 1;
            temp = temp->next;
        } 
        return false;
    }
};

// optimized
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
// TC = O(N)
// SC = O(1)