#include "Tests.h"
#include "Ui.h"
#include "Oferta.h"

// validare date de intrare (sa nu crape aplicatia)
// de facut ui-ul sa arate mai frumos

int main()
{
    Tests teste;
    teste.run_all_tests();

    Ui ui;
    ui.run();

    return 0;
}