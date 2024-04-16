#include "Service.h"

const vector<Oferta>& Service::get_elemente() const noexcept {
	return repository.get_elemente();
}

const Oferta& Service::get_element_pozitie(const int& pozitie) const {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	return repository.get_element_pozitie(pozitie);
}

vector<Oferta> Service::get_copie_elemente() const noexcept {
	return repository.get_elemente();
}

void Service::adauga_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret) {
	Oferta oferta{ denumire, destinatie, tip, pret };
	for (const auto& element : repository.get_elemente()) {
		if (oferta == element) {
			throw OfertaIdentica{};
		}
	}
	repository.adauga_oferta(Oferta{ denumire, destinatie, tip, pret });
}

void Service::sterge_oferta_service(const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	repository.sterge_oferta(pozitie);
}

void Service::modifica_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret, const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	Oferta oferta_noua{ denumire, destinatie, tip, pret };
	repository.modifica_oferta(oferta_noua, pozitie);
}

int Service::cauta_oferta_service(const string& denumire) const noexcept {
	return repository.cauta_element(denumire);
}

vector <Oferta> Service::filtrare_oferte_service(const string& destinatie) const {
	vector <Oferta> v;
	copy_if(repository.get_elemente().begin(), repository.get_elemente().end(), back_inserter(v), [destinatie](const Oferta& a) {return a.get_destinatie() == destinatie; });
	return v;
}

vector <Oferta> Service::filtrare_oferte_service(const int& pret) const noexcept {
	vector <Oferta> v;
	copy_if(repository.get_elemente().begin(), repository.get_elemente().end(), back_inserter(v), [pret](const Oferta& a) noexcept {return a.get_pret() == pret; });
	return v;
}

void Service::sortare_oferte_service(vector <Oferta>& v, const int& varianta, const bool& reversed) const {
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
		throw OptiuneSort{};
		break;
	}
}

const vector<Oferta>& Service::get_cos_service() const {
	return cos.get_cos();
}

void Service::goleste_cos_service() {
	cos.goleste_cos();
}

void Service::adaugare_oferta_in_cos_service(const string& denumire) {
	const auto& pozitie_oferta = repository.cauta_element(denumire);
	if (pozitie_oferta == -1) {
		throw OfertaNuExista{};
	}
	cos.adauga_in_cos(repository.get_element_pozitie(pozitie_oferta));
}

int Service::generare_oferte_cos_service(const int& nr_oferte) {
	if (repository.get_elemente().empty() == 1) {
		throw RepositoryGol{};
	}
	return cos.genereaza_cos(repository.get_elemente(), nr_oferte);
}

void Service::export_to_csv_service(const string& filename) {
	cos.export_to_csv(filename);
}
