#pragma once
#include <exception>

using std::exception;

//template <typename TElement>
//class IteratorVector;

template <typename TElement>
class VectorDinamic {

	TElement* elemente;
	int capacitate;
	int lungime;

	/// <summary>
	/// Redimensioneaza vectorul la adaugare unui elemenet
	///		pre:
	///			- lungimea == capacitatea
	///		post:
	///			- vectorul a fost redimensionat
	/// </summary>
	void redimensionare();

	/// <summary>
	/// Redimensioneaza vectorul la stergerea unui element
	///		pre:
	///			- lungimea <= capacitatea / 2
	///		post:
	///			- vectorul a fost redimensionat
	/// </summary>
	void redimensionare_in_jos();

public:
	
	/// <summary>
	/// Constructor pentru vectorul dinamic
	///		post:
	///			- s-a creat obiectul		
	/// </summary>
	VectorDinamic();

	/// <summary>
	/// Constructor pentru vectorul dinamic unde e pasata capacitatea
	///		pre:
	///			- capacitatea > 0
	///		post:
	///			- s-a creat obiectul
	/// </summary>
	/// <param name="capacitate_initiala"> Capacitatea initiala a vectorului </param>
	/// <exception cref="Capacitatea este < 0"></exception>
	VectorDinamic(const int& capacitate_initiala);

	/// <summary>
	/// Destructor pentru vector
	/// </summary>
	~VectorDinamic();

	/// <summary>
	/// Constructor de copiere pentru vector
	/// </summary>
	/// <param name="other"> Obiectul care este copiat </param>
	VectorDinamic(const VectorDinamic <TElement>& other);

	/// <summary>
	/// Operator de asignare intre 2 vectori
	/// </summary>
	/// <param name="other"> Obietul care va fi asignat </param>
	/// <returns> Copie a obiectului asignat </returns>
	VectorDinamic <TElement>& operator=(const VectorDinamic <TElement>& other);

	/// <summary>
	/// Getter pentru un element de pe o pozitie din vector
	///		pre:
	///			- index apartine [0, lungime-1]
	///		post:
	///			- vectorul nu este modificat
	/// </summary>
	/// <param name="pozitie"> Indexul elementului care va fi returnat </param>
	/// <returns> Elementul din lista </returns>
	/// <exception cref="Pozitia iese din vector"></exception>
	const TElement& at(const int& pozitie) const;

	/// <summary>
	/// Getter pentru un element de pe o pozitie din vector
	///		pre:
	///			- index apartine [0, lungime-1]
	///		post:
	///			- vectorul poate sa fie modificat
	/// </summary>
	/// <param name="pozitie"> Indexul elementului care va fi returnat </param>
	/// <returns> Elementul din lista </returns>
	/// <exception cref="Pozitia iese din vector"></exception>
	TElement& operator[](const int& pozitie);

	/// <summary>
	/// Getter pentru lungime
	/// </summary>
	/// <returns> Lungimea vectorului </returns>
	const int& size() const noexcept;

	/// <summary>
	/// Getter pentru capacitate
	/// </summary>
	/// <returns> Capacitatea vectorului </returns>
	const int& max_size() const noexcept;

	/// <summary>
	/// Verificare daca vectorul e gol sau nu
	/// </summary>
	/// <returns> 1 daca e gol, 0 altfel </returns>
	bool empty() const noexcept;

	/// <summary>
	/// Adauga un element la finalul vectorului (poate sa modifice capacitatea vectorului daca vectorul e plin)
	/// </summary>
	/// <param name="element"> Elementul care este adaugat </param>
	void push_back(const TElement& element);

	/// <summary>
	/// Sterge un element de pe o pozitie (poate sa modifice capacitatea vectorului daca vectorul e pe jumatate plin)
	/// </summary>
	/// <param name="pozitie"> Pozitia elementului care va fi sters </param>
	/// <exception cref="Pozitia iese din vector"></exception>
	void erase(const int& pozitie);

	//friend class IteratorVector <TElement>;

	//IteratorVector <TElement> begin();

	//IteratorVector <TElement> end();

};

//template <typename TElement>
//class IteratorVector {
//
//	const VectorDinamic <TElement>& v;
//	int pozitie = 0;
//
//public:
//
//	IteratorVector(const VectorDinamic <TElement>& v);
//	IteratorVector(Const VectorDinamic <TElement>& v, int pozitie);
//
//	bool valid();
//
//	TElement element();
//
//	void next();
//
//	TElement operator*();
//
//	void operator++();
//
//	bool operator==(const IteratorVector& other);
//
//	bool operator!=(const IteratorVector& other);
//};

template<typename TElement>
void VectorDinamic<TElement>::redimensionare() {
	TElement* temp = new TElement[capacitate * 2];
	for (int i = 0; i < lungime; i++) {
		temp[i] = elemente[i];
	}
	delete[] elemente;
	elemente = temp;
	capacitate = capacitate * 2;
}

template<typename TElement>
void VectorDinamic<TElement>::redimensionare_in_jos() {
	TElement* temp = new TElement[capacitate / 2];
	for (int i = 0; i < lungime; i++) {
		temp[i] = elemente[i];
	}
	delete[] elemente;
	elemente = temp;
	capacitate = capacitate / 2;
}

//constructor
template<typename TElement>
VectorDinamic<TElement>::VectorDinamic() : elemente{ new TElement[5] }, capacitate{ 5 }, lungime{ 0 } {}

template<typename TElement>
VectorDinamic<TElement>::VectorDinamic(const int& capacitate_initiala) : elemente{ new TElement[capacitate_initiala] }, capacitate{ capacitate_initiala }, lungime{ 0 } {
	if (capacitate <= 0) {
		throw std::exception{ "Capacitatea vectorului nu poate sa fie 0!" };
	}
}

//destructor
template<typename TElement>
VectorDinamic<TElement>::~VectorDinamic() {
	delete[] elemente;
}

///constructor copiere
template<typename TElement>
VectorDinamic<TElement>::VectorDinamic(const VectorDinamic <TElement>& other) {
	elemente = new TElement[other.max_size()];
	for (int i = 0; i < other.size(); i++) {
		elemente[i] = other.at(i);
	}
	capacitate = other.max_size();
	lungime = other.size();
}

//assigment operator
template<typename TElement>
VectorDinamic<TElement>& VectorDinamic<TElement>::operator=(const VectorDinamic <TElement>& other) {
	if (this == &other) {
		return *this;
	}
	delete[] elemente;
	elemente = new TElement[other.max_size()];
	for (int i = 0; i < other.size(); i++) {
		elemente[i] = other.at(i);
	}
	capacitate = other.max_size();
	lungime = other.size();
	return *this;
}

template<typename TElement>
const TElement& VectorDinamic<TElement>::at(const int& pozitie) const {
	if (pozitie < 0 || pozitie >= lungime) {
		throw exception{ "Outside of vector bounds!" };
	}
	return elemente[pozitie];
}

template<typename TElement>
TElement& VectorDinamic<TElement>::operator[](const int& pozitie) {
	if (pozitie < 0 || pozitie >= lungime) {
		throw exception{ "Outside of vector bounds!" };
	}
	return elemente[pozitie];
}

template<typename TElement>
const int& VectorDinamic<TElement>::size() const noexcept {
	return lungime;
}

template<typename TElement>
const int& VectorDinamic<TElement>::max_size() const noexcept {
	return capacitate;
}

template<typename TElement>
bool VectorDinamic<TElement>::empty() const noexcept {
	return !(lungime);
}

template<typename TElement>
void VectorDinamic<TElement>::push_back(const TElement& element) {
	if (lungime == capacitate) {
		redimensionare();
	}
	elemente[lungime] = element;
	lungime++;
}

template<typename TElement>
void VectorDinamic<TElement>::erase(const int& pozitie) {
	if (pozitie < 0 || pozitie >= lungime) {
		throw exception{ "Outside of vector bounds!" };
	}
	for (int i = pozitie; i < lungime - 1; i++) {
		elemente[i] = elemente[i + 1];
	}
	lungime--;
	if (lungime <= capacitate / 2 && capacitate != 1) {
		redimensionare_in_jos();
	}
}
