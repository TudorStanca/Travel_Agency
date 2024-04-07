#include "Repository.h"

const VectorDinamic<Oferta>& Repository::get_elemente() const noexcept {
	return elemente;
}

const Oferta& Repository::get_element_pozitie(const int& pozitie) const {
	return elemente.at(pozitie);
}

VectorDinamic<Oferta> Repository::get_copie_elemente() const noexcept {
	return elemente;
}

void Repository::adauga_oferta(const Oferta& oferta) {
	elemente.push_back(oferta);
}

void Repository::sterge_oferta(const int& pozitie) {
	elemente.erase(pozitie);
}

void Repository::modifica_oferta(const Oferta& oferta_noua, const int& pozitie) {
	elemente[pozitie] = oferta_noua;
}

int Repository::cauta_element(const string& denumire_cautare) const noexcept {
	for (auto i = 0; i < elemente.size(); i++) {
		if (elemente.at(i).get_denumire() == denumire_cautare) {
			return i;
		}
	}
	return -1;
}
