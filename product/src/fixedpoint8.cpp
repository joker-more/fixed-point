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
int64_t fixedpoints::fixedpoint8::getfixedpoint(){
    return _fixedpoint;
}

/**
 * @brief addition operator.
 * 
 * @param op 
 * @return fixedpoints::fixedpoint8 
 */
fixedpoints::fixedpoint8 fixedpoints::fixedpoint8::operator+ (fixedpoints::fixedpoint8& op){
    fixedpoints::fixedpoint8 return_class;
    if(!overflow_addition(this->getfixedpoint(), op.getfixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getfixedpoint() + op.getfixedpoint()));
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
    if(!overflow_subtraction(this->getfixedpoint(), op.getfixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getfixedpoint() - op.getfixedpoint()));
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
    if(!overflow_multiplication(this->getfixedpoint(), op.getfixedpoint())){
        int64_t fixedpoint = (this->getfixedpoint() * op.getfixedpoint()) >> fixedpoints::DecimalPointBit8;
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
    if(!overflow_division(this->getfixedpoint(), op.getfixedpoint())){
        return_class = fixedpoints::fixedpoint8((this->getfixedpoint() << fixedpoints::DecimalPointBit8) / op.getfixedpoint());
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
    if(this->getfixedpoint() == op.getfixedpoint()){
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
    if(this->getfixedpoint() != op.getfixedpoint()){
        return_value = true;
    }
    return return_value;
}