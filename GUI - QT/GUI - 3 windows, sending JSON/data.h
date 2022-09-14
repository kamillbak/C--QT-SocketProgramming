#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{

private:
 Data(){};
~Data(){};

protected:

  static Data* data_;

  double * array1;
  double * array2;

public:

    static Data *getInstance();

    void setArr1Pointer(double * arr);
    void setArr2Pointer(double * arr);

    double * getArray1Pointer();
    double * getArray2Pointer();

};

#endif // DATA_H
