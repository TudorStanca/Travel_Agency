#include "Ui.h"

void Ui::print_menu() const {
	cout << "\n1. Adaugare oferta\n";
	cout << "2. Stergere oferta\n";
	cout << "3. Modificare oferta				a. Afisare cos\n";
	cout << "4. Cauta oferta dupa denumire			b. Goleste cos\n";
	cout << "5. Filtrare oferte turistice			c. Adauga oferta in cos\n";
	cout << "6. Sortare oferte turistice			d. Genereaza oferte in cos\n";
	cout << "8. Adaugare oferte demo				e. Export cos\n";
	cout << "9. Afisare lista oferte\n";
	cout << "0. Exit\n";
	cout << "\nInput comanda: ";
}

void Ui::print_menu_filtrare() const {
	cout << "\n1. Filtrare dupa destinatie\n";
	cout << "2. Filtrare dupa pret\n";
}

void Ui::print_menu_sortare() const {
	cout << "\n1. Sortare dupa denumire\n";
	cout << "2. Sortare dupa destinatie\n";
	cout << "3. Sortare dupa tip + pret\n";
}

// am nevoie de pozitia elementului sa o afisez, nu merge aritmetica de pointeri
void Ui::afisare_vector_oferte(const vector <Oferta>& v) const {
	for (int i = 0; i < v.size(); i++) {
		cout << i + 1 << " ";
		cout << v.at(i) << "\n";
	}
	cout << "\n";
}

void Ui::adaugare_ui() {
	string denumire, destinatie, tip;
	int pret;
	cout << "\nInput denumire: ", cin >> denumire;
	cout << "\nInput destinatie: ", cin >> destinatie;
	cout << "\nInput tip: ", cin >> tip;
	cout << "\nInput pret: ", cin >> pret;
	service.adauga_oferta_service(denumire, destinatie, tip, pret);
	cout << "\nOferta a fost adaugata cu succes\n";
}

void Ui::stergere_ui() {
	int pozitie;
	if (service.get_elemente().size() == 0) {
		cout << "\nLista de oferte este goala\n";
		return;
	}
	afisare_vector_oferte(service.get_elemente());
	cout << "\nInput numarul ofertei care va fi stearsa: ", cin >> pozitie;
	service.sterge_oferta_service(pozitie - 1);
}

void Ui::modificare_ui() {
	string denumire, destinatie, tip;
	int pret, pozitie;
	if (service.get_elemente().size() == 0) {
		cout << "\nLista de oferte este goala\n";
		return;
	}
	afisare_vector_oferte(service.get_elemente());
	cout << "\nInput numarul ofertei care va fi modificata: ", cin >> pozitie;
	cout << "\nInput noua denumire: ", cin >> denumire;
	cout << "\nInput noua destinatie: ", cin >> destinatie;
	cout << "\nInput noul tip: ", cin >> tip;
	cout << "\nInput noul pret: ", cin >> pret;
	service.modifica_oferta_service(denumire, destinatie, tip, pret, pozitie - 1);
}

void Ui::cautare_ui() const {
	string denumire;
	int pozitie;
	cout << "\nInput denumirea dupa care se face cautarea: ", cin >> denumire;
	pozitie = service.cauta_oferta_service(denumire);
	if (pozitie == -1) {
		cout << "\nOferta cautata nu exista\n";
	}
	else {
		cout << "\nOferta cautata\n";
		cout << service.get_element_pozitie(pozitie);
	}
}

void Ui::filtrare_ui() const {
	string destinatie;
	int pret, varianta;
	vector <Oferta> v;
	if (service.get_elemente().size() == 0) {
		cout << "\nLista de oferte este goala\n";
		return;
	}
	print_menu_filtrare();
	cout << "\nInput varianta: ", cin >> varianta;
	switch (varianta) {
	case 1:
		cout << "\nInput destinatia: ", cin >> destinatie;
		v = service.filtrare_oferte_service(destinatie);
		break;
	case 2:
		cout << "\nInput pret: ", cin >> pret;
		v = service.filtrare_oferte_service(pret);
		break;
	default:
		throw NuExistaOptiune{};
		break;
	}
	if (v.empty() == 1) {
		cout << "\nVectorul filtrat este gol\n";
		return;
	}
	afisare_vector_oferte(v);
}

void Ui::sortare_ui() const {
	int varianta, reversed;
	vector <Oferta> v = service.get_copie_elemente();
	if (service.get_elemente().size() == 0) {
		cout << "\nLista de oferte este goala\n";
		return;
	}
	print_menu_sortare();
	cout << "Input varianta: ", cin >> varianta;
	cout << "\n1. Crescator\n2. Descrescator\n\nInput varianta: ", cin >> reversed;
	switch (reversed) {
	case 1:
		service.sortare_oferte_service(v, varianta, 0);
		break;
	case 2:
		service.sortare_oferte_service(v, varianta, 1);
		break;
	default:
		throw NuExistaOptiune{};
		break;
	}
	afisare_vector_oferte(v);
}

void Ui::adaugare_oferte_demo_ui(const bool& oferte_demo_adaugate) {
	if (oferte_demo_adaugate == true) {
		cout << "\nOfertele demo au fost adaugate deja!\n";
		return;
	}
	service.adauga_oferta_service("hzmdyhwtrf", "ngaugcafyq", "aa", 1);
	service.adauga_oferta_service("fuqwfnmsnl", "fuqwfnmsnl", "bb", 2);
	service.adauga_oferta_service("aisjctiejg", "nhaugcafyq", "bb", 3);
	service.adauga_oferta_service("ngaugcafyq", "aisjctiejg", "dd", 5);
	service.adauga_oferta_service("nhaugcafyq", "hzmdyhwtrf", "dd", 4);
	cout << "\nOfertele demo au fost adaugate cu succes!\n";
}

void Ui::afisare_ui() const {
	if (service.get_elemente().empty() == 1) {
		cout << "\nLista de oferte este goala!\n";
		return;
	}
	afisare_vector_oferte(service.get_elemente());
}

void Ui::afisare_cos_ui() const {
	if (service.get_cos_service().empty() == 1) {
		cout << "\nCosul este gol!\n";
		cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
		return;
	}
	cout << "\nCosul contine urmatoarele oferte: \n";
	for (const auto& oferta : service.get_cos_service()) {
		cout << oferta << "\n";
	}
	cout << "\n";
	cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
}

void Ui::goleste_cos_ui() {
	if (service.get_cos_service().empty() == 1) {
		cout << "\nCosul este deja gol!\n";
	}
	else {
		service.goleste_cos_service();
		cout << "\nCosul a fost golit!\n";
	}
	cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
}

void Ui::adauga_oferta_cos_ui() {
	string denumire;
	cout << "\nInput denumirea ofertei care va fi adaugat in cos: ", cin >> denumire;
	service.adaugare_oferta_in_cos_service(denumire);
	cout << "\nOferta a fost adaugata in cos\n";
	cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
}

void Ui::genereaza_oferte_cos_ui() {
	int numar_de_oferte;
	cout << "\nInput nr. de oferte: ", cin >> numar_de_oferte;
	const int oferte_generate = service.generare_oferte_cos_service(numar_de_oferte);
	printf("\nS-au generat %d oferte din cele %d dorite de utilizator\n", oferte_generate, numar_de_oferte);
	cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
}

void Ui::export_oferte_ui() {
	string filename;
	cout << "\nInput nume fisier: ", cin >> filename;
	service.export_to_csv_service(filename);
	cout << "\nCosul a fost exportat cu succes\n";
	cout << "\nNumar oferte in cos: " << service.get_cos_service().size() << "\n";
}

void Ui::run() {
	bool rulare = true, oferte_demo_adaugate = false;
	char comanda;
	while (rulare) {
		try {
			print_menu();
			cin >> comanda;
			switch (comanda) {
			case '1':
				adaugare_ui();
				break;
			case '2':
				stergere_ui();
				break;
			case '3':
				modificare_ui();
				break;
			case '4':
				cautare_ui();
				break;
			case '5':
				filtrare_ui();
				break;
			case '6':
				sortare_ui();
				break;
			case '8':
				adaugare_oferte_demo_ui(oferte_demo_adaugate);
				oferte_demo_adaugate = true;
				break;
			case '9':
				afisare_ui();
				break;
			case 'a':
				afisare_cos_ui();
				break;
			case 'b':
				goleste_cos_ui();
				break;
			case 'c':
				adauga_oferta_cos_ui();
				break;
			case 'd':
				genereaza_oferte_cos_ui();
				break;
			case 'e':
				export_oferte_ui();
				break;
			case '0':
				rulare = false;
				break;
			default:
				cout << "\nComanda nu exista\n";
				break;
			}
		}
		catch (const MyException& ex) {
			cout << ex.what() << "\n";
		}
	}
}
