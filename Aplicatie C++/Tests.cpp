#include "Tests.h"

void Tests::test_vector_dinamic() {
	VectorDinamic <int> v1;

	assert(v1.size() == 0);
	assert(v1.max_size() == 5);

	VectorDinamic <int> v2(1);

	assert(v1.empty() == 1);
	assert(v2.size() == 0);
	assert(v2.max_size() == 1);

	v2.push_back(1);
	assert(v2.size() == 1);
	assert(v2.max_size() == 1);
	assert(v2.at(0) == 1);
	assert(v2.empty() == 0);

	v2[0] = 2;

	assert(v2.size() == 1);
	assert(v2.max_size() == 1);
	assert(v2.at(0) == 2);

	v2.push_back(3);

	assert(v2.size() == 2);
	assert(v2.max_size() == 2);
	assert(v2.at(1) == 3);

	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);

	assert(v2.size() == 6);
	assert(v2.max_size() == 8);

	VectorDinamic <int> v3(v2);
	assert(v3.size() == 6);
	assert(v3.max_size() == 8);
	assert(v3.at(v3.size() - 1) == 7);

	v1 = v2;
	v1 = v1;

	assert(v1.size() == 6);
	assert(v1.max_size() == 8);
	assert(v1.at(v1.size() - 1) == 7);

	v2.erase(0);

	assert(v2.size() == 5);
	assert(v2.max_size() == 8);
	assert(v2.at(0) == 3);

	v2.erase(0);
	v2.erase(0);

	assert(v2.size() == 3);
	assert(v2.max_size() == 4);
	assert(v2.at(0) == 5);

	v2.erase(0);
	v2.erase(0);
	v2.erase(0);

	assert(v2.size() == 0);
	assert(v2.max_size() == 1);
	assert(v2.empty() == 1);

	try {
		v1.at(100);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	try {
		v1[100];
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	try {
		VectorDinamic <int> v(-100);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	try {
		v1.erase(1000);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}

void Tests::test_iterator_vector() {
	VectorDinamic <int> v;
	const int a[]{ 1, 2, 3, 4, 5 };
	for (const auto& el : v) {
		assert(el == 1);
	}
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	int i = 0;
	for (const auto& el : v) {
		assert(el == a[i]);
		i++;
	}
	auto it = v.end();
	assert(it.valid() == false);
}

void Tests::test_creeaza_oferta() {
	Oferta a{ "dsa", "dsadsa", "dsadsadsa", 100 };

	assert(a.get_denumire() == "dsa");
	assert(a.get_destinatie() == "dsadsa");
	assert(a.get_tip() == "dsadsadsa");
	assert(a.get_pret() == 100);

	a.set_denumire("asd");
	a.set_destinatie("asdasd");
	a.set_tip("asdasdasd");
	a.set_pret(1);

	assert(a.get_denumire() == "asd");
	assert(a.get_destinatie() == "asdasd");
	assert(a.get_tip() == "asdasdasd");
	assert(a.get_pret() == 1);

	try {
		Oferta b{ "ds", "", "", -100 };
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
}

void Tests::test_dto() {
	DTO b{};
	assert(b.get_tip() == "test");
	assert(b.get_nr_tip() == 0);
	DTO a{ "haha" };
	assert(a.get_tip() == "haha");
	assert(a.get_nr_tip() == 1);
	a.increment();
	assert(a.get_nr_tip() == 2);
}

void Tests::test_adauga_oferta() {
	Repository repository;

	assert(repository.get_elemente().empty() == 1);
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 123 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1234 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1235 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1236 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1237 });
	assert(repository.get_elemente().size() == 5);
	assert(repository.get_element_pozitie(0).get_denumire() == "dsa");
	assert(repository.get_element_pozitie(4).get_pret() == 1237);
}

void Tests::test_sterge_oferta() {
	Repository repository;
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 123 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1234 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1235 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1236 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1237 });

	assert(repository.get_elemente().size() == 5);
	assert(repository.get_element_pozitie(0).get_pret() == 123);
	repository.sterge_oferta(0);
	assert(repository.get_elemente().size() == 4);
	assert(repository.get_element_pozitie(0).get_pret() == 1234);
	repository.sterge_oferta(1);
	repository.sterge_oferta(2);
	assert(repository.get_elemente().size() == 2);
	repository.sterge_oferta(0);
	repository.sterge_oferta(0);
	assert(repository.get_elemente().empty() == 1);
}

void Tests::test_modifica_oferta() {
	Repository repository;
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 123 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1234 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1235 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1236 });
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 1237 });

	assert(repository.get_element_pozitie(0).get_denumire() == "dsa");
	assert(repository.get_element_pozitie(0).get_destinatie() == "dsa");
	assert(repository.get_element_pozitie(0).get_tip() == "dsa");
	assert(repository.get_element_pozitie(0).get_pret() == 123);
	repository.modifica_oferta(Oferta{ "marcel", "ioan", "123", 1111 }, 0);
	assert(repository.get_element_pozitie(0).get_denumire() == "marcel");
	assert(repository.get_element_pozitie(0).get_destinatie() == "ioan");
	assert(repository.get_element_pozitie(0).get_tip() == "123");
	assert(repository.get_element_pozitie(0).get_pret() == 1111);
	assert(repository.get_elemente().size() == 5);
}

void Tests::test_cauta_oferta() {
	Repository repository;
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 123 });
	repository.adauga_oferta(Oferta{ "dasdas", "dsa", "dsa", 1234 });
	repository.adauga_oferta(Oferta{ "asdasd", "dsa", "dsa", 1235 });
	repository.adauga_oferta(Oferta{ "asd", "dsa", "dsa", 1236 });
	repository.adauga_oferta(Oferta{ "dsadasasda", "dsa", "dsa", 1237 });

	assert(repository.cauta_element("dsa") == 0);
	assert(repository.cauta_element("asd") == 3);
	assert(repository.cauta_element("dsadadadadasdadadas") == -1);
}

void Tests::test_copie_elemente() {
	Repository repository;
	repository.adauga_oferta(Oferta{ "dsa", "dsa", "dsa", 123 });
	repository.adauga_oferta(Oferta{ "dasdas", "dsa", "dsa", 1234 });
	repository.adauga_oferta(Oferta{ "asdasd", "dsa", "dsa", 1235 });
	repository.adauga_oferta(Oferta{ "asd", "dsa", "dsa", 1236 });
	repository.adauga_oferta(Oferta{ "dsadasasda", "dsa", "dsa", 1237 });

	auto v = repository.get_copie_elemente();
	for (int i = 0; i < v.size(); i++) {
		assert(repository.get_element_pozitie(i) == v.at(i));
	}
}

void Tests::test_adauga_cos() {
	Cos cos;
	assert(cos.get_cos().empty() == 1);
	cos.adauga_in_cos(Oferta{ "dsaad", "das", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "s", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "d", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "f", "dsa", 1 });
	try {
		cos.adauga_in_cos(Oferta{ "dsaad", "das", "dsa", 1 });
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
	assert(cos.get_cos().size() == 4);
}

void Tests::test_goleste_cos() {
	Cos cos;
	assert(cos.get_cos().empty() == 1);
	cos.adauga_in_cos(Oferta{ "dsaad", "das", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "s", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "d", "dsa", 1 });
	cos.adauga_in_cos(Oferta{ "dsaad", "f", "dsa", 1 });
	assert(cos.get_cos().size() == 4);
	cos.goleste_cos();
	assert(cos.get_cos().empty() == 1);
}

void Tests::test_genereaza_cos() {
	Cos cos;
	vector <Oferta> v;
	v.push_back(Oferta{ "dsadas", "dsa", "dsa", 1 });
	v.push_back(Oferta{ "dsadasd", "a", "dsa", 1 });
	v.push_back(Oferta{ "dsadas", "s", "dsa", 1 });
	v.push_back(Oferta{ "dsadas", "d", "dsa", 1 });
	v.push_back(Oferta{ "dsadas", "f", "dsa", 1 });
	v.push_back(Oferta{ "dsadas", "e", "dsa", 1 });
	cos.genereaza_cos(v, 2);
	assert(cos.get_cos().size() == 2);
	cos.genereaza_cos(v, 200);
	assert(cos.get_cos().size() == 6);
}

void Tests::test_adauga_oferta_service() {
	Service service;
	assert(service.get_elemente().empty() == 1);

	service.adauga_oferta_service("dsa", "dsa", "dsa", 123);
	service.adauga_oferta_service("dsadsadsa", "dsa", "dsa", 1234);
	service.adauga_oferta_service("dsadsa", "dsa", "dsa", 1235);
	service.adauga_oferta_service("asd", "dsa", "dsa", 1236);
	service.adauga_oferta_service("asdasd", "dsa", "dsa", 1237);
	assert(service.get_elemente().size() == 5);
	assert(service.get_element_pozitie(0).get_denumire() == "dsa");
	try {
		service.get_element_pozitie(10);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
	try {
		service.adauga_oferta_service("asdasd", "dsa", "dsa", 1237);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
}

void Tests::test_sterge_oferta_service() {
	Service service;
	service.adauga_oferta_service("dsa", "dsa", "dsa", 123);
	service.adauga_oferta_service("dsadsadsa", "dsa", "dsa", 1234);
	service.adauga_oferta_service("dsadsa", "dsa", "dsa", 1235);
	service.adauga_oferta_service("asd", "dsa", "dsa", 1236);
	service.adauga_oferta_service("asdasd", "dsa", "dsa", 1237);

	assert(service.get_elemente().size() == 5);
	service.sterge_oferta_service(0);
	assert(service.get_elemente().size() == 4);
	service.sterge_oferta_service(0);
	service.sterge_oferta_service(0);
	assert(service.get_elemente().size() == 2);

	try {
		service.sterge_oferta_service(10);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
}

void Tests::test_modifica_oferta_service() {
	Service service;
	service.adauga_oferta_service("dsa", "dsa", "dsa", 123);
	service.adauga_oferta_service("dsadsadsa", "dsa", "dsa", 1234);
	service.adauga_oferta_service("dsadsa", "dsa", "dsa", 1235);
	service.adauga_oferta_service("asd", "dsa", "dsa", 1236);
	service.adauga_oferta_service("asdasd", "dsa", "dsa", 1237);

	assert(service.get_elemente().size() == 5);
	service.modifica_oferta_service("abc", "abc", "abc", 100, 0);
	assert(service.get_elemente().size() == 5);
	assert(service.get_elemente().at(0).get_denumire() == "abc");
	try {
		service.modifica_oferta_service("", "", "", 123, 10);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
}

void Tests::test_cauta_oferta_service() {
	Service service;
	service.adauga_oferta_service("dsa", "dsa", "dsa", 123);
	service.adauga_oferta_service("dsadsadsa", "dsa", "dsa", 1234);
	service.adauga_oferta_service("dsadsa", "dsa", "dsa", 1235);
	service.adauga_oferta_service("asd", "dsa", "dsa", 1236);
	service.adauga_oferta_service("asdasd", "dsa", "dsa", 1237);

	assert(service.get_elemente().size() == 5);
	assert(service.cauta_oferta_service("dsa") == 0);
	assert(service.cauta_oferta_service("asd") == 3);
	assert(service.cauta_oferta_service("adsdaadsadsadsadsadasdasdasd") == -1);
	assert(service.get_elemente().size() == 5);
}

void Tests::test_filtrare_service() {
	Service service;
	service.adauga_oferta_service("hzmdyhwtrf", "ngaugcafyq", "aa", 1);
	service.adauga_oferta_service("fuqwfnmsnl", "fuqwfnmsnl", "bb", 2);
	service.adauga_oferta_service("aisjctiejg", "nhaugcafyq", "bb", 3);
	service.adauga_oferta_service("ngaugcafyq", "aisjctiejg", "dd", 5);
	service.adauga_oferta_service("nhaugcafyq", "hzmdyhwtrf", "dd", 4);
	service.adauga_oferta_service("asd", "hzmdyhwtrf", "dd", 4);

	auto v = service.filtrare_oferte_service("ngaugcafyq");
	assert(v.size() == 1);
	assert(v.at(0).get_denumire() == "hzmdyhwtrf");

	v = service.filtrare_oferte_service("hzmdyhwtrf");
	assert(v.size() == 2);
	assert(v.at(0).get_denumire() == "nhaugcafyq");
	assert(v.at(1).get_denumire() == "asd");

	v = service.filtrare_oferte_service(1);
	assert(v.size() == 1);
	assert(v.at(0).get_denumire() == "hzmdyhwtrf");

	v = service.filtrare_oferte_service(4);
	assert(v.size() == 2);
	assert(v.at(0).get_denumire() == "nhaugcafyq");
	assert(v.at(1).get_denumire() == "asd");
}

void Tests::test_sortare_service() {
	Service service;
	service.adauga_oferta_service("hzmdyhwtrf", "ngaugcafyq", "aa", 1);
	service.adauga_oferta_service("fuqwfnmsnl", "fuqwfnmsnl", "bb", 2);
	service.adauga_oferta_service("aisjctiejg", "nhaugcafyq", "bb", 3);
	service.adauga_oferta_service("ngaugcafyq", "aisjctiejg", "dd", 5);
	service.adauga_oferta_service("nhaugcafyq", "hzmdyhwtrf", "dd", 4);

	auto v = service.get_copie_elemente();

	service.sortare_oferte_service(v, 1, 0);
	assert(v.at(0).get_denumire() == "aisjctiejg");
	assert(v.at(1).get_denumire() == "fuqwfnmsnl");
	assert(v.at(2).get_denumire() == "hzmdyhwtrf");
	assert(v.at(3).get_denumire() == "ngaugcafyq");
	assert(v.at(4).get_denumire() == "nhaugcafyq");

	service.sortare_oferte_service(v, 1, 1);
	assert(v.at(0).get_denumire() == "nhaugcafyq");
	assert(v.at(1).get_denumire() == "ngaugcafyq");
	assert(v.at(2).get_denumire() == "hzmdyhwtrf");
	assert(v.at(3).get_denumire() == "fuqwfnmsnl");
	assert(v.at(4).get_denumire() == "aisjctiejg");

	service.sortare_oferte_service(v, 2, 0);
	assert(v.at(0).get_denumire() == "ngaugcafyq");
	assert(v.at(1).get_denumire() == "fuqwfnmsnl");
	assert(v.at(2).get_denumire() == "nhaugcafyq");
	assert(v.at(3).get_denumire() == "hzmdyhwtrf");
	assert(v.at(4).get_denumire() == "aisjctiejg");

	service.sortare_oferte_service(v, 2, 1);
	assert(v.at(0).get_denumire() == "aisjctiejg");
	assert(v.at(1).get_denumire() == "hzmdyhwtrf");
	assert(v.at(2).get_denumire() == "nhaugcafyq");
	assert(v.at(3).get_denumire() == "fuqwfnmsnl");
	assert(v.at(4).get_denumire() == "ngaugcafyq");

	service.sortare_oferte_service(v, 3, 0);
	assert(v.at(0).get_denumire() == "hzmdyhwtrf");
	assert(v.at(1).get_denumire() == "fuqwfnmsnl");
	assert(v.at(2).get_denumire() == "aisjctiejg");
	assert(v.at(3).get_denumire() == "nhaugcafyq");
	assert(v.at(4).get_denumire() == "ngaugcafyq");

	service.sortare_oferte_service(v, 3, 1);
	assert(v.at(0).get_denumire() == "ngaugcafyq");
	assert(v.at(1).get_denumire() == "nhaugcafyq");
	assert(v.at(2).get_denumire() == "aisjctiejg");
	assert(v.at(3).get_denumire() == "fuqwfnmsnl");
	assert(v.at(4).get_denumire() == "hzmdyhwtrf");

	try {
		service.sortare_oferte_service(v, 321, 1);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
}

void Tests::test_raport_service() {
	Service service;
	map<string, DTO> raport = service.raport_tip_service();
	assert(raport.empty() == 1);
	service.adauga_oferta_service("hzmdyhwtrf", "ngaugcafyq", "aa", 1);
	service.adauga_oferta_service("fuqwfnmsnl", "fuqwfnmsnl", "bb", 2);
	service.adauga_oferta_service("aisjctiejg", "nhaugcafyq", "bb", 3);
	service.adauga_oferta_service("ngaugcafyq", "aisjctiejg", "dd", 5);
	service.adauga_oferta_service("nhaugcafyq", "hzmdyhwtrf", "dd", 4);
	raport = service.raport_tip_service();
	assert(raport["aa"].get_nr_tip() == 1);
	assert(raport["bb"].get_nr_tip() == 2);
	assert(raport["dd"].get_nr_tip() == 2);
}

void Tests::test_cos_service() {
	Service service;
	try {
		service.generare_oferte_cos_service(120);
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
	service.adauga_oferta_service("hzmdyhwtrf", "ngaugcafyq", "aa", 1);
	service.adauga_oferta_service("fuqwfnmsnl", "fuqwfnmsnl", "bb", 2);
	service.adauga_oferta_service("aisjctiejg", "nhaugcafyq", "bb", 3);
	service.adauga_oferta_service("ngaugcafyq", "aisjctiejg", "dd", 5);
	service.adauga_oferta_service("nhaugcafyq", "hzmdyhwtrf", "dd", 4);
	assert(service.get_cos_service().empty() == 1);
	service.adaugare_oferta_in_cos_service("hzmdyhwtrf");
	assert(service.get_cos_service().size() == 1);
	try {
		service.adaugare_oferta_in_cos_service("dsa");
		assert(false);
	}
	catch (MyException&) {
		assert(true);
	}
	service.goleste_cos_service();
	assert(service.get_cos_service().empty() == 1);
	service.generare_oferte_cos_service(3);
	assert(service.get_cos_service().size() == 3);
}

void Tests::test_vector() {
	test_vector_dinamic();
	test_iterator_vector();
}

void Tests::test_exceptii() {
	try {
		throw ValidateException{ "dsa" };
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "dsa") == 0);
	}
	try {
		throw OfertaExistaInCos{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Oferta deja exista in cos!") == 0);
	}
	try {
		throw PozitieInvalida{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Pozitia nu este valida!") == 0);
	}
	try {
		throw OfertaIdentica{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Nu se pot adauga 2 oferte identice") == 0);
	}
	try {
		throw OptiuneSort{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Optiunea nu exista!") == 0);
	}
	try {
		throw OfertaNuExista{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Ofera nu exista!") == 0);
	}
	try {
		throw RepositoryGol{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Repository-ul nu contine elemente!") == 0);
	}
	try {
		throw NuExistaOptiune{};
	}
	catch (const MyException& ex) {
		assert(strcmp(ex.what(), "Nu exista optiunea introdusa") == 0);
	}
}

void Tests::test_domain() {
	test_creeaza_oferta();
	test_dto();
}

void Tests::test_repository() {
	test_adauga_oferta();
	test_sterge_oferta();
	test_modifica_oferta();
	test_cauta_oferta();
	test_copie_elemente();
}

void Tests::test_cos() {
	test_adauga_cos();
	test_goleste_cos();
	test_genereaza_cos();
}

void Tests::test_service() {
	test_adauga_oferta_service();
	test_sterge_oferta_service();
	test_modifica_oferta_service();
	test_cauta_oferta_service();
	test_filtrare_service();
	test_sortare_service();
	test_raport_service();
	test_cos_service();
}

void Tests::run_all_tests() {
	test_vector();
	test_exceptii();
	test_domain();
	test_repository();
	test_cos();
	test_service();
}
