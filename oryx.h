#ifndef ORYX_H
#define ORYX_H

typedef enum ProcessState ProcessState;
typedef enum ProcessBondage ProcessBondage;
typedef struct ProcessControlBlock ProcessControlBlock;


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


