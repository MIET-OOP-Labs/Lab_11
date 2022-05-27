#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"

class derived : public base{
    int bar = 57;
public:
    derived();
    int getNum() override {return bar;};
    ~derived();
};

#endif // DERIVED_H
