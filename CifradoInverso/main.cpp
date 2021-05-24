#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int claveG;
int clavePriv;
int clavePub;

int modulo(int a, int b){
    if(a>=0) return a-(a/b)*b;
    return a-((a/b)-1)*b;
}

int ModularInversed(int a,int b){
    a=modulo(a,b);
	int x=0,y=1,m=b,tmp;
	int rsp=y;
	while(a>=1){
		rsp=y;
		tmp=(x-y*(b/a))%m;
		x=y;
		y=tmp;
		tmp=b%a;
		b=a;
		a=tmp;
	}
	if(b!=1)return 0;
	rsp%=m;
	if(rsp<0)rsp+=m;
	return rsp;
}

void cifrado(string texto){
    string mensaje;
    string copia;
    ifstream entrada ( texto);
    ofstream salida ("textoCifrado.txt");
    while (getline (entrada,copia)) {
        string temp=copia;
        mensaje.append(copia);
        mensaje.push_back('/');
    }
    int tam=mensaje.length();

	cout<<"ingrese la llave privada"<<endl;

    cin>>clavePriv;
    int y=clavePriv;
    y=ModularInversed(clavePriv,256);
    clavePub=y;
    if(clavePriv==0){
        cout<<"Ese numero no se puede usar como llave privada"<<endl;
    }

    for(int i=0;i<tam;i++){
		int r=mensaje.at(i);
		r=(r*clavePriv)%256;
		mensaje.at(i)=r;
	}
    salida << mensaje << endl;

    cout<<"Clave Publica: "<<clavePub<<endl;
    salida.close();
    entrada.close();

}
void descifrado(string texto, int clavePriv){
    string mensaje1;
    string copia1;
    ifstream entrada1( texto);
    ofstream salida1 ("textoDescifrado.txt");
    while (getline (entrada1,copia1)) {
        string temp=copia1;
        cout<<"copia "<<copia1<<endl;
        mensaje1.append(copia1);
    }
    int tam=mensaje1.length();

   	for(int i=0;i<tam;i++){
		int r=mensaje1.at(i);
		r=(r*clavePriv)%256;
		mensaje1.at(i)=r;
	}
    for (int i=0;i<tam;i++){
        if(mensaje1.at(i)=='/'){
            salida1<<endl;
        }
        else{
            salida1 << mensaje1[i];
        }
    }
    salida1.close();
    entrada1.close();
}


int main()
{

    cifrado("textoPlano.txt" );
    int k;
    cout << "Ingresa la Clave Publica" << endl;
    cin>>k;
    descifrado("textoCifrado.txt",k);
    return 0;
}
