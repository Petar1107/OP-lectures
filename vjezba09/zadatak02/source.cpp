#include "Interface_zivotinja.h"

int main() 
{

	Tarantula tarantula;
	Zohar zohar;
	Vrabac vrabac;

	Zivotinja* zivotinja[3];

	zivotinja[0] = new Tarantula;
	zivotinja[1] = new Zohar;
	zivotinja[2] = new Vrabac;

	Brojac br;
	for (auto& a : zivotinja) 
	{
		br.IspisZivotinje(a);
	}
	cout << "Ukupno nogu: " << br.IspisNogu() << endl;
}
