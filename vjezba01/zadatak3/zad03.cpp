#include <iostream>
using namespace std;

int max(int* arr, int size_arr)
{
    int max_num = arr[0];
    int count;
    for (count = 1; count < size_arr; count++)
    {
        if (arr[count]>max_num)
            max_num = arr[count];
    }
    return max_num;
}
int min(int* arr, int size_arr)
{
    int min_num =arr[0];
    int count;
    for (count = 1; count < size_arr; count++)
    {
        if (arr[count] < min_num)
            min_num = arr[count];
    }
    return min_num;
}
void input_arr(int* arr, int elements_in_arr)
{
    int count;
    for(count=0;count<elements_in_arr;count++)
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
    cout << "najveci element u nizu je: " << max(arr,elements) << endl;
    cout << "najmanji element u nizu je: " << min(arr,elements) << endl;
}
