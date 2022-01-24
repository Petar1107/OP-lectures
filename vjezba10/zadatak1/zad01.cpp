#include <iostream>
#include <vector>

using namespace std;
template<typename TYPE>
void sortArray(TYPE arr[], int el)
{
    for (int i = 0; i < el; i++)
    {
        for (int j = 0; j < el; j++)
        {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
template<>
void sortArray<char>(char arr[], int el)
{
    for (int i = 0; i < el; i++)
    {
        for (int j = 0; j < el; j++)
        {
            if (tolower(arr[i]) < tolower(arr[j]))
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int array1[] = { 1,33,2,12,27,11,7,31 };
    char array2[] = { 'a', 'B', 'e', 'C', 'e', 'd', 'A'};
    int s1 = sizeof(array1) / sizeof(array1[0]);
    int s2 = sizeof(array2) / sizeof(array2[0]);
    sortArray(array1, s1);
    sortArray(array2, s2);
    cout << "Int array: ";
    for (int i = 0; i < s1; i++)
    {
        (i == s1 - 1) ? cout << array1[i] : cout << array1[i] << ", ";
    }
    cout << endl;
    cout << "Char array: ";
    for (int i = 0; i < s2; i++)
    {
        (i == s2 - 1) ? cout << array2[i] : cout << array2[i] << ", ";
    }
}
