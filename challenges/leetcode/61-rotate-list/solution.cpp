/**
 * leetcode: 61-rotate-list
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Calcular la longitud de la lista y encontrar el último nodo
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Reducir k usando el módulo
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 3. Conectar la cola a la cabeza para formar un anillo
        tail->next = head;

        // 4. Encontrar el nuevo final de la lista: posición (length - k)
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 5. Romper el anillo y definir la nueva cabeza
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Función auxiliar para imprimir la lista
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : "");
        curr = curr->next;
    }
    cout << endl;
}

// MAIN PARA PRUEBAS
int main() {
    Solution sol;

    // Crear lista: [1, 2, 3, 4, 5]
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;

    cout << "Lista original: ";
    printList(head);

    ListNode* rotated = sol.rotateRight(head, k);

    cout << "Lista rotada (k = " << k << "): ";
    printList(rotated);

    return 0;
}