#include "EvenimentRepository.h"

//Constructor 
EvenimentRepository::EvenimentRepository()
{
	Eveniment* evenimente = new Eveniment[100];
}

//Destructor
EvenimentRepository::~EvenimentRepository()
{
}

//Adaugarea unui obiect
void EvenimentRepository::adaugareEveniment(Eveniment& e)
{
	this->evenimente.adaugareElem(e);
}

//Stergerea unui obiect
void EvenimentRepository::stergereEveniment(int pozitie)
{
	this->evenimente.stergereElem(pozitie);
}

//Returnarea unui obiect de pe o pozitie data
Eveniment EvenimentRepository::getEvenimentDePeOAnumePozitie(int pozitie)
{
	return this->evenimente[pozitie];
}

//Returnarea tuturor obiectelor din array
Array<Eveniment> EvenimentRepository::getAll()
{
	return this->evenimente;
}

//Afisarea tuturor obiectelor din array
void EvenimentRepository::showAll()
{
	if (evenimente.size() == 0)
		cout << "Nu exista elemente!" << endl;
	else
		for (int i = 0; i < evenimente.size(); i++)
			cout << this->evenimente[i];
	cout << endl;
}
