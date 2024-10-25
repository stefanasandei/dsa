//
// Created by Stefan on 10/20/2024.
//

#pragma once

#include "base.hpp"
#include "vector.hpp"

#include <iostream>
#include <compare>

namespace DSA {

/* -------- declaration -------- */

class BigInteger {
 public:
  // constructors
  constexpr BigInteger();
  constexpr explicit BigInteger(uint64_t initialValue);
  constexpr explicit BigInteger(const char* str);

  // destructor
  constexpr ~BigInteger() = default;

  // copy constructors
  constexpr BigInteger(const BigInteger& other);
  constexpr BigInteger& operator=(const BigInteger& other);

  // move constructors
  constexpr BigInteger(BigInteger&& other) noexcept;
  constexpr BigInteger& operator=(BigInteger&& other) noexcept;

  // utils
  [[nodiscard]] constexpr const char* ToString() const;
  [[nodiscard]] constexpr size_t GetSize() const;

  // operators
  [[nodiscard]] constexpr BigInteger operator+(const BigInteger& other) const;
  [[nodiscard]] constexpr BigInteger operator-(const BigInteger& other) const;
  [[nodiscard]] constexpr BigInteger operator*(const BigInteger& other) const;
  //  [[nodiscard]] constexpr BigInteger operator/(const BigInteger& other) const;

  //   constexpr void operator+=(const BigInteger& other);
  //   constexpr void operator-=(const BigInteger& other);
  // constexpr void operator*=(const BigInteger& other);
  //   constexpr void operator/=(const BigInteger& other);

  // comparison operators
  [[nodiscard]] constexpr std::strong_ordering operator<=>(const BigInteger& other) const;

  // input/output
  friend std::ostream& operator<<(std::ostream& os, const BigInteger& s);
  friend std::istream& operator>>(std::istream& is, BigInteger& s);

 private:
  Vector<uint8_t> m_Digits;
};

/* -------- implementation -------- */

inline constexpr BigInteger::BigInteger() {
  m_Digits.PushBack(0);
}

inline constexpr BigInteger::BigInteger(uint64_t initialValue) {
  while (initialValue > 0) {
    m_Digits.PushBack(initialValue % 10);
    initialValue /= 10;
  }

  if (m_Digits.IsEmpty()) {
    m_Digits.PushBack(0);
  }
}

inline constexpr BigInteger::BigInteger(const char* str) {
  char* end = const_cast<char*>(str);
  while(*end != '\0') {
    end++;
  }

  size_t size = end - str;

  m_Digits.Resize(size+1);
  for(size_t i = 0; i < size; i++) {
    m_Digits.PushBack(str[size-i-1]-'0');
  }
}

inline constexpr BigInteger::BigInteger(const BigInteger& other) {
  this->m_Digits = other.m_Digits;
}

inline constexpr BigInteger& BigInteger::operator=(const BigInteger& other) = default;

inline constexpr BigInteger::BigInteger(BigInteger&& other) noexcept {
  this->m_Digits = other.m_Digits;
  other.m_Digits.Clear();
}

inline constexpr BigInteger& BigInteger::operator=(BigInteger&& other) noexcept = default;

inline constexpr const char* BigInteger::ToString() const {
  char* str = new char[m_Digits.GetSize()+1];

  for(size_t i = 0; i < m_Digits.GetSize(); i++) {
    str[i] = static_cast<char>(m_Digits[m_Digits.GetSize() - i - 1] + '0');
  }

  str[m_Digits.GetSize()] = '\0';

  return str;
}

inline constexpr size_t BigInteger::GetSize() const { return m_Digits.GetSize(); }

inline constexpr BigInteger BigInteger::operator+(const BigInteger& other) const {
  BigInteger result;
  result.m_Digits.Clear();

  int carry = 0;
  size_t resultSize = static_cast<int>(std::max(m_Digits.GetSize(), other.GetSize()));

  result.m_Digits.Resize(resultSize);

  for (size_t i = 0; i < resultSize; ++i) {
    int other_digit = (i < other.GetSize()) ? other.m_Digits[i] : 0;
    int curr_digit = (i < m_Digits.GetSize()) ? m_Digits[i] : 0;

    int sum = curr_digit + other_digit + carry;
    result.m_Digits.PushBack(sum % 10);
    carry = sum / 10;
  }

  while (carry) {
    result.m_Digits.PushBack(carry % 10);
    carry /= 10;
  }

  return result;
}

inline constexpr BigInteger BigInteger::operator-(const BigInteger& other) const {
  auto compares_res = (*this <=> other);

  if(compares_res == std::strong_ordering::less) {
    // didn't implement negative integers
    return BigInteger(-1);
  }

  BigInteger result;
  if(compares_res == std::strong_ordering::equal) {
    return result;
  }

  result.m_Digits.Clear();

  int carry = 0;
  size_t resultSize = static_cast<int>(std::max(m_Digits.GetSize(), other.GetSize()));

  result.m_Digits.Resize(resultSize);

  for (size_t i = 0; i < resultSize; ++i) {
    int other_digit = (i < other.GetSize()) ? other.m_Digits[i] : 0;
    int curr_digit = (i < m_Digits.GetSize()) ? m_Digits[i] : 0;

    int sub = curr_digit - other_digit - carry;
    carry = 0;
    if(sub < 0) {
      sub += 10;
      carry = 1;
    }
    result.m_Digits.PushBack(sub);
  }

  return result;
}

inline constexpr BigInteger BigInteger::operator*(const BigInteger& other) const {
  BigInteger result;
  result.m_Digits.Clear();

  int carry = 0;
  size_t resultSize = m_Digits.GetSize() + other.GetSize();

  result.m_Digits.Resize(resultSize);
  for(size_t i = 0; i <= resultSize; i++) {
    result.m_Digits.PushBack(0);
  }

  for (size_t i = 0; i < m_Digits.GetSize(); ++i) {
    for (size_t j = 0; j < other.m_Digits.GetSize(); ++j) {
      int product = m_Digits[i] * other.m_Digits[j] + result.m_Digits[i + j] + carry;
      result.m_Digits[i + j] = product % 10;
      carry = product / 10;
    }
    result.m_Digits[i + other.m_Digits.GetSize()] += carry;
  }


  if(carry) {
    result.m_Digits.PushBack(carry);
  }

  // todo: trailing zero
  while (result.m_Digits.GetSize() > 1 && result.m_Digits.GetBack() == 0) {
    result.m_Digits.PopBack();
  }

  return result;
}

// inline constexpr BigInteger BigInteger::operator/(const BigInteger& other) const {}

// inline constexpr void BigInteger::operator+=(const BigInteger& other) {}

// inline constexpr void BigInteger::operator-=(const BigInteger& other) {}

// inline constexpr void BigInteger::operator*=(const BigInteger& other) {}

// inline constexpr void BigInteger::operator/=(const BigInteger& other) {}

inline constexpr std::strong_ordering BigInteger::operator<=>(const BigInteger& other) const {
  if(GetSize() != other.GetSize()) {
    return GetSize() <=> other.GetSize();
  }

  for(size_t i = 0; i < GetSize(); i++) {
    if(m_Digits[i] == other.m_Digits[i]) continue;

    return m_Digits[i] <=> other.m_Digits[i];
  }

  return std::strong_ordering::equal;
}

inline std::ostream& operator<<(std::ostream& os, const BigInteger& s) {
  os << s.ToString();
  return os;
}

inline std::istream& operator>>(std::istream& is, BigInteger& s) {
  char buf[4096];

  is >> buf;

  s = BigInteger(buf);

  return is;
}

}
