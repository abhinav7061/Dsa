#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            if (fast==NULL)
            {
                return false;
            }else if(fast->next==NULL ){
                return false;
            }
            fast=fast->next->next;
            slow=slow->next;
            
        } while (fast->next!=slow->next);
        return true;
    }
};

int main()
{

    return 0;
}