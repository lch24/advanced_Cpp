#include "../include/config.h"
#include "../include/observe.h"
#include "../include/analyze.h"
#include <iostream>
#include <random>

Action analyzeBestAction()
{
    //初始化随机数发生器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1,100);

    int attackValue=distrib(gen); //随机给予攻击力
    std::cout<<"Defect is observing opponent's blood value..."<<std::endl;
    int bloodValue=observeOpponent();//观察对手的血量
    if(attackValue>=bloodValue)//判断是否执行攻击
        return Action::attack;

    return Action::defent;


}