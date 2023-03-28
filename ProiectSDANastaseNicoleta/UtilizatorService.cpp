#include "UtilizatorService.h"
#include <iostream>

using namespace std;

UtilizatorService::UtilizatorService()
{
}

UtilizatorService::UtilizatorService(UtilizatorRepository& ur)
{
	this->utilizatorRepository = ur;
}

UtilizatorService::~UtilizatorService()
{
}

void UtilizatorService::adaugareUtilizatorService(const char* id, const char* nume)
{
	Utilizator u(id, nume);
	utilizatorRepository.adaugareUtilizator(u);
}

void UtilizatorService::modificareUtilizatorService(int pozitie, const char* idNou, const char* numeNou)
{
	Utilizator u(idNou, numeNou);
	utilizatorRepository.modificareUtilizator(pozitie, u);
}

void UtilizatorService::stergereUtilizatorService(int pozitie)
{
	utilizatorRepository.stergereUtilizator(pozitie);
}

Array<Utilizator> UtilizatorService::getAllUtilizatoriService()
{
	return utilizatorRepository.getAll();
}

void UtilizatorService::showAllUtilizatoriService()
{
	this->utilizatorRepository.showAll();
}
