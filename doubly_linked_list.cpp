#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    public:
    Node* head;
    Node* tail;
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) //Time Complexity: O(1)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) //Time Complexity: O(1)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val,int index) //Time Complexity: O(n)
    {
        if (index<0) {
            cout<<"Invalid Index"<<endl;
            return;
        }
        else if (index==0) {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else 
        {
            for (int i=0;i<index-1;i++)
            {
                if (temp==NULL) {
                    cout<<"Invalid index"<<endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            (temp->next)->prev = newNode;
            newNode->prev = temp;
        }
    }

    void pop_front() //Time Complexity: O(1)
    {
        if (head == NULL)
            return;
        else if (head == tail)
        {
            delete head;
            return;
        }
        else 
        {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back() //Time Complexity: O(1)
    {
        if (head==NULL)
            return;
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else 
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void printForward() //Time Complexity: O(n)
    {
        Node* temp = head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void printReverse() //Time Complexity: O(n)
    {
        Node* temp = tail;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    DoublyList dl;
}