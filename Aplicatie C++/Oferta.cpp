#define _CRT_SECURE_NO_WARNINGS
#include "Oferta.h"

//Oferta::Oferta() : pret{ 0 } {}

void Oferta::validator() const {
	string errors = "";

	if (denumire.size() < 3) {
		errors += "\nDenumirea trebuie sa aibe macar 3 caractere";
	}
	if (destinatie.size() < 1) {
		errors += "\nDestinatia nu trebuie sa fie vida";
	}
	if (tip.size() < 1) {
		errors += "\nTipul nu trebuie sa fie vid";
	}
	if (pret < 0) {
		errors += "\nPretul nu trebuie sa fie negativ";
	}

	if (errors.size() > 0) {
		throw ValidateException{ errors };
	}
}

Oferta::Oferta(const string& denumire, const string& destinatie, const string& tip, const int& pret) :denumire{ denumire }, destinatie{ destinatie }, tip{ tip }, pret{ pret } {
	validator();
}

//Oferta::Oferta(const Oferta& oferta) {
//	*this = oferta;
//}

const string& Oferta::get_denumire() const noexcept {
	return denumire;
}

const string& Oferta::get_destinatie() const noexcept {
	return destinatie;
}

const string& Oferta::get_tip() const noexcept {
	return tip;
}

const int& Oferta::get_pret() const noexcept {
	return pret;
}

void Oferta::set_denumire(const string& new_denumire) {
	denumire = new_denumire;
	validator();
}

void Oferta::set_destinatie(const string& new_destinatie) {
	destinatie = new_destinatie;
	validator();
}

void Oferta::set_tip(const string& new_tip) {
	tip = new_tip;
	validator();
}

void Oferta::set_pret(const int& new_pret) {
	pret = new_pret;
	validator();
}

bool Oferta::operator==(const Oferta& other) const noexcept {
	return denumire == other.get_denumire() && destinatie == other.get_destinatie() && tip == other.get_tip() && pret == other.get_pret();
}

ostream& operator<<(ostream& out, const Oferta& oferta) {
	out << oferta.denumire << " " << oferta.destinatie << " " << oferta.tip << " " << oferta.pret;
	return out;
}

//------------------------------------------------------------------

DTO::DTO() : tip{ "test" }, nr_tip{ 0 } {}

DTO::DTO(const string& tip) : tip{ tip }, nr_tip{ 1 } {}

const string& DTO::get_tip() const {
	return tip;
}

const int& DTO::get_nr_tip() const {
	return nr_tip;
}

void DTO::increment() {
	nr_tip++;
}

ostream& operator<<(ostream& out, const DTO& dto) {
	out << dto.tip << ": " << dto.nr_tip;
	return out;
}