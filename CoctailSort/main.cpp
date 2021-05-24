#include <iostream>
using namespace std ;

void swap(int *a, int *b){
    int copia=*a;
    *a=*b;
    *b=copia;
}

void coctailSort(int *p, int *q){
    bool cambio=true;
    while(cambio==true) {
        cambio=false;
        for (int *i = p; i < q-2;i++) {
            if (*i >*(i + 1)) {
                swap(*i, *(i +1));
                cambio=true;
            }
        }
        if(cambio==false){
            break;
        }
        cambio=false;
        for (int *i = q-2; i > p; i--) {
            if (*i > *(i +1)) {
                swap(*i, *(i + 1));
                cambio=true;
            }
        }
        if(cambio== false) {
            break;
        }
    }
}
void imprimirArray(int *ini, int *fin){
    int *i;
    for(i=ini;i<fin-1;i++){
        cout<<*(i)<< ", ";
    }
    cout<<*(fin-1)<< endl;
}


int main(){
    int p[]={3,8,1,2,6,9,15,18,13,22,50,87,10,85};
    int size_= sizeof(p)/ sizeof(p[0]);
    int *ini=&p[0];
    int *fin=ini+size_;
    imprimirArray(p,fin);
    coctailSort(ini,fin);
    imprimirArray(ini,fin);
}
