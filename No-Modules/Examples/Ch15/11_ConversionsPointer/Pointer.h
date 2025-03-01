#pragma once

#include <utility>

template <typename T> class Pointer
{
  public:
    explicit Pointer(T *ptr) : m_ptr{ptr}
    {
    }

    virtual ~Pointer()
    {
        reset();
    }

    // Disallow copy constructor and copy assignment.
    Pointer(const Pointer &src)            = delete;
    Pointer &operator=(const Pointer &rhs) = delete;

    // Allow move construction.
    Pointer(Pointer &&src) noexcept : m_ptr{std::exchange(src.m_ptr, nullptr)}
    {
    }

    // Allow move assignment.
    Pointer &operator=(Pointer &&rhs) noexcept
    {
        if (this != &rhs)
        {
            reset();
            m_ptr = std::exchange(rhs.m_ptr, nullptr);
        }
        return *this;
    }

    T &operator*()
    {
        return *m_ptr;
    }
    const T &operator*() const
    {
        return *m_ptr;
    }

    T *operator->()
    {
        return m_ptr;
    }
    const T *operator->() const
    {
        return m_ptr;
    }

    operator void *() const
    {
        return m_ptr;
    }

  private:
    void reset()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
    T *m_ptr{nullptr};
};
