#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
//#include"../data/data.h"

#include "json.hpp"

using json = nlohmann::json;


//using namespace std;

class Communication {

  private:
   Communication(){}; 
  ~Communication(){};

  protected:
    static Communication* com_;

  public:
    char buffer[1024] = { 0 }; // comunication buffer 
    char choice; //actual conversion choice 

    // socket attributes
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // methods 
    static Communication *getInstance();
    void createSocket();
    int acceptClient();
    int sendLOGasJSON(json logJSON);

  };





















  // int readChar(char &ch, int socket);

  // int readCharArray(char message[],int sizeArray, int socket);
  // int writeCharArray(char message[]);

  // int readInt(int &vInt, int socket);
  // int writeInt(int &vInt, int socket);

  // int readDouble(double &vDouble, int socket);
  // int writeDouble(double vDouble, int socket);

  // int writeDoubleArray2dim(int xSize, int ySize, double *array, int socket);
   
//   int changeArrayElement(Data &ob);
//   int getData(Data &d1);
//   int convertData(char choice, Data &d1); 
//   int sendData(Data &d1); 

