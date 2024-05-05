#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> queues;

public:
    Queue()
    {
        queues.clear();
    };

    void enqueue(const int &value)
    {
        queues.push_back(value);
    };

    bool isEmpty() const
    {
        return queues.empty();
    };

    int peek()
    {
        if (queues.empty())
            return -1; // return -1 as an error code for empty queue
        return queues.front();
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, please check!" << endl;
            return -1;
        }
        else
        {
            int tmp = queues[0];
            queues.erase(queues.begin());
            return tmp;
        }
    };
};

void testQueue()
{
    Queue q;
    for (int i = 5; i >= 1; --i)
    {
        q.enqueue(i * 2);
    }
    cout << q.peek() << q.isEmpty() << endl
         << "Queue after adding elements:" << endl;
    while (!q.isEmpty())
    {
        printf("%d ", q.dequeue());
    }
    cout << endl
         << q.isEmpty() << endl;
}

int main()
{
    testQueue();
    return 0;
}