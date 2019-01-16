typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector{

protected:
    Rank _size; int _capacity; T* _elem;
    void copyFrom(T const* A, Rank lo, Rank hi); //复制数组，区间[lo,hi）
    void expand(); // 扩容vector
    void shrink(); // 压缩vector空间
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi); //冒泡排序
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi); //选择排序
    void merge(Rank lo, Rank hi); //归并
    void mergeSort(Rank lo, Rank hi); //归并排序
    Rank partition(Rank lo, Rank hi); //快排分割
    void quickSort(Rank lo, Rank hi); //快排
    void heapSort(Rank lo, Rank hi); // 堆排序


public:
    //构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
    { _elem = new T[_capacity = c]; 
        for (_size = 0, _size < s; (_elem[_size++] = v);); }
    Vector(T const* A, Rank lo, Rank hi)
    {
        copyFrom(A, lo, hi);
    }
    Vector(T const* A, Rank n)
    {
        copyFrom(A, 0, n);
    }
    Vector(Vector<T> const& V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi);
    }
    Vector(Vector<T> const& V)
    {
        copyFrom(V._elem, 0, V._size);
    }
    //析构函数
    ~Vector(){ delete [] _elem;}

    //Read
    Rank size() const {return _size;}
    bool empty() const{ return !_size; }
    int disordered() const;
    Rank find(T const& e) const { return find(e, 0, (Rank)_size);}
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e) const
    {
        return (0 >= _size) ? -1 : search(e, (Rank)0, (Rank)_size);
    }
    Rank search(T const& e, Rank lo, Rank hi) const;
    //Write
    T& operator[](Rank r) const;
    Vector<T>& operator=(Vector<T> const& V)
    {
    if (_elem) delete [] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
    }
    T remove (Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e){ return insert(_size, e);}
    void sort(Rank lo, Rank hi);
    void sort(){sort(0, _size);}
    void unsort(Rank lo, Rank hi);
    void unsort(){unsort(0,_size);}
    int deduplicate();
    int uniquify();
    //
    void traverse(void (*)(T&));
    template <typename VST> void traverse(VST&);

};