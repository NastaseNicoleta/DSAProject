#include "PrietenieRepository.h"
#include <iostream>

using namespace std;

PrietenieRepository::PrietenieRepository()
{
	Prietenie* prietenii = new Prietenie[5000];
}

PrietenieRepository::~PrietenieRepository()
{
}

void PrietenieRepository::adaugarePrietenie(Prietenie& p)
{
	 this->prietenii.adaugareElem(p);
}

void PrietenieRepository::stergerePrietenie(int pozitie)
{
	this->prietenii.stergereElem(pozitie);
}

Prietenie PrietenieRepository::getPrietenieDePeOPozitieAnume(int pozitie)
{
	return this->prietenii[pozitie];
}

Array<Prietenie> PrietenieRepository::getAll()
{
	return this->prietenii;
}

void PrietenieRepository::showAll()
{
	if (prietenii.size() == 0) cout << "Nu exista elemente!";
	else {
		for (int i = 0; i < prietenii.size(); i++)
			cout << this->prietenii[i];
		cout << endl;
	}
}
