#include <iostream>
using namespace std;

int rek_min_num(int* arr, int e)
{
    if(e==1)
        return arr[0];
    else
        return min(arr[e-1],rek_min_num(arr,e-1));
}
int rek_max_num(int* arr, int e)
{
    if (e==1)
        return arr[0];
    return max(arr[e-1], rek_max_num(arr,e-1));
}
void input_arr(int* arr, int e)
{
    int count;
    for(count=0;count<e;count++)
    {
        cin >> (arr[count]);
    }
}
int main()
{
    int arr[100];
    int elements;
    cout << "unesite broj clanova niza: " << endl;
    cin >> elements;
    cout << "unesite elemente niza: " << endl;
    input_arr(arr,elements);
    cout << "najveci element u nizu je: " << rek_max_num(arr,elements) << endl;
    cout << "najmanji element u nizu je: " << rek_min_num(arr,elements) << endl;

}

