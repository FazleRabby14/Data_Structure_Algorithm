#include"binarysearchtree.cpp"
#include<iostream>
using namespace std;


int main()
{
   TreeType<int> tree;

   if(tree.IsEmpty()) {
    cout<<"Tree is Empty"<<endl;
   }
   else{
    cout<<"Tree is not Empty"<<endl;
   }

   tree.InsertItem(4);
   tree.InsertItem(9);
   tree.InsertItem(2);
   tree.InsertItem(7);
   tree.InsertItem(3);
   tree.InsertItem(11);
   tree.InsertItem(17);
   tree.InsertItem(0);
   tree.InsertItem(5);
   tree.InsertItem(1);

   if(tree.IsEmpty()) {
    cout<<"Tree is Empty"<<endl;
   }
   else{
    cout<<"Tree is not Empty"<<endl;
   }

   cout<<"Length of tree is:"<<tree.LengthIs()<<endl;


    // Retrieve 9 and print whether found or not
    int item = 9;
    bool found;
    tree.RetrieveItem(item, found);
    if (found) {
        cout << "Item " << item << " is found" <<endl;
    } else {
        cout << "Item " << item << " is not found" <<endl;
    }

    // Retrieve 13 and print whether found or not
    item = 13;
    tree.RetrieveItem(item, found);
    if (found) {
        cout << "Item " << item << " is found" << std::endl;
    } else {
        cout << "Item " << item << " is not found" << std::endl;
    }

    // Print the elements in the tree (In-order)
    cout << "Elements in the tree (Inorder): ";
    tree.ResetTree(IN_ORDER);
    bool finished = false;
    while (!finished) {
        tree.GetNextItem(item, IN_ORDER, finished);
        if (!finished) {
            cout << item << " ";
        }
    }
    cout <<endl;

    // Print the elements in the tree (preorder)
    cout << "Elements in the tree (preorder): ";
    tree.ResetTree(PRE_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, PRE_ORDER, finished);
        if (!finished) {
            cout << item << " ";
        }
    }
    cout <<endl;

    // Print the elements in the tree (postorder)
    cout << "Elements in the tree (postorder): ";
    tree.ResetTree(POST_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, POST_ORDER, finished);
        if (!finished) {
            cout << item << " ";
        }
    }
    cout <<endl;

    // Make the tree empty
    tree.MakeEmpty();

    // Given a sequence of integers, determine the best ordering of the integers to insert them into a binary search tree.
    int sequence[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};
    int sequenceSize = sizeof(sequence) / sizeof(sequence[0]);

    for (int i = 0; i < sequenceSize; i++)
        tree.InsertItem(sequence[i]);

    // Print the elements in the tree (inorder)
    cout << "Elements in the tree (inorder): ";
    tree.ResetTree(IN_ORDER);
    tree.GetNextItem(item, IN_ORDER, found);
    while (!found)
    {
        cout << item << " ";
        tree.GetNextItem(item, IN_ORDER, found);
    }
    cout << endl;

    return 0;
}
