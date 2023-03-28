#pragma once
#include "EvenimentRepository.h"

class EvenimentService {
private:
	EvenimentRepository evenimentRepository;
public:
	EvenimentService();
	EvenimentService(EvenimentRepository&);
	~EvenimentService();
	void adaugareEvenimentService(const char*, const char*, const char*, const char*, int, const char*);
	void stergereEvenimentService(int);
	Array<Eveniment> getAllEvenimenteService();
	void showAllEvenimenteService();
};