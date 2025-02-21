#include "Library.h"

int main()
{
    CLibrary library;

    library.Input();
    library.Delete();

    library.Output();

    library.SortYear();

    library.SortCount();

    return 0;
}