#pragma once
#include <iostream>

using namespace std;

class Prietenie {
private:
	char* id1;
	char* id2;
public:
	Prietenie();
	Prietenie(const char*, const char*);
	Prietenie(Prietenie&);
	~Prietenie();

	char* getId1();
	char* getId2();

	void setId1(const char*);
	void setId2(const char*);

	friend ostream& operator<<(ostream&, Prietenie&);
	friend istream& operator>>(istream&, Prietenie&);
	Prietenie& operator=(const Prietenie&);
	bool operator==(const Prietenie&);
};