#include <iostream>
#include <string.h>

#include "../json.hpp"

using json = nlohmann::json;

class jsonClass {

private:
    json j;

public:
    static json convertToJson(char arr[]);
    
};