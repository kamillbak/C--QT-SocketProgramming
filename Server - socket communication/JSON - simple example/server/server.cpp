// Server side C/C++ program to demonstrate Socket
// programming
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

#include <cstring>
#include "json.hpp"

#define PORT 8080

//using namespace std;
using json = nlohmann::json;

double serverArray1[] = { 0, 0, 0, 0};
int sizeArray1 =0 ;

double serverArray2[] = { 0, 0, 0, 0};
int sizeArray2 = 0;

void fcnSet1( double arr1[], int size)
{
	sizeArray1 = size;
	std::cout << "-------------------------------------------" << std::endl;
	for( int i=0; i<size; i++)
	{
		serverArray1[i] = arr1[i];
		std::cout << "I am setting array 1 elment " << i << " :" << serverArray1[i] << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void fcnSet2( double arr2[], int size)
{
	sizeArray2 = size;
	std::cout << "-------------------------------------------" << std::endl;
	for( int i=0; i<size; i++)
	{
		serverArray2[i] = arr2[i];
		std::cout << "I am setting array 2 elment " << i << " :" << serverArray2[i] << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void addToV1(double x1)
{
	for (int i=0; i< sizeArray1; i++)
	{
		serverArray1[i] = serverArray1[i] + x1; 
	}
}

void addToV2(double x2)
{
	for (int i=0; i< sizeArray2; i++)
	{
		serverArray2[i] = serverArray2[i] + x2; 
	}
}

void showArr1()
{
	for (int i=0; i< sizeArray1; i++)
	{
		std::cout << "Element arr1: " << serverArray1[i] << std::endl;
	}

}

void showArr2()
{
	for (int i=0; i< sizeArray2; i++)
	{
		std::cout << " Element arr2: " <<  serverArray2[i] << std::endl;
	}
}


int main(int argc, char const* argv[])
{
	char x,x_; //reciving 
	int return_status; 
	
	char y; //to send
	int converted_number;

	bool keepWorking = true; //variable for loop 
	
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[2048] = { 0 };

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

	while(1){		
			 
			//accept first connection request from queue
			if ((new_socket
				= accept(server_fd, (struct sockaddr*)&address,
						(socklen_t*)&addrlen))
				< 0) {
				perror("accept");
				exit(EXIT_FAILURE);
			}
			else std::cout << "accepted. " << std::endl;	
			
			
			keepWorking = true; 
			int iLicznik=0; // do testu 
			bool chengeCorrect = true; 
			
			while(keepWorking){	

				memset(buffer,0,2048); // clearing buffer 

				// Read JSONstring from client
				if(read(new_socket, &buffer, sizeof(buffer)) < 0)
				{
					std::cout << "ERROR. Can't read data" << std::endl; 		
				}
				else
				{
					std::cout << "JSON: " << buffer << std::endl; 
				}

				// Create JSON object and take value from buffer 
				json obj = json::parse(buffer);
					
				// "SWITCH" with diffren types of behavior
				if(obj["type"] == "arrayDouble1")
				{
					iLicznik++; // test

					if (iLicznik%3 ==2)// test
					{// test
						std::cout << "Failed. (test)" << std::endl;
						chengeCorrect = false ;// test
					}// test
					else // test
					{// test
						chengeCorrect = true; // test
						std::vector<double> vec; //create vector
						obj["value"].get_to(vec); // array from JSOn -> vector

						double * arr1 = &vec[0]; // vector -> array

						for (int i = 0; i < obj["value"].size(); i++){
							std::cout << arr1[i] << std::endl;
						}					
						fcnSet1(arr1,obj["value"].size());
						sizeArray1 =obj["value"].size();
					}// test

				}
				else if (obj["type"] == "arrayDouble2")
				{		
					iLicznik++;// test 
					if (iLicznik%3 ==2)// test
					{// test
						std::cout << "Failed. (test)" << std::endl;// test
						chengeCorrect = false ;// test
					}
					else // test
					{// test
						chengeCorrect = true; 	// test		
						std::vector<double> vec; //create vector
						obj["value"].get_to(vec); // array from JSOn -> vector

						double * arr2 = &vec[0]; // vector -> array

						for (int i = 0; i < obj["value"].size(); i++){
							std::cout << arr2[i] << std::endl;
						}					
						fcnSet2(arr2,obj["value"].size());
						sizeArray2 = obj["value"].size();
					}// test
				}
				else if (obj["type"] == "addToV1")
				{
					iLicznik++; // test
					if (iLicznik%3 ==2)// test
					{// test
						std::cout << "Failed. (test)" << std::endl;// test
						chengeCorrect = false ;// test
					}// test
					else // test
					{		// test
						chengeCorrect = true; 	// test		
						// take double form json
						double x1 = obj["vDouble"];
							
						// add double to array 1	
						addToV1(x1);
						showArr1();
					}		// test			
				}
				else if (obj["type"] == "addToV2")
				{
					iLicznik++; // test
					if (iLicznik%3 ==2)// test
					{// test
						std::cout << "Failed. (test)" << std::endl;// test
						chengeCorrect = false ;// test
					}// test
					else 
					{
						chengeCorrect = true; 
						// take double form json
						double x2 = obj["vDouble"];

						// add double to array 2
						addToV2(x2);
						showArr2();
					}

				}
				else
				{
					std::cout << "----" << obj["type"] << std::endl;
				}
					
				
					
				// SEND TWO ARRAYS BACK

				// send arrays after
				json response = {
      				{"type", "TwoArrays"},
      				{"array1",""},
					{"size1",0},
					{"array2",""},
					{"size2",0},
					{"flag",""}
   				 };

				if(!chengeCorrect)// test
				{
					response["flag"] = "NotOK";// test
					std::cout<< " NOT OK "; // test
				}// test
				else // test
				{// test
					response["flag"] = "OK";
				}// test

				// put arrays into json
				response["array1"] = serverArray1;
				response["array2"] = serverArray2; 

				//and sizes
				response["size1"] = sizeArray1;
				response["size2"] = sizeArray2;

				std::cout << "Sending data back"<< std::endl; 
				std::cout << response << std::endl;
				// Convert JSON to string before sending vai socket 
				std::string dataToSend1 = response.dump();

				// SEND 
  				memset(&buffer, 0, sizeof(buffer));//clear the buffer
 				strcpy(buffer, dataToSend1.c_str()); //converting string to char []

				std::cout << "Sending data back 2"<< std::endl; 
				int sendCheck = send(new_socket, (char*)&buffer, strlen(buffer), 0);
				if(sendCheck < 0) 
				{	
					std::cout << "ERROR: Can't send data via socket" << std::endl; 
				}										
			}
	}

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}
