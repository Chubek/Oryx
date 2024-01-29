#include "asm-registers-x64.S"
#include "asm-constants-x64.S"

.section .bss
    page_directory: .quad 0
    page_table:     .quad 0

.section .text
    .globl x64_initialize_page_table

x64_initialize_page_table:
   #define ARG1_VIRTUAL_ADDRESS 	SYSV_ARG1_QWORD
   #define ARG2_PHYSICAL_ADDRESS	SYSV_ARG2_QWORD
   #define ARG3_PAGE_TABLE_SIZE		SYSV_ARG3_QWORD
   #define TMP1_SWAP_REGISTER		SYSV_CALLEE_SAVED1_QWORD
   #define TMP2_ALLOC_OFFSET		SYSV_CALLEE_SAVED2_QWORD
   #define TMP3_MASK_SWAP		SYSV_CALLEE_SAVED3_QWORD


    movq $page_table, TMP1_SWAP_REGISTER   
    orq PAGE_TABLE_RW_MASK, TMP1_SWAP_REGISTER    	     
    movq TMP1_SWAP_REGISTER, page_directory

    
    movq ARG1_VIRTUAL_ADDRESS, TMP1_SWAP_REGISTER            
    movq ARG2_PHYSICAL_ADDRESS, TMP2_ALLOC_OFFSET            

    
    movq TMP2_ALLOC_OFFSET, page_table(TMP1_SWAP_REGISTER, ARG3_PAGE_TABLE_SIZE, 8)   

    
    movq page_directory, TMP1_SWAP_REGISTER
    movq TMP1_SWAP_REGISTER, X64_CONTROL_REGISTER3

    
    movq X64_CONTROL_REGISTER0, TMP1_SWAP_REGISTER
    movq PAGE_TABLE_PROT_MASK, TMP3_MASK_SWAP   
    orq TMP3_MASK_SWAP, TMP1_SWAP_REGISTER   
    movq TMP1_SWAP_REGISTER, X64_CONTROL_REGISTER0

    
    ret

    #undef ARG1_VIRITUAL_ADDRESS
    #undef ARG2_PHYSICAL_ADDRESS
    #undef TMP1_SWAP_REGISTER
