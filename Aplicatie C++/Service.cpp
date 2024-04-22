#include "Service.h"

Service::Service(Repository& repository, const Cos& cos) : repository{ repository }, cos{ cos } {}

Service::~Service() {
	while (vector_undo.empty() == false) {
		delete vector_undo.back();
		vector_undo.pop_back();
	}
}

const vector<Oferta>& Service::get_elemente() const noexcept {
	return repository.get_elemente();
}

const Oferta& Service::get_element_pozitie(const int& pozitie) const {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	return repository.get_element_pozitie(pozitie);
}

vector<Oferta> Service::get_copie_elemente() const {
	return repository.get_elemente();
}

void Service::adauga_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret) {
	Oferta oferta{ denumire, destinatie, tip, pret };
	for (const auto& element : repository.get_elemente()) {
		if (oferta == element) {
			throw OfertaIdentica{};
		}
	}
	repository.adauga_oferta(oferta);
	vector_undo.push_back(new UndoAdauga{ repository, oferta });
}

void Service::sterge_oferta_service(const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	Oferta oferta_stearsa = repository.get_element_pozitie(pozitie);
	repository.sterge_oferta(pozitie);
	vector_undo.push_back(new UndoSterge{ repository, oferta_stearsa, pozitie });
}

void Service::modifica_oferta_service(const string& denumire, const string& destinatie, const string& tip, const int& pret, const int& pozitie) {
	if (pozitie < 0 || pozitie >= repository.get_elemente().size()) {
		throw PozitieInvalida{};
	}
	Oferta oferta_noua{ denumire, destinatie, tip, pret };
	Oferta oferta_veche = repository.get_element_pozitie(pozitie);
	repository.modifica_oferta(oferta_noua, pozitie);
	vector_undo.push_back(new UndoModifica{ repository, oferta_veche, pozitie });
}

int Service::cauta_oferta_service(const string& denumire) const {
	return repository.cauta_element(denumire);
}

vector <Oferta> Service::filtrare_oferte_service(const string& destinatie) const {
	vector <Oferta> v;
	copy_if(repository.get_elemente().begin(), repository.get_elemente().end(), back_inserter(v), [destinatie](const Oferta& a) noexcept {return a.get_destinatie() == destinatie; });
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
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) noexcept {  if (a.get_denumire() <= b.get_denumire()) { return !(reversed); } return reversed; });
		break;
	case 2: // destinatie
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) noexcept {  if (a.get_destinatie() <= b.get_destinatie()) { return !(reversed); } return reversed; });
		break;
	case 3: // tip + pret
		sort(v.begin(), v.end(), [reversed](const Oferta& a, const Oferta& b) noexcept {  if (a.get_tip() < b.get_tip()) { return !(reversed); } else if (a.get_tip() == b.get_tip()) { if (a.get_pret() <= b.get_pret()) { return !(reversed); } } return reversed; });
		break;
	default:
		throw OptiuneSort{};
		break;
	}
}

map<string, DTO> Service::raport_tip_service() const {
	map<string, DTO> raport;
	for (const auto& oferta : repository.get_elemente()) {
		if (raport.count(oferta.get_tip()) == 0) {
			raport[oferta.get_tip()] = DTO{ oferta.get_tip() };
		}
		else {
			raport[oferta.get_tip()].increment();
		}
	}
	return raport;
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

void Service::undo_service() {
	if (vector_undo.empty() == true) {
		throw NuMaiSuntOperatiiUndo{};
	}
	ActiuneUndo* act = vector_undo.back();
	act->doUndo();
	vector_undo.pop_back();
	delete act;
}

int Service::generare_oferte_cos_service(const int& nr_oferte) {
	if (repository.get_elemente().empty() == 1) {
		throw RepositoryGol{};
	}
	return cos.genereaza_cos(repository.get_elemente(), nr_oferte);
}

void Service::export_to_csv_service(const string& filename) const {
	cos.export_to_csv(filename);
}
