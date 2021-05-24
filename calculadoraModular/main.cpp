#include<iostream>
using namespace std;
int modulo(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}
void sumaMod(int a, int b, int m) {
  int total = a + b;
  cout<<"La suma modular es "<< total<<" % "<< m<<" = "<< modulo(total,m)<<endl;;
}
void restaMod(int a, int b, int m) {
  int total = a - b;
  cout<<"La resta modular es "<< total<<" % "<< m<<" = "<< modulo(total, m)<<endl;;
}

void multiplicacionMod(int a, int b, int m) {
  int total = a*b;
  cout<<"La multiplicacion modular es "<< total<<" % "<< m<<" = "<< modulo(total,m)<<endl;;
}

int gcdExtendido(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        cout<<endl;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtendido(modulo(b,a), a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

void inversoMod(int a, int m){
    int x, y;
    int g = gcdExtendido(a, m, &x, &y);
    if (g != 1)
        cout << "No existe el inverso modular" << endl;
    else{
        int res = modulo((modulo(x,m) + m), m);
        cout << "El inverso modular es: " << res<< endl;
    }
}

int main()
{
    cout << " Que operacion desea hacer?"<<endl;
    cout<<"1.Suma"<<endl;
    cout<<"2.Resta"<<endl;
    cout<<"3.Multiplicacion"<<endl;
    cout<<"4.Inverso Modular"<<endl;
    int operacion;
    cin>>operacion;
    if(operacion==1){
        cout<<"Ingrese dos numeros y el modulo para sumarlos"<<endl;
        int a;
        cout<< "a= ";
        cin>>a;
        int b;
        cout<< "b= ";
        cin>>b;
        int m;
        cout<< "modulo= ";
        cin>>m;
        sumaMod(a,b,m);
    }
    if(operacion==2){
        cout<<"Ingrese dos numeros y el modulo para restarlos"<<endl;
        int a;
        cout<< "a= ";
        cin>>a;
        int b;
        cout<< "b= ";
        cin>>b;
        int m;
        cout<< "modulo= ";
        cin>>m;
        restaMod(a,b,m);
    }
        if(operacion==3){
        cout<<"Ingrese dos numeros y el modulo para multiplicarlos"<<endl;
        int a;
        cout<< "a= ";
        cin>>a;
        int b;
        cout<< "b= ";
        cin>>b;
        int m;
        cout<< "modulo= ";
        cin>>m;
        multiplicacionMod(a,b,m);
    }
    if(operacion==4){
        cout<<"Ingrese un numero y el modulo para calcular el inverso modular"<<endl;
        int a;
        cout<< "a= ";
        cin>>a;
        int m;
        cout<< "modulo= ";
        cin>>m;
        inversoMod(a,m);
    }
    return 0;
}
