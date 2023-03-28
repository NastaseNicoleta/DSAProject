#pragma once
#include <iostream>

using namespace std;

class Eveniment {
private:
	char* locatie;
	char* denumire;
	char* data;
	char* organizator;
	int capacitate;
	char* categorie;
public:
	Eveniment();
	Eveniment(const char*, const char*, const char*, const char*, int, const char*);
	Eveniment(Eveniment&);
	~Eveniment();

	char* getLocatie();
	char* getDenumire();
	char* getData();
	char* getOrganizator();
	int getCapacitate();
	char* getCategorie();

	void setLocatie(const char*);
	void setDenumire(const char*);
	void setData(const char*);
	void setOrganizator(const char*);
	void setCapacitate(int);
	void setCategorie(const char*);

	friend ostream& operator<<(ostream&, Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	Eveniment& operator=(const Eveniment&);
	bool operator==(const Eveniment&);
};