// ! Esta parrte fue desarrollada por Pablo Hanner
#include <iostream>
using namespace std;

int busqueda_H(int arreglo[], int tamano, int valorBuscado)
{
  int num;
  for (int i = 0; i < tamano; i++)
  {
    num = 0;
    if (arreglo[i] == valorBuscado)
    {
      for (int j = 0; j < tamano; j++)
      {
        if (arreglo[i] == arreglo[i - 1])
        {
          break;
        }
        if (valorBuscado == arreglo[j])
        {
          num++;
        }
      }
    }
    if (num > 0)
    {
      return num;
    }
  }
  return 99999;
}

int busquedaLineal(int arreglo[], int tamano, int valorBuscado)
{
  for (int i = 0; i < tamano; i++)
  {
    if (arreglo[i] == valorBuscado)
    {
      return i;
    }
  }
  return 99999;
}

int busquedaBinaria(int arreglo[], int inicio, int fin, int valorBuscado)
{
  if (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arreglo[medio] == valorBuscado)
    {
      return medio;
    }
    else if (arreglo[medio] > valorBuscado)
    {
      return busquedaBinaria(arreglo, inicio, medio - 1, valorBuscado); // Buscar en la mitad inferior
    }
    return busquedaBinaria(arreglo, medio + 1, fin, valorBuscado); // Buscar en la mitad superior
  }
  return -1;
}

void insercion(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main(int argc, char const *argv[])
{
  const int num = 10;
  int busqueda, resultado;
  int arr_num[num];
  cout << "Llene el siguiente arreglo: ";
  for (int i = 0; i < num; i++)
  {
    cout << "Ingrese numero " << i + 1 << ": --> ";
    cin >> arr_num[i];
  }
  cout << "********************** Ejercicio 1 **********************" << endl;
  cout << "Implementar una búsqueda lineal para encontrar un elemento en un arreglo desordenado de números." << endl;
  cout << "Que numero desea buscar? ";
  cin >> busqueda;
  resultado = busquedaLineal(arr_num, num, busqueda);
  if (resultado == 99999)
  {
    cout << "El numero " << busqueda << " no existe, en la base de datos" << endl;
  }
  else if (resultado != 99999)
  {
    cout << "El numero " << busqueda << " Fue encontrado, exitosamente" << endl;
  }

  // * ------------------------------------------------------------------------ ejercicio 2
  cout << endl
       << "********************** Ejercicio 2 **********************" << endl;
  cout << "Utilizar la búsqueda binaria para encontrar un valor específico en un arreglo ordenado de números." << endl;
  insercion(arr_num, num);
  cout << "Que numero desea buscar? ";
  cin >> busqueda;
  int tamano = sizeof(arr_num) / sizeof(arr_num[0]);
  resultado = busquedaBinaria(arr_num, 0, tamano - 1, busqueda);
  if (resultado != -1)
  {
    cout << "El valor " << busqueda << " se encuentra en el arreglo " << endl;
  }
  else
  {
    cout << "El valor " << busqueda << " no se encuentra en el arreglo " << endl;
  }

  // ! ------------------------------------------------------------------------ ejercicio 3
  cout << endl
       << "********************** Ejercicio 3 **********************" << endl;
  cout << "Utilizar la búsqueda binaria para encontrar un valor específico en un arreglo ordenado de números." << endl;
  cout << "Que numero desea buscar? ";
  cin >> busqueda;
  int repetidos;
  repetidos = busqueda_H(arr_num, tamano, busqueda);
  if (repetidos != 99999)
  {
    cout << "El valor " << busqueda << " si se encuantra en el arreglo y se repite: " << repetidos << endl;
  }
  else
  {
    cout << "El valor " << busqueda << " no se encuentra en el arreglo" << endl;
  }
  return 0;
}
