#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include "../Util.h"

class Instance{
public:
    Instance();
    enum class Status {FORWARD, BACKWARD};

    void changeVerse();
    Status getVerse();
private:
    Status verse;
};

#endif
