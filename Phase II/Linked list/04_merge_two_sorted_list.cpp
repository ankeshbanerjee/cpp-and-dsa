#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute approach -> this methods creates a new list
// TC = O(N1 + N2)
// SC = O(N1 + N2) (new list)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* newHead = ans;
        while (list1!= NULL && list2 != NULL){
            if (list1->val < list2->val){
                ans->next = new ListNode(list1->val);
                ans = ans->next;
                list1 = list1->next;
            }
            else{
                ans->next = new ListNode(list2->val);
                ans = ans->next;
                list2 = list2->next;
            }
        }
        while(list1 != NULL){
            ans->next = new ListNode(list1->val);
            ans = ans->next;
            list1 = list1->next;
        }
        while(list2 != NULL){
            ans->next = new ListNode(list2->val);
            ans = ans->next;
            list2 = list2->next;
        }
        return newHead->next;
    }
};

// optimized approach ->
// merging in-place (no new list, SC = O(1))
// intuition ->
// list1 should always point to the node with smaller value
// if list1->val > list2->val, swap them to keep list1 pointing to the smaller node
// keep forwarding list1, until list1->val is <= list2->val
// temp keeps track the previous of list1, to connect the last smaller node to list2, before list1->val gets > list2->val
// now, list1->val > list2->val, so, swap them again, to keep list1 associated with the smaller node.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode* ans = list1;
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return ans;
    }
};
// TC = O(N1 + N2)
// SC = O(1)


// below is the easier as well as optimized approach, similar with the brute approach
// and also uses constant space O(1) and does inplace merging
// TC = O(N1 + N2)
// SC = O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = new ListNode();
    ListNode* temp = ans;
    while (list1!= NULL && list2 != NULL){
        if (list1->val < list2->val){
            temp->next = list1;
            temp =temp->next;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    if(list1) 
        temp->next = list1;
    else 
        temp->next = list2;

    return ans->next;
}