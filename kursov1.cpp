#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int key;
    Node* next;

    // Конструктор
    Node(int key) : key(key), next(nullptr) {}
};
class Stack {
private:
    Node* top;
    int capacity;
    int size;

public:
    // Конструктор
    Stack(int cap) : top(nullptr), capacity(cap), size(0) {}

    // Деструктор
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Проверка на пустоту
    bool isEmpty() {
        return top == nullptr;
    }

    // Проверка на переполнение
    bool isFull() {
        return size >= capacity;
    }

    // Добавить элемент в стек (push)
    void push(int key) {
        if (isFull()) {
            std::cout << "Stack is full, cannot push more elements." << std::endl;
            return;
        }
        Node* newNode = new Node(key);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Удалить элемент и вывести на экран (pop)
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty, nothing to pop." << std::endl;
            return INT_MIN;
        }
        Node* temp = top;
        int popped = top->key;
        top = top->next;
        delete temp;
        size--;
        return popped;
    }

   

    // Функция для вывода стека в терминал
    void printStack() {
        Node* current = top;
        std::cout << "Stack: ";
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};  


  
int main() {
    Stack stack(10); // Пример: создаем стек с максимальной вместимостью 10

    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.printStack(); // Содержимое стека: 7 3 5

    stack.pop();
    stack.printStack(); // Содержимое стека после pop: 3 5

    // Добавление нужных функций
    // Инвертирование стека
    void invertStack(Stack & s) {
        std::cout << stack<int> << tempStack;
        while (!s.isEmpty()) {
            tempStack.push(s.pop());
        }
        while (!tempStack.empty()) {
            s.push(tempStack.top());
            tempStack.pop();
        }
    }

    // Пример использования в main:
    // invertStack(stack);

    //Сложение стеков
    void mergeStacks(Stack & s1, Stack & s2) {
        Stack tempStack(s1.capacity + s2.capacity);
        while (!s1.isEmpty()) {
            tempStack.push(s1.pop());
        }
        while (!s2.isEmpty()) {
            tempStack.push(s2.pop());
        }
        Stack merged(s1.capacity + s2.capacity);
        while (!tempStack.isEmpty()) {
            merged.push(tempStack.pop());
        }
    }

    // Пример использования в main:
    // mergeStacks(stack1, stack2);

    // Удаление дубликатов
    void removeDuplicates(Stack& s) {
        std::unordered_set<int> seen;
        Stack tempStack(s.capacity);
        while (!s.isEmpty()) {
            int current = s.pop();
            if (seen.find(current) == seen.end()) {
                seen.insert(current);
                tempStack.push(current);
            }
        }
        while (!tempStack.isEmpty()) {
            s.push(tempStack.pop());
        }
    }
  
    

    return 0;
}




