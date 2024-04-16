#include "Service.h"

const VectorDinamic<Oferta>& Service::get_elemente() const noexcept {
	return repository.get_elemente();
}

const Oferta& Service::get_element_pozitie(const int& pozitie) const {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw exception{ "Pozitia nu este valida!" };
	}
	return repository.get_element_pozitie(pozitie);
}

VectorDinamic<Oferta> Service::get_copie_elemente() const noexcept {
	return repository.get_elemente();
}

void Service::adauga_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret) {
	Oferta oferta{ denumire, destinatie, tip, pret };
	for (int i = 0; i < repository.get_elemente().size(); i++) {
		if (oferta == repository.get_element_pozitie(i)) {
			throw exception{ "Nu se pot adauga 2 oferte identice" };
		}
	}
	repository.adauga_oferta(Oferta{ denumire, destinatie, tip, pret });
}

void Service::sterge_oferta_service(const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw exception{ "Pozitia nu este valida!" };
	}
	repository.sterge_oferta(pozitie);
}

void Service::modifica_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret, const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw exception{ "Pozitia nu este valida!" };
	}
	Oferta oferta_noua{ denumire, destinatie, tip, pret };
	repository.modifica_oferta(oferta_noua, pozitie);
}

int Service::cauta_oferta_service(const string& denumire) const noexcept {
	return repository.cauta_element(denumire);
}

VectorDinamic <Oferta> Service::filtrare_oferte_service(const string& destinatie) const {
	vector <Oferta> v, u;
	VectorDinamic <Oferta> rezultat;
	for (const auto& oferta : repository.get_copie_elemente()) {
		v.push_back(oferta);
	}
	copy_if(v.begin(), v.end(), back_inserter(u), [destinatie](const Oferta& a) {return a.get_destinatie() == destinatie; });
	for (const auto& oferta : u) {
		rezultat.push_back(oferta);
	}
	return rezultat;
}

VectorDinamic <Oferta> Service::filtrare_oferte_service(const int& pret) const {
	vector <Oferta> v, u;
	VectorDinamic <Oferta> rezultat;
	for (const auto& oferta : repository.get_copie_elemente()) {
		v.push_back(oferta);
	}
	copy_if(v.begin(), v.end(), back_inserter(u), [pret](const Oferta& a) noexcept {return a.get_pret() == pret; });
	for (const auto& oferta : u) {
		rezultat.push_back(oferta);
	}
	return rezultat;
}

void Service::sortare_oferte_service(VectorDinamic <Oferta>& rezultat, const int& varianta, const bool& reversed) const {
	vector <Oferta> v;
	for (const auto& oferta : repository.get_copie_elemente()) {
		v.push_back(oferta);
	}
	switch (varianta) {
	case 1: // denumire
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) {  if (a.get_denumire() <= b.get_denumire()) { return !(reversed); } return reversed; });
		break;
	case 2: // destinatie
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) {  if (a.get_destinatie() <= b.get_destinatie()) { return !(reversed); } return reversed; });
		break;
	case 3: // tip + pret
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) {  if (a.get_tip() < b.get_tip()) { return !(reversed); } else if (a.get_tip() == b.get_tip()) { if (a.get_pret() <= b.get_pret()) { return !(reversed); } } return reversed; });
		break;
	default:
		throw exception{ "Nu exista optiunea introdusa!" };
		break;
	}
	for (const auto& oferta : v) {
		rezultat.erase(0);
		rezultat.push_back(oferta);
	}
}
