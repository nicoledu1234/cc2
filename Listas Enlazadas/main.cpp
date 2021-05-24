#include<iostream>

using namespace std;

template<class T>
class asc{
    public:
    bool operator()(T a,T b){
        return a<=b;
    }
};


template<class T>
class desc{
    public:
    bool operator()(T a,T b){
        return a>=b;
    }
};
template<class T>
class par{
    public:
    bool operator()(T a){
        return !(a&1);
    }
};
template<class T>
class impar{
    public:
    bool operator()(T a){
        return (a&1);
    }
};

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


template<class T,class R>
class lista {
    R r;
    public:
    nodo<T>* head;
    lista() {
        head = NULL;
    }
    bool bus(T key, nodo<T>*& pos){
        /// devuelve el anterior y si es la cabeza null
        bool enc =false;
        pos = NULL;
        for(nodo<T>*p = head;p && r(p->valor,key); p = p->next){
            if(p->valor==key){
                    /*pos=p;*/
                    enc = true;
                    break;
            }
            pos =p;
        }
        return enc;
    }

    void add(T valor) {
        nodo<T> *pos;
        //if(!head)
        // head = new nodo<T>(valor,head);
        //else
        // {

        if(!bus(valor,pos)){
            if(!pos){
                head = new nodo<T>(valor,head);
            }
            else{
                pos->next=new nodo<T>(valor,pos->next);
            }
        }
        //}
    }
    void delete_(T valor) {
        nodo<T> *pos;
        if(bus(valor,pos)){
            if(!pos){
                nodo<T> *temp=head;
                head=head->next;
                delete temp;
            }
            else{
                nodo<T> *temp=pos->next;
                pos->next=pos->next->next;
                delete temp;
            }
        }
        //}
    }
    void print(){
    cout<<endl;
    if(head !=nullptr){
         for(nodo<T> *p=head;p;p=p->next){
        if(p->next)
            cout<<p->valor<<" -> ";
        else
           cout<< p->valor;
    }
    cout<<endl;
    }

    }

};
template <class T, class R>
void merge_(nodo<T>* a,nodo<T>* b){
  R r;
  nodo<T> *head;
  if (R ()(a->valor ,b->valor)){
     head = a;
     a = a->next;
  }

  else{
     head = b;
     b = b->next;
  }


  nodo<T> *temp = head;
  while (a && b) {
    if (r(a->valor, b->valor)) {
      temp->next = a;
      a = a->next;
      temp = temp->next;
    }

    else {
      temp->next = b;
      b = b->next;
      temp = temp->next;
    }
  }

  if (!a){
    temp->next = b;
  }
  else{
    temp->next = a;
  }
  a = head;
  b=nullptr;


}



template <class T, class R>
void split_(nodo<T>* a,nodo<T>* b){
  R r;
  nodo<T> *c;
  if (r(a->valor )){
     c = a;
     a = a->next;
  }

  else{
     c =b;
     b = a;
     a = a->next;
  }


  nodo<T> *temp = c;
  nodo<T> *temp1 = b;
  while (a!=nullptr) {
        cout<<"u"<<endl;
    if (r(a->valor)) {
      temp->next = a;
      temp = temp->next;
      a = a->next;

       cout<<"if   "<<temp->valor<<endl;
    }

    else {
      temp1->next = a;
      a = a->next;
      temp1 = temp1->next;
       cout<<temp1->valor<<endl;
    }
  }
  temp->next = nullptr;
 temp1->next = nullptr;

  a=c;
  c=nullptr;


}




int main() {
/*
   lista<int,desc<int>> l;
  // l.add(1);
   l.add(1);
 //  l.print();
   l.add(3);
 //  l.print();
   l.add(8);
 //  l.print();
   l.add(25);
  // l.print();
   l.add(35);
 //  l.print();
   l.add(37);
   l.add(40);
   l.add(47);
   l.print();
   cout<<"#############################################################"<<endl;
   lista<int,desc<int>>l1;
    l1.add(2);
 //  l1.print();
   l1.add(5);
//   l1.print();
   l1.add(10);
//   l1.print();
   l1.add(15);
   l1.add(20);
   l1.add(30);
   l1.print();
   merge_<int,desc<int>>(l1.head,l.head);
   cout<<"#############################################################"<<endl;
   l.print();
   cout<<"#############################################################"<<endl;

   lista<int,desc<int>>l2;
   l2.add(2);
   l2.add(4);
   l2.print();
   cout<<"#############################################################"<<endl;
   */
   lista<int,desc<int>>l3;
   l3.add(1);
   l3.add(2);
   l3.add(3);
   l3.add(5);
   l3.add(7);
   l3.add(8);
   l3.add(9);
   l3.add(10);
  // l3.add(77);
   l3.print();
 //  merge_<int,desc<int>>(l3.head,l2.head);
   //cout<<"#############################################################"<<endl;
  // l3.print();
   cout<<"#############################################################"<<endl;
   cout<<"#############################################################"<<endl;
      lista<int,desc<int>> e;
     e.add(0);
      l3.print();
   e.print();
   split_<int,par<int>>(l3.head,e.head);
  l3.print();
   e.print();

   cout<<"#############################################################"<<endl;

}


