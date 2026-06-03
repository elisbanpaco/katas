/**
 * leetcode: 141-linked-list-cycle
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

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

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

// MAIN PARA PRUEBAS
int main()
{
    Solution sol;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = head->next->next;

    bool result = sol.hasCycle(head);
    cout << "El resultado es: " << result << endl;

    return 0;
}
