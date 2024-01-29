#include <stdint.h>
#include <stdbool.h>

#include "oryx.h"
#include "asm-interface-decl.h"


struct PageTableEntry {
   address_t base_address;
   address_t virtual_address;
   address_t physical_address;
   bool protect_read;
   bool protect_write;
   bool protect_exec;
   int flags;
   size_t size;
};


struct PageTable {
   PageTableEntry *entries[MAX_PAGE_TABLE_ENTRIES];
   size_t num_allocated;
};


struct PageDirectory {
   PageTable *tables[MAX_PAGE_DIRECTORY_TABLES];
   size_t num_allocated;
};


PageTableEntry new_page_table_entry(address_t base_address, int flags) {
   PageTableEntry entry;
   entry.base_address = base_address;
   entry.virtual_address = ADDRESS_UNASSIGNED;
   entry.physical_address = ADDRESS_UNASSIGNED;
   entry.protect_read  = false;
   entry.protect_write = false;
   entry.protect_exec = false;
   entry.flags = flags;
   return entry;
}

void page_table_entry_set_virtual_address(PageTableEntry *entry, address_t virtual_address) {
   entry->virtual_address = virtual_address;
}

void page_table_entry_set_physcial_address(PageTableEntry *entry, address_t physical_address) {
   entry->physical_address = physical_address;
}

void page_table_entry_protect_read(PageTableEntry *entry) {
   entry->protect_read = true;
}

void page_table_entry_protect_write(PageTableEntry *entry) {
   entry->protect_write = true;
}

void page_table_entry_protect_exec(PageTableEntry *entry) {
   entry->protect_exec = true;
}

void page_table_entry_unprotect_read(PageTableEntry *entry) {
   entry->protect_read = false;
}

void page_table_entry_unprotect_write(PageTableEntry *entry) {
   entry->protect_write = false;
}

void page_table_entry_unprotect_exec(PageTableEntry *entry) {
   entry->protect_exec = false;
}









