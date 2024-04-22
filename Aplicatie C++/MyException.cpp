#include "MyException.h"

ValidateException::ValidateException(const string& msg) : OfertaException{}, msg{ msg } {}

const char* ValidateException::what() const throw() {
	return msg.c_str();
}

const char* OfertaExistaInCos::what() const throw() {
	return "Oferta deja exista in cos!";
}

const char* PozitieInvalida::what() const throw() {
	return "Pozitia nu este valida!";
}

const char* OfertaIdentica::what() const throw() {
	return "Nu se pot adauga 2 oferte identice";
}

const char* OptiuneSort::what() const throw() {
	return "Optiunea nu exista!";
}

const char* OfertaNuExista::what() const throw() {
	return "Ofera nu exista!";
}

const char* RepositoryGol::what() const throw() {
	return "Repository-ul nu contine elemente!";
}

const char* NuExistaOptiune::what() const throw() {
	return "Nu exista optiunea introdusa";
}

FileNotOpen::FileNotOpen(const string& msg) : RepoException{}, msg{ msg } {}

const char* FileNotOpen::what() const throw() {
	return msg.c_str();
}

const char* NuMaiSuntOperatiiUndo::what() const throw() {
	return "Nu mai exista operatii pentru a face undo";
}
