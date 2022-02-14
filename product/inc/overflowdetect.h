#pragma once

#include <iostream>
#include <limits>

// 参考：https://www.jpcert.or.jp/sc-rules/c-int32-c.html

template <class T> bool overflow_addition(T a, T b) {
    bool return_value = false;
    if(((b > 0) && (a > (std::numeric_limits<T>::max() - b))) || ((b < 0) && (a < (std::numeric_limits<T>::min() - b)))){
        return_value = true;
    }
    return return_value;
}

template <class T> bool overflow_subtraction(T a, T b) {
    bool return_value = false;
    if(((b > 0) && (a < (std::numeric_limits<T>::min() + b))) || ((b < 0) && (a > (std::numeric_limits<T>::max() + b)))){
        return_value = true;
    }
    return return_value;
}

template <class T> bool overflow_multiplication(T a, T b) {
    bool return_value = false;

    if((a > 0) && (b > 0) && (a > (std::numeric_limits<T>::max() / b))){
        return_value = true;
    }else if((a > 0) && (b < 0) && (b < (std::numeric_limits<T>::min() / a))){
        return_value = true;
    }else if((a < 0) && (b > 0) && (a < (std::numeric_limits<T>::min() / b))){
        return_value = true;
    }else if((a < 0) && (b < 0) && (b < (std::numeric_limits<T>::max() / a))){
        return_value = true;
    }
    return return_value;
}

template <class T> bool overflow_division(T a, T b) {
    bool return_value = false;
    if((b == 0) || ((a == std::numeric_limits<T>::min()) && (b == -1))){
        return_value = true;
    }
    return return_value;
}