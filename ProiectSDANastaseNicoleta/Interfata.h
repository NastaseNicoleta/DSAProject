#pragma once
#include "UtilizatorService.h"
#include "PrietenieService.h"
#include "MesajService.h"
#include "EvenimentService.h"
#include <iostream>

using namespace std;

class Interfata {
private:
	UtilizatorService utilizatorService;
	PrietenieService prietenieService;
	MesajService mesajService;
	EvenimentService evenimentService;
public:
	Interfata();
	Interfata(UtilizatorService&, PrietenieService&, MesajService&, EvenimentService&);
	~Interfata();

	void optiuniMeniu();
	void optiuniMeniuUtilizator();
	void meniu();
	void meniuUtilizator();
	void adaugareUtilizatorInterfata();
	void modificareUtilizatorInterfata();
	void stergereUtilizatorInterfata();
	void optiuniMeniuPrietenie();
	void meniuPrietenie();
	void adaugarePrietenieInterfata();
	void stergerePrietenieInterfata();
	void optiuniMeniuMesaj();
	void meniuMesaj();
	void adaugareMesajInterfata();
	void stergereMesajInterfata();
	void optiuniMeniuEveniment();
	void meniuEveniment();
	void adaugareEvenimentInterfata();
	void stergereEvenimentInterfata();
	void adaugare15Utilizatori();
	void adaugare15Prietenii();
	void adaugare15Mesaje();
	void adaugare6Evenimente();
};