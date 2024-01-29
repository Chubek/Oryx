#include <stdbool.h>
#include <stdint.h>

#include "asm-interface-decl.h"
#include "oryx.h"

struct VirtualPageTableEntry {
  address_t base_address;
  address_t virtual_address;
  address_t physical_address;
  bool protect_read;
  bool protect_write;
  bool protect_exec;
  int flags;
  size_t size;
};

struct VirtualPageTable {
  VirtualPageTableEntry *entries[MAX_VIRTUAL_PAGE_TABLE_ENTRIES];
  size_t num_allocated;
};

struct PageDirectory {
  VirtualPageTable *tables[MAX_VIRTUALA_PAGE_DIRECTORY_TABLES];
  size_t num_allocated;
};

VirtualPageTableEntry new_page_table_entry(address_t base_address, int flags) {
  VirtualPageTableEntry entry;
  entry.base_address = base_address;
  entry.virtual_address = ADDRESS_UNASSIGNED;
  entry.physical_address = ADDRESS_UNASSIGNED;
  entry.protect_read = false;
  entry.protect_write = false;
  entry.protect_exec = false;
  entry.flags = flags;
  return entry;
}

void page_table_entry_set_virtual_address(VirtualPageTableEntry *entry,
                                          address_t virtual_address) {
  entry->virtual_address = virtual_address;
}

void page_table_entry_set_physcial_address(VirtualPageTableEntry *entry,
                                           address_t physical_address) {
  entry->physical_address = physical_address;
}

void page_table_entry_protect_read(VirtualPageTableEntry *entry) {
  entry->protect_read = true;
}

void page_table_entry_protect_write(VirtualPageTableEntry *entry) {
  entry->protect_write = true;
}

void page_table_entry_protect_exec(VirtualPageTableEntry *entry) {
  entry->protect_exec = true;
}

void page_table_entry_unprotect_read(VirtualPageTableEntry *entry) {
  entry->protect_read = false;
}

void page_table_entry_unprotect_write(VirtualPageTableEntry *entry) {
  entry->protect_write = false;
}

void page_table_entry_unprotect_exec(VirtualPageTableEntry *entry) {
  entry->protect_exec = false;
}
