#ifndef SHINY_LINKED_LIST
#define SHINY_LINKED_LIST
#include <cstddef>
#include <initializer_list>

namespace shiny
{
    template<typename dataType>
    class SinglyLinkedList
    {
    public:
        struct Node
        {
            dataType data;
            Node* link;
        };
        class iterator
        {
        public:
            using value_type = Node;
            using pointer = Node*;
            using reference = Node&;

        private:
            pointer m_ptr;
        
        public:
            iterator() {};
            iterator(Node* node);

            reference operator*();
            pointer operator->();
            iterator& operator++();
            iterator operator++(int);
            friend bool operator==(const iterator& a, const iterator& b);
            friend bool operator!=(const iterator& a, const iterator& b);

        };

    private:
        Node* m_head;

    public:
        iterator begin();
        iterator end();

        Node* front();
        Node* back();
        void pushFront(const dataType& data);
        void pushBack(const dataType& data);
        void pushAt(const dataType& data, size_t index);
        void popFront();
        void popBack();
        void popAt(size_t index);

        SinglyLinkedList() {};
        SinglyLinkedList(const SinglyLinkedList& other);
        SinglyLinkedList(std::initializer_list<dataType> list);
        SinglyLinkedList(const dataType* array, size_t size);
        template<typename container_t>
        SinglyLinkedList(container_t container);
    };
}

#endif