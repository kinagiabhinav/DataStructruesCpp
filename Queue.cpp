#include <iostream>
#include <memory>

class Node {
public:
    int data;
    std::shared_ptr<Node> next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
public:
    std::shared_ptr<Node> top;
    std::shared_ptr<Node> rear;
    int length;

    Queue() {
        top = nullptr;
        rear = nullptr;
        length = 0;
    }

    //enqueue
    void enqueue(int data) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
        if(length == 0) {
            top = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
        // r3<-2<-1t
    }

    //dequeue
    int dequeue() {
        if (length == 0){
            return -1;
        }

        std::shared_ptr<Node> current = top;
        if (length == 1) {
            top = nullptr;
            rear = nullptr;
        } else {
            top = current->next;
            current->next = nullptr;
        }
        length--;

        return current->data;   
    }

    //display
    void display() {
        std::shared_ptr<Node> current = top;
        for(size_t i = 0; i < length; i++) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    int data = q.dequeue();
    std::cout << data << std::endl;
    q.display();

    return 0;
}