#include "Utilizator.h"
#include <iostream>

using namespace std;

//Constuctor implicit: aloca spatiu si initializeaza elementele
Utilizator::Utilizator()
{
	this->id = nullptr;
	this->nume = nullptr;
}

//Constructor general (cu parametri) - initializeaza datele membre cu valori date
Utilizator::Utilizator(const char* id, const char* nume)
{
	this->id = new char[strlen(id) + 1];
	strcpy_s(this->id, strlen(id) + 1, id);
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

//Constructor de copiere - se initializeaza un obiect cu un alt obiect care este dat prin valoare 
Utilizator::Utilizator(const Utilizator& u)
{
	this->id = new char[strlen(u.id) + 1];
	strcpy_s(this->id, strlen(u.id) + 1, u.id);
	this->nume = new char[strlen(u.nume) + 1];
	strcpy_s(this->nume, strlen(u.nume) + 1, u.nume);
}

//Destructor: elibereaza spatiul ocupat de elemente
Utilizator::~Utilizator()
{
	if (this->id or this->nume) {
		delete[] this->id;
		this->id = nullptr;
		delete[] this->nume;
		this->nume = nullptr;
	}

}

//Setter: Seteaza id-ul cu cel dat
void Utilizator::setId(const char* id)
{
	if (this->id) delete[] this->id;
	if (id == nullptr) this->id = nullptr;
	else {
		this->id = new char[strlen(id) + 1];
		strcpy_s(this->id, strlen(id) + 1, id);
	}
}

//Setter: seteaza numele cu cel dat
void Utilizator::setNume(const char* nume)
{
	if (this->nume) delete[] this->nume;
	if (nume == nullptr) this->nume = nullptr;
	else {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

//Getter: returneaza id-ul obiectului
char* Utilizator::getId()
{
	return this->id;
}

//Getter: returneaza numele obiectului
char* Utilizator::getNume()
{
	return this->nume;
}

//Operatorul = pentru assign-are
Utilizator& Utilizator::operator=(const Utilizator& u)
{
	if (this != &u) {
		this->id = new char[strlen(u.id) + 1];
		strcpy_s(this->id, strlen(u.id) + 1, u.id);
		this->nume = new char[strlen(u.nume) + 1];
		strcpy_s(this->nume, strlen(u.nume) + 1, u.nume);
	}
	return *this;
}

//Operatorul == pentru egalitate
bool Utilizator::operator==(const Utilizator& u)
{
	return (strcmp(this->id, u.id) == 0 && strcmp(this->nume, u.nume) == 0);
}

//Operatorul << pentru afisare
ostream& operator<<(ostream& os, Utilizator& u)
{
	os << "Id-ul utilizatorului: " << u.id << endl << "Numele utilizatorului: " << u.nume << endl;
	return os;

}

//Operatorul >> pentru citire
istream& operator>>(istream& is, Utilizator& u)
{
	cout << "Dati id-ul utilizatorului: " << endl;
	is >> u.id;
	cout << "Dati numele utilizatorului: " << endl;
	is >> u.nume;
	cout << u.id << " " << u.nume << endl;
	return is;
}
