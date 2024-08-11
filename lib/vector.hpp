//
// Created by Asandei Stefan on 11.08.2024.
//

#pragma once

#include <cmath>
#include <vector>

namespace DSA {

/* -------- declaration -------- */

template <typename T>
class Vector {
 public:
  constexpr Vector() noexcept;
  constexpr ~Vector() noexcept;

  constexpr Vector(const Vector& other) noexcept;
  constexpr Vector& operator=(const Vector& other) noexcept;

  constexpr Vector(Vector&& other) noexcept;
  constexpr Vector& operator=(Vector&& other) noexcept;

  [[nodiscard]] constexpr size_t GetSize() const noexcept;
  [[nodiscard]] constexpr bool IsEmpty() const noexcept;

  [[nodiscard]] constexpr T* GetData() noexcept;
  [[nodiscard]] constexpr const T* GetData() const noexcept;

  [[nodiscard]] constexpr const T& operator[](size_t index) const noexcept;
  [[nodiscard]] constexpr T& operator[](size_t index) noexcept;

  constexpr void Resize(size_t newCapacity) noexcept;
  constexpr void Reserve(size_t newCap) noexcept;
  constexpr void Clear() noexcept;

  constexpr void PushBack(const T& value) noexcept;
  constexpr void PushFront(const T& value) noexcept;

  constexpr void PopBack() noexcept;
  constexpr void PopFront() noexcept;

  [[nodiscard]] constexpr T GetBack() const noexcept;
  [[nodiscard]] constexpr T GetFront() const noexcept;

 private:
  T* m_Data;
  size_t m_Size, m_Capacity;
};

/* -------- implementation -------- */

template <typename T>
inline constexpr Vector<T>::Vector() noexcept : m_Capacity(1), m_Size(0) {
  m_Data = new T[m_Capacity];
}

template <typename T>
inline constexpr Vector<T>::~Vector() noexcept {
  delete[] m_Data;
}

template <typename T>
inline constexpr Vector<T>::Vector(const Vector& other) noexcept
    : m_Size(other.GetSize()) {
  m_Capacity = pow(2, ceil(log2(m_Size)));
  m_Data = new T[m_Capacity];

  for (size_t i = 0; i < m_Size; i++) {
    m_Data[i] = other[i];
  }
}

template <typename T>
inline constexpr Vector<T>& Vector<T>::operator=(const Vector& other) noexcept {
  if (this == &other) {
    return *this;
  }

  delete[] m_Data;

  m_Size = other.GetSize();
  m_Capacity = pow(2, ceil(log2(m_Size)));
  m_Data = new T[m_Capacity];

  for (size_t i = 0; i < m_Size; i++) {
    m_Data[i] = other[i];
  }

  return *this;
}

template <typename T>
inline constexpr Vector<T>::Vector(Vector&& other) noexcept
    : m_Size(other.GetSize()),
      m_Data(other.GetData()),
      m_Capacity(other.m_Capacity) {
  other.m_Data = nullptr;
  other.m_Size = 0;
  other.m_Capacity = 0;
}

template <typename T>
inline constexpr Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  delete[] m_Data;

  m_Data = other.m_Data;
  m_Size = other.m_Size;
  m_Capacity = other.m_Capacity;

  other.m_Data = nullptr;
  other.m_Size = 0;
  other.m_Capacity = 0;

  return *this;
}

template <typename T>
inline constexpr size_t Vector<T>::GetSize() const noexcept {
  return m_Size;
}

template <typename T>
inline constexpr bool Vector<T>::IsEmpty() const noexcept {
  return m_Size == 0;
}

template <typename T>
inline constexpr T* Vector<T>::GetData() noexcept {
  return m_Data;
}

template <typename T>
inline constexpr const T* Vector<T>::GetData() const noexcept {
  return m_Data;
}

template <typename T>
inline constexpr const T& Vector<T>::operator[](size_t index) const noexcept {
  // if (index >= m_Size) return 0;
  //  todo: better error handling in the future

  return m_Data[index];
}

template <typename T>
inline constexpr T& Vector<T>::operator[](size_t index) noexcept {
  return m_Data[index];
}

template <typename T>
inline constexpr void Vector<T>::Resize(size_t newCapacity) noexcept {
  m_Capacity = newCapacity;

  T* newData = new T[newCapacity];

  for (size_t i = 0; i < m_Size; i++) {
    newData[i] = m_Data[i];
  }

  delete[] m_Data;
  m_Data = newData;
}

template <typename T>
inline constexpr void Vector<T>::PushBack(const T& value) noexcept {
  if (m_Size + 1 > m_Capacity) {
    Resize(m_Capacity * 2);
  }

  m_Data[m_Size++] = value;
}

template <typename T>
inline constexpr void Vector<T>::Reserve(size_t newCap) noexcept {
  if (newCap <= m_Capacity) return;

  Resize(newCap);
}

template <typename T>
inline constexpr void Vector<T>::Clear() noexcept {
  m_Size = 0;
}

template <typename T>
inline constexpr void Vector<T>::PushFront(const T& value) noexcept {
  PushBack(0);

  for (int i = m_Size - 1; i >= 0; i--) {
    m_Data[i + 1] = m_Data[i];
  }

  m_Data[0] = value;
}

template <typename T>
inline constexpr void Vector<T>::PopBack() noexcept {
  m_Size--;
}

template <typename T>
inline constexpr void Vector<T>::PopFront() noexcept {
  for (size_t i = 0; i < m_Size; i++) {
    m_Data[i] = m_Data[i + 1];
  }
  m_Size--;
}

template <typename T>
inline constexpr T Vector<T>::GetBack() const noexcept {
  return m_Data[m_Size - 1];
}

template <typename T>
constexpr T Vector<T>::GetFront() const noexcept {
  return m_Data[0];
}

}  // namespace DSA
