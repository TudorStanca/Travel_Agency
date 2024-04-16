#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Tests.h"
#include "Ui.h"

// de facut cu find_if
// de modificat ofertele din cos daca sunt sterse/modificate in repo
// de adaugat specificatii noi
// de facut meniul mai frumos

void run_program() {

    Tests teste;
    teste.run_all_tests();

    //Ui ui;
    //ui.run();

}

int main()
{
    run_program();
    _CrtDumpMemoryLeaks();

    return 0;
}