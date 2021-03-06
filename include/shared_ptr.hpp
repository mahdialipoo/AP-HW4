template <typename T>
SharedPtr<T>::SharedPtr(T *p) : _p{p}
{
    if (p)
        if (cnts.count(_p) == 0)
            cnts[_p] = 1;
        else
            cnts[_p]++;
}
template <typename T>
T *make_shared(T x) { return new T{x}; }
template <typename T>
SharedPtr<T>::SharedPtr() : SharedPtr<T>(nullptr) {}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (_p && !(--cnts[_p]))
        delete _p;
    _p = nullptr;
}
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &p) : _p{p._p}
{
    cnts[_p]++;
}
template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &p)
{
    cnts[_p]--;
    cnts[p._p]++;
    _p = p._p;
    return *this;
}
template <typename T>
T *&SharedPtr<T>::get()
{
    return _p;
}
template <typename T>
void SharedPtr<T>::reset(T *x)
{
    if (_p && !(--cnts[_p]))
        delete _p;
    if (x && cnts.count(x) == 0)
        cnts[x] = 1;
    else if (x)
        cnts[x]++;
    _p = x;
}
template <typename T>
T *SharedPtr<T>::operator->()
{
    return _p;
}
template <typename T>
T SharedPtr<T>::operator*()
{
    return *_p;
}
template <typename T>
SharedPtr<T>::operator bool()
{
    return _p;
}
template <typename T>
size_t SharedPtr<T>::use_count()
{
    return cnts[_p];
}
