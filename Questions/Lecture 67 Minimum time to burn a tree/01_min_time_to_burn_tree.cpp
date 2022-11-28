#include <iostream>
#include <queue>
#include <map>
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


Node * targetNodeandMapping (Node * root, int target, map <Node *, Node *> &nodeToParent){   
    // for node to parent mapping and returning the target node also

    Node * res = NULL;

    queue <Node *> q;
    q.push (root);
    nodeToParent [root] = NULL;

    while (!q.empty()){
        Node * front = q.front();
        q.pop();

        if (front->data == target){
            res = front;
        }

        if (front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burnTree (Node * root, map <Node *, Node *> nodeToParent){
    int ans = 0;

    map <Node *, bool> isVisited;
    queue <Node *> q;

    q.push (root);
    isVisited[root] = true;

    while (!q.empty()){

        bool flag = 0; // to check if addition is done in the queue or not

        int size = q.size();
        for (int i=0; i<size; i++){
            // for processing the neighbouring nodes of q.front
            Node * front = q.front();
            q.pop();

            if (front->left && !isVisited[front->left]){
                flag= 1;
                q.push(front->left);
                isVisited[front->left] = 1;
            }
            if (front->right && !isVisited[front->right]){
                flag= 1;
                q.push(front->right);
                isVisited[front->right] = 1;
            }
            if (nodeToParent[front] && !isVisited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                isVisited[nodeToParent[front]] = 1;
            }
        }

        if (flag == 1){
            ans++;
        }
    }
    return ans;
}


int minTime (Node * root, int target){

    // step 1: create nodeToparent mapping
    // step 2 : find target Node
    // step 3 : burn tree in min time

    map <Node *, Node *> nodeToParent;
    Node * targetNode = targetNodeandMapping(root, target, nodeToParent);
    
    int ans = burnTree (targetNode, nodeToParent);
    return ans;
}

// TC = O(nlogn) or O(n), depends on the map taken
// SC = O(n)

int main (){
    
return 0;
}