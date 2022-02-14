#include <iostream>
#include <gtest/gtest.h>
#include "fixedpoint8.h"

TEST(FixedPoint8, constructor){
    ASSERT_NO_THROW(
        fixedpoints::fixedpoint8 test;
    );
}

TEST(FixedPoint8, constructor_withint64t_min){
    int64_t test_parameter = std::numeric_limits<int64_t>::min();
    ASSERT_NO_THROW(
        fixedpoints::fixedpoint8 test(test_parameter);
    );
}

TEST(FixedPoint8, constructor_withint64t_max){
    int64_t test_parameter = std::numeric_limits<int64_t>::max();
    ASSERT_NO_THROW(
        fixedpoints::fixedpoint8 test(test_parameter);
    );
}

TEST(FixedPoint8, constructor_withdouble_min){
    double test_parameter = std::numeric_limits<double>::min();
    ASSERT_NO_THROW(
        fixedpoints::fixedpoint8 test(test_parameter);
    );
}

TEST(FixedPoint8, constructor_withdouble_max){
    double test_parameter = std::numeric_limits<double>::max();
    ASSERT_NO_THROW(
        fixedpoints::fixedpoint8 test(test_parameter);
    );
}

TEST(FixedPoint8, getfixedpoint){
    int64_t test_parameter = 1111111111;
    fixedpoints::fixedpoint8 test(test_parameter);
    ASSERT_EQ(test.getfixedpoint(), test_parameter);
}

TEST(FixedPoint8, operator_addition){
    int64_t test_parameter1 = 1111111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 1111111111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getfixedpoint(), (test_parameter1 + test_parameter2));
}

TEST(FixedPoint8, operator_addition_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_addition_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_subtraction){
    int64_t test_parameter1 = 1111111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 111111111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getfixedpoint(), (test_parameter1 - test_parameter2));
}

TEST(FixedPoint8, operator_subtraction_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_subtraction_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication){
    int64_t test_parameter1 = 11111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 11111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getfixedpoint(), ((test_parameter1 * test_parameter2) >> fixedpoints::DecimalPointBit8));
}

TEST(FixedPoint8, operator_multiplication_overflow_first){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_second){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_third){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_fourth){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_division){
    int64_t test_parameter1 = 111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 2;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getfixedpoint(), ((test_parameter1 << fixedpoints::DecimalPointBit8) / test_parameter2));
}

TEST(FixedPoint8, operator_division_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 0;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_division_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = -1;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getfixedpoint(), 0);
}

TEST(FixedPoint8, operator_equation){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    ASSERT_TRUE((test1 == test2));
}

TEST(FixedPoint8, operator_not_equation){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    ASSERT_TRUE((test1 != test2));
}