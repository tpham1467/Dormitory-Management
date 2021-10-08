#pragma once
#include"Node.h"
template <class T>
class Doubly_Linked_List
{
private:
    Node<T>* P_Head;
    Node<T>* P_Tail;
public:
    Doubly_Linked_List();
    ~Doubly_Linked_List();
    Node<T>* Get_P_Head();
    Node<T>* Get_P_Tail();
    void Set_P_Head(Node<T>*);
    void Set_P_Tail(Node<T>*);
    void InsertAtHead(T Val);
    void InsertAtTail(T val);
    /* void RemoveFront();
     void DeleteAtHead();
     void DeleteAtTail();
     void Show();*/

};
template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List()
{
    this->P_Head = nullptr;
    this->P_Tail = nullptr;
}
template<class T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{

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
    if (this->P_Head == nullptr)
    {
        this->P_Head = p;
        this->P_Tail = p;
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
    if (this->P_Tail == nullptr)
    {
        this->P_Head = p;
        this->P_Tail = p;
    }
    else
    {
        this->P_Tail->Set_Next(p);
        p->Set_Prev(this->P_Tail);
        this->P_Tail = p;
    }
}

