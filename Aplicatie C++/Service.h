#pragma once
#include "Repository.h"
#include "Cos.h"
#include <iterator>

using std::copy_if;
using std::back_inserter;

class Service {

	Repository repository;
	Cos cos;

public:

	/// <summary>
	/// Constructor default pentru service
	/// </summary>
	Service() = default;
	Service(const Service& service) = delete; //nu poate fi copiat

	/// <summary>
	/// Getter pentru vectorul de oferte
	/// </summary>
	/// <returns> Vectorul de oferte </returns>
	const vector <Oferta>& get_elemente() const noexcept;

	/// <summary>
	/// Getter pentru o oferta de pe o pozitie din vector
	/// </summary>
	/// <param name="pozitie"> Pozitia ofertei </param>
	/// <returns> Oferta de pe pozitie </returns>
	const Oferta& get_element_pozitie(const int& pozitie) const;

	/// <summary>
	/// Getter pentro vectorul de elemente
	/// </summary>
	/// <returns> O copie a vectorului de elemente </returns>
	vector <Oferta> get_copie_elemente() const noexcept;

	/// <summary>
	/// Adauga o oferta in repository
	/// </summary>
	/// <param name="denumire"> Denumirea ofertei </param>
	/// <param name="destinatie"> Destinatia ofertei </param>
	/// <param name="tip"> Tipul ofertei </param>
	/// <param name="pret"> Pretul ofertei </param>
	void adauga_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret);

	/// <summary>
	/// Sterge o oferta din repository
	/// </summary>
	/// <param name="pozitie"> Pozitia ofertei care va fi stearsa </param>
	void sterge_oferta_service(const int& pozitie);

	/// <summary>
	/// Modifica o oferta de pe o pozitie
	/// </summary>
	/// <param name="denumire"> Denumirea ofertei noi </param>
	/// <param name="destinatie"> Destinatia ofertei noi </param>
	/// <param name="tip"> Tipul ofertei noi </param>
	/// <param name="pret"> Pretul ofertei noi </param>
	/// <param name="pozitie"> Pozitia ofertei care va fi modificata </param>
	void modifica_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret, const int& pozitie);

	/// <summary>
	/// Cauta o oferta dupa nume in repository
	/// </summary>
	/// <param name="denumire"> Denumirea dupa care se face cautarea </param>
	/// <returns> Pozitia elementului gasit sau -1 altfel </returns>
	int cauta_oferta_service(const string& denumire) const noexcept;

	/// <summary>
	/// Filtreaza vectorul de oferte dupa o destinatie
	/// </summary>
	/// <param name="destinatie"> Element de filtrare </param>
	/// <returns> O copie a vectorului initial, filtrat </returns>
	vector <Oferta> filtrare_oferte_service(const string& destinatie) const;

	/// <summary>
	/// Filtreaza vectorul de oferte dupa un pret
	/// </summary>
	/// <param name="pret"> Element de filtrare </param>
	/// <returns> O copie a vectorului initial, filtrat </returns>
	vector <Oferta> filtrare_oferte_service(const int& pret) const noexcept;

	/// <summary>
	/// Sorteaza vectorul dupa un criteriu (denumire, destinatie, tip + pret) crescator / descrescator
	/// </summary>
	/// <param name="v"> Vectorul care este sortat </param>
	/// <param name="varianta"> Criteriul de sortare </param>
	/// <param name="reversed"> Sortare crescatoare / descrescatoare </param>
	void sortare_oferte_service(vector <Oferta>& v, const int& varianta, const bool& reversed) const;

	const vector <Oferta>& get_cos_service() const;

	void goleste_cos_service();

	void adaugare_oferta_in_cos_service(const string& denumire);

	int generare_oferte_cos_service(const int& nr_oferte);

	void export_to_csv_service(const string& filename);
};

