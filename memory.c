#include <stdint.h>

struct SegmentSelector {
    uint16_t index : 13;           
    uint16_t table_index : 1;      
    uint16_t privilege_level : 2;  
    uint16_t table_indicator : 1;
};
