#pragma once
#include <exception>

using std::exception;

template <typename TElement>
class IteratorVector;

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

	friend class IteratorVector <TElement>;

	IteratorVector <TElement> begin();

	IteratorVector <TElement> end();

	//friend ostream& operator<<(ostream& out, const VectorDinamic<TElement>& vector);

};

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
VectorDinamic<TElement>::VectorDinamic(const int& capacitate_initiala) {
	if (capacitate_initiala <= 0) {
		throw std::exception{ "Capacitatea vectorului nu poate sa fie 0!" };
	}
	elemente = new TElement[capacitate_initiala];
	capacitate = capacitate_initiala;
	lungime = 0;
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

template<typename TElement>
IteratorVector<TElement> VectorDinamic<TElement>::begin() {
	return IteratorVector<TElement>(*this);
}

template<typename TElement>
IteratorVector<TElement> VectorDinamic<TElement>::end() {
	return IteratorVector<TElement>(*this, lungime);
}

//template<typename TElement>
//ostream& operator<<(ostream& out, const VectorDinamic<TElement>& vector) {
//	for (const auto& el : vector) {
//		out << el << "\n";
//	}
//	return out;
//}


template <typename TElement>
class IteratorVector {

	const VectorDinamic <TElement>& vector;
	int pozitie;

public:

	/// <summary>
	/// Constructor pentru iteratorul de pe un vector
	/// </summary>
	/// <param name="vector"> Vectorul care se itereaza </param>
	IteratorVector(const VectorDinamic <TElement>& vector);

	/// <summary>
	/// Constructor pentru iteratorul de pe un vector
	/// </summary>
	/// <param name="vector"> Vectorul care se itereaza </param>
	/// <param name="pozitie"> Pozitia de pe care se incepe iteratia </param>
	IteratorVector(const VectorDinamic <TElement>& vector, int pozitie);

	/// <summary>
	/// Valideaza un iterator
	/// </summary>
	/// <returns> true daca e valid, false altfel </returns>
	bool valid() const;

	/// <summary>
	/// Getter pentru elementul iterat
	/// </summary>
	/// <returns> Elementul in cauza </returns>
	const TElement& element() const;

	/// <summary>
	/// Merge pe pozitia urmatoare
	/// </summary>
	void next();

	/// <summary>
	/// Versiunea de C++ la element()
	/// </summary>
	/// <returns> Elementul pe care se afla </returns>
	const TElement& operator*() const;

	/// <summary>
	/// Versiunea C++ la next()
	/// </summary>
	void operator++();

	/// <summary>
	/// Verifica daca doi iteratori sunt egali
	/// </summary>
	/// <param name="other"> Al doilea iterator </param>
	/// <returns> true daca e adevarat, false altfel </returns>
	bool operator==(const IteratorVector& other) const;

	/// <summary>
	/// Verifica daca doi iteratori sunt diferiti
	/// </summary>
	/// <param name="other"> Al doilea iterator </param>
	/// <returns> true daca e adevarat, false altfel </returns>
	bool operator!=(const IteratorVector& other) const;
};

template<typename TElement>
IteratorVector<TElement>::IteratorVector(const VectorDinamic<TElement>& vector) : vector{ vector }, pozitie{ 0 } {}

template<typename TElement>
IteratorVector<TElement>::IteratorVector(const VectorDinamic<TElement>& vector, int pozitie) : vector{ vector }, pozitie{ pozitie } {}

template<typename TElement>
bool IteratorVector<TElement>::valid() const {
	if (pozitie >= vector.size()) {
		return false;
	}
	return true;
}

template<typename TElement>
const TElement& IteratorVector<TElement>::element() const {
	return vector.at(pozitie);
}

template<typename TElement>
void IteratorVector<TElement>::next() {
	if (valid() == true) {
		pozitie++;
	}
}

template<typename TElement>
const TElement& IteratorVector<TElement>::operator*() const {
	return element();
}

template<typename TElement>
void IteratorVector<TElement>::operator++() {
	next();
}

template<typename TElement>
bool IteratorVector<TElement>::operator==(const IteratorVector& other) const {
	return pozitie == other.pozitie;
}

template<typename TElement>
bool IteratorVector<TElement>::operator!=(const IteratorVector& other) const {
	return !(*this == other);
}