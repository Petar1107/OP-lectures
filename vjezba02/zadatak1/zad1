//1. Napisati funkciju koja raèuna najveæi i najmanji broj u nizu od n prirodnih
//brojeva. Funkcija vraæa tražene brojeve pomoæu referenci
#include <iostream>
using namespace std;
int max_el(int* arr,int el, int& maxi)
{
    maxi=arr[0];
    for(int counter=1;counter<el;counter++)
    {
        if(arr[counter]>maxi)
            maxi=arr[counter];
    }
    return maxi;
}
int min_el(int* arr, int el,int& mini)
{
    mini=arr[0];
    for(int counter=1;counter<el;counter++)
    {
        if(arr[counter]<mini)
            mini=arr[counter];
    }
    return mini;
}
void input_arr(int* arr,int el)
{
    cout << "unesite clanove niza: " << endl;
    for(int counter=0;counter<el;counter++)
    {
        cin >> arr[counter];
    }
}
int main(void)
{
    int el;
    cout << "unesite broj clanova niza: " << endl;
    cin >> el;
    int* arr;
    arr = new int[el];
    input_arr(arr,el);
    int mini=min_el(arr,el,mini);
    int maxi=max_el(arr,el,maxi);
    cout << "najmanji element niza je: " << mini << endl;
    cout << "najveci element niza je: " << maxi << endl;
    delete arr;
    return 0;
}
