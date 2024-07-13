#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class SerializeAndDeserializeBinaryTree {
public:
    static void main() {
        Node* root = nullptr;
        root = addNode(root, 1, true);
        root = addNode(root, 2, true);
        root = addNode(root, 3, true);
        root = addNode(root, 4, true);
        root = addNode(root, 5, true);
        root = addNode(root, 6, true);

        printPreOrder(root);
        std::cout << std::endl;

        std::string str = serializeBinaryTree(root);
        std::cout << str << std::endl;

        Node* start = deserializeBinaryTree(str);
        std::cout << start->data << std::endl;  // Print root data of deserialized tree
        printPreOrder(start);
    }

    // Serialize Binary Tree
    static std::string serializeBinaryTree(Node* root) {
        if (root == nullptr) {
            return "null,";
        }

        std::ostringstream sb;
        sb << root->data << ",";
        sb << serializeBinaryTree(root->left);
        sb << serializeBinaryTree(root->right);
        return sb.str();
    }

    // Deserialize Binary Tree
    static Node* deserializeBinaryTree(const std::string& data) {
        std::vector<std::string> temp;
        std::istringstream ss(data);
        std::string token;
        while (std::getline(ss, token, ',')) {
            temp.push_back(token);
        }
        index = 0;
        return deserializeUsingStaticCounter(temp);
    }

private:
    static int index;

    static Node* deserializeUsingStaticCounter(const std::vector<std::string>& data) {
        if (index >= data.size() || data[index] == "null") {
            index++;
            return nullptr;
        }

        Node* node = new Node(std::stoi(data[index++]));
        node->left = deserializeUsingStaticCounter(data);
        node->right = deserializeUsingStaticCounter(data);

        return node;
    }

    static Node* addNode(Node* root, int i, bool isRoot) {
        if (root == nullptr) {
            return new Node(i);
        } else {
            if (i > root->data) {
                if (isRoot) {
                    Node* nodeToAdd = addNode(root->right, i, isRoot);
                    root->right = nodeToAdd;
                } else {
                    Node* nodeToAdd = addNode(root->left, i, isRoot);
                    root->left = nodeToAdd;
                }

            } else {
                if (isRoot) {
                    Node* nodeToAdd = addNode(root->left, i, isRoot);
                    root->left = nodeToAdd;
                } else {
                    Node* nodeToAdd = addNode(root->right, i, isRoot);
                    root->right = nodeToAdd;
                }
            }
        }
        return root;
    }

    static void printPreOrder(Node* root) {
        if (root == nullptr)
            return;
        std::cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
};

int SerializeAndDeserializeBinaryTree::index = 0;

int main() {
    SerializeAndDeserializeBinaryTree::main();
    return 0;
}
