#include <iostream>
#include "BST.h"
#include "Node.h"
#include <cstddef>

using namespace std;

int main()
{
    // 45, 15, 79, 90, 10, 55, 12, 20, 50
    BST t;
    t.insert(45);
    t.insert(15);
    t.insert(79);
    t.insert(90);
    t.insert(10);
    t.insert(55);
    t.insert(12);
    t.insert(20);
    t.insert(50);

    cout << "Dusplay The Tree Content : \n";
    t.preorder(t.root);
    cout << "\n...................\n";
    t.inorder(t.root);
    cout << "\n...................\n";
    t.postorder(t.root);
    cout << "\n...................\n";

    int key;
    cout << "enter item to search for : \n";
    cin >> key;
    if (t.search(key))
        cout << "item found \n";
    else
        cout << "Sorry, item not found \n";

    cout << "Find Minimum \n";
    Node* min = t.findmin(t.root);
    if (min == 0) // NULL
        cout << "No Item Exist\n";
    else
        cout << "Minimum is " << min->data << endl;

    cout << "Find Maximum \n";
    Node* max = t.findmax(t.root);
    if (max == 0) // NULL
        cout << "No Item Exist\n";
    else
        cout << "Maximum is " << max->data << endl;

    cout << "\n Delete items \n";
    Node* result = t.Delete(t.root, 12);
    cout << "preoreder after delete 12 \n";
    t.preorder(result);

    result = t.Delete(t.root, 15);
    cout << "\n preoreder after delete 15 \n";
    t.preorder(result);
}