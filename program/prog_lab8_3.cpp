#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedList() : head(nullptr) {}

    // Метод для добавления элемента в конец списка
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* last_node = head;
        while (last_node->next != head) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->next = head;
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
                    new_node3->next = current->next;
                    current->next = new_node1;
                    new_node1->next = new_node2;
                    new_node2->next = new_node3;
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
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        std::cout << "(head)" << std::endl;
    }

private:
    Node* head;
};

int main() {
    CircularLinkedList list;

    // Добавление элементов в список
    int sequence[] = {1, 0, 2, 0, 3, 4};
    for (int num : sequence) {
        list.append(num);
    }

    std::cout << "Исходная последовательность:" << std::endl;
    list.printList();  // Вывод: 1 -> 0 -> 2 -> 0 -> 3 -> 4 -> (head)

    // Вставка чисел B1, B2, B3 после второго нуля
    int B1 = 7, B2 = 8, B3 = 9;
    list.insertAfterSecondZero(B1, B2, B3);

    std::cout << "Последовательность после вставки B1, B2, B3:" << std::endl;
    list.printList();  // Вывод: 1 -> 0 -> 2 -> 0 -> 7 -> 8 -> 9 -> 3 -> 4 -> (head)

    return 0;
}
