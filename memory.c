#include <stdint.h>

struct SegmentSelector {
    uint16_t index : 13;           
    uint16_t table_index : 1;      
    uint16_t privilege_level : 2;  
    uint16_t table_indicator : 1;
};

struct SegmentDescriptor {
    uint64_t limit_low : 16;       
    uint64_t base_low : 24;        
    uint64_t type : 4;             
    uint64_t sys : 1;                
    uint64_t priv : 2;              
    uint64_t present : 1;          
    uint64_t limit_high : 4;       
    uint64_t avail : 1;              
    uint64_t lng : 1;                
    uint64_t dflsize : 1;              
    uint64_t granularity : 1;      
    uint64_t base_high : 8;        
} __attribute__((packed));

