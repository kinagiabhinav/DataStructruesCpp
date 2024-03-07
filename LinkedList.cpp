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

class LinkedList {
	public:
		std::shared_ptr<Node> head;
		std::shared_ptr<Node> tail;
		int length;
		
		LinkedList() {
			head = nullptr;
			tail = nullptr;
			length = 0;
		}

		void insertEnd(int data) {
			std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
			if (head == nullptr) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->next = newNode;
				tail = newNode;
			}
			length++;
		}

		void insertBeginning(int data) {
			std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
			if (head == nullptr) {
				head = newNode;
				tail = newNode;
			}
			else {
				newNode->next = head;
				head = newNode;
			}

			length++;
		}

		void removeEnd() {
			if (length == 0) {
				// Handle the case when the list is empty
				return;
			}

			std::shared_ptr<Node> current = head;
			if (length == 1) {
				head = nullptr;
				tail = nullptr;
			} else {
				while(current->next->next){
					current = current->next;
				}
				current->next = nullptr;
				tail = current;
			}
			
			length--;
		}

		void removeBeginning() {
			if (length == 0) {
				// Handle the case when the list is empty
				return;
			}

			std::shared_ptr<Node> current = head;
			if (length == 1) {
				head = nullptr;
				tail = nullptr;
			} else {
				head = current->next;
			}

			length--;
		}

		int getAt(int pos) {
			if (pos < 0 || pos > length) {
				// Handle the case when the list is empty
				return -1;
			}

			int currentIndex = 0;

			std::shared_ptr<Node> current = head;
			while(pos != currentIndex) {
				current = current->next;
				currentIndex++;
			}

			return current->data;
		}

		void insertAt(int pos, int data) {
			if (pos < 0 || pos > length) {
				// Handle the case when the list is empty
				return;
			}
			if (pos == 0){
				insertBeginning(data);
			} else if (pos == length) {
				insertEnd(data);
			} else {
				int currentIndex = 0;

				std::shared_ptr<Node> prev = nullptr;
				std::shared_ptr<Node> current = head;
				while (pos != currentIndex) {
					prev = current;
					current = current->next;
					currentIndex++;
				}
				std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
				prev->next = newNode;
				newNode->next = current;
			}
			length++;
		}

		void reverse() {
			//  1->2->3->4->n
			//  n<-1<-2<-3<-4
			if(length == 0){
				return;
			}

			std::shared_ptr<Node> temp = nullptr;
			std::shared_ptr<Node> prev = nullptr;
			
			std::shared_ptr<Node> current = head;
			head = tail;
			tail = current;
			for (size_t i = 0; i < length; i++) {
				temp = current->next;
				current->next = prev;
				prev = current;
				current = temp;
			}
		}

		void display() {
			std::shared_ptr<Node> current = head;
			while (current) {
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << std::endl;
		}

};

int main() {
	LinkedList list;

	list.insertEnd(1);
	list.insertEnd(2);
	list.insertEnd(4);
	list.insertEnd(5);
	list.insertBeginning(0);
	list.insertAt(3, 3);
	list.removeEnd();
	list.removeBeginning();
	list.display();

	int data = list.getAt(0);
	std::cout << data << std::endl;

	list.reverse();
	list.display();
	return 0;
}