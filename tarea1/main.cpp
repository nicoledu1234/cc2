#include <iostream>
#include <string>
using namespace std;
bool  verificarNumero(string numRomano){
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='I'){
            if ((numRomano[i+1]=='I')&&(numRomano[i+2]=='I')&&(numRomano[i+3]=='I')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='X'){
            if ((numRomano[i+1]=='X')&&(numRomano[i+2]=='X')&&(numRomano[i+3]=='X')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='M'){
            if ((numRomano[i+1]=='M')&&(numRomano[i+2]=='M')&&(numRomano[i+3]=='M')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='C'){
            if ((numRomano[i+1]=='C')&&(numRomano[i+2]=='C')&&(numRomano[i+3]=='C')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='V'){
            if ((numRomano[i+1]=='V')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='L'){
            if ((numRomano[i+1]=='L')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='D'){
            if ((numRomano[i+1]=='D')){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if(numRomano[i]=='I'){
            if (numRomano[i+1]=='L'||numRomano[i+1]=='C'||numRomano[i+1]=='D'||numRomano[i+1]=='M'){
                cout<<"Numero invalido "<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if((numRomano[i]=='I')&&(numRomano[i+1]!='I')){
            if (numRomano[i+2]=='I'){
                cout<<"Numero invalido 1"<<endl;
                return false;
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if((numRomano[i]=='X')){
            if((numRomano[i+1]=='V'||numRomano[i+1]=='L'||numRomano[i+1]=='C'||numRomano[i+1]=='D'||numRomano[i+1]=='M')){
                if (numRomano[i+2]=='X'){
                    cout<<"Numero invalido 2 "<<endl;
                    return false;
                }
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if((numRomano[i]=='I')){
            if (numRomano[i+1]=='X'){
                if((numRomano[i+2]=='I'||numRomano[i+2]=='X'||numRomano[i+2]=='V'||numRomano[i+2]=='L'||numRomano[i+2]=='C'||numRomano[i+2]=='D'||numRomano[i+2]=='M')){
                    cout<<"Numero invalido 2 "<<endl;
                    return false;
                }
            }
        }
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
        if((numRomano[i]=='M')){
            if((numRomano[i+1]=='V'||numRomano[i+1]=='L'||numRomano[i+1]=='I'||numRomano[i+1]=='D'||numRomano[i+1]=='M')){
                if (numRomano[i+2]=='M'){
                    cout<<"Numero invalido "<<endl;
                    return false;
                }
            }
        }
    }
    return true;
}

int buscador(string simbolo, char c){
    for (int i=0;i< simbolo.length();i++){
        if(simbolo[i]==c){
            return i;
        }
    }
}
void convertirADecimal (string numRomano){
    if(verificarNumero(numRomano)==0){}
    else{
        int valor[] = {1000, 500, 100, 50, 10, 5, 1};
        string simbolo = "MDCLXVI";
        char c;
        int resultado=0;
        int i=0;
        int j=0;
        int ultimovalor=0;
        bool valido=true;
        while(valido && (i < numRomano.length())){
            c = numRomano[i];
            j = buscador(simbolo,c);
            if(j>=0){
                resultado += valor[j];
                if(valor[j] > ultimovalor){
                    resultado -= 2 * ultimovalor;
                }
                ultimovalor = valor[j];
            }
            else{
                valido = false;
                resultado = -1;
            }
            i++;
        }
        cout<<resultado<<endl;
    }
}

int main()
{
    string  numeroRomano;
    cout<<"Ingrese un numero Romano"<<endl;
    cin>>numeroRomano;
    cout<<"Su valor en decimal es: ";
    convertirADecimal(numeroRomano);
    return 0;
}


