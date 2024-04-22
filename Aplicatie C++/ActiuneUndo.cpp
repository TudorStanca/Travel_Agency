#include "ActiuneUndo.h"

UndoAdauga::UndoAdauga(Repository& repository, const Oferta& oferta) : ActiuneUndo{}, repository{ repository }, oferta_adaugata{ oferta } {}

void UndoAdauga::doUndo() {
	repository.sterge_oferta(repository.cauta_element(oferta_adaugata.get_denumire()));
}

UndoSterge::UndoSterge(Repository& repository, const Oferta& oferta, const int& pozitie) : ActiuneUndo{}, repository{ repository }, oferta_stearsa{ oferta }, pozitie{ pozitie } {}

void UndoSterge::doUndo() {
	repository.adauga_oferta_pe_pozitie(oferta_stearsa, pozitie);
}

UndoModifica::UndoModifica(Repository& repository, const Oferta& oferta, const int& pozitie) : ActiuneUndo{}, repository{ repository }, oferta_nemodificata{ oferta }, pozitie{ pozitie } {}

void UndoModifica::doUndo() {
	repository.modifica_oferta(oferta_nemodificata, pozitie);
}
