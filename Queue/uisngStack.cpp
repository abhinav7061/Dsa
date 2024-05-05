#include <iostream>
#include <stack>
using namespace std;

class queue
{
private:
    stack<int> s1, s2; // two stack to implement the Queue
public:
    void enqueue(int x) // push element in the queue
    {
        s1.push(x); // Push the input data to first stack (s1)
    }

    void printQueue()
    {
        if (s1.empty())
        {
            cout << "Queue is empty";
        }

        while (!s1.empty())
        {
            cout << s1.top() << ", ";
            s1.pop();
        }
    }

    void dequeue() // dequeue an element from the queue
    {
        if (!s1.empty()) // check whether the queue is empty or not
        {
            if (s2.empty())         // check whether second stack is empty or not
                while (!s1.empty()) // If yes then transfer all elements from first stack to second stack
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            int x = s2.top(); // store the top of the second stack
            s2.pop();         // remove the top of the second stack
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

            cout << "The deleted item is : " << x << endl;
        }
        else
            cout << "The queue is Empty \n";
    }
    // queue();
};

int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.dequeue();
    q.printQueue();
    q.enqueue(9);
    return 0;
}