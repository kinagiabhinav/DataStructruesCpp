#include <iostream>
#include <memory>

class Node {
public:
    int data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int length = 0;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    //insertEnd
    void insertEnd(int data) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    
    //removeBeginning
    int removeBeginning(){
        if (length == 0) {
            return -1;
        }

        auto current = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = current->next;
            current->next = nullptr;
            head->prev = nullptr;
        }
        length--;

        return current->data;
    }

    //display
    void display() {
        auto current = head;
        for(size_t i = 0; i < length; i++) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dl;

    dl.insertEnd(0);
    dl.insertEnd(1);
    dl.insertEnd(2);
    dl.insertEnd(3);
    dl.insertEnd(4);
    dl.display();

    int data = dl.removeBeginning();
    std::cout << data << std::endl;

    dl.display();
    
    return 0;
}