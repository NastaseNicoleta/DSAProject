#include "PrietenieService.h"
#include <iostream>

using namespace std;

PrietenieService::PrietenieService()
{
}

PrietenieService::PrietenieService(PrietenieRepository& pr)
{
	this->prietenieRepository = pr;
}

PrietenieService::~PrietenieService()
{
}

void PrietenieService::adaugarePrietenieService(const char* id1, const char* id2)
{
	Prietenie p(id1, id2);
	prietenieRepository.adaugarePrietenie(p);
}

void PrietenieService::stergerePrietenieService(int pozitie)
{
	prietenieRepository.stergerePrietenie(pozitie);
}

Array<Prietenie> PrietenieService::getAllPrieteniiServie()
{
	return this->prietenieRepository.getAll();
}

void PrietenieService::showAllPrieteniiService()
{
	this->prietenieRepository.showAll();
}
