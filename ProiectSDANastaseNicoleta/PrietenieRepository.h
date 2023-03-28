#pragma once
#include "Prietenie.h"
#include "Array.h"

class PrietenieRepository {
private:
	Array<Prietenie> prietenii;
public:
	PrietenieRepository();
	~PrietenieRepository();
	
	void adaugarePrietenie(Prietenie&);
	//O prietenie nu poate fi modificata, doar stearsa, deci nu vom avea functie de modificare aici
	void stergerePrietenie(int);
	Prietenie getPrietenieDePeOPozitieAnume(int);
	Array<Prietenie> getAll();
	void showAll();
};