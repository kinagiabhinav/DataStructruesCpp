#include <iostream>
#include <memory>
#include <vector>

class Node {
public:
    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    std::shared_ptr<Node> root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data){
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);

        if(root == nullptr) {
            root = newNode;
            return;
        }

        std::shared_ptr<Node> current = root;
        while (true) {
            if (newNode->data == current->data) {
                current = root;
                return;
            } else if (newNode->data > current->data) {
                if (current->right == nullptr){
                    current->right = newNode;
                    return;
                }
                current = current->right;
            } else {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
        }   
    }

    void DepthFirstSearch(std::shared_ptr<Node> current) {
        if (current->left != nullptr) {
            DepthFirstSearch(current->left);
        } 
        std::cout << current->data << " ";
        if (current->right != nullptr){
            DepthFirstSearch(current->right);
        } 
        
    }

    void BreadthFirstSearch(std::shared_ptr<Node> current) {
        std::vector<std::shared_ptr<Node>> queue = {current};
        std::vector<int> visited = {};

        while(!queue.empty()) {
            auto current = queue[0];
            visited.emplace_back(current->data);

            if (current->left) {
                queue.emplace_back(current->left);
            }

            if (current->right) {
                queue.emplace_back(current->right);
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
    bst.DepthFirstSearch(bst.root);
    std::cout << std::endl << "BFS: ";
    bst.BreadthFirstSearch(bst.root);
    return 0;
}
