#include <iostream> 
using namespace std; 

// Объявление класса Node для элемента стека
class Node 
{
public:
    Node* nextNode; // Указатель на следующий элемент в стеке
    int value; // Значение элемента

    // Конструктор класса Node
    Node(int value) : value(value) {} // Инициализирует значение элемента при создании Node
};

// Объявление класса Stack для представления стека
class Stack 
{
    Node* topNode; // Указатель на вершину стека

public:
    // Конструктор класса Stack, инициализация указателя на вершину стека
    Stack() : topNode(nullptr) {} 

public:
    // Метод для возвращения и удаления верхнего элемента стека
    int pop() 
    {
        // Проверка
        if (topNode == nullptr) 
            return NULL; // Возвращает NULL, если стек пустой
    
        Node* tempNode = topNode; // Сохранение текущего верхнего элемента
        topNode = topNode->nextNode; // Перемещение указателя на вершину стека на следующий элемент
        int poppedValue = tempNode->value; // Сохранение значения верхнего элемента
        delete tempNode; // Удаление текущего верхнего элемента
        return poppedValue; // Возвращение значения удаленного элемента
    }

    // Метод для добавления элемента в стек
    void push(int value) 
    {
        Node* newNode = new Node(value); // Создание нового элемента
        newNode->nextNode = topNode; // Установка указателя на следующий элемент на текущую вершину стека
        topNode = newNode; // Обновление вершины стека новым элементом
    }
};

int main() 
{
    Stack stack; // Создание стека

    // Добавление элементов в стек
    stack.push(15); 
    stack.push(20); 
    stack.push(25); 

    // Извлечение и вывод элементов из стека
    cout << stack.pop() << std::endl; 
    cout << stack.pop() << std::endl; 
    cout << stack.pop() << std::endl; 

    return 0; 
}
