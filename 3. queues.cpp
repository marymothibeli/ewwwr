#include <iostream>
class StudentQueue {
private:
    struct Node {
        int studentNumber;
        Node* next;
        Node(int num) : studentNumber(num), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    StudentQueue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue a student number
    void enqueue(int studentNumber) {
        Node* newNode = new Node(studentNumber);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued student number: " << studentNumber << std::endl;
    }

    // Function to dequeue a student number
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        std::cout << "Dequeued student number: " << temp->studentNumber << std::endl;
        delete temp;
    }

    // Function to display all nodes and their positions
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            std::cout << " " << position << ": Student number " << current->studentNumber << std::endl;
            current = current->next;
            position++;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

   
    ~StudentQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    StudentQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();

    queue.dequeue();
    queue.display();
    queue.enqueue(4);
    queue.display();

    return 0;
}
