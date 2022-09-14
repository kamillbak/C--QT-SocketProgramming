#include "communication.h"


void Communication::communicateWithGUI()
{
    s1->createSocket();

    while(1)
    {
        s1->acceptClient();
    
        while(1)
        {
            s1->readBuffer(buffer);

            std::cout<< buffer << std::endl;

            messageKW = e1.Decrypt(buffer);

            std::cout << messageKW << std::endl; 
            std::cout <<std::endl; 
        }
    }
}

// create socket

// loop 1 
    
//     accept client

//     loop 2 

//          read buffer 
        
//          Decrypt () 
//          {
//             konwert to json 

//             create string 

//          }