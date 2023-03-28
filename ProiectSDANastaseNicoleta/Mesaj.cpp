#include "Mesaj.h"

Mesaj::Mesaj()
{
	this->text = nullptr;
	this->idExpeditor = nullptr;
	this->idDestinatar = nullptr;
}

Mesaj::Mesaj(const char* text, const char* idExpeditor, const char* idDestinatar)
{
	this->text = new char[strlen(text) + 1];
	strcpy_s(this->text, strlen(text) + 1, text);
	this->idExpeditor = new char[strlen(idExpeditor) + 1];
	strcpy_s(this->idExpeditor, strlen(idExpeditor) + 1, idExpeditor);
	this->idDestinatar = new char[strlen(idDestinatar) + 1];
	strcpy_s(this->idDestinatar, strlen(idDestinatar) + 1, idDestinatar);

}

Mesaj::Mesaj(Mesaj& m)
{
	this->text = new char[strlen(m.text) + 1];
	strcpy_s(this->text, strlen(m.text) + 1, m.text);
	this->idExpeditor = new char[strlen(m.idExpeditor) + 1];
	strcpy_s(this->idExpeditor, strlen(m.idExpeditor) + 1, m.idExpeditor);
	this->idDestinatar = new char[strlen(m.idDestinatar) + 1];
	strcpy_s(this->idDestinatar, strlen(m.idDestinatar) + 1, m.idDestinatar);
}

Mesaj::~Mesaj()
{
	if (this->text or this->idExpeditor or this->idExpeditor) {
		delete[] this->text;
		this->text = nullptr;
		delete[] this->idExpeditor;
		this->idExpeditor = nullptr;
		delete[] this->idDestinatar;
		this->idDestinatar = nullptr;
	}
}

char* Mesaj::getText()
{
	return this->text;
}

char* Mesaj::getIdExpeditor()
{
	return this->idExpeditor;
}

char* Mesaj::getIdDestinatar()
{
	return this->idDestinatar;
}

void Mesaj::setText(const char* text)
{
	if (this->text) delete[] this->text;
	if (text == nullptr) this->text = nullptr;
	else {
		this->text = new char[strlen(text) + 1];
		strcpy_s(this->text, strlen(text) + 1, text);
	}
}

void Mesaj::setIdExpeditor(const char* idExpeditor)
{
	if (this->idExpeditor) delete[] this->idExpeditor;
	if (idExpeditor == nullptr) this->idExpeditor = nullptr;
	else {
		this->idExpeditor = new char[strlen(idExpeditor) + 1];
		strcpy_s(this->idExpeditor, strlen(idExpeditor) + 1, idExpeditor);
	}
}

void Mesaj::setIdDestinatar(const char* idDestinatar)
{
	if (this->idDestinatar) delete[] this->idDestinatar;
	if (idDestinatar == nullptr) this->idDestinatar = nullptr;
	else {
		this->idDestinatar = new char[strlen(idDestinatar) + 1];
		strcpy_s(this->idDestinatar, strlen(idDestinatar) + 1, idDestinatar);
	}
}

Mesaj& Mesaj::operator=(const Mesaj& m)
{
	if (this != &m) {
		this->text = new char[strlen(m.text) + 1];
		strcpy_s(this->text, strlen(m.text) + 1, m.text);
		this->idExpeditor = new char[strlen(m.idExpeditor) + 1];
		strcpy_s(this->idExpeditor, strlen(m.idExpeditor) + 1, m.idExpeditor);
		this->idDestinatar = new char[strlen(m.idDestinatar) + 1];
		strcpy_s(this->idDestinatar, strlen(m.idDestinatar) + 1, m.idDestinatar);
	}
	return *this;
}

bool Mesaj::operator==(const Mesaj& m)
{
	return (strcmp(this->text, m.text) == 0 && strcmp(this->idExpeditor, m.idExpeditor) == 0 && strcmp(this->idDestinatar, m.idDestinatar) == 0);
}

ostream& operator<<(ostream& os, Mesaj& m)
{
	os << "Textul mesajului: " << m.text << endl << "Id expeditor: " << m.idExpeditor << endl<< "Id destinatar: "<<m.idDestinatar<<endl;
	return os;
}

istream& operator>>(istream& is, Mesaj& m)
{
	cout << "Dati textul mesajului: " << endl;
	is >> m.text;
	cout << "Dati id expeditor: " << endl;
	is >> m.idExpeditor;
	cout << "Dati id destinatar: " << endl;
	is >> m.idDestinatar;
	cout << m.text << " " << m.idExpeditor<<" "<< m.idDestinatar << endl;
	return is;
}
