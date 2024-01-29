#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum ProcessState ProcessState;
typedef enum ProcessBondage ProcessBondage;
typedef enum ProcessEagerness ProcessEeagerness;
typedef enum ProcessPriority ProcessPriority;
typedef struct ProcessControlBlock ProcessControlBlock;
typedef struct ShortTermScheduler ShortTermScheduler;
typedef struct LongTermScheduler LongTermScheduler;
typedef struct ProcessScheduler ProcessScheduler;
typedef struct PageTableEntry PageTableEntry;
typedef struct PageTable PageTable;
typedef struct PageDirectory PageDirectory;
typedef struct VirtualPageTableEntry VirtualPageTableEntry;
typedef struct VirtualPageTable VirtualPageTable;
typedef struct VirtualPageDirectory VirtualPageDirectory;
typedef struct X64PageTableEntry X64PageTableEntry;
typedef struct X64PageTable X64PageTable;
typedef struct X64PageDirectory X64PageDirectory;
typedef struct X64PageMapLevel4 X64PageMapLevel4;

typedef int procid_t;
typedef int threadid_t;
typedef int registerid_t;
typedef int exitcode_t;
typedef unsigned long processnum_t;

#endif
