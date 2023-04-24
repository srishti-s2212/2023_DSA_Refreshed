// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <limits.h>

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

    int longestConsecutive(Node* root)
    {
         if(root == NULL)
            return 1;
        return longestConsecutiveUtil(root);
    }
    int longestPath = -1;
    int leftans = 1;
    int rightans = 1;
    int longestConsecutiveUtil(Node* root)
    {       
         if(root == NULL)
            return 0;
        
        if(root->left != NULL){
             if(root->left->data - root->data == 2 || root->data - root->left->data == 2){
                 leftans++;
                 longestConsecutiveUtil(root->left);
             }
        }
        if(root->right != NULL){
             if(root->right->data - root->data == 2 || root->data - root->right->data == 2){
                 rightans++;
                 longestConsecutiveUtil(root->right);
             }
        }
        
        longestPath = max(longestPath, leftans+rightans-1);
        return longestPath;
    }
    
};

int main() {

    Solution obj;
    Node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(8);
    Node* curr = root->left;
    curr->left = newNode(2);

    cout<<"Max length is: "<<obj.longestConsecutive(root);
    return 0;
}