#include <iostream>
#include <vector>

using namespace std;

class Zivotinja 
{
public:
	virtual int brojNogu() = 0;
	virtual string vrstaZivotinje()=0;
	virtual ~Zivotinja();
};

class Kukac : public Zivotinja 
{
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};

class Zohar : public Kukac 
{
public:
	Zohar();
};

class Muha : public Kukac {
public:
	Muha();
};


class Pauk : public Zivotinja
{
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};

class Tarantula : public Kukac 
{
public:
	Tarantula();
};


class Ptica : public Zivotinja 
{
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};

class Golub : public Ptica 
{
public:
	Golub();
};

class Vrabac : public Ptica 
{
public:
	Vrabac();
};

class Brojac 
{
private:
	int noge = 0;
public:
	void IspisZivotinje(Zivotinja* zivotinja);
	int IspisNogu();
};

