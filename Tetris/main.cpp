
#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 75
#define KEY_LEFT 77
#define KEY_SPACE 60


using namespace std;
void der(int(*matriz)[20]);
void izq(int(*matriz)[20]);
int modulo(int t, int m) {
int mo=-1 ;
if (t < 0)
return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
return (t >= m) ? t - (t / m * m) : t;
}
int generadorAleatorios(int maximo) {
srand(time(NULL));
int aleatorio, DESDE = 0, HASTA = maximo;
aleatorio = modulo(rand(), HASTA);
return aleatorio;
}
bool evaluarMat(int(*matriz)[20]){
    bool limpia=true;
    for (int(*filas)[20] = matriz + 1; filas < matriz + 19; filas++) {
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
            if(*columnas==5){
                limpia=false;
                return false;
            }
}
    }
    return true;
}
void llenarFicha(int(*matriz)[20]){
    int fichaA[3][3]={{5,0,0},
                      {5,5,0},
                      {5,0,0}};
    int fichaB[3][3]={{5,0,0},
                      {5,5,0},
                      {0,5,0}};
    int fichaC[3][3]={{0,5,0},
                      {0,5,0},
                      {0,5,0}};
    int fichaD[3][3]={{5,0,0},
                      {5,0,0},
                      {5,5,0}};
     int (*fA)[3];
    int ale=generadorAleatorios(5);
    if(ale==0){
      fA=fichaB;
    }
    if(ale==1){
         fA=fichaA;
    }
    if(ale==2){
         fA=fichaB;
    }
    if(ale==3){
         fA=fichaC;
    }
    if(ale==4){
         fA=fichaD;
    }

    if(evaluarMat(matriz)==true){

        int *posi=&matriz[2][10];
        *posi=**fA;
        *(posi+1)=*(*fA+1);
        *(posi+2)=*(*fA+2);
        *(posi+20)=*(*fA+3);
        *(posi+21)=*(*fA+4);
        *(posi+22)=*(*fA+5);
        *(posi+40)=*(*fA+6);
        *(posi+41)=*(*fA+7);
        *(posi+42)=*(*fA+8);
    }

}
void imprimir(int(*matriz)[20]) {
cout << "_________________" << endl;
for (int(*filas)[20] = matriz + 1; filas < matriz + 19; filas++) {
            cout << "|";
for (int* columnas = *filas+2; columnas < *(filas)+18; columnas++) {
if (*columnas == 1) {
cout << char(219);
}
else {
if (*columnas == 5) {
cout << char(220);
}
else {
cout << *columnas;
}
}
}
       cout << "|";
cout << endl;
}
cout << "_________________" << endl;
}
void girar(int(*matriz)[20]) {
bool cambio = false;
for (int(*filas)[20] = matriz; filas < matriz + 20; filas++) {
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
if (*columnas == 5) {
int* centro;
if(*(columnas+1)==5&&*(columnas+2)==5){
                    centro = columnas +1;
                    //cout<<"2"<<endl;
                    if(*(centro+20)==5){
                        centro=columnas+21;
                        //cout<<"3"<<endl;
                    }
}
else if(*(columnas-1)!=5&&*(columnas+1)!=5){
                    centro=columnas+20;
                    //cout<<"4"<<endl;
                     if(*(centro-1)==5){

                       //cout<<"9"<<endl;
                       if(*(centro+1)==5){
                        centro=columnas+20;
                        }
                        else {
                            centro=columnas+19;
                        }
                    }

}
else if(*(columnas+1)==5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"5"<<endl;
}
else if(*(columnas+1)!=5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"6"<<endl;
                    if(*(centro+1)==5){
                        centro=columnas+21;
                         //cout<<"7"<<endl;
                    }
}




//PUNTEROS ESQUINAS:
int* ptrESI = (centro - 20) - 1;
//*ptrESI=11;
int* ptrESD = (centro - 20) + 1;
//*ptrESD=3;
int* ptrEII = (centro + 20) - 1;
// *ptrEII=7;
int* ptrEID = (centro + 20) + 1;
//*ptrEID=9;


//PUNTEROS NO ESQUINAS:
int* q1 = (centro - 20);
//      *q1=2;
int* q2 = (centro + 1);
// *q2=6;
int* q3 = (centro + 20);
int* q4 = (centro - 1);
// *q3=8;
//*q4=44;
/*
imprimir(matriz);
cout<<endl;
*/

//GIRAMOS LA PIEZA:
int tempESI = *ptrESI;
int tempESD = *ptrESD;
int tempEID = *ptrEID;
int tempEII = *ptrEII;
*ptrESI = tempEII;
*ptrESD = tempESI;
*ptrEID = tempESD;
*ptrEII = tempEID;

int  tempq1 = *q1;
int  tempq2 = *q2;
int  tempq3 = *q3;
int  tempq4 = *q4;

*q1 = tempq4;
*q2 = tempq1;
*q3 = tempq2;
*q4 = tempq3;
cambio = true;

}

if (cambio) {
break;
}
}
if (cambio) {
break;
}
}
}
void decender(int(*matriz)[20]) {
bool cambio = false;
for (int(*filas)[20] = matriz; filas < matriz + 20; filas++) {
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
if (*columnas == 5) {
              int* centro;
if(*(columnas+1)==5&&*(columnas+2)==5){
                    centro = columnas +1;
                    //cout<<"2"<<endl;
                    if(*(centro+20)==5){
                        centro=columnas+21;
                        //cout<<"3"<<endl;
                    }
}
else if(*(columnas-1)!=5&&*(columnas+1)!=5){
                    centro=columnas+20;
                    //cout<<"4"<<endl;
                     if(*(centro-1)==5){

                       //cout<<"9"<<endl;
                       if(*(centro+1)==5){
                        centro=columnas+20;
                        }
                        else {
                            centro=columnas+19;
                        }
                    }

}
else if(*(columnas+1)==5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"5"<<endl;
}
else if(*(columnas+1)!=5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"6"<<endl;
                    if(*(centro+1)==5){
                        centro=columnas+21;
                         //cout<<"7"<<endl;
                    }
}

 //              cout<<"*centro "<<*centro<<endl;
//PUNTEROS ESQUINAS:
int* ptrESI = (centro - 20) - 1;
// cout<<"*ptrESI "<<*ptrESI<<endl;
int* ptrESD = (centro - 20) + 1;
// cout<<"*ptrESD "<<*ptrESD<<endl;
int* ptrEII =(centro + 20) -1;
          //      cout<<"*ptrEII "<<*ptrEII<<endl;
int* ptrEID = (centro + 20) + 1;
// cout<<"*ptrEID "<<*ptrEID<<endl;


//PUNTEROS NO ESQUINAS:
int* q1 = (centro - 20);
//      *q1=2;
int* q2 = (centro + 1);
// *q2=6;
int* q3 = (centro + 20);
int* q4 = (centro - 1);

if(*(q3+20)==1&&*q3==5||*(ptrEID+20)==1&&*ptrEID==5||*(ptrEII+20)==1&&*ptrEII==5){
              //  if(*(q3+20)==1||*(ptrEID+20)==1||*(ptrEII+20)==1){
                       // cout<<"________________________________________________________________________"<<endl;
                        if(*q3==5){
                            *q3=1;
                        }
                        if(*q1==5){
                            *q1=1;
                        }
                        if(*q4==5){
                            *q4=1;
                        }
                        if(*q2==5){
                            *q2=1;
                        }
                       if(*centro==5){
                        *centro=1;
                       }
                        if(*ptrEID==5){
                            *ptrEID=1;
                        }
                        if(*ptrEII==5){
                            *ptrEII=1;
                        }
                        if(*ptrESD==5){
                            *ptrESD=1;
                        }
                        if(*ptrESI==5){
                            *ptrESI=1;
                        }

                        cambio=true;
                        break;

}


// *q3=8;

/* cout<<*ptrESI<<" "<<*q1<<" "<<*ptrESD<<endl;
cout<<*q4<<" "<<*centro<<" "<<*q2<<endl;
cout<<*ptrEII<<" "<<*q3<<" "<<*ptrEID<<endl;
*/
if(*(ptrEID+20)!=1){
                   *(ptrEID+20)=*ptrEID;
}

//imprimir(matriz);
if(*(ptrEII+20)!=1){
                    *(ptrEII+20)=*ptrEII;
}

//imprimir(matriz);
if(*(q3+20)!=1){
                   *(q3+20)=*q3;
}

// imprimir(matriz);
/* cout<<"2"<<endl;
cout<<*(ptrEII+20)<<" "<<*(q3+20)<<" "<<*(ptrEID+20)<<endl;*/
                if(*(ptrEID)!=1){
                   *(ptrEID)=*q2;
                }

// imprimir(matriz);
                if(*(q3)!=1){
                    *(q3)=*centro;
                }

if(*(ptrEII)!=1){
                    *(ptrEII)=*q4;;
                }

// imprimir(matriz);
/* cout<<"3"<<endl;
cout<<*(ptrEII)<<" "<<*(q3)<<" "<<*(ptrEID)<<endl;
*/
if(*(q4)!=1){
                        *(q4)=*(ptrESI);
                }

                    *(centro)=*q1;

                if(*q2!=1){
                   *q2=*ptrESD;
                }


//imprimir(matriz);
/* cout<<"4"<<endl;
cout<<*(q4)<<" "<<*(centro)<<" "<<*(q2)<<endl;
*/

                    *ptrESI=*(ptrESI-20);


                   *q1=*(q1-20);


*ptrESD=*(ptrESD-20);
// imprimir(matriz);
/* cout<<"5"<<endl;
cout<<*(ptrESI)<<" "<<*(q1)<<" "<<*(ptrESD)<<endl;
*/
                cambio = true;

}

if (cambio) {
break;
}
}
if (cambio) {
break;
}
}
}
void izq(int(*matriz)[20]) {
bool cambio = false;
for (int(*filas)[20] = matriz; filas < matriz + 20; filas++) {
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
if (*columnas == 5) {
                int* centro;
if(*(columnas+1)==5&&*(columnas+2)==5){
                    centro = columnas +1;
                    //cout<<"2"<<endl;
                    if(*(centro+20)==5){
                        centro=columnas+21;
                        //cout<<"3"<<endl;
                    }
}
else if(*(columnas-1)!=5&&*(columnas+1)!=5){
                    centro=columnas+20;
                    //cout<<"4"<<endl;
                     if(*(centro-1)==5){

                       //cout<<"9"<<endl;
                       if(*(centro+1)==5){
                        centro=columnas+20;
                        }
                        else {
                            centro=columnas+19;
                        }
                    }

}
else if(*(columnas+1)==5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"5"<<endl;
}
else if(*(columnas+1)!=5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"6"<<endl;
                    if(*(centro+1)==5){
                        centro=columnas+21;
                         //cout<<"7"<<endl;
                    }
}
      //     cout<<"*centro "<<*centro<<endl;
//PUNTEROS ESQUINAS:
int* ptrESI = (centro - 20) - 1;
// cout<<"*ptrESI "<<*ptrESI<<endl;
int* ptrESD = (centro - 20) + 1;
// cout<<"*ptrESD "<<*ptrESD<<endl;
int* ptrEII =(centro + 20) -1;
      //          cout<<"*ptrEII "<<*ptrEII<<endl;
int* ptrEID = (centro + 20) + 1;
// cout<<"*ptrEID "<<*ptrEID<<endl;

//PUNTEROS NO ESQUINAS:
int* q1 = (centro - 20);
//      *q1=2;
int* q2 = (centro + 1);
// *q2=6;
int* q3 = (centro + 20);
 int*q4 = (centro - 1);




                      if(*(ptrESD-2)==2||*(q2-2)==2||*(ptrEID-2)==2){

               // der(matriz);
                    break;
                    //cambio=true;
               }
               else if(*(ptrESD-2)==2||*(q2-2)==2||*(ptrEID-2)==2){

               // der(matriz);
                    break;
                    //cambio=true;
               }
               if(*(centro-3)==2){
                    //der(matriz);
                    break;
                   // cambio=true;
                }

            if(*(ptrESI-2)!=2){
                     *(ptrESI-1)==*(ptrESI);
                }
                if(*ptrESI!=2){
                     *ptrESI=*q1;
                }
                if( *ptrESI!=2){
                     *ptrESI=*q1;
                }


*q1=*ptrESD;
*ptrESD=*(ptrESD+1);


if(*(q4-2)!=2){
*(q4-2)=*q4;
                }
if(*(q4)!=2){
*(q4)=*centro;}
*(centro)=*q2;
*q2=*(q2+1);

if(*(ptrEII-2)!=2){
*(ptrEII-2)=*ptrEII;
}
if(*(ptrEII)!=2){
*ptrEII=*q3;
}


*q3=*ptrEID;
*ptrEID=*(ptrEID+1);









                cambio = true;

}

if (cambio) {
break;
}
}
if (cambio) {
break;
}
}
}
void der(int(*matriz)[20]) {
bool cambio = false;
for (int(*filas)[20] = matriz; filas < matriz + 20; filas++) {
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
if (*columnas == 5) {
                int* centro;
if(*(columnas+1)==5&&*(columnas+2)==5){
                    centro = columnas +1;
                    //cout<<"2"<<endl;
                    if(*(centro+20)==5){
                        centro=columnas+21;
                        //cout<<"3"<<endl;
                    }
}
else if(*(columnas-1)!=5&&*(columnas+1)!=5){
                    centro=columnas+20;
                    //cout<<"4"<<endl;
                     if(*(centro-1)==5){

                       //cout<<"9"<<endl;
                       if(*(centro+1)==5){
                        centro=columnas+20;
                        }
                        else {
                            centro=columnas+19;
                        }
                    }

}
else if(*(columnas+1)==5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"5"<<endl;
}
else if(*(columnas+1)!=5&&*(columnas+2)!=5){
                    centro=columnas+20;
                    //cout<<"6"<<endl;
                    if(*(centro+1)==5){
                        centro=columnas+21;
                         //cout<<"7"<<endl;
                    }
}

  //             cout<<"*centro "<<*centro<<endl;
//PUNTEROS ESQUINAS:

int* ptrESI = (centro - 20) - 1;
//cout<<"*ptrESI "<<*ptrESI<<endl;
int*ptrESD = (centro - 20) + 1;
// cout<<"*ptrESD "<<*ptrESD<<endl;
int*ptrEII =(centro + 20) -1;
          //      cout<<"*ptrEII "<<*ptrEII<<endl;
int* ptrEID = (centro + 20) + 1;
// cout<<"*ptrEID "<<*ptrEID<<endl;

//EROS NO ESQUINAS:

//PUNTEROS NO ESQUINAS:
int* q1 = (centro - 20);
//      *q1=2;
 int*q2 = (centro + 1);
// *q2=6;
int* q3 = (centro + 20);
int*q4 = (centro - 1);


// *q3=8;

/*cout<<*ptrESI<<" "<<*q1<<" "<<*ptrESD<<endl;
cout<<*q4<<" "<<*centro<<" "<<*q2<<endl;
cout<<*ptrEII<<" "<<*q3<<" "<<*ptrEID<<endl;


*/


            if(*(ptrESD+2)==2||*(q2+2)==2||*(ptrEID+2)==2){

               // der(matriz);
                    break;
                    //cambio=true;
               }
               else if(*(ptrESD+2)==2||*(q2+2)==2||*(ptrEID+2)==2){

               // der(matriz);
                    break;
                    //cambio=true;
               }
               if(*(centro+3)==2){
                    //der(matriz);
                    break;
                   // cambio=true;
                }

               if(*(ptrESD+1)!=2||*(q2+1)!=2||*(ptrEID+1)!=2){
                    *(ptrESD+1)=*ptrESD;
                    *(ptrEID+1)=*ptrEID;
                    *(q2+1)=*q2;
                    *ptrESD=*q1;
                    *q2=*centro;
                    *ptrEID=*q3;

                    *q1=*ptrESI;
                    *centro=*q4;
                    *q3=*ptrEII;

                    *ptrESI=*(ptrESI-1);
                    *q4=*(q4-1);
                    *ptrEII=*(ptrEII-1);


                    /*if(*(ptrESI+1)==2&&*(ptrEID+1)==2&&*(q2+1)==2){
                        *(ptrESD)=0;
                        *(q2)=0;
                        *ptrEID=0;
                    }
                    else{
                        *(ptrESD)=*(ptrESD+1);
                        *(q2)=*(q2+1);
                        *ptrEID=*(ptrEID+1);
                    }*/

                }


                cambio = true;

}

if (cambio) {
break;
}
}
if (cambio) {
break;
}

}
}
void elimirarFila(int(*matriz)[20]){
    for (int(*filas)[20] = matriz+18; filas > matriz +1; filas--) {
        int cont=0;
for (int* columnas = *filas; columnas < *(filas)+20; columnas++) {
            if(*columnas==1){
                cont++;
            }
}
//cout<<cont<<endl;

if(cont==18&&evaluarMat(matriz)){
               // cout<<filas<<endl;
            for (int(*filas1)[20] = filas; filas1 > matriz +1; filas1--) {
                    //cout<<"1"<<endl;
                for (int* columnas = *filas1; columnas < *(filas1)+20; columnas++) {
                     *(columnas)=*(columnas-20);
                }
            }
}


    }
}
int main() {
int(*matriz)[20];
int mat[20][20] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,2},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };


matriz = mat;
//imprimir(matriz);
//cout<<"1"<<endl;
//system("cls");
//int c=0;
bool juego=true;
while(juego){
     imprimir(matriz);
    elimirarFila(matriz);
    system("cls");
    llenarFicha(matriz);
    imprimir(matriz);


        switch((getch())) {
            case 72:
                system("cls");
                girar(matriz);
                imprimir(matriz);
                //cout << endl << "Up" << endl;//key up
                break;
            case 80:
                system("cls");
                decender(matriz);
                imprimir(matriz);
                //cout << endl << "Down" << endl;   // key down
                // system("cls");
                break;
            case 75:
                 system("cls");
                izq(matriz);
                imprimir(matriz);
                //cout << endl << "Left" << endl;  // key left
                 //system("cls");
          //  elimirarFila(matriz);
              //  imprimir(matriz);
                break;
            case 77:
                 system("cls");
                der(matriz);
                imprimir(matriz);
                //cout << endl << "Right" << endl;  // key right
                 //system("cls");
          //  elimirarFila(matriz);
                imprimir(matriz);
                break;


            case 60 :
                juego=false;
                cout << endl << "esp" << endl;  // not arrow
                break;

            }
    system("cls");
    imprimir(matriz);

}

}






