#ifndef ORYX_H
#define ORYX_H

// + A: Processes +

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
                                                 char name[MAX_PROCESS_NAME],
                                                 ProcessBondage bondage);
ShortTermScheduler create_short_term_scheduler(void);
ShortTermScheduler create_long_term_scheduler(void);
ProcessScheduler create_process_scheduler(void);
void process_schedular_add_pcb(ProcessScheduler *sched,
                               ProcessControlBlock *pcb);


// + B: Memory +

typedef 













#endif
