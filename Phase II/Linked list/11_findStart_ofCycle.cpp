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
// hash the every entire node (not only the values of the node, because values might be repeated)
// whenever you reach a node first time, which is already hashed
// that node is the start of the cycle, so return that
// TC = O(N)
// SC = O(N) (for using hashmap)

// optimized approach->
// algorithm ->
// fast and slow pointer
// after they meet, move slow and entry(which is pointed at head initially) pointer simultaneously
// whenever they meet, that is the node where the cycle starts.
// for intutition, watch the last part of the video
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* entry = head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                while(entry != slow){
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
// TC = O(N)
// SC = O(1)