#include "UtilizatorRepository.h"
#include "Array.h"
#include <iostream>
#include <fstream>

using namespace std;


UtilizatorRepository::UtilizatorRepository()
{
	Utilizator* utilizatori = new Utilizator[25];
	this->numeFisier = nullptr;
}

UtilizatorRepository::UtilizatorRepository(const char* numeFisier)
{
	if (numeFisier != nullptr) {
		this->numeFisier = new char[strlen(numeFisier) + 1];
		strcpy_s(this->numeFisier, strlen(numeFisier) + 1, numeFisier);
	}
	else {
		this->numeFisier = nullptr;
		this->incarcaDinFisier();
	}
}

UtilizatorRepository::~UtilizatorRepository()
{
	if (numeFisier == nullptr)
		delete[] this->numeFisier;
}

void UtilizatorRepository::incarcaDinFisier()
{
	if (this->numeFisier) {
		ifstream f(this->numeFisier);
		char id[5], nume[15];
		while (!f.eof()) {
			f >> id >> nume;
			if (strlen(nume) > 0 && strlen(id) > 0) {
				Utilizator u(id, nume);
				this->adaugareUtilizator(u);
			}
		}
		f.close();
	}
}

void UtilizatorRepository::salveazaInFisier()
{
	if (this->numeFisier) {
		ofstream f(this->numeFisier);
		for (int i = 0; i < utilizatori.size(); i++) {
			f << this->utilizatori[i] << endl;
		}
	}
}

void UtilizatorRepository::adaugareUtilizator(Utilizator& u)
{
	 this->utilizatori.adaugareElem(u);
}

void UtilizatorRepository::modificareUtilizator(int pozitie, Utilizator& u)
{
	this->utilizatori[pozitie] = u;
}

void UtilizatorRepository::stergereUtilizator(int pozitie)
{
	this->utilizatori.stergereElem(pozitie);
}

int UtilizatorRepository::getSize()
{
	return this->utilizatori.size();
}

Utilizator UtilizatorRepository::getUtilizatorDePeOPozitieAnume(int pozitie)
{
	return this->utilizatori[pozitie];
}

Array<Utilizator> UtilizatorRepository::getAll()
{
	return this->utilizatori;
}

void UtilizatorRepository::showAll()
{
	if (utilizatori.size() == 0)
		cout << "Nu exista elemente!" << endl;
	else
		for (int i = 0; i < utilizatori.size(); i++)
			cout << this->utilizatori[i];
	cout << endl;
}
