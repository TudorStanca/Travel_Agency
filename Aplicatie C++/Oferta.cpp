#include "Oferta.h"

Oferta::Oferta() : pret{ 0 } {}

Oferta::Oferta(const string& denumire, const string& destinatie, const string& tip, const int& pret) :denumire{ denumire }, destinatie{ destinatie }, tip{ tip }, pret{ pret } {}

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
}

void Oferta::set_destinatie(const string& new_destinatie) {
	destinatie = new_destinatie;
}

void Oferta::set_tip(const string& new_tip) {
	tip = new_tip;
}

void Oferta::set_pret(const int& new_pret) noexcept {
	pret = new_pret;
}

bool Oferta::operator==(const Oferta& other) const noexcept {
	return denumire == other.get_denumire() && destinatie == other.get_destinatie() && tip == other.get_tip() && pret == other.get_pret();
}