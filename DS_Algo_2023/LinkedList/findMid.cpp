#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    Node* next;
    int data;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class FindMiddle
{
public:
    Node* findMid(Node* head)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        Node *slow, *fast;
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    void print(Node* head)
    {
        if(head==NULL)
            cout<<"Empty LinkedList";
        
        Node* curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        return;
    }
};

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout << "Input:";
    FindMiddle obj;
    obj.print(head);
    cout << endl;
    cout << "Output:";
    Node* mid = obj.findMid(head);
    cout<<mid->data;
    return 0;
}