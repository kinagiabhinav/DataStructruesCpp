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

class Stack {
public:
	std::shared_ptr<Node> top, bottom;
	int length;

	Stack() {
		top = nullptr;
		bottom = nullptr;
		length = 0;
	}

	//push  t3->2->1b
	void push(int data) {
		std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
		if (length == 0) {
			top = newNode;
			bottom = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		length++;
	}
	
	//pop
	int pop() {
		if (length == 0) {
			return -1;
		}
		std::shared_ptr<Node> curr = top;
		if (length == 1) {
			top = nullptr;
			bottom = nullptr;
		} else {
			top = curr->next;
			curr->next = nullptr;
		}
		length--;

		return curr->data;
	}

	//peek
	int peek() {
		if(length == 0)
			return -1;

		return top->data;
	}

	void display() {
		std::shared_ptr<Node> current = top;
		for (size_t i = 0; i < length; i++) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.display();
	int data = s.pop();
	std::cout << data << std::endl;

	data = s.peek();
	std::cout << data << std::endl;

	s.display();
	return 0;
}