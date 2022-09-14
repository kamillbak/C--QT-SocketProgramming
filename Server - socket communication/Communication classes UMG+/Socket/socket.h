// Class socket is Singleton
// Task of this class is to communicat 
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


// #include "json.hpp"
// using json = nlohmann::json;

#define PORT 8080

class Socket {
  private:
   Socket(){}; 
  ~Socket(){};

  protected:
  static Socket* com_;

  public :

  char buffer[1024] = { 0 }; // comunication buffer 

  // socket attributes
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  // methods 
  static Socket *getInstance();
  void createSocket();
  int acceptClient();
  //int sendLOGasJSON(json logJSON);

  void readBuffer( char *buff); 
};