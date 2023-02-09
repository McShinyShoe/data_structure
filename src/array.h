#ifndef SHINY_ARRAY_LIB
#define SHINY_ARRAY_LIB
#include <cstddef>
#include <cstring>
#include <initializer_list>

namespace shiny
{
    template<typename dataType, size_t arraySize>
    class Array
    {
    public:
        using iterator = dataType*;
        using const_iterator = const dataType*;

    private:
        dataType m_data[arraySize] = { 0 };

    public:
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        dataType* data() const;
        size_t size() const;
        void set(const dataType& data, const size_t& index);
        const dataType& get(const size_t& index) const;
        dataType& at(const size_t& index);
        void fill(const dataType& data);
        template<size_t otherArraySize>
        Array<dataType, arraySize + otherArraySize> combine(const Array<dataType, otherArraySize>& other);

        Array();
        Array(std::initializer_list<dataType> list);
        Array(const dataType* array);
        Array(const dataType* array, const size_t& size);
        template<size_t otherArraySize>
        Array(const Array<dataType, otherArraySize>& other);

        template<size_t otherArraySize>
        Array& operator=(const Array<dataType, otherArraySize>& other);
        dataType& operator[](const size_t& index);
        
    };
}

#include "array.cpp"
#endif