#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int copia=*a;
    *a=*b;
    *b=copia;
}
void imprimirArray(int *ini, int *fin){
    int *i;
    for(i=ini;i<fin-1;i++){
        cout<<*(i)<< ", ";
    }
    cout<<*(fin-1)<< endl;
}
void  OrdenamientoMezcla(int* a,int* b, int tam ,int * c){
    int *finA=a+tam;
    int *finB=b+tam;
    for(int i=0;i<tam*2-1;i++){
       if(*a<=*b){
        *c=*a;
         cout<<"a  "<<*a<<"      "<<"b  "<<*b<<"  c  "<<*c<<endl;
         a++;
          c++;

       }
       else{
        *c=*b;
        cout<<"a  "<<*a<<"      "<<"b  "<<*b<<"  c  "<<*c<<endl;
        b++;
          c++;

       }
   }

   }

//Mezcla no solo Swap
void OrdenamientoParImpar(int* i,int* p){
  for(int *j=i;j<=p;j++){
       if(*(i)<*p){
         cout<<"1 a  "<<*i<<"      "<<"b  "<<*p<<endl;
          i++;
          //p++;

       }
       else{
        cout<<"2 a  "<<*i<<"      "<<"b  "<<*p<<endl;
        swap(*i,*p);
        cout<<"SWAP  a  "<<*i<<"      "<<"b  "<<*p<<endl;
        //j++;
        i++;
       }
       if(i==p){
        p++;
        i--;
       }
   }
}

void OrdenamientoParImpar1(int* i,int* p){
    int temp;
    int*fin=p+(p-i)-1;
    int*pt=p;
    for(int *r=i;r<fin;r++){
        if(*i>*p){
            temp=*p;
            for(int *j=p;j>i;j--){
                *j=*(j-1);
                //imprimirArray(i,fin+1);

            }
            *i=temp;
            p=++pt;
        }
        i++;
    }
}

void fibonacci(int *arr, int tam){
    for (int *i=arr+2;i<arr+tam;i++){
        *i=*(i-1)+*(i-2);
        cout<<*i<<endl;
    }
}


int main()
{
   /* int a[]={3,4,9,12};
    int r=0;
    int b[]={5,7,11,23};
    int c[8];
    OrdenamientoMezcla(a,b,4,c);
    imprimirArray(c,c+8);
*/
    int arr[]={4,8,16,1,5,9};
    imprimirArray(arr,arr+6);
    cout<<endl;
    OrdenamientoParImpar1(arr,arr+3);
    imprimirArray(arr,arr+6);
 cout<<endl;


     int arr1[]={1,5,11,4,8,16};
    imprimirArray(arr1,arr1+6);
     cout<<endl;
    OrdenamientoParImpar1(arr1,arr1+3);
    imprimirArray(arr1,arr1+6);

 cout<<endl;

         int arr2[]={2,8,40,5,17,77};
    imprimirArray(arr2,arr2+6);
     cout<<endl;
    OrdenamientoParImpar1(arr2,arr2+3);
    imprimirArray(arr2,arr2+6);

     cout<<endl;  cout<<endl;

         int arr3[]={7,9,11,2,8,16};
    imprimirArray(arr3,arr3+6);
     cout<<endl;
    OrdenamientoParImpar1(arr3,arr3+3);
    imprimirArray(arr3,arr3+6);



       cout<<endl;  cout<<endl;

         int arr4[]={7,9,11,21,2,8,16,20};
    imprimirArray(arr4,arr4+8);
     cout<<endl;
    OrdenamientoParImpar1(arr4,arr4+4);
    imprimirArray(arr4,arr4+8);
/*

    int arrFib[9]={0,1};
    fibonacci(arrFib,9);
     imprimirArray(arrFib,arrFib+9);


  /*   char arr[3][5]={"Hugo","paco","luis"};
  for(char*p=arr[0];p<=&arr[2][4];p++){
        cout<<p<<endl;
        */
   // cout<<*p<<"";

    return 0;
}
