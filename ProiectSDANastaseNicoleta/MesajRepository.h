#pragma once
#include "Mesaj.h"
#include "Array.h"

class MesajRepository {
private:
	Array<Mesaj> mesaje;
public:
	MesajRepository();
	~MesajRepository();
	void adaugareMesaj(Mesaj&);
	void stergereMesaj(int);
	Mesaj getMesajDePeOAnumePozitie(int);
	Array<Mesaj> getAll();
	void showAll();
};