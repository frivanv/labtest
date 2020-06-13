#include <iostream>
#include <string>
#include "LinkedListSequence.h"
#include "Node.h"

using namespace std;

template<class T>
class BinaryTree {


public:
    Node<T> *root;

    BinaryTree() { //constructor
        root = nullptr;
    }

    explicit BinaryTree(Node<T> *node) {
        this->root = node;
    }

    ~BinaryTree() { //destructor
        Delete(root, root->item);
    }

    int max(int a, int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }

    void Enter() {
        cout << "Please, type size of the Tree:";
        int size;
        cin >> size;

        for (int i = 0; i < size; i++) {
            T elem;
            cout << "Element" << i << "-";
            cin >> elem;
            Insert(elem);
        }
    }

    void Print(Node<T> *node) {
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        } else {
            Print(node->left);
            cout << node->item << endl;
            Print(node->right);
        }
    }

    int Depth(Node<T> *node) {
        int left_depth, right_depth;

        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        } else {
            if (node->left != nullptr) {
                left_depth = Depth(node->left) + 1;
            } else {
                left_depth = 0;
            }

            if (node->right != nullptr) {
                right_depth = Depth(node->right) + 1;
            } else {
                right_depth = 0;
            }
        }

        return max(left_depth, right_depth);
    }

    int Depth() {
        return Depth(this->root);
    }

    bool IsThereElement(T elem) {
        Node<T> *node = this->root;

        if (node == nullptr) return false;

        while (node != nullptr) {
            if (elem < node->item) {
                node = node->left;
            } else {
                if (elem > node->item) {
                    node = node->right;
                } else {
                    return true;
                }
            }
        }
    }

    void Insert(T elem) {
        Node<T> *tree = root;
        Node<T> *ptr = nullptr;
        auto *new_node = new Node<T>(elem);

        while (tree != nullptr) {
            ptr = tree;
            if (elem <= tree->item) {
                tree = tree->left;
            } else {
                tree = tree->right;
            }
        }

        if (ptr == nullptr) {
            root = new_node;
        } else {
            if (elem <= ptr->item) {
                ptr->left = new_node;
            } else {
                ptr->right = new_node;
            }
        }
    }

    bool Delete(Node<T> *node, T elem) {
        if (node == nullptr) {
            return false;
        }

        Node<T> *ptr1 = node;
        Node<T> *new_node = nullptr;
        bool check = false;

        if (ptr1->left == nullptr && ptr1->right == nullptr) {
            if (elem == ptr1->item) {
                delete ptr1;
                return true;
            } else {
                return false;
            }
        }

        while (ptr1 != nullptr && ptr1->item != elem) {
            if (elem <= ptr1->item) {
                check = false;
                new_node = ptr1;
                ptr1 = ptr1->left;
            } else {
                if (elem > ptr1->item) {
                    check = true;
                    new_node = ptr1;
                    ptr1 = ptr1->right;
                }
            }
        }

        if (ptr1 == nullptr) {
            return false;
        } else {
            if (ptr1->right == nullptr && ptr1->left == nullptr) {
                if (check) {
                    new_node->right = nullptr;
                } else {
                    new_node->left = nullptr;
                }

                delete ptr1;
                return true;
            } else {
                if (ptr1->right == nullptr && ptr1->left == nullptr) {
                    if (new_node->left == ptr1) {
                        new_node->left = ptr1->right;
                    } else {
                        new_node->right = ptr1->right;
                    }

                    delete ptr1;
                    return true;
                } else {
                    if (ptr1->left != nullptr && ptr1->right != nullptr) {
                        Node<T> *ptr2 = nullptr;
                        new_node = ptr1;
                        ptr2 = ptr1;
                        check = true;
                        ptr1 = ptr1->right;
                        while (ptr1->left != nullptr) {
                            ptr2 = ptr1;
                            check = false;
                            ptr1 = ptr1->left;
                        }
                        new_node->item = ptr1->item;

                        if (ptr1->right != nullptr) {
                            if (check) {
                                ptr2->right = ptr1->right;
                            } else {
                                ptr2->left = ptr1->right;
                            }

                            delete ptr1;
                            return true;
                        } else {
                            if (check) {
                                ptr2->right = nullptr;
                            } else {
                                ptr2->left = nullptr;
                            }

                            delete ptr1;
                            return true;
                        }
                    }
                }
            }
        }

    }

    bool Delete(T elem) {
        return Delete(this->root, elem);
    }

    Node<T> *Search(Node<T> *node, T elem) {
        if ((root == nullptr) || (node == nullptr)) {
            cout << "Tree is empty" << endl;
            return node;
        }

        if (elem == node->item) {
            return node;
        } else if (elem < node->item) {
            return Search(node->left, elem);
        } else {
            return Search(node->right, elem);
        }
    }

    Node<T> *Search(T elem) {
        return Search(this->root, elem);
    }

    BinaryTree<T> *SubTree(T elem) {
        Node<T> *node = this->Search(elem);
        auto *new_tree = new BinaryTree<T>(node);

        return new_tree;
    }

    bool SearchSubTree(BinaryTree<T> *subtree) {

        return SubTree(subtree->root->item) == subtree;
    }

    void Map(Node<T> *node, T(*func)(T)) {
        node->item = func(node->item);
        if (node->left != nullptr) Map(node->left, func);
        if (node->right != nullptr) Map(node->right, func);
    }

    void Map(T(*func)(T)) {
        if (this->root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        } else {
            this->Map(this->root, func);
        }
    }

    void TreeToList(Node<T> *node, LinkedListSequence<T> &list) {
        if (this->root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        } else {
            TreeToList(node->left, list);
            list.Prepend(node->item);
            TreeToList(node->right, list);
        }
    }

    void TreeToString(Node<T> *node, string str) {
        if (this->root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        } else {
            LinkedListSequence<T> list = LinkedListSequence<T>();
            TreeToList(node, list);

            for (int i = 0; i < list.GetLength(); i++) {
                str += list.Get(i) + "\t";
            }
        }
    }

};