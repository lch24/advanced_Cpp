#include "../include/act.h"
#include "../include/observe.h"
#include "../include/analyze.h"
#include "../include/config.h"
#include <iostream>

bool execAction()
{
    Action bestMove=analyzeBestAction();

    if(bestMove==Action::attack)
    {
        std::cout<<"Defect is attacking!"<<std::endl;
        std::cout<<"Defect is attacking!"<<std::endl;
    }
    else if(bestMove==Action::defent)
    {
        std::cout<<"Defect is defentfing!"<<std::endl;
        std::cout<<"Defect is defentfing!"<<std::endl;
    }
    else
    {
        std::cout<<"Defect is doing something!"<<std::endl;
    }
    return 0;

}