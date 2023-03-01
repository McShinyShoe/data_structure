#include "../src/array.h"
#include "../src/linked_list.h"

using namespace std;
using namespace shiny;

template<typename dataType>
void print(SinglyLinkedList<dataType> linked_list)
{
    int i = 0;
    for(auto& element : linked_list)
    {
        cout << ++i << ") " << element.data << endl;
    }
}

template<typename dataType>
void print(DoublyLinkedList<dataType> linked_list)
{
    typename DoublyLinkedList<dataType>::Node* cursor = linked_list.tail();
    int i = 0;
    for(auto& element : linked_list)
    {
        cout << ++i << ") " << element.data << " - " << cursor->data << endl;
        cursor = cursor->prev;
    }
}


int counter = 0;
void printTest()
{
    cout << "Test" << counter++ << ":\n";
}

int main()
{

    SinglyLinkedList<int> singlyLinkedList;
    DoublyLinkedList<int> doublyLinkedList;

    cout << "Singly Linked List:" << endl;
    // push&pop front test
    singlyLinkedList.pushFront(1);
    printTest();
    print(singlyLinkedList);
    singlyLinkedList.popFront();
    printTest();
    print(singlyLinkedList);

    // push&pop back test
    singlyLinkedList.pushBack(2);
    printTest();
    print(singlyLinkedList);
    singlyLinkedList.popBack();
    printTest();
    print(singlyLinkedList);
    
    singlyLinkedList.pushFront(1);
    singlyLinkedList.pushBack(2);
    printTest();
    print(singlyLinkedList);
    // push&pop at test
    singlyLinkedList.pushAt(3, 1);
    printTest();
    print(singlyLinkedList);
    singlyLinkedList.popAt(1);
    printTest();
    print(singlyLinkedList);

    // Resize test
    singlyLinkedList.resize(5);
    printTest();
    print(singlyLinkedList);
    singlyLinkedList.resize(2);
    printTest();
    print(singlyLinkedList);
    cout << endl;

    cout << "Doubly Linked List:" << endl;
    // push&pop front test
    doublyLinkedList.pushFront(1);
    printTest();
    print(doublyLinkedList);
    doublyLinkedList.popFront();
    printTest();
    print(doublyLinkedList);

    // push&pop back test
    doublyLinkedList.pushBack(2);
    printTest();
    print(doublyLinkedList);
    doublyLinkedList.popBack();
    printTest();
    print(doublyLinkedList);
    
    doublyLinkedList.pushFront(1);
    doublyLinkedList.pushBack(2);
    printTest();
    print(doublyLinkedList);
    // push&pop at test
    doublyLinkedList.pushAt(3, 1);
    printTest();
    print(doublyLinkedList);
    doublyLinkedList.popAt(1);
    printTest();
    print(doublyLinkedList);

    // Resize test
    doublyLinkedList.resize(5);
    printTest();
    print(doublyLinkedList);
    doublyLinkedList.resize(2);
    printTest();
    print(doublyLinkedList);
    
    return 0;
}