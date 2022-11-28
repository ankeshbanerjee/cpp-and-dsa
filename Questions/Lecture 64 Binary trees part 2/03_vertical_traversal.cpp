#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

vector <int> verticalOrder (Node * root){

    // map <horizontal distance, map <level, datas needed on that level>> 
    map <int, map <int, vector<int> > > nodes;
    // creating a queue as needed in level order traversal, pushing a pair of node and its hd and lvl
    queue <pair<Node *, pair<int, int> > > q;
    vector <int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0,0)));

    while (!q.empty()){
        pair<Node *, pair<int, int> > temp = q.front();
        q.pop();

        Node * frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    for (auto i: nodes){
        for (auto j: i.second){
            for (auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main (){

return 0;
}