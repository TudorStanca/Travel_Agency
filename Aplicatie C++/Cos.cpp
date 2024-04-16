#include "Cos.h"

const vector<Oferta>& Cos::get_cos() const {
	return elemente;
}

void Cos::goleste_cos() {
	elemente.clear();
}

void Cos::adauga_in_cos(const Oferta& oferta) {
	if (elemente.empty() == 0) {
		for (const auto& oferta_cos : elemente) {
			if (oferta == oferta_cos) {
				throw OfertaExistaInCos{};
			}
		}
	}
	elemente.push_back(oferta);
}

int Cos::genereaza_cos(vector<Oferta> oferte, const int& n) {

	//std::mt19937 mt{ std::random_device{}() };
	//std::uniform_int_distribution<> dist(0, int(oferte.size()) - 1);
	//for (int i = 0; i < n; i++) {
	//	const auto& nr_random = dist(mt);
	//	elemente.push_back(oferte.at(nr_random));
	//}

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(oferte.begin(), oferte.end(), std::default_random_engine(unsigned int(seed)));

	int i = 0;
	int oferte_generate = 0;
	while (i < n) {
		const Oferta& oferta = oferte.at(i);
		bool adauga = true;
		if (elemente.empty() == 0) {
			for (const auto& oferta_cos : elemente) {
				if (oferta == oferta_cos) {
					adauga = false;
				}
			}
		}
		if (adauga == true) {
			elemente.push_back(oferta);
			oferte_generate++;
		}
		i++;
		if (i == oferte.size()) {
			break;
		}
	}
	return oferte_generate;
}

void Cos::export_to_csv(string filename) const {
	filename += ".csv";
	ofstream csv_file(filename);
	for (const auto& oferta : elemente) {
		csv_file << oferta.get_denumire() + "," << oferta.get_destinatie() + "," << oferta.get_tip() + "," << std::to_string(oferta.get_pret()) + "," << "\n";
	}
}
