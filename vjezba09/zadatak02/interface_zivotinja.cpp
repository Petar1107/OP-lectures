#include "Interface_zivotinja.h"

Zivotinja::~Zivotinja() {}

string Ptica::vrstaZivotinje()
{
	return this->vrsta;
}

int Ptica::brojNogu() 
{
	return this->noge;
}

void Ptica::setVrsta(string str) 
{
	this->vrsta = str;
}

void Ptica::setNoge(int num)
{
	this->noge = num;
}

string Pauk::vrstaZivotinje()
{
	return this->vrsta;
}

int Pauk::brojNogu() 
{
	return this->noge;
}

void Pauk::setVrsta(string str) 
{
	this->vrsta = str;
}

void Pauk::setNoge(int num) 
{
	this->noge = num;
}

string Kukac::vrstaZivotinje()
{
	return this->vrsta;
}

int Kukac::brojNogu() 
{
	return this->noge;
}


void Kukac::setVrsta(string str) 
{
	this->vrsta = str;
}

void Kukac::setNoge(int num) 
{
	this->noge = num;
}

Zohar::Zohar() 
{
	setVrsta("zohar");
	setNoge(6);
}

Muha::Muha() 
{
	setVrsta("muha");
	setNoge(6);
}

Golub::Golub() 
{
	setVrsta("golub");
	setNoge(2);
}

Vrabac::Vrabac() 
{
	setVrsta("vrabac");
	setNoge(2);
}
Tarantula::Tarantula()
{
	setVrsta("tarantula");
	setNoge(8);
}
void Brojac::IspisZivotinje(Zivotinja* zivotinja)
{
	cout << "Dodan: " << zivotinja->vrstaZivotinje() << endl << endl;
	this->noge += zivotinja->brojNogu();
};
int Brojac::IspisNogu()
{
	return this->noge;
}
