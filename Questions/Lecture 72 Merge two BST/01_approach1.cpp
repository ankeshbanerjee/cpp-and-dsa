// store the inorders of two given bst
// merge those two vectors to a sorted vector
// make a bst from that inorder vector

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node (int data){
        this->data = data;
        this->left = NULL;
        this->data = NULL;
    }
};

void inorder (Node * root, vector <int> &in){
    // base case
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector <int> mergeTwoSortedArrays (vector<int> &a1, vector<int> &a2){
    vector <int> ans;
    int i=0, j=0, size1 = a1.size(), size2 = a2.size();

    while (i<size1 && j<size2){
        if (a1[i] < a2[j]){
            ans.push_back(a1[i++]);
        }
        else{
            ans.push_back(a2[j++]);
        }
    }

    while (i<size1){
        ans.push_back(a1[i++]);
    }
    while (j<size2){
        ans.push_back(a2[j++]);
    }

    return ans;
}

Node * inorderToBST (int s, int e, vector<int> &in){
    // base case
    if (s>e)
        return NULL;

    int mid = (s+e)/2;
    Node * root = new Node (in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST (mid+1, e, in);

    return root;
}

Node * mergeBST (Node * r1, Node * r2){
    vector <int> bst1, bst2;
    // store inorder values
    inorder (r1, bst1);
    inorder (r2, bst2);

    // final sorted array
    vector <int> ans = mergeTwoSortedArrays(bst1, bst2);

    // ans
    return inorderToBST(0, ans.size()-1, ans);
}

// TC & SC = O(m+n) for the traversal in merging two sorted arrays and using ans vector of size (m+n)

int main (){
    
return 0;
}