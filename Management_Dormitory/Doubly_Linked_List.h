#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template <class T>
class Doubly_Linked_List
{
private:
    Node<T>* P_Head;
    Node<T>* P_Tail;
    int lenght;
public:
    Doubly_Linked_List();
    Doubly_Linked_List(const Doubly_Linked_List<T>& );
    ~Doubly_Linked_List();
    Node<T>* Get_P_Head();
    Node<T>* Get_P_Tail();
    void Set_P_Head(Node<T>*);
    void Set_P_Tail(Node<T>*);
    void InsertAtHead(T);
    void InsertAtTail(T);
    void DeleteAtHead();
    void DeleteAtTail();
    void Delete_indexoff(Node<T>*);
    void Delete_indexoff(int);
    int Get_Lenght();
    T Font();
    T Back();
    T at(int);
    T operator[](int);
 /*   Doubly_Linked_List<T>& operator=(const Doubly_Linked_List<T>&);*/
    void replace(int,T);
    void replace(Node<T>*,T);
};
template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List(const Doubly_Linked_List<T>& db)
{
    Node<T>* p1 = db.P_Head;
    this->lenght = db.lenght;
    while (p1 != nullptr)
    {
        this->InsertAtTail(p1->Get_Data());
        p1 = p1->Get_Next();
    }
}
template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List()
{
    this->P_Head = nullptr;
    this->P_Tail = nullptr;
    this->lenght = 0;
}
template<class T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
    Node<T>* p=this->P_Head;
    while(p!=nullptr)
    {
        this->P_Head=this->P_Head->Get_Next();
        delete p;
        p=this->P_Head;
    }
}
template<class T>
Node<T>* Doubly_Linked_List<T>::Get_P_Head()
{
    return this->P_Head;
}
template<class T>
Node<T>* Doubly_Linked_List<T>::Get_P_Tail()
{
    return this->P_Tail;
}
template<class T>
void Doubly_Linked_List<T>::Set_P_Head(Node<T>* P_Head)
{
    this->P_Head = P_Head;
}
template<class T>
void Doubly_Linked_List<T>::Set_P_Tail(Node<T>* P_Tail)
{
    this->P_Tail = P_Tail;
}
template<class T>
void Doubly_Linked_List<T>::InsertAtHead(T Val)
{
    Node<T>* p = new Node<T>;
    p->Set_Data(Val);
    p->Set_Next(nullptr);
    p->Set_Prev(nullptr);
    this->lenght++;
    if (this->P_Head == nullptr)
    {
        this->P_Head = p;
        this->P_Tail = p;
        this->P_Head->Set_Prev(nullptr);
        this->P_Head->Set_Next(nullptr);
        this->P_Tail->Set_Next(nullptr);
        this->P_Tail->Set_Prev(nullptr);
    }
    else
    {
        this->P_Head->Set_Prev(p);
        p->Set_Next(this->P_Head);
        this->P_Head = p;
    }
}
template<class T>
void Doubly_Linked_List<T>::InsertAtTail(T Val)
{
    Node<T>* p = new Node<T>;
    p->Set_Data(Val);
    p->Set_Next(nullptr);
    p->Set_Prev(nullptr);
    this->lenght++;
    if (this->P_Tail == nullptr)
    {
        this->P_Head = p;
        this->P_Tail = p;
        this->P_Head->Set_Prev(nullptr);
        this->P_Head->Set_Next(nullptr);
        this->P_Tail->Set_Next(nullptr);
        this->P_Tail->Set_Prev(nullptr);
    }
    else
    {
        this->P_Tail->Set_Next(p);
        p->Set_Prev(this->P_Tail);
        this->P_Tail = p;
    }
}
template<class T>
void Doubly_Linked_List<T>::DeleteAtHead()
{
    Node<T>* p = this->P_Head->Get_Next();
    delete this->P_Head;
    this->Set_P_Head(p);
    this->P_Head->Set_Prev(nullptr);
    this->lenght--;
}
template<class T>
void Doubly_Linked_List<T>::DeleteAtTail()
{
    Node<T>* p = this->P_Tail->Get_Prev();
    delete this->P_Tail;
    this->Set_P_Tail(p);
    this->P_Tail->Set_Next(nullptr);
    this->lenght--;
}
template<class T>
void Doubly_Linked_List<T>::Delete_indexoff(Node<T>* p)
{
    Node<T>* prev = p->Get_Prev();
    Node<T>* Next = p->Get_Next();
    if (prev == nullptr)
    {
        DeleteAtHead();
    }
    else if (Next == nullptr)
    {
        DeleteAtTail();
    }
    else
    {
        prev->Set_Next(Next);
        Next->Set_Prev(prev);
        this->lenght--;
    }
}
template<class T>
int Doubly_Linked_List<T>::Get_Lenght()
{
    return this->lenght;
}
template<class T>
T Doubly_Linked_List<T>::Font()
{
    return this->Get_P_Head()->Get_Data();
}
template<class T>
T  Doubly_Linked_List<T>::Back()
{
    return this->Get_P_Tail()->Get_Data();
}
template<class T>
T Doubly_Linked_List<T>::at(int i)
{
    Node<T>* p = this->Get_P_Head();
    for (int j = 0; j < i; j++)
    {
        p = p->Get_Next();
    }
    return p->Get_Data();
}
template<class T>
void Doubly_Linked_List<T>::Delete_indexoff(int i)
{   
    Node<T>* p = this->Get_P_Head();
    for (int j = 0; j < i; j++)
    {
        p = p->Get_Next();
    }
    this->lenght--;
    Delete_indexoff(p);

}
template<class T>
T Doubly_Linked_List<T>::operator[](int i)
{
    return at(i);
}
template<class T>
void Doubly_Linked_List<T>::replace(int i,T val)
{
    Node<T>* p = this->Get_P_Head();
    for (int j = 0; j < i; j++)
    {
        p = p->Get_Next();
    }
    p->Set_Data(val);
}
template<class T>
void Doubly_Linked_List<T>::replace(Node<T>* p,T val)
{
    p->Set_Data(val);
}
//template<class T>
//Doubly_Linked_List<T>& Doubly_Linked_List<T>::operator=(const Doubly_Linked_List<T>& db)
//{
//    Node<T>* p1 = db.P_Head;
//    Node<T>* p2 = db.P_Tail;
//    this->lenght = db.lenght;
//    this->Set_P_Head(p1);
//    this->Set_P_Tail(p2);
//    return *this;
//}