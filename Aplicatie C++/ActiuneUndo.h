#pragma once
#include "Oferta.h"
#include "Repository.h"

class ActiuneUndo {

public:

	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() {};

};

class UndoAdauga : public ActiuneUndo {

	Oferta oferta_adaugata;
	Repository& repository;

public:

	UndoAdauga(Repository& repository, const Oferta& oferta);

	void doUndo();

};

class UndoSterge : public ActiuneUndo {

	Oferta oferta_stearsa;
	int pozitie;
	Repository& repository;

public:

	UndoSterge(Repository& repository, const Oferta& oferta, const int& pozitie);

	void doUndo();

};

class UndoModifica : public ActiuneUndo {

	Oferta oferta_nemodificata;
	int pozitie;
	Repository& repository;

public:

	UndoModifica(Repository& repository, const Oferta& oferta, const int& pozitie);

	void doUndo();

};