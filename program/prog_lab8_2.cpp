#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Метод для добавления элемента в конец списка
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    // Метод для вставки элементов после второго нулевого элемента
    void insertAfterSecondZero(int B1, int B2, int B3) {
        Node* current = head;
        int zero_count = 0;

        while (current) {
            if (current->data == 0) {
                zero_count++;
                if (zero_count == 2) {
                    // Создание новых узлов для B1, B2, B3
                    Node* new_node1 = new Node(B1);
                    Node* new_node2 = new Node(B2);
                    Node* new_node3 = new Node(B3);
                    
                    // Вставка новых узлов после второго нуля
                    new_node3->next = current->next;
                    new_node3->prev = new_node2;
                    new_node2->next = new_node3;
                    new_node2->prev = new_node1;
                    new_node1->next = new_node2;
                    new_node1->prev = current;
                    
                    if (current->next) {
                        current->next->prev = new_node3;
                    } else {
                        tail = new_node3;
                    }
                    current->next = new_node1;
                    return;
                }
            }
            current = current->next;
        }
    }

    // Метод для печати списка с начала
    void printList() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "None" << std::endl;
    }

    // Метод для печати списка с конца
    void printListReverse() const {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "None" << std::endl;
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList list;

    // Добавление элементов в список
    int sequence[] = {1, 0, 2, 0, 3, 4};
    for (int num : sequence) {
        list.append(num);
    }

    std::cout << "Исходная последовательность:" << std::endl;
    list.printList();  // Вывод: 1 <-> 0 <-> 2 <-> 0 <-> 3 <-> 4 <-> None

    // Вставка чисел B1, B2, B3 после второго нуля
    int B1 = 7, B2 = 8, B3 = 9;
    list.insertAfterSecondZero(B1, B2, B3);

    std::cout << "Последовательность после вставки B1, B2, B3:" << std::endl;
    list.printList();  // Вывод: 1 <-> 0 <-> 2 <-> 0 <-> 7 <-> 8 <-> 9 <-> 3 <-> 4 <-> None

    return 0;
}
