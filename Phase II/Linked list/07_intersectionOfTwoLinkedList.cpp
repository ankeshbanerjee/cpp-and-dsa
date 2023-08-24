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
// standing at each node of first list, 
// traversing through all the nodes of the second list, for each node of the first list.
// if (node1 == node2), that's the ans.
// TC = O(M*N) = O(N^2)

// optimized, but not preferred in interview, for long code length.
class Solution {
private:
    int countNodes(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = countNodes(headA);
        int cntB = countNodes(headB);
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        int diff = cntA-cntB;
        if (diff>0){
            while(diff){
                d1= d1->next;
                diff--;
            }
        }
        else{
            while (diff != 0){
                d2 = d2->next;
                diff++;
            }
        }
        while (d1 != d2){
            d1 = d1->next;
            d2 = d2->next;
        }
        return d1;
    }
};
// TC = O(N) + O(M) + O(M-N) + O(N) = O(2M)
// SC = O(1)

// optimized approach with concise code (preferred in interview)
// intuition ->
// let the diffrence of length between the two lists is 'd'.
// after the first pass, pointer of longer list(b), will stand at the node, which is at 'd' distance from the end of the list.
// when the pointer of shorter list(a) reaches NULL, point it again to the head of longer list(headB).
// now, move both forward.
// so, by the time, the pointer of longer list goes to NULL, 'a' pointer will point to the node, which is at 'd' distance from the start of the longer list.
// now, when b reaches NULL, point it again to the head of the shorter list(headA).
// as of now, both a and b is at same level. now forward both of them simultaneously and whenever both of them are equal, that is the intersection point.
// Thus, the length difference is covered by this intution.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != NULL || b != NULL){
            if (a == b) break;
            a = a==NULL ? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        return a;
    }
};
// TC = O(M) + O(M-N) + O(N) = O(2M)
// SC = O(1)

void helper(ListNode* &head){
    while(head->next){
        head = head->next;
    }
}

int main (){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    helper(head);
    cout << head->val << endl;
}