#ifndef KERNEL_H
#define KERNEL_H

#include <mm/mmu.h>

extern uint32_t _kernel_tic;
extern uint64_t _kernel_usec;
extern char _kernel_start[];
extern char _kernel_end[];

extern char _bss_start[];
extern char _bss_end[];

extern page_dir_entry_t* _kernel_vm;
extern void set_kernel_vm(page_dir_entry_t* vm);

#endif
