#ifndef HANDLE_H_
#define HANDLE_H_
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class handle_t
{
public:
    handle_t(T* p=0) : ptr(p), use(new size_t(1)) {}
    T& operator* ();
    T* operator->();

    const T& operator* () const;
    const T* operator->() const;

    handle_t(const handle_t& sp) : ptr(sp.ptr), use(sp.use)
    {
        ++*use;
    }

    handle_t& operator=(const handle_t& rhs);
    ~handle_t() {rem_ref();}

private:
    T* ptr;
    size_t* use;
    void rem_ref()
    {
        if (--*use == 0)
        {
            delete ptr;
            delete use;
        }
        else
        {
            cout << "has " <<*use << " ref" << endl;
        }
    }
};

template<typename T>
inline handle_t<T>& handle_t<T>::operator = (const handle_t& rhs)
{
    ++*rhs.use;
    rem_ref();
    ptr = rhs.ptr;
    use = rhs.use;

    return *this;
}

template<typename T>
inline T& handle_t<T>::operator *()
{
    if (ptr)
        return *ptr;
    throw std::runtime_error("dereference of unbound Handle");
}

template<typename T>
inline T* handle_t<T>::operator ->()
{
    if (ptr)
        return ptr;
    throw std::runtime_error("dereference of unbound Handle");
}
template<typename T>
inline const T& handle_t<T>::operator *() const
{
    if (ptr)
        return *ptr;
    throw std::runtime_error("dereference of unbound Handle");
}
template<typename T>
inline const T* handle_t<T>::operator ->() const
{
    if (ptr)
        return ptr;
    throw std::runtime_error("dereference of unbound Handle");
}


#endif // HANDLE_H_
