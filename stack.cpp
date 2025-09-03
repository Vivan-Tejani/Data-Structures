// stack implementation using vector and linked list
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Stack 
{
    // vector <int> v;
    list<int> ll;

public: 

    void push_back(int val) { //Time Complexity: O(1) 
        // v.push_back(val); 
        ll.push_front(val);
    }

    void pop() { //Time Complexity: O(1)
        // v.pop_back();
        ll.pop_front();
    }

    int top() { //Time Complexity: O(1)
        // return v[v.size()-1];
        return ll.front();
    }

    bool empty() {
        // return v.size() == 0;
        return ll.size() == 0;
    }
};

int main()
{
    Stack s;
}