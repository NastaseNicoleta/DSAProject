#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

template <class T>
class Array {
private: 
	T* elem;
	int nr;
	int cap;
	void resize();
public:
	Array();
	~Array();

	void adaugareElem(T);
	void modificareElem(int, T);
	void stergereElem(int);
	T* getAll();
	int size();
	T& operator[](int i);
	T& operator=(T&);
};

//Constuctor implicit: aloca spatiu si initializeaza elementele
template<class T>
inline Array<T>::Array() {
	this->elem = new T[10];
	this->nr = 0;
	this->cap = 0;
}

//Destructor: elibereaza spatiul ocupat de elemente
template<class T>
inline Array<T>::~Array(){}

//Resize: cresterea capacitatii array-ului in cazul in care cea maxima a fost atinsa
template<class T>
inline void Array<T>::resize() {
	T* aux = new T[this->cap];
	for (int i = 0; i < this->cap; i++)
		aux[i] = elem[i];
	delete[] elem;
	elem = nullptr;
	int capNoua = this->cap + 10;
	this->elem = new T[capNoua];
	for (int i = 0; i < this->cap; i++) elem[i] = aux[i];
	delete[] aux;
	aux = nullptr;
	this->cap = this->cap + 10;
}

//Adaugarea unui element in array
template<class T>
inline void Array<T>::adaugareElem(T elem){
	if (this->cap == this->nr) resize();
	this->elem[this->nr] = elem;
	this->nr++;
}

//Modificarea unui element din array
template<class T>
inline void Array<T>::modificareElem(int pozitie, T elemNou) {
	this->elem[pozitie] = elemNou;
}

//Stergerea unui element din array
template<class T>
inline void Array<T>::stergereElem(int pozitie) {
	int i;
	T* elems = new T[nr];
	for (i = 0; i < pozitie; i++)
		elems[i] = elem[i];
	for (int j = pozitie; j < nr; j++)
		elems[i++] = elem[j];
	delete[] elem;
	nr--;
	elem = new T[nr];
	for (i = 0; i < nr; i++)
		elem[i] = elems[i];
	delete[] elems;
}

//GetAll: returneaza toate elementele array-ului
template<class T>
inline T* Array<T>::getAll() {
	return this->elem;
}

//Size: returneaza marimea array-ului
template<class T>
inline int Array<T>::size() {
	return this->nr;
}

//Implementarea operatorului [] pentru a lucra mai usor iterativ
template<class T>
inline T& Array<T>::operator[](int i) {
	return elem[i];
}

//Implementarea operatorului = pentru assign-are
template<class T>
inline T& Array<T>::operator=(T& elems) {
	if (this != &elems) {
		if (nr > size(elems))
			nr = size(elems);
		for (int i = 0; i < nr; i++)
			this->elem[i] = elems[i];
			return *this;
	}
}

