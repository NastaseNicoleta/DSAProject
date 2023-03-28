#pragma once
#include <iostream>

using namespace std;

class Mesaj{
private:
	char* text;
	char* idExpeditor;
	char* idDestinatar;
public:
	Mesaj();
	Mesaj(const char*, const char*, const char*);
	Mesaj(Mesaj&);
	~Mesaj();

	char* getText();
	char* getIdExpeditor();
	char* getIdDestinatar();
	void setText(const char*);
	void setIdExpeditor(const char*);
	void setIdDestinatar(const char*);
	friend ostream& operator<<(ostream&, Mesaj&);
	friend istream& operator>>(istream&, Mesaj&);
	Mesaj& operator=(const Mesaj&);
	bool operator==(const Mesaj&);
};