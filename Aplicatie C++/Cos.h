#pragma once
#include "Oferta.h"
#include "Repository.h"
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>

using std::vector;
using std::ofstream;

class Cos {
	
	vector <Oferta> elemente;

public:

	Cos() = default;

	const vector<Oferta>& get_cos() const;

	void goleste_cos();

	void adauga_in_cos(const Oferta& oferta);

	int genereaza_cos(vector<Oferta> oferte, const int& n);

	void export_to_csv(string filename) const;
		
};

