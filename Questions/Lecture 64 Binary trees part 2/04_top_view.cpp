#include <iostream>
#include <map>
#include <queue>
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

vector <int> topView (Node * root){
    vector <int> ans;

    // horizontal distance : node->data
    map <int, int> topNode;    // used map for getting data in sorted order
    
    // queue for level order traversal => pair:- node : hd
    queue <pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()){
       pair<Node *, int> temp = q.front();
       q.pop();
       Node * frontNode = temp.first;
       int hd = temp.second;

       // if one value is mapped to a hd, then do nothing (1:1 mapping for topview)
       if (topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
       }
       if (frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }

    for (auto i: topNode){
        ans.push_back(i.second);
    }
}

int main (){
    
return 0;
}