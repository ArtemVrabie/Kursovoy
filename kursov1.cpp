#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int key;
    Node* next;

    // �����������
    Node(int key) : key(key), next(nullptr) {}
};
class Stack {
private:
    Node* top;
    int capacity;
    int size;

public:
    // �����������
    Stack(int cap) : top(nullptr), capacity(cap), size(0) {}

    // ����������
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // �������� �� �������
    bool isEmpty() {
        return top == nullptr;
    }

    // �������� �� ������������
    bool isFull() {
        return size >= capacity;
    }

    // �������� ������� � ���� (push)
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

    // ������� ������� � ������� �� ����� (pop)
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

   

    // ������� ��� ������ ����� � ��������
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
    Stack stack(10); // ������: ������� ���� � ������������ ������������ 10

    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.printStack(); // ���������� �����: 7 3 5

    stack.pop();
    stack.printStack(); // ���������� ����� ����� pop: 3 5

    // ���������� ������ �������
    // �������������� �����
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

    // ������ ������������� � main:
    // invertStack(stack);

    //�������� ������
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

    // ������ ������������� � main:
    // mergeStacks(stack1, stack2);

    // �������� ����������
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




