#include "encryption.h"



std::string Encryption::int_array_to_string(double double_array[], int size_of_array) {
  std::string returnstring = "";
  for (int temp = 0; temp < size_of_array; temp++)
  {
    returnstring += std::to_string(double_array[temp]);
    returnstring += " ";
  }
  
  return returnstring;
}

std::string Encryption::Decrypt(char buff[])
{
    
    // konwert to json 
    json j = jsonClass::convertToJson(buff);

    
    this->keyWordAndValues = ""; // clear string 
    
    
    // IF with every possibility  ///////////////////////////////////////

    if(j["type"] == "arrayDouble1")
    {
        this->keyWordAndValues += (j["type"]); //Keyword
        this->keyWordAndValues += " ";
       
        // CONVERT "ARRAY" FROM JSON TO ARRAY
       	std::vector<double> vec; //create vector
		j["value"].get_to(vec); // array from JSOn -> vector
	    double * arr1 = &vec[0]; // vector -> array
        
        // ARRAY SIZE
        int size = j["size"];

        // ARRAY TO STRING 
        std::string s = int_array_to_string(arr1, size);

        this->keyWordAndValues += s;   
    }
    else if (j["type"] == "arrayDouble2")
    {
        this->keyWordAndValues += j["type"]; //Keyword
        this->keyWordAndValues += " ";
		 
        // SAME AS ABOVE 
		std::vector<double> vec; //create vector
		j["value"].get_to(vec); // array from JSOn -> vector
		double * arr1 = &vec[0]; // vector -> array   
        int size = j["size"];
        std::string s = int_array_to_string(arr1, size);
        this->keyWordAndValues += s;
    }
    else if (j["type"] == "addToV1")
    {
        this->keyWordAndValues += (j["type"]); // Keyword
        this->keyWordAndValues += " ";

        double tmpV =j["vDouble"];
        this->keyWordAndValues += std::to_string(tmpV); //value
    }
    else if (j["type"] == "addToV2")
    {
        this->keyWordAndValues += (j["type"]); // Keyword
        this->keyWordAndValues += " ";

        double tmpV =j["vDouble"];
        this->keyWordAndValues += std::to_string(tmpV); //value
    }
    else
    {
        std::cout << "Unknown type of JASON structure" << std::endl; 
    }

     // END OF IF  ///////////////////////////////////////

    return this->keyWordAndValues; 
}

// std::string Encryption::getKeyWord()
// {
//     return this->keyWordAndValues; 
// }




