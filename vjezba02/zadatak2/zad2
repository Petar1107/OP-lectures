//zadatak.2
//Napisati funkciju koja vraæa referencu na neki element niza.
//Koristeæi povratnu vrijednost funkcije kao lvalue uveæajte i-ti element niza za jedan.

#include <iostream>
using namespace std;


int& funk(int* arr, int k)
{
    return arr[k];
}
int main()
{
    int arr[100];
    int index;
    int e;
    cout << "unesite broj elementa niza: " << endl;
    cin >> e;
    cout << "unesite clanove niza: " << endl;
    for(int i=0;i<e;i++)
    {
        cin >> arr[i];
    }
    cout << "unesite index clana kojeg zelite promjeniti: ";
    cin >> index;
    if(index>=e);
    cout << "indeks elementa kojeg zelite promijeniti je veci od broja clanova niza!"<< endl;
    funk(arr, index) = arr[index]+1;
    for(int i=0;i<e;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
