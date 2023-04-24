#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
 
// A utility function to create a node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
class Tree
{
    public:
    int maxLevelSum(Node* root) {
        // Your code here
        if(root==NULL)
            return -1;
        queue<Node*> q;
        q.push(root);
        int maxSum = INT_MIN; //Imp. We cannot have maxSum as 0 since Tree may contain negative values as well
        while(!q.empty())
        {
            int qsize = q.size();
            int sum = 0;
            while(qsize>0)
            {
                Node* curr = q.front();
                q.pop();
                sum = sum + curr->data;
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                qsize--;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
int main()
{
    Tree obj;
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout<<obj.maxLevelSum(root);
    return 0;
}
    