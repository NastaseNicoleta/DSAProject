#include <iostream>
#include "Interfata.h"

using namespace std;

int main() {
	UtilizatorRepository utilizatorRepository;
	UtilizatorService utilizatorService(utilizatorRepository);
	PrietenieRepository prietenieRepository;
	PrietenieService prietenieService(prietenieRepository);
	MesajRepository mesajRepository;
	MesajService mesajService(mesajRepository);
	EvenimentRepository evenimentRepository;
	EvenimentService evenimentService(evenimentRepository);
	Interfata interfata(utilizatorService, prietenieService, mesajService, evenimentService);
	interfata.adaugare15Utilizatori();
	interfata.adaugare15Prietenii();
	interfata.adaugare15Mesaje();
	interfata.adaugare6Evenimente();
	interfata.meniu();
}
