//
// Created by Asandei Stefan on 11.08.2024.
//

#pragma once

namespace DSA {

/* -------- declaration -------- */

template <typename T, size_t S>
class Array {
 public:
  Array() = default;
  ~Array() = default;

  [[nodiscard]] constexpr size_t GetSize() const noexcept;

  [[nodiscard]] constexpr T* GetData() noexcept;
  [[nodiscard]] constexpr const T* GetData() const noexcept;

  [[nodiscard]] constexpr const T& operator[](size_t index) const noexcept;
  [[nodiscard]] constexpr T& operator[](size_t index) noexcept;

 private:
  T m_Data[S];
};

/* -------- implementation -------- */

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
  static_assert(index < S);

  return m_Data[index];
}

template <typename T, size_t S>
inline constexpr T& Array<T, S>::operator[](size_t index) noexcept {
  static_assert(index < S);

  return m_Data[index];
}

}  // namespace DSA
