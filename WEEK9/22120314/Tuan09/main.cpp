#define _CRT_SECURE_NO_WARNINGS
#include "CStore.h"
#include <iostream>
#include <locale>
#include <codecvt>

int main() 
{

    CStore store;

    freopen("INPUT.TXT", "r", stdin);
    store.Input();
    fclose(stdin);

    freopen("OUTPUT.TXT", "w", stdout);
    store.Output();
    fclose(stdout);

    freopen("EXPDATE.TXT", "w", stdout);
    store.ViewExpDate();
    fclose(stdout);

    freopen("BUY.TXT", "r", stdin);
    freopen("INVOICE.TXT", "w", stdout);
    store.Buy();
    fclose(stdin);
    fclose(stdout);

    freopen("QUANTITY.TXT", "w", stdout);
    store.ViewQuantity();
    fclose(stdout);

  /*  freopen("CON", "r", stdin);
    store.Delete();
 */
    freopen("OUTPUT.TXT", "w", stdout);
    store.Output();
    fclose(stdout);

    freopen("CON", "w", stdout);
    return 0;
}