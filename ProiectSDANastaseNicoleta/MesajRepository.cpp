#include "MesajRepository.h"

MesajRepository::MesajRepository()
{
	Mesaj* mesaje = new Mesaj[2000];
}

MesajRepository::~MesajRepository()
{
}

void MesajRepository::adaugareMesaj(Mesaj& m)
{
	this->mesaje.adaugareElem(m);
}


void MesajRepository::stergereMesaj(int pozitie)
{
	this->mesaje.stergereElem(pozitie);
}

Mesaj MesajRepository::getMesajDePeOAnumePozitie(int pozitie)
{
	return this->mesaje[pozitie];
}

Array<Mesaj> MesajRepository::getAll()
{
	return this->mesaje;
}

void MesajRepository::showAll()
{
	if (mesaje.size() == 0)
		cout << "Nu exista elemente!" << endl;
	else
		for (int i = 0; i < mesaje.size(); i++)
			cout << this->mesaje[i];
	cout << endl;
}
