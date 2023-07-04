#ifndef SPQLIOS_COMMONS_PRIVATE_H
#define SPQLIOS_COMMONS_PRIVATE_H

#include "commons.h"

/** @brief log2 of a power of two (UB if m is not a power of two) */
uint32_t log2m(uint32_t m);

/** @brief checks if the doublevalue is a power of two */
uint64_t is_not_pow2_double(void* doublevalue);

#define UNDEFINED()                    \
  {                                    \
    fprintf(stderr, "UNDEFINED!!!\n"); \
    abort();                           \
  }
#define NOT_IMPLEMENTED()                    \
  {                                          \
    fprintf(stderr, "NOT IMPLEMENTED!!!\n"); \
    abort();                                 \
  }
#define NOT_SUPPORTED()                    \
  {                                          \
    fprintf(stderr, "NOT SUPPORTED!!!\n"); \
    abort();                                 \
  }
#define FATAL_ERROR(MESSAGE)                   \
  {                                            \
    fprintf(stderr, "ERROR: %s\n", (MESSAGE)); \
    abort();                                   \
  }

/** @brief reports the error and returns nullptr */
EXPORT void* spqlios_error(const char* error);
/** @brief if ptr2 is not null, returns ptr, otherwise free ptr and return null */
EXPORT void* spqlios_keep_or_free(void* ptr, void* ptr2);

#ifdef __x86_64__
#define CPU_SUPPORTS __builtin_cpu_supports
#else
// TODO for now, we do not have any optimization for non x86 targets
#define CPU_SUPPORTS(xxxx) 0
#endif

uint32_t revbits(uint32_t nbits, uint32_t value);

/**
 * @brief this computes the sequence: 0,1/2,1/4,3/4,1/8,5/8,3/8,7/8,...
 * essentially: the bits of (i+1) in lsb order on the basis (1/2^k) mod 1*/
double fracrevbits(uint32_t i);

#endif  // SPQLIOS_COMMONS_PRIVATE_H