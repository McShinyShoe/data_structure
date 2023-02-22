#include "linked_list.h"

#include <iostream>

namespace shiny
{
        template <typename dataType>
    SinglyLinkedList<dataType>::iterator::iterator() : m_ptr(nullptr) {}
    template <typename dataType>
    SinglyLinkedList<dataType>::iterator::iterator(const iterator &other) : m_ptr(other.m_ptr) {}
    template <typename dataType>
    SinglyLinkedList<dataType>::iterator::iterator(pointer node) : m_ptr(node) {}
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator::reference SinglyLinkedList<dataType>::iterator::operator*()
    {
        return *m_ptr;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator::pointer SinglyLinkedList<dataType>::iterator::operator->()
    {
        return m_ptr;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator &SinglyLinkedList<dataType>::iterator::operator++()
    {
        m_ptr = m_ptr->link;
        return *this;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator SinglyLinkedList<dataType>::iterator::operator++(int)
    {
        iterator old = *this;
        operator++();
        return old;
    }
    template <typename dataType>
    SinglyLinkedList<dataType>::const_iterator::const_iterator() : m_ptr(nullptr) {}
    template <typename dataType>
    SinglyLinkedList<dataType>::const_iterator::const_iterator(const const_iterator &other) : m_ptr(other.m_ptr) {}
    template <typename dataType>
    SinglyLinkedList<dataType>::const_iterator::const_iterator(pointer node) : m_ptr(node) {}
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator::reference SinglyLinkedList<dataType>::const_iterator::operator*() const
    {
        return *m_ptr;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator::pointer SinglyLinkedList<dataType>::const_iterator::operator->() const
    {
        return m_ptr;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator &SinglyLinkedList<dataType>::const_iterator::operator++()
    {
        m_ptr = m_ptr->link;
        return *this;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator SinglyLinkedList<dataType>::const_iterator::operator++(int)
    {
        const_iterator old = *this;
        operator++();
        return old;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator SinglyLinkedList<dataType>::begin()
    {
        return iterator(m_head);
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::iterator SinglyLinkedList<dataType>::end()
    {
        return iterator(nullptr);
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator SinglyLinkedList<dataType>::cbegin() const
    {
        return const_iterator(m_head);
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::const_iterator SinglyLinkedList<dataType>::cend() const
    {
        return const_iterator(nullptr);
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::Node *SinglyLinkedList<dataType>::head() const
    {
        return m_head;
    }
    template <typename dataType>
    size_t SinglyLinkedList<dataType>::size() const
    {
        size_t r = 0;
        Node* cursor = m_head;
        while(cursor != nullptr) 
        {
            r++;
            cursor = cursor->link;
        }
        return r;
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::set(const dataType &data, size_t index)
    {
        Node* cursor = m_head;
        while(index--)
        {
            if(cursor == nullptr) return;
            cursor = cursor->link;
        };
        cursor->data = data;
    }

    template <typename dataType>
    const dataType &SinglyLinkedList<dataType>::get(size_t index) const
    {
        Node* cursor = m_head;
        while(index--)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        };
        return cursor->data;
    }
    template <typename dataType>
    dataType &SinglyLinkedList<dataType>::at(size_t index)
    {
        Node* cursor = m_head;
        while(index--)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        };
        return cursor->data;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::Node *SinglyLinkedList<dataType>::front()
    {
        return m_head;
    }
    template <typename dataType>
    typename SinglyLinkedList<dataType>::Node *SinglyLinkedList<dataType>::back()
    {
        if(m_head == nullptr) return nullptr;
        Node* cursor = m_head;
        while(cursor->link != nullptr) cursor = cursor->link;
        return cursor;
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::pushFront(const dataType &data)
    {
        m_head = new Node {data, m_head};
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::pushBack(const dataType &data)
    {
        if(m_head == nullptr) 
        {
            m_head = new Node {data, nullptr};
            return;
        }
        Node* cursor = back();
        cursor->link = new Node{data, nullptr};
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::pushAt(const dataType &data, size_t index)
    {
        if(index == 0)
        {
            pushFront(data);
            return;
        }
        else if(index == size())
        {
            pushBack(data);
            return;
        }
        Node* cursor = m_head;
        while(--index)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        };
        cursor->link = new Node {data, cursor->link};

    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::popFront()
    {
        if(m_head == nullptr) return;
        Node* temp = m_head->link;
        delete m_head;
        m_head = temp;  
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::popBack()
    {
        if(m_head == nullptr) return;
        else if(m_head->link == nullptr) 
        {
            delete m_head;
            m_head = nullptr;
            return;
        }
        Node* cursor = m_head;
        while(cursor->link->link != nullptr) cursor = cursor->link;
        delete cursor->link;
        cursor->link = nullptr;
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::popAt(size_t index)
    {
        if(m_head == nullptr) return;
        else if(index == 0)
        {
            popFront();
            return;
        }
        else if(index == size())
        {
            popBack();
            return;
        }
        Node* cursor = m_head;
        while(--index)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        }
        Node* old = cursor->link->link;
        delete cursor->link;
        cursor->link = old;
    }
    template <typename dataType>
    void SinglyLinkedList<dataType>::resize(const size_t &newSize)
    {
        size_t currentSize = size();
        Node* cursor = back();
        while(currentSize < newSize)
        {
            pushBack(dataType());
            currentSize++;
        }
        while(currentSize > newSize)
        {
            popBack();
            currentSize--;
        }

    }
    template <typename dataType>
    SinglyLinkedList<dataType>::SinglyLinkedList() {}
    template <typename dataType>
    SinglyLinkedList<dataType>::SinglyLinkedList(const SinglyLinkedList &other)
    {
        Node* cursor;
        for(const_iterator it = other.cbegin(); it != other.cend(); it++)
        {
            if(m_head == nullptr)
            {
                m_head = new Node {it->data, nullptr};
                cursor = m_head;
            }
            else
            {
                cursor->link = new Node {it->data, nullptr};
                cursor = cursor->link;
            }
        };
    }
    template <typename dataType>
    SinglyLinkedList<dataType>::SinglyLinkedList(const std::initializer_list<dataType>& list)
    {
        Node* cursor;
        for(const dataType& data : list)
        {
            if(m_head == nullptr)
            {
                m_head = new Node{data, nullptr};
                cursor = m_head;
            }
            else
            {
                cursor->link = new Node{data, nullptr};
                cursor = cursor->link;
            }
        };
    }
    template <typename dataType>
    SinglyLinkedList<dataType>::SinglyLinkedList(const dataType *array, const size_t& size)
    {
        Node* cursor;
        for(size_t i = 0; i < size; i++)
        {
            if(m_head == nullptr)
            {
                m_head = new Node {array[i], nullptr};
                cursor = m_head;
            }
            else
            {
                cursor->link = new Node {array[i], nullptr};
                cursor = cursor->link;
            }
        };
    }

    template <typename dataType>
    DoublyLinkedList<dataType>::iterator::iterator() : m_ptr(nullptr) {}
    template <typename dataType>
    DoublyLinkedList<dataType>::iterator::iterator(const iterator &other) : m_ptr(other.m_ptr) {}
    template <typename dataType>
    DoublyLinkedList<dataType>::iterator::iterator(pointer node) : m_ptr(node) {}
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator::reference DoublyLinkedList<dataType>::iterator::operator*()
    {
        return *m_ptr;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator::pointer DoublyLinkedList<dataType>::iterator::operator->()
    {
        return m_ptr;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator &DoublyLinkedList<dataType>::iterator::operator++()
    {
        m_ptr = m_ptr->next;
        return *this;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator DoublyLinkedList<dataType>::iterator::operator++(int)
    {
        iterator old = *this;
        operator++();
        return old;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator &DoublyLinkedList<dataType>::iterator::operator--()
    {
        m_ptr = m_ptr->prev;
        return *this;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator DoublyLinkedList<dataType>::iterator::operator--(int)
    {
        iterator old = *this;
        operator--();
        return old;
    }
    template <typename dataType>
    DoublyLinkedList<dataType>::const_iterator::const_iterator() : m_ptr(nullptr) {}
    template <typename dataType>
    DoublyLinkedList<dataType>::const_iterator::const_iterator(const const_iterator &other) : m_ptr(other.m_ptr) {}
    template <typename dataType>
    DoublyLinkedList<dataType>::const_iterator::const_iterator(pointer node) : m_ptr(node) {}
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator::reference DoublyLinkedList<dataType>::const_iterator::operator*() const
    {
        return *m_ptr;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator::pointer DoublyLinkedList<dataType>::const_iterator::operator->() const
    {
        return m_ptr;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator &DoublyLinkedList<dataType>::const_iterator::operator++()
    {
        m_ptr = m_ptr->next;
        return *this;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator DoublyLinkedList<dataType>::const_iterator::operator++(int)
    {
        const_iterator old = *this;
        operator++();
        return old;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator &DoublyLinkedList<dataType>::const_iterator::operator--()
    {
        m_ptr = m_ptr->prev;
        return *this;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator DoublyLinkedList<dataType>::const_iterator::operator--(int)
    {
        const_iterator old = *this;
        operator--();
        return old;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator DoublyLinkedList<dataType>::begin()
    {
        return iterator(m_head);
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::iterator DoublyLinkedList<dataType>::end()
    {
        return iterator(nullptr);
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator DoublyLinkedList<dataType>::cbegin() const
    {
        return const_iterator(m_head);
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::const_iterator DoublyLinkedList<dataType>::cend() const
    {
        return const_iterator(nullptr);
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::Node *DoublyLinkedList<dataType>::head() const
    {
        return m_head;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::Node *DoublyLinkedList<dataType>::tail() const
    {
        return m_tail;
    }
    template <typename dataType>
    size_t DoublyLinkedList<dataType>::size() const
    {
        size_t r = 0;
        Node* cursor = m_head;
        while(cursor != nullptr) 
        {
            r++;
            cursor = cursor->next;
        }
        return r;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::set(const dataType &data, size_t index)
    {
        Node* cursor = m_head;
        while(index--)
        {
            if(cursor == nullptr) return;
            cursor = cursor->link;
        };
        cursor->data = data;
    }

    template <typename dataType>
    const dataType &DoublyLinkedList<dataType>::get(size_t index) const
    {
        Node* cursor = m_head;
        while(index--)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        };
        return cursor->data;
    }
    template <typename dataType>
    dataType &DoublyLinkedList<dataType>::at(size_t index)
    {
        Node* cursor = m_head;
        while(index--)
        {
            //if(cursor == nullptr);
            cursor = cursor->link;
        };
        return cursor->data;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::Node *DoublyLinkedList<dataType>::front()
    {
        return m_head;
    }
    template <typename dataType>
    typename DoublyLinkedList<dataType>::Node *DoublyLinkedList<dataType>::back()
    {
        return m_tail;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::pushFront(const dataType &data)
    {
        Node* temp = new Node{data, nullptr, m_head};
        if(m_head != nullptr) m_head->prev = temp;
        if(m_tail == nullptr) m_tail = temp;
        m_head = temp;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::pushBack(const dataType &data)
    {
        Node* temp = new Node{data, m_tail, nullptr};
        if(m_tail != nullptr) m_tail->next = temp;
        if(m_head == nullptr) m_head = temp;
        m_tail = temp;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::pushAt(const dataType &data, size_t index)
    {
        if(index == 0)
        {
            pushFront(data);
            return;
        }
        else if(index == size())
        {
            pushBack(data);
            return;
        }
        Node* cursor = m_head;
        while(--index)
        {
            //if(cursor == nullptr);
            cursor = cursor->next;
        };
        Node* temp = new Node {data, cursor, cursor->next};
        cursor->next = temp;
        cursor->next->prev = temp;

    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::popFront()
    {
        if(m_head == nullptr) return;
        if(m_tail == m_head) m_tail = nullptr;
        Node* temp = m_head->next;
        delete m_head;
        m_head = temp;
        if(m_head != nullptr) m_head->prev = nullptr;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::popBack()
    {
        if(m_tail == nullptr) return;
        if(m_head == m_tail) m_head = nullptr;
        Node* temp = m_tail->prev;
        delete m_tail;
        m_tail = temp;
        if(m_tail != nullptr) m_tail->next = nullptr;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::popAt(size_t index)
    {
        if(m_head == nullptr) return;
        else if(index == 0)
        {
            popFront();
            return;
        }
        else if(index == size())
        {
            popBack();
            return;
        }
        Node* cursor = m_head;
        while(--index)
        {
            //if(cursor == nullptr);
            cursor = cursor->next;
        }
        Node* old = cursor->next->next;
        delete cursor->next;
        cursor->next = old;
    }
    template <typename dataType>
    void DoublyLinkedList<dataType>::resize(const size_t &newSize)
    {
        size_t currentSize = size();
        Node* cursor = back();
        while(currentSize < newSize)
        {
            pushBack(dataType());
            currentSize++;
        }
        while(currentSize > newSize)
        {
            popBack();
            currentSize--;
        }
    }
    template <typename dataType>
    DoublyLinkedList<dataType>::DoublyLinkedList() {}
    template <typename dataType>
    DoublyLinkedList<dataType>::DoublyLinkedList(const DoublyLinkedList &other)
    {
        Node* cursor;
        for(const_iterator it = other.cbegin(); it != other.cend(); it++)
        {
            if(m_head == nullptr)
            {
                m_head = new Node {it->data, nullptr, nullptr};
                m_tail = m_head;
                cursor = m_head;
            }
            else
            {
                cursor->next = new Node {it->data, cursor, nullptr};
                cursor = cursor->next;
                m_tail = cursor;
            }
        };
    }
    template <typename dataType>
    DoublyLinkedList<dataType>::DoublyLinkedList(const std::initializer_list<dataType>& list)
    {
        Node* cursor;
        for(const dataType& data : list)
        {
            if(m_head == nullptr)
            {
                m_head = new Node{data, nullptr};
                cursor = m_head;
            }
            else
            {
                cursor->link = new Node{data, nullptr};
                cursor = cursor->link;
            }
        };
    }
    template <typename dataType>
    DoublyLinkedList<dataType>::DoublyLinkedList(const dataType *array, const size_t& size)
    {
        Node* cursor;
        for(size_t i = 0; i < size; i++)
        {
            if(m_head == nullptr)
            {
                m_head = new Node {array[i], nullptr};
                cursor = m_head;
            }
            else
            {
                cursor->link = new Node {array[i], nullptr};
                cursor = cursor->link;
            }
        };
    }
}