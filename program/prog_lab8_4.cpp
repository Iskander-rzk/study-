#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // Метод для добавления элемента в конец списка
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            new_node->next = head;
            new_node->prev = head;
            return;
        }
        Node* last = head->prev;

        last->next = new_node;
        new_node->prev = last;
        new_node->next = head;
        head->prev = new_node;
    }

    // Метод для вставки элементов после второго нулевого элемента
    void insertAfterSecondZero(int B1, int B2, int B3) {
        if (!head) return;

        Node* current = head;
        int zero_count = 0;

        do {
            if (current->data == 0) {
                zero_count++;
                if (zero_count == 2) {
                    // Создание новых узлов для B1, B2, B3
                    Node* new_node1 = new Node(B1);
                    Node* new_node2 = new Node(B2);
                    Node* new_node3 = new Node(B3);

                    // Вставка новых узлов после второго нуля
                    Node* next_node = current->next;
                    current->next = new_node1;
                    new_node1->prev = current;
                    new_node1->next = new_node2;
                    new_node2->prev = new_node1;
                    new_node2->next = new_node3;
                    new_node3->prev = new_node2;
                    new_node3->next = next_node;
                    next_node->prev = new_node3;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
    }

    // Метод для печати списка
    void printList() const {
        if (!head) return;

        Node* current = head;
        do {
            std::cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        std::cout << "(head)" << std::endl;
    }

private:
    Node* head;
};

int main() {
    CircularDoublyLinkedList list;

    // Добавление элементов в список
    int sequence[] = {1, 0, 2, 0, 3, 4};
    for (int num : sequence) {
        list.append(num);
    }

    std::cout << "Исходная последовательность:" << std::endl;
    list.printList();  // Вывод: 1 <-> 0 <-> 2 <-> 0 <-> 3 <-> 4 <-> (head)

    // Вставка чисел B1, B2, B3 после второго нуля
    int B1 = 7, B2 = 8, B3 = 9;
    list.insertAfterSecondZero(B1, B2, B3);

    std::cout << "Последовательность после вставки B1, B2, B3:" << std::endl;
    list.printList();  // Вывод: 1 <-> 0 <-> 2 <-> 0 <-> 7 <-> 8 <-> 9 <-> 3 <-> 4 <-> (head)

    return 0;
}
