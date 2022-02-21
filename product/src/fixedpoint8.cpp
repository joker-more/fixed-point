#include "fixedpoint8.h"

/**
 * @brief Construct a new fixedpoints::fixedpoint8::fixedpoint8 object.
 * 
 */
fixedpoints::fixedpoint8::fixedpoint8()
:_fixedpoint(0){
}

/**
 * @brief Construct a new fixedpoints::fixedpoint8::fixedpoint8 object.
 * 
 * @param [int64_t] fixedpoint 
 */
fixedpoints::fixedpoint8::fixedpoint8(int64_t fixedpoint)
:_fixedpoint(fixedpoint){
}

/**
 * @brief Construct a new fixedpoints::fixedpoint8::fixedpoint8 object.
 * 
 * @param [double] floatingpoint 
 */
fixedpoints::fixedpoint8::fixedpoint8(double floatingpoint)
:_fixedpoint(0){
    _fixedpoint = (int64_t)(floatingpoint * (1 << fixedpoints::DecimalPointBit8));
}

/**
 * @brief Destroy the fixedpoints::fixedpoint8::fixedpoint8 object.
 * 
 */
fixedpoints::fixedpoint8::~fixedpoint8(){
}

/**
 * @brief Get fixedpoint(int64_t).
 * 
 * @return int64_t 
 */
int64_t fixedpoints::fixedpoint8::getFixedpoint(){
    return _fixedpoint;
}

/**
 * @brief Get floatingpoint(double).
 * 
 * @return double
 */
double fixedpoints::fixedpoint8::getFloatingpoint(){
    double return_value = (double)((double)_fixedpoint / (double)(1 << fixedpoints::DecimalPointBit8));
    return return_value;
}

/**
 * @brief print floatingpoint(double).
 * @details If you want to specify the number of floating-point digits, use std::setprecision.
 * @return void
 */
void fixedpoints::fixedpoint8::printFloatingpoint(){
    std::cout << this->getFloatingpoint() << std::endl;
    return;
}

/**
 * @brief addition operator.
 * 
 * @param op 
 * @return fixedpoints::fixedpoint8 
 */
fixedpoints::fixedpoint8 fixedpoints::fixedpoint8::operator+ (fixedpoints::fixedpoint8& op){
    fixedpoints::fixedpoint8 return_class;
    if(!overflow_addition(this->getFixedpoint(), op.getFixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getFixedpoint() + op.getFixedpoint()));
    }
    return return_class;
}

/**
 * @brief subtraction operator.
 * 
 * @param op 
 * @return fixedpoints::fixedpoint8 
 */
fixedpoints::fixedpoint8 fixedpoints::fixedpoint8::operator- (fixedpoints::fixedpoint8& op){
    fixedpoints::fixedpoint8 return_class;
    if(!overflow_subtraction(this->getFixedpoint(), op.getFixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getFixedpoint() - op.getFixedpoint()));
    }
    return return_class;
}

/**
 * @brief multiplication operator.
 * 
 * @param op 
 * @return fixedpoints::fixedpoint8 
 */
fixedpoints::fixedpoint8 fixedpoints::fixedpoint8::operator* (fixedpoints::fixedpoint8& op){
    fixedpoints::fixedpoint8 return_class;
    if(!overflow_multiplication(this->getFixedpoint(), op.getFixedpoint())){
        int64_t fixedpoint = (this->getFixedpoint() * op.getFixedpoint()) >> fixedpoints::DecimalPointBit8;
        return_class = fixedpoints::fixedpoint8(fixedpoint);
    }
    return return_class;
}

/**
 * @brief division operator.
 * 
 * @param op 
 * @return fixedpoints::fixedpoint8 
 */
fixedpoints::fixedpoint8 fixedpoints::fixedpoint8::operator/ (fixedpoints::fixedpoint8& op){
    fixedpoints::fixedpoint8 return_class;
    if(!overflow_division(this->getFixedpoint(), op.getFixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getFixedpoint() << fixedpoints::DecimalPointBit8) / op.getFixedpoint());
    }
    return return_class;
}

/**
 * @brief equation operator.
 * 
 * @param op 
 * @return true 
 * @return false 
 */
bool fixedpoints::fixedpoint8::operator== (fixedpoints::fixedpoint8& op){
    bool return_value = false;
    if(this->getFixedpoint() == op.getFixedpoint()){
        return_value = true;
    }
    return return_value;
}

/**
 * @brief not equation operator.
 * 
 * @param op 
 * @return true 
 * @return false 
 */
bool fixedpoints::fixedpoint8::operator!= (fixedpoints::fixedpoint8& op){
    bool return_value = false;
    if(this->getFixedpoint() != op.getFixedpoint()){
        return_value = true;
    }
    return return_value;
}