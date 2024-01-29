#ifndef ASM_INTERFACE_DECL
#define ASM_INTERFACE_DECL



#include "oryx.h"

void x64_initialize_page_table(virtaddr_t virtual_address, 
		physaddr_t physical_address,
		pagesize_t size);








#endif
