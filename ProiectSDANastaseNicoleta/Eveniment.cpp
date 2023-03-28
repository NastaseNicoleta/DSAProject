#include "Eveniment.h"

Eveniment::Eveniment()
{
	this->locatie = nullptr;
	this->denumire = nullptr;
	this->data = nullptr;
	this->organizator = nullptr;
	this->capacitate = 0;
	this->categorie = nullptr;
}

Eveniment::Eveniment(const char* locatie, const char* denumire, const char* data, const char* organizator, int capacitate, const char* categorie)
{
	this->locatie = new char[strlen(locatie) + 1];
	strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, strlen(data) + 1, data);
	this->organizator = new char[strlen(organizator) + 1];
	strcpy_s(this->organizator, strlen(organizator) + 1, organizator);
	this->categorie = new char[strlen(categorie) + 1];
	strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
	this->capacitate = capacitate;
}

Eveniment::Eveniment(Eveniment& e)
{
	this->locatie = new char[strlen(e.locatie) + 1];
	strcpy_s(this->locatie, strlen(e.locatie) + 1, e.locatie);
	this->denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(this->denumire, strlen(e.denumire) + 1, e.denumire);
	this->data = new char[strlen(e.data) + 1];
	strcpy_s(this->data, strlen(e.data) + 1, e.data);
	this->organizator = new char[strlen(e.organizator) + 1];
	strcpy_s(this->organizator, strlen(e.organizator) + 1, e.organizator);
	this->categorie = new char[strlen(e.categorie) + 1];
	strcpy_s(this->categorie, strlen(e.categorie) + 1, e.categorie);
	this->capacitate = e.capacitate;
}

Eveniment::~Eveniment()
{
	if (this->locatie or this->denumire or this->data or this->organizator or this->categorie or this->capacitate) {
		delete[] this->locatie;
		this->locatie = nullptr;
		delete[] this->denumire;
		this->denumire = nullptr;
		delete[] this->data;
		this->data = nullptr;
		delete[] this->organizator;
		this->organizator = nullptr;
		delete[] this->categorie;
		this->categorie = nullptr;
		this->capacitate = 0;
	}
}

char* Eveniment::getLocatie()
{
	return this->locatie;
}

char* Eveniment::getDenumire()
{
	return this->denumire;
}

char* Eveniment::getData()
{
	return this->data;
}

char* Eveniment::getOrganizator()
{
	return this->organizator;
}

int Eveniment::getCapacitate()
{
	return this->capacitate;
}

char* Eveniment::getCategorie()
{
	return this->categorie;
}

void Eveniment::setLocatie(const char* locatie)
{
	if (this->locatie) delete[] this->locatie;
	if (locatie == nullptr) this->locatie = nullptr;
	else {
		this->locatie = new char[strlen(locatie) + 1];
		strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
	}
}

void Eveniment::setDenumire(const char* denumire)
{
	if (this->denumire) delete[] this->denumire;
	if (denumire == nullptr) this->denumire = nullptr;
	else {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
}

void Eveniment::setData(const char* data)
{
	if (this->data) delete[] this->data;
	if (data == nullptr) this->data = nullptr;
	else {
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
}

void Eveniment::setOrganizator(const char* organizator)
{
	if (this->organizator) delete[] this->organizator;
	if (organizator == nullptr) this->organizator = nullptr;
	else {
		this->organizator = new char[strlen(organizator) + 1];
		strcpy_s(this->organizator, strlen(organizator) + 1, organizator);
	}
}

void Eveniment::setCapacitate(int capacitate)
{
	this->capacitate = capacitate;
}

void Eveniment::setCategorie(const char* categorie)
{
	if (this->categorie) delete[] this->categorie;
	if (categorie == nullptr) this->categorie = nullptr;
	else {
		this->categorie = new char[strlen(categorie) + 1];
		strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
	}
}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e) {
		this->locatie = new char[strlen(e.locatie) + 1];
		strcpy_s(this->locatie, strlen(e.locatie) + 1, e.locatie);
		this->denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(this->denumire, strlen(e.denumire) + 1, e.denumire);
		this->data = new char[strlen(e.data) + 1];
		strcpy_s(this->data, strlen(e.data) + 1, e.data);
		this->organizator = new char[strlen(e.organizator) + 1];
		strcpy_s(this->organizator, strlen(e.organizator) + 1, e.organizator);
		this->categorie = new char[strlen(e.categorie) + 1];
		strcpy_s(this->categorie, strlen(e.categorie) + 1, e.categorie);
		this->capacitate = e.capacitate;
	}
	return *this;
}

bool Eveniment::operator==(const Eveniment& e)
{
	return (strcmp(this->locatie, e.locatie) == 0 && (strcmp(this->denumire, e.denumire)) == 0 && strcmp(this->data, e.data)==0 && strcmp(this->organizator, e.organizator)==0 && strcmp(this->categorie, e.categorie)==0 && (this->capacitate == e.capacitate));
}

ostream& operator<<(ostream& os, Eveniment& e)
{
	os << "Locatia evenimentului: " << e.locatie << endl << "Denumirea evenimentului: " << e.denumire << endl << "Data evenimentului: " << e.data << endl << "Organizatotul evenimentului: " << e.organizator << endl << "Capacitatea evenimentului: " << e.capacitate << endl << "Categoria evenimentului: " << e.categorie << endl;
	return os;
}

istream& operator>>(istream& is, Eveniment& e)
{
	cout << "Dati locatia evenimentului: "<< endl;
	is >> e.locatie;
	cout << "Dati denumirea evenimentului: " << endl;
	is >> e.denumire;
	cout << "Dati data evenimentului: " << endl;
	is >> e.data;
	cout << "Dati organizatorul evenimentului: " << endl;
	is >> e.organizator;
	cout << "Dati capacitatea evenimentului: " << endl;
	is >> e.capacitate;
	cout << "Dati categoria evenimentului: " << endl;
	is >> e.categorie;
	return is;
}
