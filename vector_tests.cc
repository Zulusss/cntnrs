#include <gtest/gtest.h>

#include <vector>

#include "testVector.h"

TEST(Vector_constructor, case1) {
  s21::Vector<int> s21_vec_int;
  s21::Vector<double> s21_vec_double;
  s21::Vector<std::string> s21_vec_string;
  std::vector<int> vec_int;

  EXPECT_EQ(s21_vec_int.size(), vec_int.size());
  EXPECT_EQ(s21_vec_int.size(), 0U);
  EXPECT_EQ(s21_vec_int.capacity(), 0U);
  EXPECT_EQ(&s21_vec_int[0], nullptr);

  EXPECT_EQ(s21_vec_double.size(), 0U);
  EXPECT_EQ(s21_vec_double.capacity(), 0U);
  EXPECT_EQ(&s21_vec_double[0], nullptr);

  EXPECT_EQ(s21_vec_string.size(), 0U);
  EXPECT_EQ(s21_vec_string.capacity(), 0U);
  EXPECT_EQ(&s21_vec_string[0], nullptr);
}

TEST(Vector_constructor, case2) {
  s21::Vector<int> s21_vec_int(5);
  s21::Vector<double> s21_vec_double(5);
  s21::Vector<std::string> s21_vec_string(5);

  EXPECT_EQ(s21_vec_int.size(), 5U);
  EXPECT_EQ(s21_vec_int.capacity(), 5U);
  EXPECT_NE(&s21_vec_int[0], nullptr);

  EXPECT_EQ(s21_vec_double.size(), 5U);
  EXPECT_EQ(s21_vec_double.capacity(), 5U);
  EXPECT_NE(&s21_vec_double[0], nullptr);

  EXPECT_EQ(s21_vec_string.size(), 5U);
  EXPECT_EQ(s21_vec_string.capacity(), 5U);
  EXPECT_NE(&s21_vec_string[0], nullptr);
}

TEST(Vector_constructor, case3) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.size(), 4U);
  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_int[0], 1);
  EXPECT_EQ(s21_vec_int[1], 4);
  EXPECT_EQ(s21_vec_int[2], 8);
  EXPECT_EQ(s21_vec_int[3], 9);

  EXPECT_EQ(s21_vec_double.size(), 4U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_double[0], 1.4);
  EXPECT_EQ(s21_vec_double[1], 4.8);
  EXPECT_EQ(s21_vec_double[2], 8.9);
  EXPECT_EQ(s21_vec_double[3], 9.1);

  EXPECT_EQ(s21_vec_string.size(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
  EXPECT_EQ(s21_vec_string[0], "Hello");
  EXPECT_EQ(s21_vec_string[1], ",");
  EXPECT_EQ(s21_vec_string[2], "world");
  EXPECT_EQ(s21_vec_string[3], "!");

  EXPECT_EQ(s21_vec_string[0], std_vec_string[0]);
  EXPECT_EQ(s21_vec_string[1], std_vec_string[1]);
  EXPECT_EQ(s21_vec_string[2], std_vec_string[2]);
  EXPECT_EQ(s21_vec_string[3], std_vec_string[3]);
}

// TEST(Vector_constructor, case4) {
//   s21::Vector<int> s21_vec_ref_int{1, 4, 8, 9};
//   s21::Vector<int> s21_vec_res_int(s21_vec_ref_int);

//   s21::Vector<double> s21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
//   s21::Vector<double> s21_vec_res_double(s21_vec_ref_double);

//   s21::Vector<std::string> s21_vec_ref_string{"Hello", ",", "world", "!"};
//   s21::Vector<std::string> s21_vec_res_string(s21_vec_ref_string);

//   EXPECT_EQ(s21_vec_ref_int.size(), s21_vec_res_int.size());
//   EXPECT_EQ(s21_vec_ref_int.capacity(), s21_vec_res_int.capacity());
//   EXPECT_EQ(s21_vec_ref_int[0], s21_vec_res_int[0]);
//   EXPECT_EQ(s21_vec_ref_int[1], s21_vec_res_int[1]);
//   EXPECT_EQ(s21_vec_ref_int[2], s21_vec_res_int[2]);
//   EXPECT_EQ(s21_vec_ref_int[3], s21_vec_res_int[3]);

//   EXPECT_EQ(s21_vec_ref_double.size(), s21_vec_res_double.size());
//   EXPECT_EQ(s21_vec_ref_double.capacity(), s21_vec_res_double.capacity());
//   EXPECT_EQ(s21_vec_ref_double[0], s21_vec_res_double[0]);
//   EXPECT_EQ(s21_vec_ref_double[1], s21_vec_res_double[1]);
//   EXPECT_EQ(s21_vec_ref_double[2], s21_vec_res_double[2]);
//   EXPECT_EQ(s21_vec_ref_double[3], s21_vec_res_double[3]);

//   EXPECT_EQ(s21_vec_ref_string.size(), s21_vec_res_string.size());
//   EXPECT_EQ(s21_vec_ref_string.capacity(), s21_vec_res_string.capacity());
//   EXPECT_EQ(s21_vec_ref_string[0], s21_vec_res_string[0]);
//   EXPECT_EQ(s21_vec_ref_string[1], s21_vec_res_string[1]);
//   EXPECT_EQ(s21_vec_ref_string[2], s21_vec_res_string[2]);
//   EXPECT_EQ(s21_vec_ref_string[3], s21_vec_res_string[3]);
// }

TEST(Vector_constructor, case5) {
  s21::Vector<int> s21_vec_ref_int{1, 4, 8, 9};
  s21::Vector<int> s21_vec_res_int = std::move(s21_vec_ref_int);
  s21::Vector<double> s21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<double> s21_vec_res_double = std::move(s21_vec_ref_double);
  s21::Vector<std::string> s21_vec_ref_string{"Hello", ",", "world", "!"};
  s21::Vector<std::string> s21_vec_res_string = std::move(s21_vec_ref_string);

  EXPECT_EQ(s21_vec_ref_int.size(), 0U);
  EXPECT_EQ(s21_vec_ref_int.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_int.size(), 4U);
  EXPECT_EQ(s21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_int[0], 1);
  EXPECT_EQ(s21_vec_res_int[1], 4);
  EXPECT_EQ(s21_vec_res_int[2], 8);
  EXPECT_EQ(s21_vec_res_int[3], 9);

  EXPECT_EQ(s21_vec_ref_double.size(), 0U);
  EXPECT_EQ(s21_vec_ref_double.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_double.size(), 4U);
  EXPECT_EQ(s21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_double[0], 1.4);
  EXPECT_EQ(s21_vec_res_double[1], 4.8);
  EXPECT_EQ(s21_vec_res_double[2], 8.9);
  EXPECT_EQ(s21_vec_res_double[3], 9.1);

  EXPECT_EQ(s21_vec_ref_string.size(), 0U);
  EXPECT_EQ(s21_vec_ref_string.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_string.size(), 4U);
  EXPECT_EQ(s21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_string[0], "Hello");
  EXPECT_EQ(s21_vec_res_string[1], ",");
  EXPECT_EQ(s21_vec_res_string[2], "world");
  EXPECT_EQ(s21_vec_res_string[3], "!");
}

TEST(Vector_constructor, case6) {
  s21::Vector<int> s21_vec_ref_int{1, 4, 8, 9};
  s21::Vector<int> s21_vec_res_int;
  s21_vec_res_int = std::move(s21_vec_ref_int);

  s21::Vector<double> s21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<double> s21_vec_res_double;
  s21_vec_res_double = std::move(s21_vec_ref_double);

  s21::Vector<std::string> s21_vec_ref_string{"Hello", ",", "world", "!"};
  s21::Vector<std::string> s21_vec_res_string;
  s21_vec_res_string = std::move(s21_vec_ref_string);

  EXPECT_EQ(s21_vec_ref_int.size(), 0U);
  EXPECT_EQ(s21_vec_ref_int.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_int.size(), 4U);
  EXPECT_EQ(s21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_int[0], 1);
  EXPECT_EQ(s21_vec_res_int[1], 4);
  EXPECT_EQ(s21_vec_res_int[2], 8);
  EXPECT_EQ(s21_vec_res_int[3], 9);

  EXPECT_EQ(s21_vec_ref_double.size(), 0U);
  EXPECT_EQ(s21_vec_ref_double.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_double.size(), 4U);
  EXPECT_EQ(s21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_double[0], 1.4);
  EXPECT_EQ(s21_vec_res_double[1], 4.8);
  EXPECT_EQ(s21_vec_res_double[2], 8.9);
  EXPECT_EQ(s21_vec_res_double[3], 9.1);

  EXPECT_EQ(s21_vec_ref_string.size(), 0U);
  EXPECT_EQ(s21_vec_ref_string.capacity(), 0U);
  EXPECT_EQ(s21_vec_res_string.size(), 4U);
  EXPECT_EQ(s21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_string[0], "Hello");
  EXPECT_EQ(s21_vec_res_string[1], ",");
  EXPECT_EQ(s21_vec_res_string[2], "world");
  EXPECT_EQ(s21_vec_res_string[3], "!");
}

TEST(Vector_at, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.at(0), 1);
  EXPECT_EQ(s21_vec_double.at(0), 1.4);
  EXPECT_EQ(s21_vec_string.at(0), "Hello");
  EXPECT_EQ(s21_vec_string.at(0), std_vec_string.at(0));
  EXPECT_EQ(s21_vec_string.at(1), std_vec_string.at(1));
  EXPECT_EQ(s21_vec_string.at(2), std_vec_string.at(2));
  EXPECT_EQ(s21_vec_string.at(3), std_vec_string.at(3));
}

TEST(Vector_at, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};
  

  EXPECT_THROW(s21_vec_int.at(5), std::out_of_range);
  EXPECT_THROW(s21_vec_double.at(5), std::out_of_range);
  EXPECT_THROW(s21_vec_string.at(5), std::out_of_range);
  EXPECT_THROW(std_vec_string.at(5), std::out_of_range);
}

TEST(Vector_at, case3) {
  s21::Vector<int> s21_vec_int;
  s21::Vector<double> s21_vec_double;
  s21::Vector<std::string> s21_vec_string;

  EXPECT_THROW(s21_vec_int.at(5), std::out_of_range);
  EXPECT_THROW(s21_vec_double.at(5), std::out_of_range);
  EXPECT_THROW(s21_vec_string.at(5), std::out_of_range);
}

TEST(Vector_square_braces, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int[3], 9);
  EXPECT_EQ(s21_vec_double[0], 1.4);
  EXPECT_EQ(s21_vec_string[0], "Hello");
  EXPECT_EQ(std_vec_string[0], "Hello");
}

TEST(Vector_front, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.front(), 1);
  EXPECT_EQ(s21_vec_double.front(), 1.4);
  EXPECT_EQ(s21_vec_string.front(), "Hello");
  EXPECT_EQ(std_vec_string.front(), "Hello");
}

TEST(Vector_back, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.back(), 9);
  EXPECT_EQ(s21_vec_double.back(), 9.1);
  EXPECT_EQ(s21_vec_string.back(), "!");
  EXPECT_EQ(std_vec_string.back(), "!");
  EXPECT_EQ(std_vec_string.back(), s21_vec_string.back());
}

TEST(Vector_data, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.data(), &s21_vec_int[0]);
  EXPECT_EQ(s21_vec_double.data(), &s21_vec_double[0]);
  EXPECT_EQ(s21_vec_string.data(), &s21_vec_string[0]);
  EXPECT_EQ(std_vec_string.data(), &std_vec_string[0]);
  EXPECT_EQ(s21_vec_string[0], std_vec_string[0]);
}

TEST(Vector_begin, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Happy", "tree", "frends", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};
  std::vector<double> std_vec_double{1.4, 4.8, 8.9, 9.1};


  EXPECT_EQ(s21_vec_int.begin(), &s21_vec_int[0]);
  EXPECT_EQ(s21_vec_double.begin(), &s21_vec_double[0]);
  EXPECT_EQ(s21_vec_string.begin(), &s21_vec_string[0]);
  // EXPECT_EQ(std_vec_string.begin(), &std_vec_string[0]);
  // EXPECT_EQ(std_vec_double.begin(), &std_vec_double[0]);
  // EXPECT_EQ(s21_vec_string, std_vec_string);
  // EXPECT_EQ(s21_vec_string[0], std_vec_string[0]);
}

TEST(Vector_end, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.end(), &s21_vec_int[0] + 4);
  EXPECT_EQ(s21_vec_double.end(), &s21_vec_double[0] + 4);
  EXPECT_EQ(s21_vec_string.end(), &s21_vec_string[0] + 4);
}

TEST(Vector_empty, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};

  EXPECT_EQ(s21_vec_int.empty(), 0);
  EXPECT_EQ(s21_vec_double.empty(), 0);
  EXPECT_EQ(s21_vec_string.empty(), 0);
  EXPECT_EQ(std_vec_string.empty(), 0);
}

TEST(Vector_empty, case2) {
  s21::Vector<int> s21_vec_int{};
  s21::Vector<double> s21_vec_double{};
  s21::Vector<std::string> s21_vec_string{};

  EXPECT_EQ(s21_vec_int.empty(), 1);
  EXPECT_EQ(s21_vec_double.empty(), 1);
  EXPECT_EQ(s21_vec_string.empty(), 1);
}

TEST(Vector_size, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};
  

  EXPECT_EQ(s21_vec_int.size(), 4U);
  EXPECT_EQ(s21_vec_double.size(), 4U);
  EXPECT_EQ(s21_vec_string.size(), 4U);
  EXPECT_EQ(std_vec_string.size(), 4U);
}

TEST(Vector_size, case2) {
  s21::Vector<int> s21_vec_int{};
  s21::Vector<double> s21_vec_double{};
  s21::Vector<std::string> s21_vec_string{};

  EXPECT_EQ(s21_vec_int.size(), 0U);
  EXPECT_EQ(s21_vec_double.size(), 0U);
  EXPECT_EQ(s21_vec_string.size(), 0U);
}

TEST(Vector_max_size, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  std::vector<int> std_vec_int{1, 4, 8, 9};

  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  std::vector<double> std_vec_double{1.4, 4.8, 8.9, 9.1};

  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_vec_int.max_size(), std_vec_int.max_size());
  EXPECT_EQ(s21_vec_double.max_size(), std_vec_double.max_size());
  EXPECT_EQ(s21_vec_string.max_size(), std_vec_string.max_size());
}

TEST(Vector_reserve, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};


  s21_vec_int.reserve(20);
  s21_vec_double.reserve(20);
  s21_vec_string.reserve(20);
  std_vec_string.reserve(20);

  EXPECT_EQ(s21_vec_int.capacity(), 20U);
  EXPECT_EQ(s21_vec_double.capacity(), 20U);
  EXPECT_EQ(s21_vec_string.capacity(), 20U);
  EXPECT_EQ(std_vec_string.capacity(), 20U);
}

TEST(Vector_reserve, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};

  s21_vec_int.reserve(2);
  s21_vec_double.reserve(2);
  s21_vec_string.reserve(2);

  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
}

TEST(Vector_capacity, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};

  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
  EXPECT_EQ(std_vec_string.capacity(), 4U);
}

TEST(Vector_capacity, case2) {
  s21::Vector<int> s21_vec_int{};
  s21::Vector<double> s21_vec_double{};
  s21::Vector<std::string> s21_vec_string{};

  EXPECT_EQ(s21_vec_int.capacity(), 0U);
  EXPECT_EQ(s21_vec_double.capacity(), 0U);
  EXPECT_EQ(s21_vec_string.capacity(), 0U);
}

TEST(Vector_shrink_to_fit, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};

  s21_vec_int.reserve(20);
  s21_vec_double.reserve(20);
  s21_vec_string.reserve(20);
  std_vec_string.reserve(20);

  s21_vec_int.shrink_to_fit();
  s21_vec_double.shrink_to_fit();
  s21_vec_string.shrink_to_fit();
  std_vec_string.shrink_to_fit();

  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
  EXPECT_EQ(std_vec_string.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), std_vec_string.capacity());
}

TEST(Vector_shrink_to_fit, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};

  s21_vec_int.shrink_to_fit();
  s21_vec_double.shrink_to_fit();
  s21_vec_string.shrink_to_fit();

  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
}

TEST(Vector_clear, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};

  s21_vec_int.clear();
  s21_vec_double.clear();
  s21_vec_string.clear();
  std_vec_string.clear();

  EXPECT_EQ(&s21_vec_int[0], nullptr);
  EXPECT_EQ(&s21_vec_double[0], nullptr);
  EXPECT_EQ(&s21_vec_string[0], nullptr);
  // EXPECT_EQ(&std_vec_string[0], nullptr);
}

TEST(Vector_clear, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};

  s21_vec_int.clear();
  s21_vec_double.clear();
  s21_vec_string.clear();

  EXPECT_EQ(&s21_vec_int[0], nullptr);
  EXPECT_EQ(&s21_vec_double[0], nullptr);
  EXPECT_EQ(&s21_vec_string[0], nullptr);
}

TEST(Vector_insert, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "", "!"};
  std::vector<std::string> std_vec_string{"Happy", "tree", "frends", "!"};

  auto pos_int = s21_vec_int.begin() + 2;
  auto pos_double = s21_vec_double.begin() + 2;
  auto pos_string = s21_vec_string.begin() + 2;
  auto pos_string2 = std_vec_string.begin() + 2;

  s21_vec_int.insert(pos_int, 2);
  s21_vec_double.insert(pos_double, 2.0);
  s21_vec_string.insert(pos_string, "world");
  std_vec_string.insert(pos_string2, "plants_and");

  EXPECT_EQ(s21_vec_int[2], 2);
  EXPECT_EQ(s21_vec_double[2], 2.0);
  EXPECT_EQ(s21_vec_string[2], "world");
  EXPECT_EQ(std_vec_string[2], "plants_and");
}

TEST(Vector_insert, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "", "!"};

  auto pos_int = s21_vec_int.begin();
  auto pos_double = s21_vec_double.begin();
  auto pos_string = s21_vec_string.begin();

  s21_vec_int.insert(pos_int, 2);
  s21_vec_double.insert(pos_double, 2.0);
  s21_vec_string.insert(pos_string, "world");

  EXPECT_EQ(s21_vec_int[0], 2);
  EXPECT_EQ(s21_vec_double[0], 2.0);
  EXPECT_EQ(s21_vec_string[0], "world");
}

TEST(Vector_insert, case3) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "", "!"};

  auto pos_int = s21_vec_int.end();
  auto pos_double = s21_vec_double.end();
  auto pos_string = s21_vec_string.end();

  s21_vec_int.insert(pos_int, 2);
  s21_vec_double.insert(pos_double, 2.0);
  s21_vec_string.insert(pos_string, "world");

  EXPECT_EQ(s21_vec_int[4], 2);
  EXPECT_EQ(s21_vec_double[4], 2.0);
  EXPECT_EQ(s21_vec_string[4], "world");
}

TEST(Vector_erase, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 1, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 1.0, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "plants and", "tree", "frends", "!"};

  auto pos_int = s21_vec_int.begin() + 2;
  auto pos_double = s21_vec_double.begin() + 2;
  auto pos_string = s21_vec_string.begin() + 2;
  auto pos_string2 = std_vec_string.begin() + 2;

  s21_vec_int.erase(pos_int);
  s21_vec_double.erase(pos_double);
  s21_vec_string.erase(pos_string);
  std_vec_string.erase(pos_string2);

  EXPECT_EQ(s21_vec_int[2], 8);
  EXPECT_EQ(s21_vec_double[2], 8.9);
  EXPECT_EQ(s21_vec_string[2], "world");
  EXPECT_EQ(std_vec_string[2], "frends");
}

TEST(Vector_erase, case2) {
  s21::Vector<int> s21_vec_int{1, 1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.0, 1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"", "Hello", ",", "world", "!"};

  auto pos_int = s21_vec_int.begin();
  auto pos_double = s21_vec_double.begin();
  auto pos_string = s21_vec_string.begin();

  s21_vec_int.erase(pos_int);
  s21_vec_double.erase(pos_double);
  s21_vec_string.erase(pos_string);

  EXPECT_EQ(s21_vec_int[0], 1);
  EXPECT_EQ(s21_vec_double[0], 1.4);
  EXPECT_EQ(s21_vec_string[0], "Hello");
}

TEST(Vector_push_back, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "plants and", "tree", "frends", "!"};

  s21_vec_int.push_back(10);
  s21_vec_double.push_back(10.0);
  s21_vec_string.push_back("!!");
  std_vec_string.push_back("Can you hear it?");

  EXPECT_EQ(*(s21_vec_int.end() - 1), 10);
  EXPECT_EQ(*(s21_vec_double.end() - 1), 10.0);
  EXPECT_EQ(*(s21_vec_string.end() - 1), "!!");
  EXPECT_EQ(*(std_vec_string.end() - 1), "Can you hear it?");
}

TEST(Vector_push_back, case2) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};

  s21_vec_int.reserve(20);
  s21_vec_double.reserve(20);
  s21_vec_string.reserve(20);

  s21_vec_int.push_back(10);
  s21_vec_double.push_back(10.0);
  s21_vec_string.push_back("!!");

  EXPECT_EQ(*(s21_vec_int.end() - 1), 10);
  EXPECT_EQ(*(s21_vec_double.end() - 1), 10.0);
  EXPECT_EQ(*(s21_vec_string.end() - 1), "!!");
}

TEST(Vector_pop_back, case1) {
  s21::Vector<int> s21_vec_int{1, 4, 8, 9};
  s21::Vector<double> s21_vec_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<std::string> s21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Happy", "plants and", "tree", "frends", "!"};

  s21_vec_int.pop_back();
  s21_vec_double.pop_back();
  s21_vec_string.pop_back();
  std_vec_string.pop_back();

  EXPECT_EQ(s21_vec_int.size(), 3U);
  EXPECT_EQ(s21_vec_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_double.size(), 3U);
  EXPECT_EQ(s21_vec_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_string.size(), 3U);
  EXPECT_EQ(s21_vec_string.capacity(), 4U);
  EXPECT_EQ(std_vec_string.size(), 4U);
  EXPECT_EQ(std_vec_string.capacity(), 5U);
}

TEST(Vector_swap, case1) {
  s21::Vector<int> s21_vec_ref_int{1, 4, 8, 9};
  s21::Vector<int> s21_vec_res_int{0, 0, 0};

  s21::Vector<double> s21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::Vector<double> s21_vec_res_double{0.0, 0.0, 0.0};

  s21::Vector<std::string> s21_vec_ref_string{"Hello", ",", "world", "!"};
  s21::Vector<std::string> s21_vec_res_string{"", "", ""};

  std::vector<std::string> std_vec_string{"Happy", "plants and", "tree", "frends", "!"};
  std::vector<std::string> std_vec_res_string{"", "", ""};

  s21_vec_ref_int.swap(s21_vec_res_int);
  s21_vec_ref_double.swap(s21_vec_res_double);
  s21_vec_ref_string.swap(s21_vec_res_string);
  std_vec_string.swap(std_vec_res_string);


  EXPECT_EQ(s21_vec_res_int.size(), 4U);
  EXPECT_EQ(s21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_int[2], 8);

  EXPECT_EQ(s21_vec_res_double.size(), 4U);
  EXPECT_EQ(s21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_double[2], 8.9);

  EXPECT_EQ(s21_vec_res_string.size(), 4U);
  EXPECT_EQ(s21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(s21_vec_res_string[2], "world");

  EXPECT_EQ(std_vec_res_string.size(), 5U);
  EXPECT_EQ(std_vec_res_string.capacity(), 5U);
  EXPECT_EQ(std_vec_res_string[2], "tree");
}

// TEST(Vector_insert_many, case1) {
//   s21::Vector<int> s21_vec_int{1, 4};
//   s21::Vector<double> s21_vec_double{1.4, 4.8};
//   s21::Vector<std::string> s21_vec_string{"Hello", ","};

//   auto pos_int = s21_vec_int.begin() + 1;
//   auto pos_double = s21_vec_double.begin() + 1;
//   auto pos_string = s21_vec_string.begin() + 1;

//   s21_vec_int.insert_many(pos_int, 2, 3);
//   s21_vec_double.insert_many(pos_double, 2.0, 3.56);
//   s21_vec_string.insert_many(pos_string, "world", "!");

//   EXPECT_EQ(s21_vec_int[1], 2);
//   EXPECT_EQ(s21_vec_int[2], 3);

//   EXPECT_EQ(s21_vec_double[1], 2.0);
//   EXPECT_EQ(s21_vec_double[2], 3.56);

//   EXPECT_EQ(s21_vec_string[1], "world");
//   EXPECT_EQ(s21_vec_string[2], "!");
// }

// TEST(Vector_insert_many, case2) {
//   s21::Vector<int> s21_vec_int{1, 4};
//   s21::Vector<double> s21_vec_double{1.4, 4.8};
//   s21::Vector<std::string> s21_vec_string{"Hello", ","};

//   auto pos_int = s21_vec_int.begin();
//   auto pos_double = s21_vec_double.begin();
//   auto pos_string = s21_vec_string.begin();

//   s21_vec_int.insert_many(pos_int, 2, 3);
//   s21_vec_double.insert_many(pos_double, 2.0, 3.56);
//   s21_vec_string.insert_many(pos_string, "world", "!");

//   EXPECT_EQ(s21_vec_int[0], 2);
//   EXPECT_EQ(s21_vec_int[1], 3);

//   EXPECT_EQ(s21_vec_double[0], 2.0);
//   EXPECT_EQ(s21_vec_double[1], 3.56);

//   EXPECT_EQ(s21_vec_string[0], "world");
//   EXPECT_EQ(s21_vec_string[1], "!");
// }

// TEST(Vector_insert_many, case3) {
//   s21::Vector<int> s21_vec_int;
//   s21::Vector<double> s21_vec_double;
//   s21::Vector<std::string> s21_vec_string;

//   auto pos_int = s21_vec_int.begin();
//   auto pos_double = s21_vec_double.begin();
//   auto pos_string = s21_vec_string.begin();

//   s21_vec_int.insert_many(pos_int, 2, 3);
//   s21_vec_double.insert_many(pos_double, 2.0, 3.56);
//   s21_vec_string.insert_many(pos_string, "world", "!");

//   EXPECT_EQ(s21_vec_int[0], 2);
//   EXPECT_EQ(s21_vec_int[1], 3);

//   EXPECT_EQ(s21_vec_double[0], 2.0);
//   EXPECT_EQ(s21_vec_double[1], 3.56);

//   EXPECT_EQ(s21_vec_string[0], "world");
//   EXPECT_EQ(s21_vec_string[1], "!");
// }

TEST(Vector_insert_many_back, case1) {
  s21::Vector<int> s21_vec_int{1, 4};
  s21::Vector<double> s21_vec_double{1.4, 4.8};
  s21::Vector<std::string> s21_vec_string{"Hello", ","};
  std::vector<std::string> std_vec_string{"Happy", "plants and", "tree", "frends", "!"};
  std::vector<double> std_vec_double{1.4, 4.8};

  s21_vec_int.insert_many_back(2, 3);
  s21_vec_double.insert_many_back(2.0, 3.56);
  s21_vec_string.insert_many_back("world", "!");
  // std_vec_string.emplace_back("Why", "not", "the", "same", "name", "this", "time", "?");
  // std_vec_string.append_range("Why", "not", "the", "same", "name", "this", "time", "?");
  // std_vec_double.emplace_back(2.0, 3.56);

  EXPECT_EQ(s21_vec_int[2], 2);
  EXPECT_EQ(s21_vec_int[3], 3);

  EXPECT_EQ(s21_vec_double[2], 2.0);
  EXPECT_EQ(s21_vec_double[3], 3.56);

  EXPECT_EQ(s21_vec_string[2], "world");
  EXPECT_EQ(s21_vec_string[3], "!");
  // EXPECT_EQ(std_vec_string[6], "Why");
  // EXPECT_EQ(std_vec_string[7], "not");

  // EXPECT_EQ(std_vec_double[2], 2.0);
  // EXPECT_EQ(std_vec_double[3], 3.56);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}