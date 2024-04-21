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

int Repository::cauta_element(const string& denumire_cautare) const {
	//for (auto i = 0; i < elemente.size(); i++) {
	//	if (elemente.at(i).get_denumire() == denumire_cautare) {
	//		return i;
	//	}
	//}
	const auto pos = std::distance(elemente.begin(), std::find_if(elemente.begin(), elemente.end(), [denumire_cautare](const Oferta& oferta) noexcept { return oferta.get_denumire() == denumire_cautare; }));
	if (int(pos) != elemente.size()) {
		return int(pos);
	}
	return -1;
}
