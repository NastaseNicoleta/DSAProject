#pragma once
#include "UtilizatorRepository.h"
#include <iostream>

using namespace std;

class UtilizatorService {
private:
	UtilizatorRepository utilizatorRepository;
public:
	UtilizatorService();
	UtilizatorService(UtilizatorRepository&);
	~UtilizatorService();
	void adaugareUtilizatorService(const char*, const char*);
	void modificareUtilizatorService(int, const char*, const char*);
	void stergereUtilizatorService(int);
	Array<Utilizator> getAllUtilizatoriService();
	void showAllUtilizatoriService();
};