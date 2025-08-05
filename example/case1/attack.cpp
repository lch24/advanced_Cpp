#include<iostream>

#define STRENGTH 10

void attack()
{
    std::cout<<"Defect is attacking!"<<std::endl;
    std::cout<<"Defect causes "<<STRENGTH<<" damage!"<<std::endl;
    std::cout<<"Defect ended the attack"<<std::endl;
}

int main()
{
    attack();
    return 0;
}