#include "jsonClass.h"

json jsonClass::convertToJson(char arr[])
{
    return json::parse(arr);					
}

