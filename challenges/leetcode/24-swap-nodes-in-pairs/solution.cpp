/**
 * leetcode: 24-swap-nodes-in-pairs
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *aux = head->next;
        head->next = swapPairs(aux->next);
        aux->next = head;
        return aux;
        
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

    ListNode *result = sol.swapPairs(head);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
