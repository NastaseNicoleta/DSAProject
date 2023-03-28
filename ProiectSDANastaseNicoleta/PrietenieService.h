#pragma once
#include "PrietenieRepository.h"

class PrietenieService {
private:
	PrietenieRepository prietenieRepository;
public:
	PrietenieService();
	PrietenieService(PrietenieRepository&);
	~PrietenieService();

	void adaugarePrietenieService(const char*, const char*);
	void stergerePrietenieService(int);
	Array<Prietenie> getAllPrieteniiServie();
	void showAllPrieteniiService();
};