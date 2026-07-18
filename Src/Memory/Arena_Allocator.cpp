#include <cstdint> // This is for uint64_t
#include <cstdlib> // This is for malloc and free
#include <cstring> // This is for memset
#include <cassert> // This is for assert
#include <memory.h> // This is for memset


#ifndef ARENA_ALLOCATOR_H
#endif 
#define ARENA_ALLOCATOR_H

namespace Memory
{
    class ArenaAllocator
    {
    public:
        ArenaAllocator(size_t size)
        {
            m_size = size;
            m_memory = (uint8_t*)malloc(size);
            assert(m_memory != nullptr);
            m_offset = 0;
        }

        ~ArenaAllocator()
        {
            free(m_memory);
        }

        void* allocate(size_t size)
        {
            if (m_offset + size > m_size)
            {
                return nullptr; // Not enough memory
            }
            void* ptr = m_memory + m_offset;
            m_offset += size;
            return ptr;
        }

        void reset()
        {
            m_offset = 0;
        }

    private:
        uint8_t* m_memory;
        size_t m_size;
        size_t m_offset;
    };
}
class Memory_BitmapAllocator
{
public:
    Memory_BitmapAllocator(size_t size)
    {
       
    }
};

class Arena {
    
};
