#pragma once
#include "MesajRepository.h"

class MesajService {
private:
	MesajRepository mesajRepository;
public:
	MesajService();
	MesajService(MesajRepository&);
	~MesajService();
	void adaugareMesajService(Mesaj&);
	void stergereMesajService(int);
	Array<Mesaj> getAllMesajeService();
	void showAllMesajeService();
};