#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

class Oferta {

	string denumire;
	string destinatie;
	string tip;
	int pret;

public:

	/// <summary>
	/// Constructor pentru oferta
	/// </summary>
	/// <param name="denumire"> Denumirea ofertei </param>
	/// <param name="destinatie"> Destinatia ofertei </param>
	/// <param name="tip"> Tipul ofertei </param>
	/// <param name="pret"> Pretul ofertei </param>
	Oferta(const string& denumire, const string& destinatie, const string& tip, const int& pret);
	//Oferta(const Oferta& oferta);

	/// <summary>
	/// Getter pentru denumire
	/// </summary>
	/// <returns> Denumirea ofertei </returns>
	const string& get_denumire() const noexcept;

	/// <summary>
	/// Getter pentru destinatie
	/// </summary>
	/// <returns> Destinatia ofertei </returns>
	const string& get_destinatie() const noexcept;

	/// <summary>
	/// Getter pentru tip
	/// </summary>
	/// <returns> tipul ofertei </returns>
	const string& get_tip() const noexcept;

	/// <summary>
	/// Getter pentru pret
	/// </summary>
	/// <returns> Pretul ofertei </returns>
	const int& get_pret() const noexcept;

	/// <summary>
	/// Setter pentru denumire
	/// </summary>
	/// <param name="new_denumire"> Noua denumire </param>
	void set_denumire(const string& new_denumire);

	/// <summary>
	/// Setter pentru destinatie
	/// </summary>
	/// <param name="new_destinatie"> Noua destinatie </param>
	void set_destinatie(const string& new_destinatie);

	/// <summary>
	/// Setter pentru tip
	/// </summary>
	/// <param name="new_tip"> Noul tip </param>
	void set_tip(const string& new_tip);

	/// <summary>
	/// Setter pentru pret
	/// </summary>
	/// <param name="new_pret"> Noul pret </param>
	void set_pret(const int& new_pret) noexcept;

	/// <summary>
	/// Definirea operatiei == intre doua oferte ( egalitate intre fiecare atribut )
	/// </summary>
	/// <param name="other"> Elementul cu care este comparat </param>
	/// <returns> 1 - egalitate, 0 altfel </returns>
	bool operator==(const Oferta& other) const noexcept;
};

