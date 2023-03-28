#include "Interfata.h"
#include <cstring>
#include <sstream>
#include <string.h>

Interfata::Interfata()
{
}

Interfata::Interfata(UtilizatorService& us, PrietenieService& ps, MesajService& ms, EvenimentService& es)
{
	this->utilizatorService = us;
	this->prietenieService = ps;
	this->mesajService = ms;
	this->evenimentService = es;
}

Interfata::~Interfata()
{
}

void Interfata::optiuniMeniu()
{
	cout << "1. Meniu utilizator" << endl;
	cout << "2. Meniu prietenie" << endl;
	cout << "3. Meniu mesaj" << endl;
	cout << "4. Meniu eveniment" << endl;
	cout << "x. Iesire aplicatie" << endl;
	cout << "Dati optiune: " << endl;
}

void Interfata::optiuniMeniuUtilizator()
{
	cout << "1. Adaugati un utilizator" << endl;
	cout << "2. Modificati un utilizator existent" << endl;
	cout << "3. Stergeti un utilizator existent" << endl;
	cout << "4. Afisati toti utilizatorii" << endl;
	cout << "5. Intoarceti-va la meniul principal" << endl;
	cout << "x. Iesire aplicatie" << endl;
	cout << "Dati optiune: " << endl;
}

void Interfata::meniu()
{
	optiuniMeniu();
	char optiune;
	cin >> optiune;
	while (optiune) {
		if (optiune == '1') this->meniuUtilizator();
		else if (optiune == '2') this->meniuPrietenie();
		else if (optiune == '3') this->meniuMesaj();
		else if (optiune == '4') this->meniuEveniment();
		else if (optiune == 'x') break;
		else cout << "Optiune gresita!" << endl;
		optiuniMeniu();
		cout << "Dati optiune: ";
		cin >> optiune;
		cout << endl;
	}
}

void Interfata::meniuUtilizator()
{
	optiuniMeniuUtilizator();
	char optiune;
	cin >> optiune; 
	cout << endl;
	while (optiune) {
		if (optiune == '1') this->adaugareUtilizatorInterfata();
		else if (optiune == '2') this->modificareUtilizatorInterfata();
		else if (optiune == '3') this->stergereUtilizatorInterfata();
		else if (optiune == '4') this->utilizatorService.showAllUtilizatoriService();
		else if (optiune == '5') meniu();
		else if (optiune == 'x') break;
		else cout << "Optiune gresita!" << endl;
		if (optiune != '5') this->meniuUtilizator();
	}
}

void Interfata::adaugareUtilizatorInterfata()
{
	char* id = new char[10];
	char* nume = new char[20];
	cout << "Dati id-ul utilizatorului: ";
	cin >> id; cout << endl;
	cout << "Dati numele utilizatorului: ";
	cin >> nume; cout << endl;
	this->utilizatorService.adaugareUtilizatorService(id, nume);
}

void Interfata::modificareUtilizatorInterfata()
{
	int pozitie;
	char* idNou = new char[10];
	char* numeNou = new char[20];
	cout << "Dati pozitia utilizatorului pe care doriti sa il modificati: ";
	cin >> pozitie;
	cout << endl;
	cout << "Dati id-ul cel nou al utilizatorului: ";
	cin >> idNou; 
	cout << endl;
	cout << "Dati noul nume al utilizatorului: ";
	cin >> numeNou;
	cout << endl;
	this->utilizatorService.modificareUtilizatorService(pozitie, idNou, numeNou);
}

void Interfata::stergereUtilizatorInterfata()
{
	int pozitie;
	cout << "Dati pozitia utilizatorului pe care doriti sa il stergeti: ";
	cin >> pozitie;
	cout << endl;
	this->utilizatorService.stergereUtilizatorService(pozitie);
}

void Interfata::optiuniMeniuPrietenie()
{
	cout << "1. Adaugati o prietenie" << endl;
	cout << "2. Stergeti o prietenie existenta" << endl;
	cout << "3. Afisati toate prieteniile" << endl;
	cout << "4. Intoarceti-va la meniul principal" << endl;
	cout << "x. Iesire aplicatie" << endl;
	cout << "Dati optiune: " << endl;
}

void Interfata::meniuPrietenie()
{
	optiuniMeniuPrietenie();
	char optiune;
	cin >> optiune;
	cout << endl;
	while (optiune) {
		if (optiune == '1') this->adaugarePrietenieInterfata();
		else if (optiune == '2') this->stergerePrietenieInterfata();
		else if (optiune == '3') this->prietenieService.showAllPrieteniiService();
		else if (optiune == '4') meniu();
		else if (optiune == 'x') break;
		else cout << "Optiune gresita!" << endl;

		if (optiune != '5') this->meniuPrietenie();
	}
}

void Interfata::adaugarePrietenieInterfata()
{
	cout << "Dati id-ul primului utilizator: ";
	char id1[10]; cin >> id1; cout << endl;
	cout << "Dati id-ul celuilalt utilizator cu care doriti sa se lege o prietenie: ";
	char id2[10]; cin >> id2; cout << endl;
	this->prietenieService.adaugarePrietenieService(id1, id2);
}


void Interfata::stergerePrietenieInterfata()
{
	int pozitie;
	cout << "Dati pozitia de pe care doriti sa stergeti o prietenie: ";
	cin >> pozitie; cout << endl;
	this->prietenieService.stergerePrietenieService(pozitie);
}

void Interfata::optiuniMeniuMesaj()
{
	cout << "1. Trimiteti un mesaj" << endl;
	cout << "2. Stergeti un mesaj existent" << endl;
	cout << "3. Afisati toate mesajele" << endl;
	cout << "4. Intoarceti-va la meniul principal" << endl;
	cout << "x. Iesire aplicatie" << endl;
	cout << "Dati optiune: " << endl;
}

void Interfata::meniuMesaj()
{
	optiuniMeniuMesaj();
	char optiune;
	cin >> optiune;
	cout << endl;
	while (optiune) {
		if (optiune == '1') this->adaugareMesajInterfata();
		else if (optiune == '2') this->stergereMesajInterfata();
		else if (optiune == '3') this->mesajService.showAllMesajeService();
		else if (optiune == '4') meniu();
		else if (optiune == 'x') break;
		else cout << "Optiune gresita!" << endl;

		if (optiune != '4') this->meniuMesaj();
	}
}

void Interfata::adaugareMesajInterfata()
{
	cout << "Introduceti mesajul pe care doriti sa il trimiteti: ";
	char text[100]; cin >> text; cout << endl;
	cout << "Dati id-ul expeditorului: ";
	char idExp[10]; cin >> idExp; cout << endl;
	cout << "Dati id-ul destinatarului: ";
	char idDest[10]; cin >> idDest; cout << endl;
	Mesaj m(text, idExp, idDest);
	this->mesajService.adaugareMesajService(m);
}


void Interfata::stergereMesajInterfata()
{
	int pozitie;
	cout << "Dati pozitia mesajului pe care doriti sa il stergeti: ";
	cin >> pozitie; cout << endl;
	this->mesajService.stergereMesajService(pozitie);
}

void Interfata::optiuniMeniuEveniment()
{
	cout << "1. Adaugati un eveniment" << endl;
	cout << "2. Stergeti un eveniment existent" << endl;
	cout << "3. Afisati toate evenimentele" << endl;
	cout << "4. Intoarceti-va la meniul principal" << endl;
	cout << "x. Iesire aplicatie" << endl;
	cout << "Dati optiune: " << endl;
}

void Interfata::meniuEveniment()
{
	optiuniMeniuEveniment();
	char optiune;
	cin >> optiune;
	cout << endl;
	while (optiune) {
		if (optiune == '1') this->adaugareEvenimentInterfata();
		else if (optiune == '2') this->stergereEvenimentInterfata();
		else if (optiune == '3') this->evenimentService.showAllEvenimenteService();
		else if (optiune == '4') meniu();
		else if (optiune == 'x') break;
		else cout << "Optiune gresita!" << endl;

		if (optiune != '4') this->meniuEveniment();
	}
}

void Interfata::adaugareEvenimentInterfata()
{
	char* locatie = new char[20];
	char* denumire = new char[20];
	char* data = new char[20];
	char* organizator = new char[20];
	int capacitate = 0;
	char* categorie = new char[20];
	cout << "Dati locatia evenimentului: ";
	cin >> locatie; cout << endl;
	cout << "Dati denumirea evenimentului: ";
	cin >> denumire; cout << endl;
	cout << "Dati data evenimentului: ";
	cin >> data; cout << endl;
	cout << "Dati organizatorul evenimentului: ";
	cin >> organizator; cout << endl;
	cout << "Dati capacitatea evenimentului: ";
	cin >> capacitate; cout << endl;
	cout << "Dati categoria evenimentului: ";
	cin >> categorie; cout << endl;
	this->evenimentService.adaugareEvenimentService(locatie, denumire, data, organizator, capacitate, categorie);
}

void Interfata::stergereEvenimentInterfata()
{
	int pozitie;
	cout << "Dati pozitia evenimentului pe care doriti sa il stergeti: ";
	cin >> pozitie; cout << endl;
	this->evenimentService.stergereEvenimentService(pozitie);
}

void Interfata::adaugare15Utilizatori()
{
	this->utilizatorService.adaugareUtilizatorService("1", "Nicoleta");
	this->utilizatorService.adaugareUtilizatorService("2", "Maria");
	this->utilizatorService.adaugareUtilizatorService("3", "Ana");
	this->utilizatorService.adaugareUtilizatorService("4", "George");
	this->utilizatorService.adaugareUtilizatorService("5", "Gabi");
	this->utilizatorService.adaugareUtilizatorService("6", "Vio");
	this->utilizatorService.adaugareUtilizatorService("7", "Teodora");
	this->utilizatorService.adaugareUtilizatorService("8", "Andreea");
	this->utilizatorService.adaugareUtilizatorService("9", "Ciprian");
	this->utilizatorService.adaugareUtilizatorService("10", "Valentin");
	this->utilizatorService.adaugareUtilizatorService("11", "Adrian");
	this->utilizatorService.adaugareUtilizatorService("12", "Madalina");
	this->utilizatorService.adaugareUtilizatorService("13", "Delia");
	this->utilizatorService.adaugareUtilizatorService("14", "Matei");
	this->utilizatorService.adaugareUtilizatorService("15", "Cristian");

}

void Interfata::adaugare15Prietenii()
{
	this->prietenieService.adaugarePrietenieService("1", "2");
	this->prietenieService.adaugarePrietenieService("4", "8");
	this->prietenieService.adaugarePrietenieService("3", "10");
	this->prietenieService.adaugarePrietenieService("5", "1");
	this->prietenieService.adaugarePrietenieService("8", "3");
	this->prietenieService.adaugarePrietenieService("6", "7");
	this->prietenieService.adaugarePrietenieService("11", "1");
	this->prietenieService.adaugarePrietenieService("13", "15");
	this->prietenieService.adaugarePrietenieService("15", "14");
	this->prietenieService.adaugarePrietenieService("6", "4");
	this->prietenieService.adaugarePrietenieService("2", "7");
	this->prietenieService.adaugarePrietenieService("10", "12");
	this->prietenieService.adaugarePrietenieService("11", "13");
	this->prietenieService.adaugarePrietenieService("15", "7");
	this->prietenieService.adaugarePrietenieService("4", "12");
}

void Interfata::adaugare15Mesaje() {
	Mesaj m1("buna", "1", "2");
	Mesaj m2("ce faci?", "3", "10");
	Mesaj m3("bine, tu?", "10", "3");
	Mesaj m4("alo", "15", "5");
	Mesaj m5("da", "2", "7");
	Mesaj m6("clar", "2", "13");
	Mesaj m7("hello", "12", "14");
	Mesaj m8("hai afara", "1", "9");
	Mesaj m9("vin acum", "9", "1");
	Mesaj m10("cand iesim?", "11", "3");
	Mesaj m11("mai tarziu", "3", "11");
	Mesaj m12("cum esti?", "4", "7");
	Mesaj m13("ce faci azi?", "6", "3");
	Mesaj m14("m-ai sunat?", "14", "15");
	Mesaj m15("nu", "12", "11");
	this->mesajService.adaugareMesajService(m1);
	this->mesajService.adaugareMesajService(m2);
	this->mesajService.adaugareMesajService(m3);
	this->mesajService.adaugareMesajService(m4);
	this->mesajService.adaugareMesajService(m5);
	this->mesajService.adaugareMesajService(m6);
	this->mesajService.adaugareMesajService(m7);
	this->mesajService.adaugareMesajService(m8);
	this->mesajService.adaugareMesajService(m9);
	this->mesajService.adaugareMesajService(m10);
	this->mesajService.adaugareMesajService(m11);
	this->mesajService.adaugareMesajService(m12);
	this->mesajService.adaugareMesajService(m13);
	this->mesajService.adaugareMesajService(m14);
}

void Interfata::adaugare6Evenimente()
{
	this->evenimentService.adaugareEvenimentService("Constanta", "Neversea", "07.07.2022", "Neversea STAFF", 10000, "festival");
	this->evenimentService.adaugareEvenimentService("Constanta", "Nunta A&B", "10.06.2027", "A&B", 300, "nunta");
	this->evenimentService.adaugareEvenimentService("Cluj", "EC", "13.07.2022", "EC STAFF", 10000, "festival");
	this->evenimentService.adaugareEvenimentService("Cluj", "Food-Street", "15.05.2022", "Primarie", 170, "festival");
	this->evenimentService.adaugareEvenimentService("Bucuresti", "ONM", "14.03.2025", "MEN", 100, "olimpiada");
	this->evenimentService.adaugareEvenimentService("Tulcea", "Tulcea-Fest", "10.08.2022", "Primarie", 10000, "festival");

}

