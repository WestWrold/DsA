#include"vector.hpp"

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2*(hi - lo)]; _size = 0;
    while (lo < hi)
        {
            _elem[_size++] = A[lo++];
        }
}

template <typename T> 
void Vector<T>::expand()
{
    if (_size < _capacity ) return ;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oldElem = _elem; _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        {
            _elem[i] = oldElem[i];
        }
    delete [] oldElem;
}

template <typename T> 
void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1) return ;
    if (_size<<2 > _capacity) return ;
    T* oldElem = _elem; _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete [] oldElem;
}

template <typename T> T& Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template <typename T> Rank Vector<T>::insert(Rank r, T const& e)
{
    expand();
    for( int i = _size; i > r; i-- )
    {
        _elem[i] = _elem[i-1];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T> Rank Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi) return 0;
    while (hi < _size) 
        _elem[lo++] = _elem[hi++];
    _size = _size - hi + lo;
    shrink();
    return hi-lo;
}

template <typename T> T Vector<T>::remove(Rank r)
{
    T  e = _elem[r];
    remove(r, r+1);
    return e;
}

template <typename T> int Vector<T>::deduplicate() //删除无序向量中的重复元素 n^2
{
    int oldSize = _size;
    Rank i = 1;
    while ( i < _size)
        (find(_elem[i], 0, i)< 0 )? i++ : remove(i);
    return oldSize-_size; 
}

template <typename T> void Vector<T>::traverse(void (*visit)(T&))//函数指针
{
    for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> template <typename VST>//函数对象
void Vector<T>::traverse(VST& visit)
{
    for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> struct Increase
{
    virtual void operator()(T& e){ e++; }
};

template <typename T> void increase(Vector<T> & V)
{
    V.traverse(Increase<T>());  
}

template <typename T> int Vector<T>::disordered() const
{
    int n = 0;
    for (int i = 1; i < _size; i++)
    {
        if (_elem[i-1] > _elem[i]) n++;
    }
    return n;
}

// template <typename T> int Vector<T>::uniquify()//有序向量删除重复元素 n^2
// {
//     int oldSize = _size; int i = 0;
//     while ( i < _size - 1)
//     {
//         _elem[i] == _elem[i+1] ? remove(i+1) : i++;
//     }
//     return oldSize - _size;
// }
template <typename T> int Vector<T>::uniquify()
{
    int i = 0, j = 0;
    while (++j < _size-1)
        if (_elem[i] != _elem[j])
        {
            _elem[++i] = _elem[j];
        }
    _size = ++i; shrink();
    return j-i;
    
}