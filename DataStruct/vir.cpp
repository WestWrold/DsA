#include<stdio.h>
#include<iostream>

using namespace std;
class A
{
public:
    virtual void foo()
    {
        cout<<"A is called"<< endl;
    }
};

class B:public A
{
public:
    void foo()
    {
        cout<<"B is called"<< endl;
    }
};


int main( )
{
    A *a = new B();
    a->foo();
    return 0;
}