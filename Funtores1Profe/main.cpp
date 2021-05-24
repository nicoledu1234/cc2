#include <iostream>

using namespace std;

/*
typedef int (*pf)(int*);

int s(int* x)
{ return *x + *(x+1);}

int m(int* x)
{ return *x * *(x+1);}

template<class T>
class clase
{
private:
    int _x;
public:
    clase(int x):_x(x){}
    void operator()(int* x, T p)
    {
       _x = p(x);
       *x = *(x+1);
       *(x+1) = _x;
    }
};

int main()
{
    int a[2] = {0,1};
    clase<pf> A(7);

    for(int i=0;i<10;i++)
    { cout<<"a[0] "<<a[0]<< " a[1] "<<a[1]<<endl;
      A(a,s);
      }

    cout<<"************"<<endl;

    clase<pf> B(0);
    a[0]=1;
    a[1]=2;
    for(int i=0;i<10;i++)
    { cout<<"a[0] "<<a[0]<< " a[1] "<<a[1]<<endl;
      B(a,m);
      }
    return 0;
}



class operacion
{
private:
	int _x;
public:
	operacion(int x):_x(x) {};
	int operator()(int a)
	{ return _x+a;}
};

template<typename T>
void operador(T a, int *b)
{
	*(b-1) = *b;
	*b = a(*b);
}

int main()
{
	int *a = new int[2];
	*a = 0;
	*(a+1) = 1;

	for(int i= 0; i<=10; i++)
	{
		cout<<*a<<endl;
		operador(operacion(*a),a+1);
	}
	return 0;
}

template <class T>
class Stack {
    public:
        Stack():top(0) {  }
        ~Stack() {
       /*     while ( !isEmpty() ) {
                pop();
            }
            isEmpty();

        }

        void push (T o){
            if(isEmpty()){
                top=new StackNode(o,top);
            }
            else {
                StackNode *tmp=top;
                 while(tmp->next){
                    tmp=tmp->next;

                 }
                tmp->next=new StackNode(o,tmp->next);
            }

        }
        T pop(){
           if(isEmpty()){
                cout<<"vacia"<<endl;
            }
            else {
                StackNode *tmp=top;
                 while(tmp->next){
                    tmp=tmp->next;

                 }
                 T val=tmp->data;
                 cout<<val<<endl;
                delete tmp;
                return val;
            }
}
        bool isEmpty();


        struct StackNode {
            T data;
            StackNode *next;

            StackNode(T newData, StackNode *nextNode)
                : data(newData), next(nextNode) {}
        };
        StackNode *top=0;

        void print(){
    for(StackNode *t=top;t;t=t->next){
            cout<<t->data<<" -> ";

    }
cout<<endl;
    }

};

template <class T>
bool Stack<T>::isEmpty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main(){
  Stack<int> l;
  l.push(4);
  l.print();
  l.push(7);
  l.print();
  l.push(9);
  l.print();
   l.push(48);
  l.print();
  l.pop();
  l.print();

}


*/
class operacion
{
public:
	int operator()(int a, int b)
	{ return a+b;}
};

template<typename T>
class operador
{
private:
	T op;
public:
	void operator()(int *a)
	{
                            *a=*(a+1);
                           *(a+1)=op(*(a+1),*a);
	}
};

int main(){
	int *a = new int[2];
	*a = 0;
	*(a+1) = 1;
	for(int i= 0; i<=10; i++)
	{
     cout<<*a<<endl;
    operador<operacion>()(a);
	}

	return 0;
}

