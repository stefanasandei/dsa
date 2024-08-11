//
// Created by Asandei Stefan on 11.08.2024.
//

#pragma once

namespace DSA {

/* -------- declaration -------- */

template <typename T, size_t S>
class Array {
 public:
  constexpr Array() = default;
  constexpr ~Array() = default;

  constexpr Array(const Array& other) noexcept;
  constexpr Array& operator=(const Array& other) noexcept;

  constexpr Array(Array&& other) noexcept;
  constexpr Array& operator=(Array&& other) noexcept;

  [[nodiscard]] constexpr size_t GetSize() const noexcept;

  [[nodiscard]] constexpr T* GetData() noexcept;
  [[nodiscard]] constexpr const T* GetData() const noexcept;

  [[nodiscard]] constexpr const T& operator[](size_t index) const noexcept;
  [[nodiscard]] constexpr T& operator[](size_t index) noexcept;

  constexpr void Fill(const T& value) noexcept;

 private:
  T m_Data[S];
};

/* -------- implementation -------- */

template <typename T, size_t S>
inline constexpr Array<T, S>::Array(const Array& other) noexcept {
  for (size_t i = 0; i < S; i++) {
    m_Data[i] = other[i];
  }
}

template <typename T, size_t S>
inline constexpr Array<T, S>& Array<T, S>::operator=(
    const Array& other) noexcept {
  if (this == &other) {
    return *this;
  }

  for (size_t i = 0; i < S; i++) {
    m_Data[i] = other[i];
  }

  return *this;
}

template <typename T, size_t S>
inline constexpr Array<T, S>::Array([[maybe_unused]] Array&& other) noexcept {}

template <typename T, size_t S>
inline constexpr Array<T, S>& Array<T, S>::operator=(
    [[maybe_unused]] Array&& other) noexcept {}

template <typename T, size_t S>
inline constexpr size_t Array<T, S>::GetSize() const noexcept {
  return S;
}

template <typename T, size_t S>
inline constexpr T* Array<T, S>::GetData() noexcept {
  return m_Data;
}

template <typename T, size_t S>
inline constexpr const T* Array<T, S>::GetData() const noexcept {
  return m_Data;
}

template <typename T, size_t S>
inline constexpr const T& Array<T, S>::operator[](size_t index) const noexcept {
  // static_assert(index < S);

  return m_Data[index];
}

template <typename T, size_t S>
inline constexpr T& Array<T, S>::operator[](size_t index) noexcept {
  // static_assert(index < S);

  return m_Data[index];
}

template <typename T, size_t S>
inline constexpr void Array<T, S>::Fill(const T& value) noexcept {
  for (size_t i = 0; i < S; i++) {
    m_Data[i] = value;
  }
}

}  // namespace DSA
