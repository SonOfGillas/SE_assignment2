#include "StateInitial.h"

StateName StateInitial::name() {
    return StateName::Initial;
}

StateInitial::StateInitial(int carWashed):State(carWashed) {}

bool StateInitial::goNext() {
    return true;
}

StateInitial::~StateInitial() {}