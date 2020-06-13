#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int interface() {
    cout << "What type of data do you want to work with?" << endl;
    cout << "Please, type '1' for integer or '2' for double" << endl;
    int type;

    do {
        cin >> type;
        cout << endl;
        if ((type != 1) && (type != 2)) {
            cout << ("You must choose 1 or 2") << endl;
        }
    } while ((type != 1) && (type != 2));

    auto *Tree1 = new BinaryTree<int>();
    auto *Tree2 = new BinaryTree<double>();

    if (type == 1) {
        Tree1->Enter();
    } else if (type == 2) {
        Tree2->Enter();
    }

    int choice = 0;

    cout << "Please, choose the operation:" << endl;
    cout << "1. Print Tree" << endl;
    cout << "2. Check for element" << endl;
    cout << "3. Get depth" << endl;
    cout << "4. Insert" << endl;
    cout << "5. Delete" << endl;
    cout << "6. Search" << endl;
    cout << "7. Get SubTree" << endl;
    cout << "8. Check for SubTree" << endl;
    cout << "9. Map" << endl;
    cout << "10. Get tree in string" << endl;

    cout << endl << "Your choice:";
    cin >> choice;
    cout << endl;

    int int_el = 0;
    double double_el = 0;

    switch (choice) {
        case 1: {
            if (type == 1) {
                Tree1->Print(Tree1->root);
            } else if (type == 2) {
                Tree2->Print(Tree2->root);
            }

            break;
        }

        case 2: {
            if (type == 1) {
                cout << "Please, type your element:";
                cin >> int_el;
                cout << endl;
                if (Tree1->IsThereElement(int_el)){
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else if (type == 2) {
                cout << "Please, type your element:";
                cin >> double_el;
                cout << endl;
                if (Tree2->IsThereElement(double_el)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }

            break;
        }

        case 3: {
            if (type == 1) {
                cout << Tree1->Depth(Tree1->root);
            } else if (type == 2) {
                cout << Tree2->Depth(Tree2->root);
            }

            break;
        }

        case 4: {
            if (type == 1) {
                cout << "Please, type your element:";
                cin >> int_el;
                cout << endl;
                Tree1->Insert(int_el);
            } else if (type == 2) {
                cout << "Please, type your element:";
                cin >> double_el;
                cout << endl;
                Tree2->Insert(double_el);
            }

            break;
        }

        case 5: {
            if (type == 1) {
                cout << "Please, type your element:";
                cin >> int_el;
                cout << endl;
                Tree1->Search(Tree1->root, int_el);
            } else if (type == 2) {
                cout << "Please, type your element:";
                cin >> double_el;
                cout << endl;
                Tree2->Search(Tree2->root, double_el);
            }

            break;
        }

        case 6: {
            if (type == 1) {
                cout << "Please, type your element:";
                cin >> int_el;
                cout << endl;
                Tree1->Delete(Tree1->root, int_el);
            } else if (type == 2) {
                cout << "Please, type your element:";
                cin >> double_el;
                cout << endl;
                Tree2->Delete(Tree2->root, double_el);
            }

            break;
        }

        default:
            cout << "ERROR. You need choose an action.";
    }

    return 0;
}

int main() {
    interface();

    //LinkedListSequence_Tests();
    return 0;
}
