#ifndef ORYX_H
#define ORYX_H

typedef enum ProcessState ProcessState;
typedef enum ProcessBondage ProcessBondage;
typedef enum ProcessEagerness ProcessEeagerness;
typedef enum ProcessPriority ProcessPriority;
typedef struct ProcessControlBlock ProcessControlBlock;
typedef struct ShortTermScheduler ShortTermScheduler;
typedef struct LongTermScheduler LongTermScheduler;
typedef struct ProcessScheduler ProcessScheduler;
typedef int procid_t;
typedef int threadid_t;
typedef int threadid_t;
typedef int registerid_t;
typedef int exitcode_t;
typedef unsigned long processnum_t;

ProcessControlBlock create_process_control_block(procid_t parent_id, 
                char name[MAX_PROCESS_NAME], ProcessBondage bondage);
ShortTermScheduler create_short_term_scheduler(void);
ShortTermScheduler create_long_term_scheduler(void);
ProcessScheduler create_process_scheduler(void);
void process_schedular_add_pcb(ProcessScheduler *sched, ProcessControlBlock *pcb);

typedef struct VirtualMemoryPage VirtualMemoryPage;
typedef struct PageTable PageTable;
typedef unsigned int pageid_t;
typedef unsigned long physaddr_t;
typedef unsigned long pageaddr_t;
typedef unsigned long pagesize_t;
typedef unsigned long pageoffs_t;
typedef unsigned long mapaddr_t;
typedef int pageflag_t;
typedef unsigned long acctime_t;
typedef unsigned long avail_t;


VirtualMemoryPage create_virtual_page(pageid_t id,                   
                pageflag_t flags, 
                physaddr_t physical_addr,   
                pagesize_t size,   
                pageoffs_t offset);



#endif


