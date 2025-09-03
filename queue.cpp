#include <iostream>
#include <vector>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
    Node (int val) 
    {
        data = val;
        next = NULL;
    }
};

class Queue 
{
    Node* head;
    Node* tail;
public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int val) //Time Complexity: O(1)
    {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() //Time Compleity: O(1)
    {
        if(empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front() //Time Complexity: O(1)
    {
        if(empty()) {
            cout<<"Queue is empty";
            return -1;
        }
        return head->data;
    }

    bool empty() //Time Complexity: O(1)
    {
        return head == NULL;
    }
};

int main()
{
    Queue q;
    q.pop();
}