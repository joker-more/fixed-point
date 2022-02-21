#include <iostream>
#include <iomanip>
#include "fixedpoint8.h"

int main(){
    fixedpoints::fixedpoint8 construct(12.25);
    std::cout << std::fixed << std::setprecision(2) << construct.getFixedpoint() << std::endl;
    return 0;
}