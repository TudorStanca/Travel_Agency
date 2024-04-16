#pragma once
#include "Oferta.h"
#include "VectorDinamic.h"
#include <vector>
#include <algorithm>

using std::vector;

class Repository {

	vector <Oferta> elemente;

public:

	/// <summary>
	/// Constructorul default pentru repository
	/// </summary>
	Repository() = default;
	Repository(const Repository& repo) = delete; // repository nu poate fi copiat

	/// <summary>
	/// Getter pentru vectorul de oferte
	/// </summary>
	/// <returns> Vectorul de oferte </returns>
	const vector <Oferta>& get_elemente() const noexcept;

	/// <summary>
	/// Getter pentru un element de pe o pozitie din vectorul de oferte
	/// </summary>
	/// <param name="pozitie"> Pozitia elementului din vector </param>
	/// <returns> Elementul de pe pozitia 'pozitie' </returns>
	const Oferta& get_element_pozitie(const int& pozitie) const;

	/// <summary>
	/// Getter pentru o copie a vectorului de oferte
	/// </summary>
	/// <returns> O copie a vectorului de oferte </returns>
	vector <Oferta> get_copie_elemente() const noexcept;

	/// <summary>
	/// Adauga o oferta in repository
	/// </summary>
	/// <param name="oferta"> Oferta care va fi adaugata </param>
	void adauga_oferta(const Oferta& oferta);

	/// <summary>
	/// Sterge o ofera din repository de pe o pozitie data
	/// </summary>
	/// <param name="pozitie"> Pozitia ofertei care va fi stearsa </param>
	void sterge_oferta(const int& pozitie) noexcept;

	/// <summary>
	/// Modifica o oferta din repository cu o alta oferta noua
	/// </summary>
	/// <param name="oferta_noua"> Noua oferta care va inlocui vechea oferta </param>
	/// <param name="pozitie"> Pozitia pe care se afla vechea oferta </param>
	void modifica_oferta(const Oferta& oferta_noua, const int& pozitie);

	/// <summary>
	/// Cauta o oferta dupa denumirea ei
	/// </summary>
	/// <param name="denumire_cautare"> Denumirea dupa care se face cautarea </param>
	/// <returns> Pozitia ofertei sau -1 daca nu exista </returns>
	int cauta_element(const string& denumire_cautare) const noexcept;
};