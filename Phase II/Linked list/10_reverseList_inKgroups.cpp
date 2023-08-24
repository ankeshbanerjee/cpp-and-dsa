#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive soln.
// approach -> reverse first k nodes
// get the result of the rest of list through recursion
class Solution {
private:
    int countNodes (ListNode* head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseHelper(ListNode* head, int k, int nodes){
        // base case
        if (head == NULL || nodes < k)
            return head;

        // reverse first k nodes
        int cnt = 0;
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL && cnt != k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // call recursion
        head->next = reverseHelper(curr, k, nodes-k);
        
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = countNodes(head);
        return reverseHelper(head, k, count);
    }
};
// TC = O(N/K)(number of recursion calls) * O(K)(reverse list) = O(N)
// SC = O(N/K)(number of recursion calls).


// removing the extra space ->
// using iterative approach
// this method is really a pointer complex problem and one of the toughest linked list problems

// few points to note to understand->
// pre->next always points to the current node
// cur points to the head of each group before reversing, and after reversing, it becomes the tail of the group
// nex points to the next of current node (nex = pre->next->next)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy, *cur = NULL, *nex = NULL;
        // count nodes
        int count = 0;
        cur = head;
        while(cur){
            cur = cur->next;
            count++;
        }

        while(count >= k){
            cur = pre->next;
            nex = cur->next;
            // reversing k-1 times
            for (int i=1; i<k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }

        return dummy->next;
    }
};
// TC = O(N/k) * O(K) = O(N)
// SC = O(1)