//
// Created by Asandei Stefan on 12.08.2024.
//

#pragma once

#include <cstdio>

namespace DSA {

static inline constexpr void Assert(bool cond, int line,
                                    const char* filename) noexcept {
  if (cond) {
    return;
  }

  fprintf(stderr, "Assert failed at line %d in file %s\n", line, filename);
  exit(-1);
}

}  // namespace DSA

#ifndef NDEBUG
#define ASSERT(x) DSA::Assert(x, __LINE__, __FILE__)
#else
#define ASSERT(x) x
#endif
