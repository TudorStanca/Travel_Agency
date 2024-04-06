#pragma once
#include "Service.h"
#include "iostream"

using std::cin;
using std::cout;

class Ui {

	Service service;

	/// <summary>
	/// Afiseaza meniul aplicatiei
	/// </summary>
	void print_menu() const;

	/// <summary>
	/// Afiseaza meniul filtrarii
	/// </summary>
	void print_menu_filtrare() const;

	/// <summary>
	/// Afiseaza meniul sortarii
	/// </summary>
	void print_menu_sortare() const;

	/// <summary>
	/// Afiseaza o oferta pe ecran
	/// </summary>
	/// <param name="oferta"> Oferta care este afisata </param>
	void afisare_oferta(const Oferta& oferta) const;

	/// <summary>
	/// Afiseaza un vector de oferte pe ecran
	/// </summary>
	/// <param name="v"> Vectorul de oferte afisat </param>
	void afisare_vector_oferte(const VectorDinamic <Oferta>& v) const;

	/// <summary>
	/// Functia de ui pentru adaugare
	/// </summary>
	void adaugare_ui();

	/// <summary>
	/// Functia de ui pentru stergere
	/// </summary>
	void stergere_ui();

	/// <summary>
	/// Functia de ui pentru modificare
	/// </summary>
	void modificare_ui();

	/// <summary>
	/// Functia de ui pentru cautare
	/// </summary>
	void cautare_ui() const;

	/// <summary>
	/// Functia de ui pentru filtrare
	/// </summary>
	void filtrare_ui() const;

	/// <summary>
	/// Functia de ui pentru sortare
	/// </summary>
	void sortare_ui() const;

	/// <summary>
	/// Functia de ui pentru adaugare_oferte_demo
	/// </summary>
	/// <param name="oferte_demo_adaugate"> Verificare daca au fost sau nu adaugate deja ofertele </param>
	void adaugare_oferte_demo_ui(const bool& oferte_demo_adaugate);

	/// <summary>
	/// Afisarea repository-ului in consola
	/// </summary>
	void afisare_ui() const;

public:

	/// <summary>
	/// Constructor pentru ui
	/// </summary>
	Ui() = default;
	Ui(const Ui& ui) = delete; //nu se poate copia

	/// <summary>
	/// Functia care ruleaza aplicatia
	/// </summary>
	void run();


};

