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
        this->right = NULL;
    }
};

Node * createBinaryTree (Node * root){
    cout << "Enter the data: " ;
    int data;
    cin >> data;
    root = new Node(data);
    
    if (data == -1){
        return NULL;
    }

    cout << "Enter the left child of " << data << " :" << endl;
    root->left = createBinaryTree(root->left);
    cout << "Enter the right child of " << data << " :" << endl;
    root->right = createBinaryTree(root->right);

    return root;
}


void solve (Node * root, int k, int &count, vector<int> &path){
    // base case
    if (root == NULL)
        return;
    
    path.push_back(root->data);
    // left
    solve (root->left, k, count, path);
    // right
    solve (root->right, k, count, path);

    // check k sum
    int size = path.size();
    int sum = 0;
    for (int i=size-1; i>=0; i--){
        sum += path[i];
        if (sum == k)
            count ++;
    }

    // before returning, pop the last element from path
    path.pop_back();
}

int kSum (Node * root, int k){
    vector <int> path;
    int count = 0;
    solve (root, k, count, path);
    return count;
}

int main (){
    
return 0;
}