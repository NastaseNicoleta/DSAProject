#pragma once
#include "Utilizator.h"
#include "Array.h"
#include <iostream>

using namespace std;

class UtilizatorRepository {
private:
	Array<Utilizator> utilizatori;
	char* numeFisier;
	void incarcaDinFisier();
	void salveazaInFisier();
public:
	UtilizatorRepository();
	UtilizatorRepository(const char*);
	~UtilizatorRepository();
	void adaugareUtilizator(Utilizator&);
	void modificareUtilizator(int, Utilizator&);
	void stergereUtilizator(int);
	int getSize();
	Utilizator getUtilizatorDePeOPozitieAnume(int);
	Array<Utilizator> getAll();
	void showAll();
	
};
