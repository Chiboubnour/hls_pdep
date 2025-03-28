#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <immintrin.h>

 int64_t pdep_u64_arm (const uint64_t val, const uint64_t _mask)
{
  uint64_t mask = _mask;
  int64_t res = 0;
  for (uint64_t bb = 1; mask; bb += bb) {
    if (val & bb)
      res |= mask & -mask;
    mask &= mask - 1;
  }
  return res;
}
