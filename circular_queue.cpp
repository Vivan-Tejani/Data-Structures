#include <iostream>
using namespace std;

class CircularQueue 
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size) 
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0, r = -1;
    }

    void push(int val) 
    {
        if (currSize == cap) {
            cout<< "Circular Queue is full"<<endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = val;
        currSize++;
    }

    void pop() 
    {
        if (empty()) {
            cout<<"Circular Queue is empty"<<endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front() 
    {
        if (empty()) {
            cout<<"Circular Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() 
    {
        return currSize == 0;
    }
};

int main() 
{
    CircularQueue cq(3);
}