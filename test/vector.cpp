//
// Created by Asandei Stefan on 11.08.2024.
//

#include <gtest/gtest.h>

#include <dsa.hpp>

class VectorTest : public testing::Test {
 protected:
  VectorTest() = default;

  DSA::Vector<int32_t> v_;
};

TEST_F(VectorTest, Constructed) {
  EXPECT_EQ(v_.GetSize(), 0);
  EXPECT_NE(v_.GetData(), nullptr);
}

TEST_F(VectorTest, Resize) {
  EXPECT_EQ(v_.GetSize(), 0);

  size_t targetCapacity = 1024;
  EXPECT_NO_FATAL_FAILURE(v_.Resize(targetCapacity));
}

TEST_F(VectorTest, Clear) {
  EXPECT_EQ(v_.GetSize(), 0);

  size_t targetSize = 10;
  for (size_t i = 0; i < targetSize; i++) {
    v_.PushBack(static_cast<int32_t>(i));
  }

  EXPECT_EQ(v_.GetSize(), targetSize);

  v_.Clear();
  EXPECT_EQ(v_.GetSize(), 0);
}

TEST_F(VectorTest, ElementInsertion) {
  int32_t targetValue = 420;

  v_.PushBack(targetValue);
  EXPECT_EQ(v_[0], targetValue);
  EXPECT_EQ(v_.GetBack(), targetValue);
  EXPECT_EQ(v_.GetFront(), targetValue);
  EXPECT_EQ(v_.IsEmpty(), false);

  v_.PushBack(targetValue + 1);
  EXPECT_EQ(v_.GetBack(), targetValue + 1);
  EXPECT_EQ(v_.GetFront(), targetValue);
  EXPECT_EQ(v_.GetSize(), 2);

  v_.PushFront(targetValue + 2);
  EXPECT_EQ(v_.GetBack(), targetValue + 1);
  EXPECT_EQ(v_.GetFront(), targetValue + 2);
  EXPECT_EQ(v_.GetSize(), 3);

  v_.PopBack();
  EXPECT_EQ(v_.GetBack(), targetValue);
  EXPECT_EQ(v_.GetFront(), targetValue + 2);
  EXPECT_EQ(v_.GetSize(), 2);

  v_.PopFront();
  EXPECT_EQ(v_.GetBack(), targetValue);
  EXPECT_EQ(v_.GetFront(), targetValue);
  EXPECT_EQ(v_.GetSize(), 1);

  v_.PopFront();
  EXPECT_EQ(v_.GetSize(), 0);
  EXPECT_EQ(v_.IsEmpty(), true);
}

TEST_F(VectorTest, Resizing) {
  EXPECT_EQ(v_.GetSize(), 0);

  size_t targetSize = 2049;
  for (size_t i = 0; i < targetSize; i++) {
    v_.PushBack(static_cast<int32_t>(i));
  }

  EXPECT_EQ(v_.GetSize(), targetSize);
  EXPECT_EQ(v_.GetCapacity(), (targetSize - 1) * 2);
}
