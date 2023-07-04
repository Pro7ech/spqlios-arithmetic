#include "commons_private.h"

#include <stdio.h>
#include <stdlib.h>

#include "commons.h"

EXPORT void* spqlios_error(const char* error) {
  fputs(error, stderr);
  abort();
  return nullptr;
}
EXPORT void* spqlios_keep_or_free(void* ptr, void* ptr2) {
  if (!ptr2) {
    free(ptr);
  }
  return ptr2;
}

EXPORT uint32_t log2m(uint32_t m) {
  uint32_t a = m - 1;
  if (m & a) FATAL_ERROR("m must be a power of two");
  a = (a & 0x55555555u) + ((a >> 1) & 0x55555555u);
  a = (a & 0x33333333u) + ((a >> 2) & 0x33333333u);
  a = (a & 0x0F0F0F0Fu) + ((a >> 4) & 0x0F0F0F0Fu);
  a = (a & 0x00FF00FFu) + ((a >> 8) & 0x00FF00FFu);
  return (a & 0x0000FFFFu) + ((a >> 16) & 0x0000FFFFu);
}

EXPORT uint64_t is_not_pow2_double(void* doublevalue) { return (*(uint64_t*)doublevalue) & 0x7FFFFFFFFFFFFUL; }
