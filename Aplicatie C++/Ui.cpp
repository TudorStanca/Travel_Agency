#include "Ui.h"

void Ui::print_menu() const {
	cout << "\n1. Adaugare oferta\n";
	cout << "2. Stergere oferta\n";
	cout << "3. Modificare oferta\n";
	cout << "4. Cauta oferta dupa denumire\n";
	cout << "5. Filtrare oferte turistice\n";
	cout << "6. Sortare oferte turistice\n";
	cout << "8. Adaugare oferte demo\n";
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

void Ui::afisare_oferta(const Oferta& oferta) const {
	cout << oferta.get_denumire() << " " << oferta.get_destinatie() << " " << oferta.get_tip() << " " << oferta.get_pret() << "\n";
}

void Ui::afisare_vector_oferte(const VectorDinamic <Oferta>& v) const {
	for (int i = 0; i < v.size(); i++) {
		cout << i + 1 << " ";
		afisare_oferta(v.at(i));
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
	afisare_ui();
	cout << "\nInput numarul ofertei care va fi stearsa: ", cin >> pozitie;
	service.sterge_oferta_service(pozitie - 1);
}

void Ui::modificare_ui() {
	string denumire, destinatie, tip;
	int pret, pozitie;
	afisare_ui();
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
		afisare_oferta(service.get_element_pozitie(pozitie));
	}
}

void Ui::filtrare_ui() const {
	string destinatie;
	int pret, varianta;
	VectorDinamic <Oferta> v;
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
		throw exception{ "E bai!" };
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
	VectorDinamic <Oferta> v = service.get_copie_elemente();
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
		throw exception{ "E bai!" };
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

void Ui::run() {
	bool rulare = true, oferte_demo_adaugate = false;
	int comanda;
	while (rulare) {
		try {
			print_menu();
			cin >> comanda;
			switch (comanda) {
			case 1:
				adaugare_ui();
				break;
			case 2:
				stergere_ui();
				break;
			case 3:
				modificare_ui();
				break;
			case 4:
				cautare_ui();
				break;
			case 5:
				filtrare_ui();
				break;
			case 6:
				sortare_ui();
				break;
			case 8:
				adaugare_oferte_demo_ui(oferte_demo_adaugate);
				oferte_demo_adaugate = true;
				break;
			case 9:
				afisare_ui();
				break;
			case 0:
				rulare = false;
				break;
			default:
				cout << "\nComanda nu exista\n";
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << "\n";
		}
	}
}
