#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List
{
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) //Time Complexity: O(1)
    {
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head=tail=newNode;
            return;
        }
        else 
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) //Time Complexity: O(1)
    {
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head = tail = newNode;
            return;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() //Time Complexity: O(1)
    {
        if (head==NULL)
            return;

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() //Time Complexity: O(n)
    {
        if (head==NULL)
            return;
        
        Node* temp = head;
        while (temp->next!=tail)
            temp = temp->next;

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert (int val, int pos) //Time Complexity: O(n)
    {
        Node* newNode = new Node(val);
        Node* temp = head;
        if (pos<0)
            return;
        else if (pos==0)
            push_front(val);

        for (int i=0;i<pos-1;i++)
        {
            if (temp == NULL) {
                cout<<"Invalid position "<<endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search (int val) //Time Complexity: O(n)
    {
        Node* temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == val) {
                cout<<index<<endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout<<-1<<endl;
    }


    void print() //Time Complexity: O(n)
    {
        Node* temp = head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main()
{
   List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print();
}