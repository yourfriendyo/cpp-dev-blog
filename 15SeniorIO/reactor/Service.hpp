#pragma once
#include "Reactor.hpp"

int Recver(Event* evp)
{
    std::cout << "Recver Callback has been called!" << std::endl;

}

int Sender(Event* evp)
{
    std::cout << "Sender Callback has been called!" << std::endl;

}

int Errorer(Event* evp)
{
    std::cout << "Errorer Callback has been called!" << std::endl;

}
