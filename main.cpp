#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int mitad (int arr[], int pinicial, int pfinal);
void ordenar(int arr[], int pinicial, int pfinal);
int main()
{
  ofstream datos;
  int A[10];
  srand(time(0));
  datos.open("quicksort.txt",ios::out);
  datos << "elementos sin ordenar" << endl;
  for(int i=0; i<10;i++)
  {
    A[i]=1+rand()&100;
    datos << A[i] << endl;
  }
  datos << "elementos ordenados" << endl;
  for(int i=0; i<10;i++)
  {
    cout << A[i] << endl;
  }
    ordenar(A,0,9);
    cout<<endl;
      cout << "elementos ordenados" << endl;
    for(int i=0; i<10;i++)
    {
        cout<<A[i]<< endl;
        datos << A[i] << endl;
    }
    datos << "algoritmo utilzado: Quicksort" << endl;
    datos.close();
    return 0;
}
int mitad (int arr[], int pinicial,  int pfinal)
{
    return arr[(pinicial+pfinal)/2];
}
void ordenar(int arr[], int pinicial, int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(arr,pinicial,pfinal);

    do
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while(arr[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }

    }
    while(i<=j);

    if(pinicial<j)
        ordenar(arr,pinicial,j);
    if(i<pfinal)
        ordenar(arr,i,pfinal);
}