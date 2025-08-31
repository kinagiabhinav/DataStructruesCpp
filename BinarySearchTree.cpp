#include <iostream>
#include <memory>
#include <vector>

class Node {
public:
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    std::unique_ptr<Node> root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data){
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);

        if(root == nullptr) {
            root = std::move(newNode);
            return;
        }

        Node* current = root.get();
        while (true) {
            if (newNode->data == current->data) {
                current = root.get();
                return;
            } else if (newNode->data > current->data) {
                if (current->right == nullptr){
                    current->right = std::move(newNode);
                    return;
                }
                current = current->right.get();
            } else {
                if (current->left == nullptr) {
                    current->left = std::move(newNode);
                    return;
                }
                current = current->left.get();
            }
        }   
    }

    void DepthFirstSearch(Node* current) {
        if (current->left != nullptr) {
            DepthFirstSearch(current->left.get());
        } 
        std::cout << current->data << " ";
        if (current->right != nullptr){
            DepthFirstSearch(current->right.get());
        } 
        
    }

    void BreadthFirstSearch(Node* current) {
        std::vector<Node*> queue = {current};
        std::vector<int> visited = {};

        while(!queue.empty()) {
            auto current = queue[0];
            visited.emplace_back(current->data);

            if (current->left) {
                queue.emplace_back(current->left.get());
            }

            if (current->right) {
                queue.emplace_back(current->right.get());
            }

            queue.erase(queue.begin());
        }

        for (auto &&i : visited) {
            std::cout << i << " ";
        }
        
    }
};

int main() {
    /**
     *   3
     * 2    5
     *    4    6
    */
    BinarySearchTree bst;
    bst.insert(3);
    bst.insert(5);
    bst.insert(6);
    bst.insert(4);
    bst.insert(2);
    std::cout << "DFS: ";
    bst.DepthFirstSearch(bst.root.get());
    std::cout << std::endl << "BFS: ";
    bst.BreadthFirstSearch(bst.root.get());
    return 0;
}
