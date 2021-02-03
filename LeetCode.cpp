// LeetCode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "day1_two_sum.hpp"
#include "day2_add_two_numbers.hpp"
#include "day4_median_of_two_sorted.hpp"
#include "day5_longgest_palindromic.hpp"


#include "day8_string_to_integer.hpp"
#include "day10_regular_expression.hpp"
#include "day14_longest_common_prefix.hpp"
#include "day15_3sum.hpp"

#include "day17_letter_combinations.hpp"
#include "day18_four_sum.hpp"
#include "day19_remove_Nth_from_end.hpp"
#include "day20_vaild_parentheses.hpp"
#include "day21_merge_two_sorted_lists.hpp"
#include "day22_generate_parentheses.hpp"
#include "day23_merge_k_sorted_lists.hpp"
#include "day25_reverse_nodes_in_k-group.hpp"

#include "day46_premutations.hpp"

#include "day50_my_pow.hpp"
#include "day57_insert_interval.hpp"

#include "day63_unique_pathII.hpp"
#include "day64_minimum_path_sum.hpp"
#include "day66_plus_one.hpp"
#include "day67_add_binary.hpp"

#include "day71_simplify_path.hpp"
#include "day92_reverse_between.hpp"

#include "day148_sort_list.hpp"
#include "day160_getIntersectionNode.hpp"

#include "day215_find_Kth_largest.hpp"
#include "day695_max_area_of_island.hpp"

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

#include<iostream>
#include<list>

int main()
{
    //test_case();
    //test_day2();
    //test_day4();
    //test_day5();
    //test_day8();
    //test_day10();
    //test_day14();
    //test_day15();
    //test_day57();
    //test_day63();
    //test_day64();

    //test_day66();
    //test_day67();

    //test_day71();
	test_day92();
    //test_day148();
    //test_day160();
    //test_day215();
    //test_day695();

    return 0;
}
