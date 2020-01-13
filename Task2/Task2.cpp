#include "VintagePort.h"

int main()
{
    VintagePort bottle("Yellow Tail", 20, "Kangoo", 1870);
    cout << bottle;
    VintagePort bottle2;
    bottle2 = bottle;
    cout << bottle2;
}