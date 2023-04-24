// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution{
  public:

    void boundary(Node* root){
        if(root == NULL)
            return;
        
        queue<Node*> q;
        q.push(root);

        stack<Node*> stLeft;
        queue<Node*> qRight;

        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                Node* curr = q.front();
                q.pop();
                if(i == 0)
                    stLeft.push(curr);
                
                else if(i == qsize-1 )
                    qRight.push(curr);
                
                if(curr->left != NULL)
                    q.push(curr->left);
                
                if(curr->right != NULL)
                    q.push(curr->right);
            }
        }

        vector<int> ans;
        while(!stLeft.empty()){
            ans.push_back(stLeft.top() -> data);
            stLeft.pop();
        }

        while(!qRight.empty()){
            ans.push_back(qRight.front() -> data);
            qRight.pop();
        }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

        return;     
    }
    
    
};

int main() {

    Solution obj;
    // Node* root = newNode(4);
    // root->left = newNode(5);
    // root->left->left = newNode(12);
    // root->left->right = newNode(1);
    // root->right = newNode(7);
    // root->right->right = newNode(8);

    Node* root = newNode(4);
    root->left = newNode(5);
    root->left->left = newNode(12);
    root->right = newNode(7);
    root->right->right = newNode(8);

    obj.boundary(root);
    return 0;
}

//Alternate Question: Instead of Binary Tree, we may be given general tree => each node having n children
//Change the class definition to have node and vector of childres
//Logic should remain mostly same. Instead of traversing left, right child, traverse children vector