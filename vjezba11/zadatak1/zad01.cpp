#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void putInVector(const string& file, vector<int>& v)
{
	ifstream f;
	int tmp;

	f.open(file);
	if (!f.is_open()) {
		throw exception();
	}
	istream_iterator<int> it(f);
	istream_iterator<int> eos;
	copy(it, eos, back_inserter(v));
}

int main()
{
	vector<int> v;
	const string f = "numbers.txt";

	try {
		putInVector(f, v);
	}
	catch (const exception& e) {
		cout << "Error opening file! " << endl;
		return 0;
	}

	// Printing original vector
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	int greater500 = count_if(v.begin(), v.end(), [](int i) { return i > 500; });
	cout << "Numbers greater than 500: " << greater500 << endl << endl;

	// Functions for min and max element of vector
	int min = *min_element(v.begin(), v.end());
	int max = *max_element(v.begin(), v.end());
	cout << "Min element: " << min << endl;
	cout << "Max element: " << max << endl;

	// Removing elements of vector with condition
	std::vector<int>::iterator it;
	it = remove_if(v.begin(), v.end(), [](int i) { return i < 300; });
	v.resize(std::distance(v.begin(), it));
	sort(v.begin(), v.end(), greater<int>());

	// Print vector without elements < 300
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl << endl;
	return 0;
}
