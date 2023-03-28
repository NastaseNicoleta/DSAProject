#include "MesajService.h"

MesajService::MesajService()
{
}

MesajService::MesajService(MesajRepository& mr)
{
	this->mesajRepository = mr;
}

MesajService::~MesajService()
{
}

void MesajService::adaugareMesajService(Mesaj& m)
{
	mesajRepository.adaugareMesaj(m);
}


void MesajService::stergereMesajService(int pozitie)
{
	mesajRepository.stergereMesaj(pozitie);
}

Array<Mesaj> MesajService::getAllMesajeService()
{
	return mesajRepository.getAll();
}

void MesajService::showAllMesajeService()
{
	this->mesajRepository.showAll();
}
