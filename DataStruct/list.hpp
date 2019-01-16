#include<stdlib.h>
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*
//节点模板
template <typename T> struct ListNode{
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;

    ListNode() {}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL): data(e), pred(p), succ(s){}

    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

//链表
template <typename T> class List{

private:
    int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNodePosi(T), int);
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
    void mergeSort(ListNodePosi(T)&, int);
    void selectionSort(ListNodePosi(T), int);
    void insertionSort(ListNodePosi(T), int);

public:
    List(){init();}
    List(List<T> const& L);
    List(List<T> const& L, Rank r, int n);
    List(ListNodePosi(T) p, int n);

    ~List();

    //read
    Rank size() const { return _size;}
    bool empty() const { return  _size <= 0;}
    T& operator[](int r) const;
    ListNodePosi(T) first() const{ return header->succ;}
    ListNodePosi(T) last() const{ return trailer->pred;}
    bool valid(ListNodePosi(T) p)
    { return p && (trailer!=p) && (header != p );}
    int disordered() const;

    ListNodePosi(T) find(T const & e ) const {return find(e, _size, trailer);}
    ListNodePosi(T) find(T const & e, int n, ListNodePosi(T) p) const;

    ListNodePosi(T) search(T const& e) const{ return search(e, _size, trailer);}
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;

    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
    ListNodePosi(T) selectMax(){return selectMax(header->succ, _size);}

    //write
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e );
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);

    T remove(ListNodePosi(T) p);
    void merge(List<T>& L) {merge(first(), _size, L, L.first(), L._size);}
    void sort(ListNodePosi(T) p, int n);
    void sort() {sort(first(), _size);}
    int deduplicate();
    int uniquify();
    void reverse();

    void traverse(void (*)(T&));
    template< typename VST>
    void traverse(VST&); 
};