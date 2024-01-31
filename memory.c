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
    uint64_t s : 1;
    uint64_t dpl : 2;
    uint64_t present : 1;
    uint64_t limit_high : 4;
    uint64_t avl : 1;
    uint64_t l : 1;
    uint64_t d_b : 1;
    uint64_t granularity : 1;
    uint64_t base_high : 8;
} __attribute__((packed));


void set_code_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t dpl) {
    descriptor->limit_low = limit & 0xFFFF;
    descriptor->base_low = base & 0xFFFFFF;
    descriptor->type = 0x0A;  
    descriptor->s = 1;        
    descriptor->dpl = dpl;    
    descriptor->present = 1;  
    descriptor->limit_high = (limit >> 16) & 0x0F;
    descriptor->avl = 0;
    descriptor->l = 1;        
    descriptor->d_b = 1;      
    descriptor->granularity = 1;  
    descriptor->base_high = (base >> 24) & 0xFF;
}


void set_data_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t dpl) {
    descriptor->limit_low = limit & 0xFFFF;
    descriptor->base_low = base & 0xFFFFFF;
    descriptor->type = 0x02;  
    descriptor->s = 1;        
    descriptor->dpl = dpl;    
    descriptor->present = 1;  
    descriptor->limit_high = (limit >> 16) & 0x0F;
    descriptor->avl = 0;
    descriptor->l = 0;
    descriptor->d_b = 1;      
    descriptor->granularity = 1;  
    descriptor->base_high = (base >> 24) & 0xFF;
}


void set_system_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t type, 
		uint8_t dpl) {
    descriptor->limit_low = limit & 0xFFFF;
    descriptor->base_low = base & 0xFFFFFF;
    descriptor->type = type;  
    descriptor->s = 0;        
    descriptor->dpl = dpl;    
    descriptor->present = 1;  
    descriptor->limit_high = (limit >> 16) & 0x0F;
    descriptor->avl = 0;
    descriptor->l = 0;
    descriptor->d_b = 0;
    descriptor->granularity = 0;  
    descriptor->base_high = (base >> 24) & 0xFF;
}
