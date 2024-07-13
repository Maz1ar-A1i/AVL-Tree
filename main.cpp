#include <cstdlib> 
#include "AVL.h"

int main() {
    AVL<int> avl;

    int choice;
    int key;

    while (true) {
        system("cls"); 
        cout << " ________________" << endl;
        cout << "| AVL Tree Menu  |" << endl;
        cout << " ________________" << endl << endl;
        cout << "1. Insert key" << endl;
        cout << "2. Delete key" << endl;
        cout << "3. Search key" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Preorder traversal" << endl;
        cout << "6. Postorder traversal" << endl;
        cout << "7. Height of tree" << endl;
        cout << "8. Diameter of tree" << endl;
        cout << "9. Find minimum key" << endl;
        cout << "10. Find maximum key" << endl;
        cout << "11. Find successor of key" << endl;
        cout << "12. Find predecessor of key" << endl;
        cout << "13. Exit" << endl<<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            avl.insert(key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            avl.deleteNode(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            if (avl.search(avl.root, key) != nullptr) {
                cout << "Key found!" << endl;
            }
            else {
                cout << "Key not found!" << endl;
            }
            break;
        case 4:
            avl.inorderTraversal();
            cout << endl;
            break;
        case 5:
            avl.preorderTraversal();
            cout << endl;
            break;
        case 6:
            avl.postorderTraversal();
            cout << endl;
            break;
        case 7:
            cout << "Height of tree: " << avl.height() << endl;
            break;
        case 8:
            cout << "Diameter of tree: " << avl.calculateDiameter() << endl;
            break;
        case 9:
            if (!avl.isEmpty()) {
                cout << "Minimum key: " << avl.findMin() << endl;
            }
            else {
                cout << "Tree is empty!" << endl;
            }
            break;
        case 10:
            if (!avl.isEmpty()) {
                cout << "Maximum key: " << avl.findMax() << endl;
            }
            else {
                cout << "Tree is empty!" << endl;
            }
            break;
        case 11:
            cout << "Enter key to find successor: ";
            cin >> key;
            if (!avl.isEmpty()) {
                int successor = avl.findSuccessor(key);
                if (successor != -1) {
                    cout << "Successor of " << key << ": " << successor << endl;
                }
                else {
                    cout << "Successor not found!" << endl;
                }
            }
            else {
                cout << "Tree is empty!" << endl;
            }
            break;
        case 12:
            cout << "Enter key to find predecessor: ";
            cin >> key;
            if (!avl.isEmpty()) {
                int predecessor = avl.findPredecessor(key);
                if (predecessor != -1) {
                    cout << "Predecessor of " << key << ": " << predecessor << endl;
                }
                else {
                    cout << "Predecessor not found!" << endl;
                }
            }
            else {
                cout << "Tree is empty!" << endl;
            }
            break;
        case 13:
            return 0;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }

        system("pause"); 
    }

    return 0;
}