#pragma once

#include <cstdint>
#include "overflowdetect.h"

/**
 * @brief Class for handling fixed points.
 * 
 */

namespace fixedpoints {
    const int8_t DecimalPointBit8 = 8;
    class fixedpoint8{
        private:
            int64_t _fixedpoint;

        public:
            fixedpoint8();
            fixedpoint8(int64_t fixedpoint);
            fixedpoint8(double floatingpoint);
            ~fixedpoint8();
            int64_t getfixedpoint();
            fixedpoint8 operator+ (fixedpoint8& op);
            fixedpoint8 operator- (fixedpoint8& op);
            fixedpoint8 operator* (fixedpoint8& op);
            fixedpoint8 operator/ (fixedpoint8& op);
            bool operator== (fixedpoint8& op);
            bool operator!= (fixedpoint8& op);
    };
}