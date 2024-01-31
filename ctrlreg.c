#include <stdint.h>


#include <stdint.h>


struct CR0Flags {
    uint32_t pe : 1;   
    uint32_t mp : 1;   
    uint32_t em : 1;   
    uint32_t ts : 1;   
    uint32_t et : 1;   
    uint32_t reserved1 : 11;  
    uint32_t pg : 1;   
    uint32_t cd : 1;   
    uint32_t nw : 1;   
    uint32_t am : 1;   
    uint32_t reserved2 : 20;  
};


struct CR4Flags {
    uint32_t vme : 1;  
    uint32_t pvi : 1;  
    uint32_t tsd : 1;  
    uint32_t de : 1;   
    uint32_t pse : 1;  
    uint32_t pae : 1;  
    uint32_t mce : 1;  
    uint32_t pge : 1;  
    uint32_t pce : 1;  
    uint32_t osfxsr : 1;  
    uint32_t osxmmexcpt : 1;  
    uint32_t umip : 1;  
    uint32_t reserved1 : 1;  
    uint32_t la57 : 1;  
    uint32_t reserved2 : 7;  
    uint32_t vmxe : 1;  
    uint32_t smxe : 1;  
    uint32_t reserved3 : 8;  
    uint32_t fsgsbase : 1;  
    uint32_t pcide : 1;  
    uint32_t reserved4 : 10;  
};


struct CR8Flags {
    uint64_t interrupt_priority : 4;  
    uint64_t reserved : 60;  
};

