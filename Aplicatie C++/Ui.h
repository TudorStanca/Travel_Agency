#pragma once
#include "Service.h"
#include <sstream>

using std::stringstream;
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
	/// Afiseaza un vector de oferte pe ecran
	/// </summary>
	/// <param name="v"> Vectorul de oferte afisat </param>
	void afisare_vector_oferte(const vector <Oferta>& v) const;

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
	/// Functia de ui pentru raport_tip_ui
	/// </summary>
	void raport_tip_ui() const;

	/// <summary>
	/// Functia de ui pentru adaugare_oferte_demo
	/// </summary>
	/// <param name="oferte_demo_adaugate"> Verificare daca au fost sau nu adaugate deja ofertele </param>
	void adaugare_oferte_demo_ui(const bool& oferte_demo_adaugate);

	/// <summary>
	/// Afisarea repository-ului in consola
	/// </summary>
	void afisare_ui() const;

	/// <summary>
	/// Functia de ui pentru afisare_cos_ui
	/// </summary>
	void afisare_cos_ui() const;

	/// <summary>
	/// Functia de ui pentru goleste_cos_ui
	/// </summary>
	void goleste_cos_ui();

	/// <summary>
	/// Functia de ui pentru adauga_oferta_cos_ui
	/// </summary>
	void adauga_oferta_cos_ui();

	/// <summary>
	/// Functia de ui pentru genereaza_oferte_cos_ui
	/// </summary>
	void genereaza_oferte_cos_ui();

	/// <summary>
	/// Functia de ui pentru export_oferte_ui
	/// </summary>
	void export_oferte_ui() const;

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
