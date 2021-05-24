#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
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
string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789/ ";
string claveG="";
string clavePriv="";
string clavePub="";
string ClavePrivada(int tam){
    string clave;
    cin>>clave;
   /* for (int i = 0; i < claveG.length(); i ++){
        clave.push_back(alfabeto.at(aleatorio));
    }*/
    claveG=clave;
}
string ClavePublica(string claveG){
    string clave="";
    for (int i = 0; i < claveG.length(); i ++){
        clave.push_back(ModularInversed(clave.at(i),38));
        if((ModularInversed(clave.at(i),38))==0)cout<<"Ese numero no se puede usar como llave privada"<<endl;
    }
    clavePub=clave;

}/*
string convertirClave(string clavePub){

}*/

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
    ClavePrivada(tam);
    ClavePublica(claveG);


    cout<< "claveg "<<claveG<<endl;
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje.at(i));
        int c=alfabeto.find(claveG.at(i));
        int sumaT=(m+c)%38;
        mensaje.at(i)=alfabeto.at(sumaT);
    }
    cout<<"mensaje "<<mensaje<<endl;
    salida << mensaje << endl;
    salida.close();
    entrada.close();
}
void descifrado(string texto, string clave){
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

   /* int r=arr[i];//char a entero
		r=(r*n)%256;
    */
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje1.at(i));
        int c=alfabeto.find(clavePub.at(i));
        int restaT=(m*c)%38;
        /*if(restaT<0){
            restaT = (38 + restaT)%38;
        }*/
        mensaje1.at(i)=alfabeto.at(restaT);
    }
    cout<<"mensaje "<<mensaje1<<endl;
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
    descifrado("textoCifrado.txt",claveG);
    return 0;
}
