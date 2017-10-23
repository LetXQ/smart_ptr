#ifndef SMART_PTR_H_
#define SMART_PTR_H_
#include <iostream>

using namespace std;
template <typename T>
class smart_ptr_t;

template <typename T>
class u_ptr_t
{
private:
    friend class smart_ptr_t<T>;

    u_ptr_t(T *ptr) : m_p(ptr), m_count(1) {}

    ~u_ptr_t() {delete m_p;}

    int m_count;

    T *m_p;
};

template <typename T>
class smart_ptr_t
{
private:
    u_ptr_t<T>* m_rp;

public:
    smart_ptr_t(T* ptr) : m_rp(new u_ptr_t<T>(ptr)) {}

    smart_ptr_t(const smart_ptr_t<T>& sp) : m_rp(sp.m_rp)
    {
        ++ m_rp->m_count;
    }

    smart_ptr_t& operator =(const smart_ptr_t<T>& rhs)
    {
        ++rhs.m_rp->m_count;
        if (--m_rp->m_count == 0)
        {
            delete m_rp;
        }
        m_rp = rhs.m_rp;
        return *this;
    }

    T& operator* ()
    {
        return *(m_rp->m_p);
    }

    T* operator -> ()
    {
        return m_rp->m_p;
    }

    ~smart_ptr_t()
    {
        if (--m_rp->m_count == 0)
        {
            delete m_rp;
        }
        else
        {
            cout << "count: " << m_rp->m_count << endl;
        }
    }
};
#endif // SMART_PTR_H_
