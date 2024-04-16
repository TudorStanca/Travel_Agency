#include "Repository.h"

const vector<Oferta>& Repository::get_elemente() const noexcept {
	return elemente;
}

const Oferta& Repository::get_element_pozitie(const int& pozitie) const {
	return elemente.at(pozitie);
}

vector<Oferta> Repository::get_copie_elemente() const noexcept {
	return elemente;
}

void Repository::adauga_oferta(const Oferta& oferta) {
	elemente.push_back(oferta);
}

void Repository::sterge_oferta(const int& pozitie) noexcept {
	elemente.erase(elemente.begin() + pozitie);
}

void Repository::modifica_oferta(const Oferta& oferta_noua, const int& pozitie) {
	elemente.at(pozitie) = oferta_noua;
}

// da eroare daca fac cu range for la aritmetica de pointeri
int Repository::cauta_element(const string& denumire_cautare) const noexcept {
	for (auto i = 0; i < elemente.size(); i++) {
		if (elemente.at(i).get_denumire() == denumire_cautare) {
			return i;
		}
	}
	return -1;
}
