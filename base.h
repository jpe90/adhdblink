#include <stdint.h>
#include <stdio.h>

typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef U8 B8;
typedef U32 B32;

#define Min(a,b) ((a) < (b) ? (a) : (b))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Clamp(a,x,b) ((x) < (a) ? (a) : (x) > (b) ? (b) : (x))

#define ClampTop(a,b) Min(a,b)
#define ClampBottom(a,b) Max(a,b)

#define AlignUpPow2(x,p) (((x) + ((p) - 1)) & ~((p) - 1))
#define AlignDownPow2(x,p) ((x)&~((p)-1))

#define function static
#define global static
#define local static

#define GB(count) (U64) (count * 1024 * 1024 * 1024)
#define MB(count) (U64) (count * 1024 * 1024)
#define KB(count) (U64) (count * 1024)

#define EvalPrint(x)    (printf("%s = %d\n", #x, (int)(x)))
#include <string.h>
#define MemoryZero(p, z)    memset((p), 0, (z))
