#include "array.h"

namespace shiny
{
    template<typename dataType, size_t arraySize>
    typename Array<dataType, arraySize>::iterator Array<dataType, arraySize>::begin()
    {
        return iterator(&m_data[0]);
    };
    template<typename dataType, size_t arraySize>
    typename Array<dataType, arraySize>::iterator Array<dataType, arraySize>::end()
    {
        return iterator(&m_data[arraySize]);
    };
    template<typename dataType, size_t arraySize>
    typename Array<dataType, arraySize>::const_iterator Array<dataType, arraySize>::cbegin() const 
    {
        return iterator(&m_data[0]);
    };
    template<typename dataType, size_t arraySize>
    typename Array<dataType, arraySize>::const_iterator Array<dataType, arraySize>::cend() const 
    {
        return iterator(&m_data[arraySize]);
    };

    template<typename dataType, size_t arraySize>
    dataType* Array<dataType, arraySize>::data() const
    {
        return m_data;
    };
    template<typename dataType, size_t arraySize>
    size_t Array<dataType, arraySize>::size() const
    {
        return arraySize;
    };
    template<typename dataType, size_t arraySize>
    void Array<dataType, arraySize>::set(const dataType& data, const size_t& index)
    {
        m_data[index] = data;
    };
    template<typename dataType, size_t arraySize>
    const dataType& Array<dataType, arraySize>::get(const size_t& index) const
    {
        return m_data[index];
    };
    template<typename dataType, size_t arraySize>
    dataType& Array<dataType, arraySize>::at(const size_t& index)
    {
        return m_data[index];
    };
    template<typename dataType, size_t arraySize>
    void Array<dataType, arraySize>::fill(const dataType& data)
    {
        for(dataType& dat : *this) dat = data;
    };
    template<typename dataType, size_t arraySize>
    template<size_t otherArraySize>
    Array<dataType, arraySize + otherArraySize> Array<dataType, arraySize>::combine(const Array<dataType, otherArraySize>& other)
    {
        Array<dataType, arraySize + otherArraySize> ret;
        size_t i = 0;
        memcpy(ret.begin(), begin(), arraySize * sizeof(dataType));
        memcpy(ret.begin() + arraySize, other.cbegin(), otherArraySize * sizeof(dataType));
        return ret;
    };

    template<typename dataType, size_t arraySize>
    Array<dataType, arraySize>::Array()
    {

    };
    template<typename dataType, size_t arraySize>
    Array<dataType, arraySize>::Array(std::initializer_list<dataType> list)
    {
        memcpy(m_data, list.begin(), (list.size() < arraySize ? list.size() : arraySize) * sizeof(dataType));
    };
    template<typename dataType, size_t arraySize>
    Array<dataType, arraySize>::Array(const dataType* array)
    {
        memcpy(m_data, array, arraySize * sizeof(dataType));
    };
    template<typename dataType, size_t arraySize>
    Array<dataType, arraySize>::Array(const dataType* array, const size_t& size)
    {
        memcpy(m_data, array, (size < arraySize ? size : arraySize) * sizeof(dataType));
    };
    template<typename dataType, size_t arraySize>
    template<size_t otherArraySize>
    Array<dataType, arraySize>::Array(const Array<dataType, otherArraySize>& other)
    {
        memcpy(m_data, other.cbegin(), (other.size() < arraySize ? other.size() : arraySize) * sizeof(dataType));
    };


    template<typename dataType, size_t arraySize>
    template<size_t otherArraySize>
    Array<dataType, arraySize>& Array<dataType, arraySize>::operator=(const Array<dataType, otherArraySize>& other)
    {
        memcpy(m_data, other.cbegin(), arraySize);
        return *this;
    };
    template<typename dataType, size_t arraySize>
    dataType& Array<dataType, arraySize>::operator[](const size_t& index)
    {
        return at(index);
    };
}