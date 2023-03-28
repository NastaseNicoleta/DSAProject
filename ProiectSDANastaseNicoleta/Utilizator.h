#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Utilizator {
private:
	char* id;
	char* nume;
public:
	Utilizator();
	Utilizator(const char*, const char*);
	Utilizator(const Utilizator&);
	~Utilizator();

	void setId(const char*);
	void setNume(const char*);

	char* getId();
	char* getNume();

	friend ostream& operator<<(ostream&, Utilizator&);
	friend istream& operator>>(istream&, Utilizator&);
	Utilizator& operator=(const Utilizator&);
	bool operator==(const Utilizator&);
};
