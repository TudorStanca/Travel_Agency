#pragma once
#include "Oferta.h"
#include "Repository.h"
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>

using std::vector;
using std::ofstream;

class Cos {

	vector <Oferta> elemente;

public:

	/// <summary>
	/// Consturctorul default pentru cos
	/// </summary>
	Cos() = default;

	/// <summary>
	/// Getter pentru elementele din cos
	/// </summary>
	/// <returns> Vectorul care contine elementele din cos </returns>
	const vector<Oferta>& get_cos() const;

	/// <summary>
	/// Sterge toate elementele din cos
	/// </summary>
	void goleste_cos();

	/// <summary>
	/// Adauga o oferta in cos
	/// </summary>
	/// <param name="oferta"> Oferta care va fi adaugata </param>
	void adauga_in_cos(const Oferta& oferta);

	/// <summary>
	/// Genereaza random un numar de oferte in cos
	/// Numarul de oferte generate poate sa difere fata de cel dorit de utilizator
	/// </summary>
	/// <param name="oferte"> Vectorul din care se extrag ofertele random </param>
	/// <param name="n"> Numarul de oferte care vor fi generate random </param>
	/// <returns> Numarul de oferte generate </returns>
	int genereaza_cos(vector<Oferta> oferte, const int& n);

	/// <summary>
	/// Exporta ofertele din cos intr-ul fisier csv
	/// Daca nu exista fisierul, va fi creat
	/// </summary>
	/// <param name="filename"> Numele fisierului in care se face exportul </param>
	void export_to_csv(string filename) const;

};