#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace  std;
int arregloNum[10];
string arregloCadena[10];
int arregloDis[10];

void disenoOrdenamiento(int arr[], int n) {
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			if (arr[a] > arr[b]) {
				swap(arr[a], arr[b]); //intercambia de una vez
			}
		}
	}
}



void burbuja(char arr[], int n, int num) { // N = 11
	bool cambio;
	for (int i = 0; i < n - 1; i++) {  //10
		cambio = false;
		for (int j = 0; j < n - i - 1; j++) { //J < 9
			if (arr[j] > arr[j + 1]) {  //SI J > J + 1
				swap(arr[j], arr[j + 1]); //intercambia de una vez
				cambio = true;
			}
		}
		if (!cambio) {
			break;
		}
	}
}

void seleccion(int arreglo[], int n, int num) { // n = 11
	for (int i = 0; i < n - 1; i++) { // n = 9
		int min_idx = i;   //indice es igual a 0
		for (int a = i + 1; a < n; a++) {  //a es igual a 1
			if (arreglo[a] < arreglo[min_idx]) { //si el valor del arreglo en a es menor que el arreglo en indice
				min_idx = a;         //indice es igual a 1 de lo contrario no hace nada
			}
		}
		int temporal = arreglo[min_idx];
		arreglo[min_idx] = arreglo[i];
		arreglo[i] = temporal;
	}
}

//INSERCION
void insercion(string arreglo[], int n) {
	for (int i = 1; i < n; i++) {
		string llave = arreglo[i];
		int j = i - 1;
		while (j >= 0 && arreglo[j] > llave) {
			arreglo[j + 1] = arreglo[j];
			j--;
		}
		arreglo[j + 1] = llave;
	}
}

int main()
{
    cout << "INGRESE LOS DATOS PARA EL ARREGLO NUMERICO" << endl;
    for (int a = 0; a < 10; a++) {
        cout << "INGRESE EL VALOR PARA LA POSICION " << a << " DEL ARREGLO: " << endl;
        cin >> arregloNum[a];
    }
	system("cls");
	cout << "INGRESE LOS DATOS PARA EL ARREGLO DE CRARACTERES" << endl;
   for (int a = 0; a < 10; a++) {
        cout << "INGRESE EL VALOR PARA LA POSICION " << a << " DEL ARREGLO: " << endl;
        cin >> arregloCadena[a];
    }
	system("cls");

	cout << "DISEÑO RANDOM" << endl << endl;
	cout << "INGRESE LOS DATOS PARA EL ARREGLO NUMERICO DE SIEÑO DE ORDENAMIENTO" << endl;
	for (int a = 0; a < 10; a++) {
		cout << "INGRESE EL VALOR PARA LA POSICION " << a << " DEL ARREGLO: " << endl;
		cin >> arregloDis[a];
	}
	system("cls");

	int tamano = sizeof(arregloNum) / sizeof(arregloNum[0]);
	seleccion(arregloNum, tamano, 0);
	cout << "ARREGLO NUMERICO ORDENADO DE FORMA ASCENDENTE" << endl << endl;

	for (int a = 0; a < 10; a++) {
		cout <<  arregloNum[a] << ", ";
	}

	cout << endl << endl;

	cout << "ARREGLO DE CARACTERES ORDENADO ALFABETICAMENTE" << endl << endl;;
	int Size = sizeof(arregloNum) / sizeof(arregloNum[0]);
	insercion(arregloCadena, Size);
	for (int a = 0; a < 10; a++) {
		cout << arregloCadena[a] << ", ";
	}

	cout << endl << endl;


	//DISEÑO DEL ALGORITMO DE ORDENAMIENTO
	cout << "ORDENAMIENTO POR MEDIO DEL ALGORITMO DE DISEÑO" << endl << endl;
	int tamano2 = sizeof(arregloDis) / sizeof(arregloDis[0]);
	disenoOrdenamiento(arregloDis, tamano2);
	for (int a = 0; a < 10; a++) {
		cout << arregloDis[a] << ", ";
	}

}

