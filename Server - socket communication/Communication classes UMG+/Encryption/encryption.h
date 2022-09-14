// Task of this class is to encrypt and dicrypt json files 
#include <iostream>
#include <string.h>
#include "../jsonClass/jsonClass.h"
using json = nlohmann::json;

class Encryption {
  
  private: 

  std::string keyWordAndValues; // string "KeyWord + v1 + ... "

  public :
  
  // metohds
  std::string Decrypt(char buff[]); // decrypt char[] -> " KeyWrod + v1 + ..."
  //std::string getKeyWord();
  std::string int_array_to_string(double double_array[], int size_of_array); // method I use for double arays in JSON 
  void Encrypt(); // TO WRITE 
};