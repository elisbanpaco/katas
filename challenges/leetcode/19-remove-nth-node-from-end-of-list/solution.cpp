/**
 * leetcode: 19-remove-nth-node-from-end-of-list
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// MAIN PARA PRUEBAS
int main(){
    Solution sol;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = sol.removeNthFromEnd(head, 2);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
