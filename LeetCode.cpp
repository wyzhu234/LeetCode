// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "day1_two_sum.hpp"
#include "day2_add_two_numbers.hpp"
#include "day4_median_of_two_sorted.hpp"
#include "day5_longgest_palindromic.hpp"


#include "day8_string_to_integer.hpp"
#include "day10_regular_expression.hpp"


#include "day17_letter_combinations.hpp"
#include "day18_four_sum.hpp"
#include "day19_remove_Nth_from_end.hpp"
#include "day20_vaild_parentheses.hpp"

void one_error()
{
    string s1 = string("string1");
    string s2 = string("string2");
    const char *p1 = s1.substr(1).data();
    const char *p2 = s2.substr(1).data();
    cout << p1 << p2 << endl;
}

void fun(double **p, int m, int n)
{
    //*((double*)array + n*i + j);
    double temp = *((double *)p + 1);
    cout << temp << endl;
}

void test_2darry_2p()
{
    double a[][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
    double **p = (double **)a;
    double **b = reinterpret_cast<double **>(a);
    fun(b, 3, 3);
}



int main()
{
    //test_case();
    //test_day2();
    //test_day4();
    //test_day5();
    //test_day8();
    //test_day10();
    test_day20();

    return 0;
}

