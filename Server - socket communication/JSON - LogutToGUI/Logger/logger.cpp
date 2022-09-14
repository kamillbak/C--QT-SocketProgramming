#include "logger.h"
#include "string.h"

void Logger::sendLogs()
{
    Communication* c1 = Communication::getInstance(); // using singleton

    json LogOut = {
		{"type", "log"},
		{"message", "Message X "}
	};
       
    for( int i = 1; i<11; i++)
    {

        LogOut["message"] = "Message " + std::to_string(i);
        
        std::cout << LogOut["message"] << std::endl;
        
        c1->sendLOGasJSON(LogOut);	// use function from singleton
    }	
}

