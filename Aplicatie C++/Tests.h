#pragma once
#include "VectorDinamic.h"
#include "Oferta.h"
#include "Repository.h"
#include "Cos.h"
#include "Service.h"
#include "MyException.h"
#include <cassert>
#include <cstring>

class Tests {

	void test_vector_dinamic();
	void test_iterator_vector();

	void test_creeaza_oferta();

	void test_adauga_oferta();
	void test_sterge_oferta();
	void test_modifica_oferta();
	void test_cauta_oferta();
	void test_copie_elemente();

	void test_adauga_cos();
	void test_goleste_cos();
	void test_genereaza_cos();

	void test_adauga_oferta_service();
	void test_sterge_oferta_service();
	void test_modifica_oferta_service();
	void test_cauta_oferta_service();
	void test_filtrare_service();
	void test_sortare_service();
	void test_cos_service();

	void test_vector();

	void test_exceptii();

	void test_domain();

	void test_repository();

	void test_cos();

	void test_service();

public:

	void run_all_tests();

};

