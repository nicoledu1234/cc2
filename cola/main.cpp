#include <iostream>

using namespace std;
#include<iostream>
using namespace std;

template<class T>
class nodo {
    public:
    T valor;
    nodo* next;
    nodo(T v, nodo* n = NULL){
        valor = v;
        next =n;
    }
};


template<class T>
class cola {
    public:
    nodo<T>* head;
    nodo<T>* tail;
    cola(){
        head = NULL;
        tail = NULL;
    }

    void push(T valor) {
        if(!head){
            head = new nodo<T>(valor,head);
            tail=head;
        }
        else{
            tail->next=new nodo<T>(valor,tail->next);
            tail=tail->next;
        }
    }

    T pop() {
       if(!head){
        cout<<"vacia"<<endl;
        return 0;
       }
       nodo<T> *temp=head;
       T r=head->valor;
       head=head->next;
       delete temp;
       return r;
    }

    void print(){
    cout<<endl;
    for(nodo<T> *p=head;p;p=p->next){
         if(p->next)
            cout<<p->valor<<" -> ";
        else
           cout<< p->valor;

    }
    cout<<endl;
    }

};
int main()
{
   cola<int> c;
   c.push(1);
   c.print();
   c.push(2);
    c.print();
   cout<<c.pop()<<endl;
   c.print();
   cout<<c.pop()<<endl;
   c.print();
   cout<<c.pop()<<endl;
   c.print();

}
