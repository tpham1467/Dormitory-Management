#pragma once
template<class T>
class Node
{
private:
    Node<T>* Prev;
    Node<T>* Next;
    T data;
public:
    Node();
    ~Node();
    Node<T>* Get_Next();
    Node<T>* Get_Prev();
    void    Set_Next(Node<T>*);
    void    Set_Prev(Node<T>*);
    T&       Get_Data();
    void    Set_Data(T);
};
template<class T>
Node<T>::Node()
{
    this->Next = nullptr;
    this->Prev = nullptr;
}
template<class T>
Node<T>::~Node()
{

}
template<class T>
void Node<T>::Set_Data(T Val)
{
    this->data = Val;
}
template<class T>
T& Node<T>::Get_Data()
{
    return this->data;
}
template<class T>
Node<T>* Node<T>::Get_Next()
{
    return this->Next;
}
template<class T>
Node<T>* Node<T>::Get_Prev()
{
    return this->Prev;
}
template<class T>
void Node<T>::Set_Next(Node<T>* Next)
{
    this->Next = Next;
}
template<class T>
void Node<T>::Set_Prev(Node<T>* Prev)
{
    this->Prev = Prev;
}

