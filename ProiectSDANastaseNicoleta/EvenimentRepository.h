#pragma once
#include "Eveniment.h"
#include "Array.h"
#include <iostream>

class EvenimentRepository {
private:
	Array<Eveniment> evenimente;
public:
	EvenimentRepository();
	~EvenimentRepository();
	void adaugareEveniment(Eveniment&);
	void stergereEveniment(int);
	Eveniment getEvenimentDePeOAnumePozitie(int);
	Array<Eveniment> getAll();
	void showAll();
};