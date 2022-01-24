#include "Zadatak02.h"
#include <iostream>
using namespace std;

void main() {
    Stack<int> intStack(7);
    intStack.push(61);
    intStack.push(13);
    intStack.push(22);
    intStack.push(1);
    intStack.push(7);
    intStack.push(11);
    intStack.push(1);
    intStack.print();
    cout << endl;
    intStack.CheckEmpty() ? cout << "Not empty. " << endl : cout << "Empty. " << endl;
}
