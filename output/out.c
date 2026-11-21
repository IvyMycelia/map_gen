#include <stdint.h>
#include <limits.h>
#if SIZE_MAX > UINT64_MAX
#error Flower sizeof requires size_t to fit in u64
#endif
#if CHAR_BIT != 8 || INT_MAX != 2147483647 || INT_MIN != (-2147483647 - 1)
#error Flower C backend requires 8-bit bytes and a signed 32-bit C int type
#endif
typedef char flower_int_storage_must_be_4_bytes[(sizeof(int) == 4) ? 1 : -1];
#include <stdio.h>
#define FLOWER_INTEGER_i8(value) ((int8_t)(((uint8_t)(value) <= INT8_MAX) ? (int64_t)(uint8_t)(value) : (-INT64_C(1) - (int64_t)(UINT8_MAX - (uint8_t)(value)))))
#define FLOWER_INTEGER_u8(value) ((uint8_t)(value))
static int8_t flower_integer_i8(uint64_t value) {
  return FLOWER_INTEGER_i8(value);
}
static uint8_t flower_integer_u8(uint64_t value) {
  return FLOWER_INTEGER_u8(value);
}
#define FLOWER_INTEGER_i16(value) ((int16_t)(((uint16_t)(value) <= INT16_MAX) ? (int64_t)(uint16_t)(value) : (-INT64_C(1) - (int64_t)(UINT16_MAX - (uint16_t)(value)))))
#define FLOWER_INTEGER_u16(value) ((uint16_t)(value))
static int16_t flower_integer_i16(uint64_t value) {
  return FLOWER_INTEGER_i16(value);
}
static uint16_t flower_integer_u16(uint64_t value) {
  return FLOWER_INTEGER_u16(value);
}
#define FLOWER_INTEGER_i32(value) ((int32_t)(((uint32_t)(value) <= INT32_MAX) ? (int64_t)(uint32_t)(value) : (-INT64_C(1) - (int64_t)(UINT32_MAX - (uint32_t)(value)))))
#define FLOWER_INTEGER_u32(value) ((uint32_t)(value))
static int32_t flower_integer_i32(uint64_t value) {
  return FLOWER_INTEGER_i32(value);
}
static uint32_t flower_integer_u32(uint64_t value) {
  return FLOWER_INTEGER_u32(value);
}
#define FLOWER_INTEGER_i64(value) ((int64_t)(((uint64_t)(value) <= INT64_MAX) ? (int64_t)(uint64_t)(value) : (-INT64_C(1) - (int64_t)(UINT64_MAX - (uint64_t)(value)))))
#define FLOWER_INTEGER_u64(value) ((uint64_t)(value))
static int64_t flower_integer_i64(uint64_t value) {
  return FLOWER_INTEGER_i64(value);
}
static uint64_t flower_integer_u64(uint64_t value) {
  return FLOWER_INTEGER_u64(value);
}
typedef struct { char* data; int length; } flower_string;
static int flower_cstr_len(char* s) {
  int i = 0;
  if (s == NULL) return 0;
  while (s[i] != '\0') i++;
  return i;
}
static flower_string flower_string_from_cstr(char* s) {
  flower_string out;
  out.data = s;
  out.length = (int)flower_cstr_len(s);
  return out;
}
static int flower_string_eq(flower_string a, flower_string b) {
  int i = 0;
  if (a.length != b.length) return 0;
  while (i < a.length) {
      if (a.data[i] != b.data[i]) return 0;
      i++;
  }
  return 1;
}
static void flower_print_string(flower_string s) {
  int i = 0;
  while (i < s.length) {
      putchar(s.data[i]);
      i++;
  }
}
#include <stdlib.h>
static void flower_integer_trap(const char* message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
#define FLOWER_add_i8(a, b) FLOWER_INTEGER_i8((uint64_t)(a) + (uint64_t)(b))
static int8_t flower_add_i8(int8_t a, int8_t b) {
  return FLOWER_add_i8(a, b);
}
#define FLOWER_sub_i8(a, b) FLOWER_INTEGER_i8((uint64_t)(a) - (uint64_t)(b))
static int8_t flower_sub_i8(int8_t a, int8_t b) {
  return FLOWER_sub_i8(a, b);
}
#define FLOWER_mul_i8(a, b) FLOWER_INTEGER_i8((uint64_t)(a) * (uint64_t)(b))
static int8_t flower_mul_i8(int8_t a, int8_t b) {
  return FLOWER_mul_i8(a, b);
}
#define FLOWER_neg_i8(a) FLOWER_INTEGER_i8(UINT64_C(0) - (uint64_t)(a))
static int8_t flower_neg_i8(int8_t a) {
  return FLOWER_neg_i8(a);
}
#define FLOWER_div_i8(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (int8_t)0) : ((a) == INT8_MIN && (b) == -1 ? (flower_integer_trap("signed integer division overflow"), (int8_t)0) : (int8_t)((a) / (b))))
static int8_t flower_div_i8(int8_t a, int8_t b) {
  return FLOWER_div_i8(a, b);
}
#define FLOWER_add_u8(a, b) FLOWER_INTEGER_u8((uint64_t)(a) + (uint64_t)(b))
static uint8_t flower_add_u8(uint8_t a, uint8_t b) {
  return FLOWER_add_u8(a, b);
}
#define FLOWER_sub_u8(a, b) FLOWER_INTEGER_u8((uint64_t)(a) - (uint64_t)(b))
static uint8_t flower_sub_u8(uint8_t a, uint8_t b) {
  return FLOWER_sub_u8(a, b);
}
#define FLOWER_mul_u8(a, b) FLOWER_INTEGER_u8((uint64_t)(a) * (uint64_t)(b))
static uint8_t flower_mul_u8(uint8_t a, uint8_t b) {
  return FLOWER_mul_u8(a, b);
}
#define FLOWER_neg_u8(a) FLOWER_INTEGER_u8(UINT64_C(0) - (uint64_t)(a))
static uint8_t flower_neg_u8(uint8_t a) {
  return FLOWER_neg_u8(a);
}
#define FLOWER_div_u8(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (uint8_t)0) : (uint8_t)((a) / (b)))
static uint8_t flower_div_u8(uint8_t a, uint8_t b) {
  return FLOWER_div_u8(a, b);
}
#define FLOWER_add_i16(a, b) FLOWER_INTEGER_i16((uint64_t)(a) + (uint64_t)(b))
static int16_t flower_add_i16(int16_t a, int16_t b) {
  return FLOWER_add_i16(a, b);
}
#define FLOWER_sub_i16(a, b) FLOWER_INTEGER_i16((uint64_t)(a) - (uint64_t)(b))
static int16_t flower_sub_i16(int16_t a, int16_t b) {
  return FLOWER_sub_i16(a, b);
}
#define FLOWER_mul_i16(a, b) FLOWER_INTEGER_i16((uint64_t)(a) * (uint64_t)(b))
static int16_t flower_mul_i16(int16_t a, int16_t b) {
  return FLOWER_mul_i16(a, b);
}
#define FLOWER_neg_i16(a) FLOWER_INTEGER_i16(UINT64_C(0) - (uint64_t)(a))
static int16_t flower_neg_i16(int16_t a) {
  return FLOWER_neg_i16(a);
}
#define FLOWER_div_i16(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (int16_t)0) : ((a) == INT16_MIN && (b) == -1 ? (flower_integer_trap("signed integer division overflow"), (int16_t)0) : (int16_t)((a) / (b))))
static int16_t flower_div_i16(int16_t a, int16_t b) {
  return FLOWER_div_i16(a, b);
}
#define FLOWER_add_u16(a, b) FLOWER_INTEGER_u16((uint64_t)(a) + (uint64_t)(b))
static uint16_t flower_add_u16(uint16_t a, uint16_t b) {
  return FLOWER_add_u16(a, b);
}
#define FLOWER_sub_u16(a, b) FLOWER_INTEGER_u16((uint64_t)(a) - (uint64_t)(b))
static uint16_t flower_sub_u16(uint16_t a, uint16_t b) {
  return FLOWER_sub_u16(a, b);
}
#define FLOWER_mul_u16(a, b) FLOWER_INTEGER_u16((uint64_t)(a) * (uint64_t)(b))
static uint16_t flower_mul_u16(uint16_t a, uint16_t b) {
  return FLOWER_mul_u16(a, b);
}
#define FLOWER_neg_u16(a) FLOWER_INTEGER_u16(UINT64_C(0) - (uint64_t)(a))
static uint16_t flower_neg_u16(uint16_t a) {
  return FLOWER_neg_u16(a);
}
#define FLOWER_div_u16(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (uint16_t)0) : (uint16_t)((a) / (b)))
static uint16_t flower_div_u16(uint16_t a, uint16_t b) {
  return FLOWER_div_u16(a, b);
}
#define FLOWER_add_i32(a, b) FLOWER_INTEGER_i32((uint64_t)(a) + (uint64_t)(b))
static int32_t flower_add_i32(int32_t a, int32_t b) {
  return FLOWER_add_i32(a, b);
}
#define FLOWER_sub_i32(a, b) FLOWER_INTEGER_i32((uint64_t)(a) - (uint64_t)(b))
static int32_t flower_sub_i32(int32_t a, int32_t b) {
  return FLOWER_sub_i32(a, b);
}
#define FLOWER_mul_i32(a, b) FLOWER_INTEGER_i32((uint64_t)(a) * (uint64_t)(b))
static int32_t flower_mul_i32(int32_t a, int32_t b) {
  return FLOWER_mul_i32(a, b);
}
#define FLOWER_neg_i32(a) FLOWER_INTEGER_i32(UINT64_C(0) - (uint64_t)(a))
static int32_t flower_neg_i32(int32_t a) {
  return FLOWER_neg_i32(a);
}
#define FLOWER_div_i32(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (int32_t)0) : ((a) == INT32_MIN && (b) == -1 ? (flower_integer_trap("signed integer division overflow"), (int32_t)0) : (int32_t)((a) / (b))))
static int32_t flower_div_i32(int32_t a, int32_t b) {
  return FLOWER_div_i32(a, b);
}
#define FLOWER_add_u32(a, b) FLOWER_INTEGER_u32((uint64_t)(a) + (uint64_t)(b))
static uint32_t flower_add_u32(uint32_t a, uint32_t b) {
  return FLOWER_add_u32(a, b);
}
#define FLOWER_sub_u32(a, b) FLOWER_INTEGER_u32((uint64_t)(a) - (uint64_t)(b))
static uint32_t flower_sub_u32(uint32_t a, uint32_t b) {
  return FLOWER_sub_u32(a, b);
}
#define FLOWER_mul_u32(a, b) FLOWER_INTEGER_u32((uint64_t)(a) * (uint64_t)(b))
static uint32_t flower_mul_u32(uint32_t a, uint32_t b) {
  return FLOWER_mul_u32(a, b);
}
#define FLOWER_neg_u32(a) FLOWER_INTEGER_u32(UINT64_C(0) - (uint64_t)(a))
static uint32_t flower_neg_u32(uint32_t a) {
  return FLOWER_neg_u32(a);
}
#define FLOWER_div_u32(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (uint32_t)0) : (uint32_t)((a) / (b)))
static uint32_t flower_div_u32(uint32_t a, uint32_t b) {
  return FLOWER_div_u32(a, b);
}
#define FLOWER_add_i64(a, b) FLOWER_INTEGER_i64((uint64_t)(a) + (uint64_t)(b))
static int64_t flower_add_i64(int64_t a, int64_t b) {
  return FLOWER_add_i64(a, b);
}
#define FLOWER_sub_i64(a, b) FLOWER_INTEGER_i64((uint64_t)(a) - (uint64_t)(b))
static int64_t flower_sub_i64(int64_t a, int64_t b) {
  return FLOWER_sub_i64(a, b);
}
#define FLOWER_mul_i64(a, b) FLOWER_INTEGER_i64((uint64_t)(a) * (uint64_t)(b))
static int64_t flower_mul_i64(int64_t a, int64_t b) {
  return FLOWER_mul_i64(a, b);
}
#define FLOWER_neg_i64(a) FLOWER_INTEGER_i64(UINT64_C(0) - (uint64_t)(a))
static int64_t flower_neg_i64(int64_t a) {
  return FLOWER_neg_i64(a);
}
#define FLOWER_div_i64(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (int64_t)0) : ((a) == INT64_MIN && (b) == -1 ? (flower_integer_trap("signed integer division overflow"), (int64_t)0) : (int64_t)((a) / (b))))
static int64_t flower_div_i64(int64_t a, int64_t b) {
  return FLOWER_div_i64(a, b);
}
#define FLOWER_add_u64(a, b) FLOWER_INTEGER_u64((uint64_t)(a) + (uint64_t)(b))
static uint64_t flower_add_u64(uint64_t a, uint64_t b) {
  return FLOWER_add_u64(a, b);
}
#define FLOWER_sub_u64(a, b) FLOWER_INTEGER_u64((uint64_t)(a) - (uint64_t)(b))
static uint64_t flower_sub_u64(uint64_t a, uint64_t b) {
  return FLOWER_sub_u64(a, b);
}
#define FLOWER_mul_u64(a, b) FLOWER_INTEGER_u64((uint64_t)(a) * (uint64_t)(b))
static uint64_t flower_mul_u64(uint64_t a, uint64_t b) {
  return FLOWER_mul_u64(a, b);
}
#define FLOWER_neg_u64(a) FLOWER_INTEGER_u64(UINT64_C(0) - (uint64_t)(a))
static uint64_t flower_neg_u64(uint64_t a) {
  return FLOWER_neg_u64(a);
}
#define FLOWER_div_u64(a, b) ((b) == 0 ? (flower_integer_trap("integer division by zero"), (uint64_t)0) : (uint64_t)((a) / (b)))
static uint64_t flower_div_u64(uint64_t a, uint64_t b) {
  return FLOWER_div_u64(a, b);
}


typedef struct Tiles {
char water;
char land;
} Tiles;


Tiles* mod_main_flo_setup() {
Tiles* tiles = malloc(sizeof(Tiles));
tiles->land = '#';
tiles->water = '~';
return tiles;
}


int32_t mod_main_flo_index(int32_t x, int32_t y, int32_t width) {
return flower_add_i32(flower_mul_i32(y, width), x);
}
int64_t SEED = ((int64_t)(INT64_C(1234)));


int64_t mod_main_flo_mod(int64_t a, int64_t b) {
return flower_sub_i64(a, flower_mul_i64(flower_div_i64(a, b), b));
}


int32_t mod_main_flo_random(int32_t max) {
SEED = mod_main_flo_mod(flower_mul_i64(SEED, ((int64_t)(INT64_C(48271)))), ((int64_t)(INT64_C(2147483647))));
return flower_integer_i32((uint64_t)(mod_main_flo_mod(SEED, flower_integer_i64((uint64_t)(max)))));
}
int32_t WIDTH = ((int32_t)(INT64_C(4)));


int32_t main() {
Tiles* tiles = mod_main_flo_setup();
char map[16];
{
const int32_t __flower_range_0_from = ((int32_t)(INT64_C(0)));
const int32_t __flower_range_0_to = WIDTH;
const int __flower_range_0_descending = __flower_range_0_from > __flower_range_0_to;
int __flower_range_0_active = 1;
for (int32_t x = __flower_range_0_from;
  __flower_range_0_active && (__flower_range_0_descending ? x > __flower_range_0_to : x < __flower_range_0_to);
  __flower_range_0_active = (x != __flower_range_0_to),
  x = __flower_range_0_active ? (__flower_range_0_descending ? flower_sub_i32(x, 1) : flower_add_i32(x, 1)) : x) {
{
const int32_t __flower_range_1_from = ((int32_t)(INT64_C(0)));
const int32_t __flower_range_1_to = WIDTH;
const int __flower_range_1_descending = __flower_range_1_from > __flower_range_1_to;
int __flower_range_1_active = 1;
for (int32_t y = __flower_range_1_from;
  __flower_range_1_active && (__flower_range_1_descending ? y > __flower_range_1_to : y < __flower_range_1_to);
  __flower_range_1_active = (y != __flower_range_1_to),
  y = __flower_range_1_active ? (__flower_range_1_descending ? flower_sub_i32(y, 1) : flower_add_i32(y, 1)) : y) {
int32_t choice = mod_main_flo_random(((int32_t)(INT64_C(2))));
if ((choice > ((int32_t)(INT64_C(0))))) {
map[mod_main_flo_index(x, y, WIDTH)] = tiles->land;
}
else {
map[mod_main_flo_index(x, y, WIDTH)] = tiles->water;
}
}
}
}
}
{
const int32_t __flower_range_2_from = ((int32_t)(INT64_C(0)));
const int32_t __flower_range_2_to = WIDTH;
const int __flower_range_2_descending = __flower_range_2_from > __flower_range_2_to;
int __flower_range_2_active = 1;
for (int32_t x = __flower_range_2_from;
  __flower_range_2_active && (__flower_range_2_descending ? x > __flower_range_2_to : x < __flower_range_2_to);
  __flower_range_2_active = (x != __flower_range_2_to),
  x = __flower_range_2_active ? (__flower_range_2_descending ? flower_sub_i32(x, 1) : flower_add_i32(x, 1)) : x) {
{
const int32_t __flower_range_3_from = ((int32_t)(INT64_C(0)));
const int32_t __flower_range_3_to = WIDTH;
const int __flower_range_3_descending = __flower_range_3_from > __flower_range_3_to;
int __flower_range_3_active = 1;
for (int32_t y = __flower_range_3_from;
  __flower_range_3_active && (__flower_range_3_descending ? y > __flower_range_3_to : y < __flower_range_3_to);
  __flower_range_3_active = (y != __flower_range_3_to),
  y = __flower_range_3_active ? (__flower_range_3_descending ? flower_sub_i32(y, 1) : flower_add_i32(y, 1)) : y) {
printf("%c", map[mod_main_flo_index(x, y, WIDTH)]);
}
}
flower_print_string(((flower_string){ "\n", (int)(sizeof("\n") - 1) }));
}
}
}
