#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Tests.h"
#include "Ui.h"

// de testat undo

void run_program() {

    Tests teste{};
    teste.run_all_tests();

    //Repository repository{};
    //RepoToFile repository{"Oferte.txt"};
    //Cos cos{};
    //Service service{ repository, cos };
    //Ui ui{service};
    //ui.run();

}

int main()
{
    run_program();
    _CrtDumpMemoryLeaks();

    return 0;
}