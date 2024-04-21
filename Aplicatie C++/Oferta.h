#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <exception>
#include "MyException.h"

using std::exception;
using std::string;
using std::ostream;

class Oferta {

	string denumire;
	string destinatie;
	string tip;
	int pret;

	void validator() const;

public:

	/// <summary>
	/// Default constructor pentru oferta
	/// </summary>
	Oferta() = default;

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
	void set_pret(const int& new_pret);

	/// <summary>
	/// Definirea operatiei == intre doua oferte ( egalitate intre fiecare atribut )
	/// </summary>
	/// <param name="other"> Elementul cu care este comparat </param>
	/// <returns> 1 - egalitate, 0 altfel </returns>
	bool operator==(const Oferta& other) const noexcept;

	friend ostream& operator<<(ostream& out, const Oferta& oferta);
};

class DTO {
	string tip;
	int nr_tip;

public:

	/// <summary>
	/// Constructor default pentru DTO
	/// </summary>
	DTO();

	/// <summary>
	/// Constructor pentru DTO
	/// </summary>
	/// <param name="tip"> Tipul DTO-ului </param>
	DTO(const string& tip);

	/// <summary>
	/// Getter pentru tip
	/// </summary>
	/// <returns> Tipul DTO-ului </returns>
	const string& get_tip() const;

	/// <summary>
	/// Getter pentru nr_tip
	/// </summary>
	/// <returns> Numarul de tipuri al DTO-ului </returns>
	const int& get_nr_tip() const;

	/// <summary>
	/// Incrementeaza numarul de tipuri
	/// </summary>
	void increment();

	friend ostream& operator<<(ostream& out, const DTO& dto);
};