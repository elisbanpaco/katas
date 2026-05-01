/**
 * leetcode: 83-remove-duplicates-from-sorted-list
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == nullptr)
            return nullptr;
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    ListNode *result = sol.deleteDuplicates(head);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
