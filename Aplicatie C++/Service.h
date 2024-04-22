#pragma once
#include "Repository.h"
#include "Cos.h"
#include "ActiuneUndo.h"
#include <iterator>
#include <map>

using std::copy_if;
using std::map;
using std::back_inserter;

class Service {

	Repository& repository;
	Cos cos;
	vector <ActiuneUndo*> vector_undo;

public:

	/// <summary>
	/// Constructor default pentru service
	/// </summary>
	Service(Repository& repository, const Cos& cos);

	~Service();

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
	vector <Oferta> get_copie_elemente() const;

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
	int cauta_oferta_service(const string& denumire) const;

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

	void undo_service();

	/// <summary>
	/// Creeaza un raport dupa tipurile din service
	/// </summary>
	/// <returns> Un map unde se afla raportul </returns>
	map <string, DTO> raport_tip_service() const;

	/// <summary>
	/// Getter pentru elementele din cos
	/// </summary>
	/// <returns> Vector cu elementele din cos </returns>
	const vector <Oferta>& get_cos_service() const;

	/// <summary>
	/// Sterge ofertele din cos
	/// </summary>
	void goleste_cos_service();

	/// <summary>
	/// Adauga o oferta in cos dupa denumirea ei
	/// </summary>
	/// <param name="denumire"> Denumirea ofertei care va fi adaugata </param>
	void adaugare_oferta_in_cos_service(const string& denumire);

	/// <summary>
	/// Genereaza un nr de oferte in cos
	/// </summary>
	/// <param name="nr_oferte"> Numarul de oferte generate in cos </param>
	/// <returns> Numarul de oferte generate cu succes </returns>
	int generare_oferte_cos_service(const int& nr_oferte);

	/// <summary>
	/// Exporta intr-un fisier csv ofertele din cos
	/// </summary>
	/// <param name="filename"> Numele fisierului in care se face exportul </param>
	void export_to_csv_service(const string& filename) const;
};