/**
 * leetcode: 21-merge-two-sorted-lists
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Nodo "falso" (dummy) para empezar la lista resultante
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Mientras ambas listas tengan elementos
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1; // Conectamos el nodo de list1
                list1 = list1->next; // Avanzamos en list1
            } else {
                tail->next = list2; // Conectamos el nodo de list2
                list2 = list2->next; // Avanzamos en list2
            }
            tail = tail->next; // Movemos el puntero de la nueva lista
        }

        // Si una lista se acabó antes que la otra, 
        // simplemente pegamos lo que queda de la otra lista.
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << " -> nullptr" << endl;
}


// MAIN SOLO PARA PRUEBAS
int main() {
    Solution sol;

    // Crear Lista 1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    // Crear Lista 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    cout << "Lista 1: "; printList(l1);
    cout << "Lista 2: "; printList(l2);

    // Probar la función
    ListNode* result = sol.mergeTwoLists(l1, l2);

    cout << "Resultado fusionado: ";
    printList(result);

    return 0;
}