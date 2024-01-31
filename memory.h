#ifndef MEMORY_H
#define MEMORY_H


typedef struct SegmentSelector SegmentSelector;
typedef struct SegmentDescriptor SegmentDescriptor;



#define CODE_SEGMENT_TYPE 0x0A   
#define DATA_SEGMENT_TYPE 0x02   
#define SYSTEM_SEGMENT_TYPE 0x09 

#define SEGMENT_LIMIT_LOW_BITS 16
#define SEGMENT_BASE_LOW_BITS 24
#define SEGMENT_TYPE_BITS 4
#define SEGMENT_S_BIT 1
#define SEGMENT_DPL_BITS 2
#define SEGMENT_PRESENT_BIT 1
#define SEGMENT_LIMIT_HIGH_BITS 4
#define SEGMENT_AVL_BIT 1
#define SEGMENT_L_BIT 1
#define SEGMENT_D_B_BIT 1
#define SEGMENT_GRANULARITY_BIT 1
#define SEGMENT_BASE_HIGH_BITS 8


void set_code_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t dpl);

void set_data_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t dpl);

void set_system_segment(SegmentDescriptor *descriptor, 
		uint64_t base, 
		uint64_t limit, 
		uint8_t type, 
		uint8_t dpl);

#endif
