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

TEST(FixedPoint8, getFixedpoint){
    int64_t test_parameter = 1111111111;
    fixedpoints::fixedpoint8 test(test_parameter);
    ASSERT_EQ(test.getFixedpoint(), test_parameter);
}

TEST(FixedPoint8, getFloatingpoint){
    double constructor_parameter = 1.1;
    fixedpoints::fixedpoint8 test(constructor_parameter);
 
    int64_t pseudo_fixedpoint_parameter = (int64_t)(constructor_parameter * (1 << fixedpoints::DecimalPointBit8));
 
    double test_parameter = (double)((double)pseudo_fixedpoint_parameter / (double)(1 << fixedpoints::DecimalPointBit8));
 
    ASSERT_DOUBLE_EQ(test.getFloatingpoint(), test_parameter);
}

TEST(FixedPoint8, printFloatingpoint){
    double constructor_parameter = 1.1;
    fixedpoints::fixedpoint8 test(constructor_parameter);
 
    int64_t pseudo_fixedpoint_parameter = (int64_t)(constructor_parameter * (1 << fixedpoints::DecimalPointBit8));
 
    double test_parameter = (double)((double)pseudo_fixedpoint_parameter / (double)(1 << fixedpoints::DecimalPointBit8));

    std::cout << std::fixed << std::setprecision(6);
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    test.printFloatingpoint();

    std::cout.rdbuf(p_cout_streambuf);

    std::string print_double_value = oss.str();
    print_double_value.erase(--print_double_value.end());

    ASSERT_STREQ(print_double_value.c_str(), std::to_string(test_parameter).c_str());
}

TEST(FixedPoint8, operator_addition){
    int64_t test_parameter1 = 1111111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 1111111111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getFixedpoint(), (test_parameter1 + test_parameter2));
}

TEST(FixedPoint8, operator_addition_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_addition_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 + test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_subtraction){
    int64_t test_parameter1 = 1111111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 111111111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getFixedpoint(), (test_parameter1 - test_parameter2));
}

TEST(FixedPoint8, operator_subtraction_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_subtraction_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 - test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication){
    int64_t test_parameter1 = 11111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 11111;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getFixedpoint(), ((test_parameter1 * test_parameter2) >> fixedpoints::DecimalPointBit8));
}

TEST(FixedPoint8, operator_multiplication_overflow_first){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_second){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_third){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_multiplication_overflow_fourth){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 * test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_division){
    int64_t test_parameter1 = 111111;
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 2;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getFixedpoint(), ((test_parameter1 << fixedpoints::DecimalPointBit8) / test_parameter2));
}

TEST(FixedPoint8, operator_division_overflow_left){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::max();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = 0;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
}

TEST(FixedPoint8, operator_division_overflow_right){
    int64_t test_parameter1 = std::numeric_limits<int64_t>::min();
    fixedpoints::fixedpoint8 test1(test_parameter1);

    int64_t test_parameter2 = -1;
    fixedpoints::fixedpoint8 test2(test_parameter2);

    fixedpoints::fixedpoint8 test3 = test1 / test2;

    ASSERT_EQ(test3.getFixedpoint(), 0);
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