#include "../include/act.h"
#include "../include/analyze.h"
#include "../include/observe.h"
#include "../include/delay.h"
#include <iostream>

int main()
{
    int dummy=Delay<10000>::value;
    execAction();
    return 0;
}