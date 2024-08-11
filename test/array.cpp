//
// Created by Asandei Stefan on 11.08.2024.
//

#include <gtest/gtest.h>

#include <dsa.hpp>

class ArrayTest : public testing::Test {
 protected:
  ArrayTest() = default;

  DSA::Array<int32_t, 5> arr_{};
  DSA::Array<char, 15> arr1_{};
  DSA::Array<int32_t, 5> arr2_{};
};

TEST_F(ArrayTest, SizeDefined) { EXPECT_EQ(arr_.GetSize(), 5); }

TEST_F(ArrayTest, RandomAccess) {
  EXPECT_EQ(arr_[0], 0);

  arr_[0] = 1;
  EXPECT_EQ(arr_[0], 1);
}

TEST_F(ArrayTest, ReadData) {
  EXPECT_EQ(arr1_.GetSize(), 15);

  char targetValue = 'e';
  memset(arr1_.GetData(), targetValue, arr1_.GetSize());

  for (size_t i = 0; i < arr1_.GetSize(); i++) {
    EXPECT_EQ(arr1_[i], targetValue);
  }
}

TEST_F(ArrayTest, CanBeCopied) {
  for (int i = 0; i < arr_.GetSize(); i++) {
    arr_[i] = i;
  }

  arr2_ = arr_;

  EXPECT_EQ(arr2_.GetSize(), arr_.GetSize());

  for (int i = 0; i < arr2_.GetSize(); i++) {
    EXPECT_EQ(arr2_[i], i);
  }
}

TEST_F(ArrayTest, Fill) {
  int32_t targetValue = 420;

  arr_.Fill(targetValue);

  for (int i = 0; i < arr_.GetSize(); i++) {
    EXPECT_EQ(arr_[i], targetValue);
  }
}
