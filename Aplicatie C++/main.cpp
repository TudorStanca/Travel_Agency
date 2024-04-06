#include "Tests.h"
#include "Ui.h"

// de facut validari in service
// de facut functie de cautare generica cu template in repository
// verificare unicitate a denumirei
// validare date de intrare (sa nu crape aplicatia)
// de facut ui-ul sa arate mai frumos

int main()
{
    Tests teste;
    teste.run_all_tests();

    //Ui ui;
    //ui.run();

    return 0;
}