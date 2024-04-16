#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Tests.h"
#include "Ui.h"
#include "Oferta.h"

int main()
{
    Tests teste;
    teste.run_all_tests();

    Ui ui;
    ui.run();

    _CrtDumpMemoryLeaks();

    return 0;
}