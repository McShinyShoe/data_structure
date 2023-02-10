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
            Node* link = nullptr;
        };
        class iterator
        {
        public:
            using value_type = Node;
            using pointer = value_type*;
            using reference = value_type&;

        private:
            pointer m_ptr;
        
        public:
            iterator();
            iterator(const iterator& other);
            iterator(pointer node);

            reference operator*();
            pointer operator->();
            iterator& operator++();
            iterator operator++(int);

            
            friend bool operator==(const iterator& a, const iterator& b)
            {
                return a.m_ptr == b.m_ptr;
            };
            friend bool operator!=(const iterator& a, const iterator& b)
            {
                return a.m_ptr != b.m_ptr;
            };
        };
        class const_iterator
        {
        public:
            using value_type = const Node;
            using pointer = value_type*;
            using reference = value_type&;

        private:
            pointer m_ptr;
        
        public:
            const_iterator();
            const_iterator(const const_iterator& other);
            const_iterator(pointer node);

            reference operator*() const;
            pointer operator->() const;
            const_iterator& operator++();
            const_iterator operator++(int);

            
            friend bool operator==(const const_iterator& a, const const_iterator& b)
            {
                return a.m_ptr == b.m_ptr;
            };
            friend bool operator!=(const const_iterator& a, const const_iterator& b)
            {
                return a.m_ptr != b.m_ptr;
            };
        };
        

    private:
        Node* m_head = nullptr;

    public:
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        Node* head() const;
        size_t size() const;
        void set(const dataType& data, size_t index);
        const dataType& get(size_t index) const;
        dataType& at(size_t index);
        Node* front();
        Node* back();
        void pushFront(const dataType& data);
        void pushBack(const dataType& data);
        void pushAt(const dataType& data, size_t index);
        void popFront();
        void popBack();
        void popAt(size_t index);
        void resize(const size_t& newSize);
        
        SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList& other);
        SinglyLinkedList(const std::initializer_list<dataType>& list);
        SinglyLinkedList(const dataType* array, const size_t& size);
    };
}

#include "linked_list.cpp"
#endif