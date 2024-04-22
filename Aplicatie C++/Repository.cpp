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

void Repository::adauga_oferta_pe_pozitie(const Oferta& oferta, const int& pozitie) {
	elemente.insert(elemente.begin() + pozitie, oferta);
}

void Repository::sterge_oferta(const int& pozitie) {
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

//-------------------------------------------------------------------------------

void RepoToFile::read_from_file() {
	ifstream fin(filepath);
	if (!fin.is_open()) throw FileNotOpen{ "Fisierul cu path-ul " + filepath + " nu s-a putut deschide la citire" };
	if (fin.peek() != EOF) {
		while (!fin.eof()) {
			string denumire, destinatie, tip;
			int pret;
			getline(fin, denumire);
			getline(fin, destinatie);
			getline(fin, tip);
			fin >> pret;
			fin.get();
			Repository::adauga_oferta(Oferta{ denumire, destinatie, tip, pret });
		}
	}
	fin.close();
}

void RepoToFile::write_to_file() const {
	ofstream fout(filepath);
	if (!fout.is_open()) throw FileNotOpen{ "Fisierul cu path-ul " + filepath + " nu s-a putut deschide la scriere" };
	for (const auto& oferta : get_elemente()) {
		fout << oferta.get_denumire() << "\n";
		fout << oferta.get_destinatie() << "\n";
		fout << oferta.get_tip() << "\n";
		fout << oferta.get_pret();
		if (cauta_element(oferta.get_denumire()) != get_elemente().size() - 1) {
			fout << "\n";
		}
	}
	fout.close();
}

RepoToFile::RepoToFile(const string& filepath) : Repository{}, filepath{ filepath } {
	read_from_file();
}

void RepoToFile::adauga_oferta(const Oferta& oferta) {
	Repository::adauga_oferta(oferta);
	write_to_file();
}

void RepoToFile::sterge_oferta(const int& pozitie) {
	Repository::sterge_oferta(pozitie);
	write_to_file();
}

void RepoToFile::modifica_oferta(const Oferta& oferta_noua, const int& pozitie) {
	Repository::modifica_oferta(oferta_noua, pozitie);
	write_to_file();
}
