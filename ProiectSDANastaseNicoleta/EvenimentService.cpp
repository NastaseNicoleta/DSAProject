#include "EvenimentService.h"

EvenimentService::EvenimentService()
{
}

EvenimentService::EvenimentService(EvenimentRepository& er)
{
	this->evenimentRepository = er;
}

EvenimentService::~EvenimentService()
{
}

void EvenimentService::adaugareEvenimentService(const char* locatie, const char* denumire, const char* data, const char* organizator, int capacitate, const char* categorie)
{
	Eveniment e(locatie, denumire, data, organizator, capacitate, categorie);
	this->evenimentRepository.adaugareEveniment(e);
}

void EvenimentService::stergereEvenimentService(int pozitie)
{
	this->evenimentRepository.stergereEveniment(pozitie);
}

Array<Eveniment> EvenimentService::getAllEvenimenteService()
{
	return this->evenimentRepository.getAll();
}

void EvenimentService::showAllEvenimenteService()
{
	this->evenimentRepository.showAll();
}
