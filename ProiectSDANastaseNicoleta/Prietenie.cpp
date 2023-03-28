#include "Prietenie.h"

//Constuctor implicit: aloca spatiu si initializeaza elementele
Prietenie::Prietenie()
{
	this->id1 = nullptr;
	this->id2 = nullptr;
}

//Constructor general (cu parametri) - initializeaza datele membre cu valori date
Prietenie::Prietenie(const char* id1, const char* id2)
{
	this->id1 = new char[strlen(id1) + 1];
	strcpy_s(this->id1, strlen(id1) + 1, id1);
	this->id2 = new char[strlen(id2) + 1];
	strcpy_s(this->id2, strlen(id2) + 1, id2);
}

//Constructor de copiere - se initializeaza un obiect cu un alt obiect care este dat prin valoare 
Prietenie::Prietenie(Prietenie& p)
{
	this->id1 = new char[strlen(p.id1) + 1];
	strcpy_s(this->id1, strlen(p.id1) + 1, p.id1);
	this->id2 = new char[strlen(p.id2) + 1];
	strcpy_s(this->id2, strlen(p.id2) + 1, p.id2);
}

//Destructor: elibereaza spatiul ocupat de elemente
Prietenie::~Prietenie()
{
	if (this->id1 or this->id2) {
		delete[] this->id1;
		this->id1 = nullptr;
		delete[] this->id2;
		this->id2 = nullptr;
	}
}

char* Prietenie::getId1()
{
	return this->id1;
}

char* Prietenie::getId2()
{
	return this->id2;
}

void Prietenie::setId1(const char* id1)
{
	if (this->id1) delete[] this->id1;
	if (id1 == nullptr) this->id1 = nullptr;
	else {
		this->id1 = new char[strlen(id1) + 1];
		strcpy_s(this->id1, strlen(id1) + 1, id1);
	}
}

void Prietenie::setId2(const char* id2)
{
	if (this->id2) delete[] this->id2;
	if (id2 == nullptr) this->id2 = nullptr;
	else {
		this->id2 = new char[strlen(id2) + 1];
		strcpy_s(this->id2, strlen(id2) + 1, id2);
	}
}

Prietenie& Prietenie::operator=(const Prietenie& p)
{
	if (this != &p) {
		this->id1 = new char[strlen(p.id1) + 1];
		strcpy_s(this->id1, strlen(p.id1) + 1, p.id1);
		this->id2 = new char[strlen(p.id2) + 1];
		strcpy_s(this->id2, strlen(p.id2) + 1, p.id2);
	}
	return *this;
}

bool Prietenie::operator==(const Prietenie& p)
{
	return (strcmp(this->id1, p.id1) == 0 && strcmp(this->id2, p.id2) == 0);
}

ostream& operator<<(ostream& os, Prietenie& p)
{
	os << "Id-ul primului utilizatorului: " << p.id1 << endl << "Id-ul celui de al doilea utilizator: " << p.id2 << endl;
	return os;
}

istream& operator>>(istream& is, Prietenie& p)
{
	cout << "Dati id-ul primului utilizatorului: " << endl;
	is >> p.id1;
	cout << "Dati id-ul celui de al doilea utilizatorului: " << endl;
	is >> p.id2;
	cout << p.id1 << " " << p.id2 << endl;
	return is;
}
