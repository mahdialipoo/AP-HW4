template <typename T>
UniquePtr<T>::UniquePtr(T *p) { _p = p; };
template <typename T>
T *make_unique(T x) { return new T{x}; }
template <typename T>
UniquePtr<T>::UniquePtr() : UniquePtr<T>(nullptr) {}
template <typename T>
UniquePtr<T>::~UniquePtr() { delete _p; }