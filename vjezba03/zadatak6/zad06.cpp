// Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
//svaki string preokrene te sortira vektor po preokrenutim stringovima.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input_vector(vector <string>* v, int num_str)
{
	string str;
	cout << "enter strings: ";
	for (int i = 0; i < num_str; i++)
	{
		cin >> str;
		reverse(str.begin(), str.end());
		v->push_back(str);
	}
	sort(v->begin(), v->end());
}
void output_vector(vector <string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
int main(void)
{
	vector <string> v;
	string str;
	int num_str;
	cout << "enter the number of strings you want to enter: ";
	cin >> num_str;
	input_vector(&v, num_str);
	cout << "the sorted array of inverted strings is: " << endl;
	output_vector(v);
	return 0;
}
