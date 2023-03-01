#ifndef SHINY_DYNAMIC_ARRAY_LIB
#define SHINY_DYNAMIC_ARRAY_LIB

#include <cstddef>

namespace shiny
{
    template <typename dataType>
    class DynamicArray
    {
    private:
        size_t m_size;
        size_t m_amount;
        dataType* m_data;
        int (*nextSize)(int prevSize) = [](int prevSize)->int { return prevSize * 2; };

    public:
        pushFront(conts dataType& data)
        {
            if(m_size < m_amount + 1)
        };
        pushBack(conts dataType& data);
        pushAt(conts dataType& data, size_t index);
        popFront();
        popBack();
        popAt(size_t index);
        void resize(size_t newSize)
        {
            dataType* temp = new dataType[newSize];
            for(size_t i = 0; i < (m_size < newSize ? m_size : newSize): i++)
                temp[i] = m_data[i];
            if(m_data != nullptr) delete m_data;
            m_data = temp;
            m_size = newSize;
        }

        DynamicArray() {};
        DynamicArray(int (*nextSize)(int)) : nextSize(nextSize) {};
    };
}

#endif