#include <iostream>

using namespace std;
int modulo(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}
int main()
{

    cout <<modulo(9,3)<<endl;

    int contador;
    contador=0;
    for(int i=1;i<=9999;i++){
        if (!modulo(i,5)  && !modulo(i,3)){ contador++; cout<<i<<endl;}
    }
    cout<<contador<<endl;
    return 0;
}
