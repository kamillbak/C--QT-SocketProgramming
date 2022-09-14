#include "comSocket.h"

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

using json = nlohmann::json;


Communication* Communication::com_ = nullptr;

// Create socket
void Communication::createSocket()
{
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) // server_fd - handler, descriptor 
		== 0) {										  // AF_INET - comunication domain
		perror("socket failed");					  // SOCK_STREAM - comuniaction TCP or UDP
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET; // set data structure before binding to the socket
	address.sin_addr.s_addr = INADDR_ANY; //Local host adress 
	address.sin_port = htons(PORT);  // Port 8080 define above 

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

// accept coonection request
int Communication::acceptClient()
{
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen))< 0) 
	{
		perror("accept");
		exit(EXIT_FAILURE);
		return -1;
	}
	else{
		std::cout<<"Client accepted"<<std::endl; 
		return 1; 
	}
}

int Communication::sendLOGasJSON(json logJSON)
{
	// Convert JSON to string before sending vai socket 
	std::string dataToSend1 = logJSON.dump();

	// SEND 
  	memset(&buffer, 0, sizeof(buffer));//clear the buffer
 	strcpy(buffer, dataToSend1.c_str()); //converting string to char []

    int sendCheck = send(new_socket, (char*)&buffer, strlen(buffer), 0);
	
	read(new_socket,&buffer, sizeof(buffer));
		
	if(sendCheck <0)
	{	
		std::cout << "ERROR: Can't send data via socket" << std::endl; 
		return -1;
	}
	else return 1;
}


Communication *Communication::getInstance()
{
	// static InstanceGuard guard;
	if(com_ == nullptr)
	{
		com_ = new Communication;
	}
	return com_;
}
