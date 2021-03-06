#ifndef __TIME_HELPER_H_INC__
#define __TIME_HELPER_H_INC__
#include <stdint.h>

namespace conet
{

// rdtscp 比 rdtsc 更安全， 做了cpu同步
inline 
uint64_t rdtscp(void)
{
    volatile uint64_t tsc;
    __asm__ __volatile__("rdtscp; "     // serializing read of tsc
                     "shl $32,%%rdx; "  // shift higher 32 bits stored in rdx up
                     "or %%rdx,%%rax"   // and or onto rax
                     : "=a"(tsc)        // output to tsc variable
                     :
                     : "%rcx", "%rdx"); // rcx and rdx are clobbered
    return tsc;
}

uint64_t get_cpu_khz();

uint64_t get_tick_ms();

uint64_t get_sys_ms();

}


#define time_after(a,b) (((int64_t)(b) - (int64_t)(a))<0)
#define time_before(a,b) time_after(b, a)

#define time_after_eq(a,b) (((int64_t)(a) - (int64_t)(b))>=0)
#define time_before_eq(a,b) time_after_eq(b, a)

#define time_diff(a, b) ((int64_t)(a) - (int64_t)(b))

#endif
