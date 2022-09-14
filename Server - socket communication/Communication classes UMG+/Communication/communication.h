#include <iostream>
#include "string.h"

#include "../Encryption/encryption.h"
#include "../Socket/socket.h"



class Communication {


Socket * s1 = Socket::getInstance();
Encryption e1;


std::string messageKW; 

public:
    char buffer[1024];

   // Communication(); //constructor

    void communicateWithGUI();

    void execute(); // TO WRITE

};
