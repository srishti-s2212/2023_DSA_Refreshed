#include <iostream>
#include <vector>

using namespace std;

//LinkedList
// struct Node
// {
//     Node* next;
//     int data;
//     Node(int x)
//     {
//         data=x;
//         next=NULL;
//     }
// };
    // void insertathead(Node*& head, int val)
    // {
    //     Node* curr = new node(val);
    //     curr->next = head;
    //     head = n;
    // }
// void insertafter(Node* head, int key, int val)
// {
//     Node* n = new node(val);
//     if (key == head->data) {
//         n->next = head->next;
//         head->next = n;
//         return;
//     }
  
//     node* temp = head;
//     while (temp->data != key) {
//         temp = temp->next;
//         if (temp == NULL) {
//             return;
//         }
//     }
//     n->next = temp->next;
//     temp->next = n;
// }

// void insertattail(node*& head, int val)
// {
//     node* n = new node(val);
//     if (head == NULL) {
//         head = n;
//         return;
//     }
  
//     node* temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = n;
// }
// int main()
// {
//     Node *head = new Node(10);
//     head->next = new Node(20);
//     head->next->next = new Node(30);
//     head->next->next->next = new Node(40);
//     head->next->next->next->next = new Node(50);
//     cout << "Input: ";
//     FindMiddle obj;
//     obj.print(head);
//     cout << endl;
//     cout << "Output:";
//     cout<<obj.detectCycle(head);

//     return 0;
// }

//Graphs
// int main()
// {
//     int v1=5;
//     vector<int> adj1[5] =  {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;
//     int v2=4;
//     vector<int> adj2[4] = {{}, {2}, {1, 3}, {2}};
//     // Graphs graph;
//     // cout<<graph.detectCycleDirected(adj1, v1)<<endl;
//     // cout<<graph.detectCycleDirected(adj2, v2);
// }

//Trees
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

