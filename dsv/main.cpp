#include <iostream>
#include <string>
using namespace std;
void swap(int* a, int* b) {
	int copia = *a;
	*a = *b;
	*b = copia;
}
void imprimirArray(int* ini, int  tam) {
	for (int *i = ini; i < ini+tam - 1; i++) {
		cout << *(i) << ", ";
	}
	cout << *(ini+tam - 1) << endl;
}
bool par(int a) {
	return !(a & 1);
}
void split(int* arr, int* q, int tam, bool(*comp)(int)) {
	int* r=nullptr;
	q = nullptr;
	for (int* p1 = arr; p1 < arr + tam; p1++) {
		if ( !(comp(*p1))){
			if (!q) {
				//el primer elemento no cumple
				q = p1;
				p1++;
			}
			else {
				//swap porque q ya apunta  algo
				swap(p1, q);
				if (q != p1) {
					r = q;
					while (r!=p1){
						swap(r, r + 1);
					}
				}
				q++;
				p1++;
			}
		}
		else {
			//q = p1;
			p1++;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	imprimirArray(arr, 10);
	int* q=nullptr;
	bool (*comp)(int);
	comp = par;
	split(arr, q, 10, comp);
	imprimirArray(arr, 10);
}
