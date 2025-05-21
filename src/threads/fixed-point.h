#ifndef __THREADS_FIXED_POINT_H
#define __THREADS_FIXED_POINT_H

#define FP_SHIFT_AMOUNT 14

#define INT_TO_FP(n) ((n) << FP_SHIFT_AMOUNT)
#define FP_TO_INT_ZERO(x) ((x) >> FP_SHIFT_AMOUNT)
#define FP_TO_INT_NEAREST(x) (((x) >= 0) ? (((x) + (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT) \
                                         : (((x) - (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT))

#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define MUL(x, y) (((int64_t)(x)) * (y) >> FP_SHIFT_AMOUNT)
#define DIV(x, y) ((((int64_t)(x)) << FP_SHIFT_AMOUNT) / (y))

#define ADD_MIX(x, n) ((x) + ((n) << FP_SHIFT_AMOUNT))
#define SUB_MIX(x, n) ((x) - ((n) << FP_SHIFT_AMOUNT))
#define MUL_MIX(x, n) ((x) * (n))
#define DIV_MIX(x, n) ((x) / (n))

#endif /* threads/fixed-point.h */
