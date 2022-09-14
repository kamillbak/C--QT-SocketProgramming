#include <iostream>

#include "Logger/logger.h"


int main()
{
    Communication *c1 = Communication::getInstance();
    c1->createSocket();
    c1->acceptClient();

    Logger l1; 
    l1.sendLogs();
}