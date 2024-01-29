#include <stdint.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define X64_PAGE_TABLE_ENTRIES 512

struct X64PageTableEntry {
  uint64_t present : 1;
  uint64_t writable : 1;
  uint64_t user_accessible : 1;
  uint64_t write_through : 1;
  uint64_t cache_disabled : 1;
  uint64_t accessed : 1;
  uint64_t dirty : 1;
  uint64_t huge_page : 1;
  uint64_t global : 1;
  uint64_t reserved1 : 3;
  uint64_t address : 40;
  uint64_t reserved2 : 11;
  uint64_t no_execute : 1;
};

struct X64PageTable {
  X64PageTableEntry entries[X64_PAGE_TABLE_ENTRIES];
};

struct X64PageDirectoryPointerTable {
  X64PageTable *page_tables[X64_PAGE_TABLE_ENTRIES];
};

struct X64PageDirectory {
  X64PageTable *page_tables[X64_PAGE_TABLE_ENTRIES];
};

struct X64PageTable {
  X64PageTable *page_tables[X64_PAGE_TABLE_ENTRIES];
};

struct X64PageMapLevel4 {
  X64PageDirectoryPointerTable *pdpts[X64_PAGE_TABLE_ENTRIES];
};

void initialize_page_table_entry(X64PageTableEntry *entry, uint64_t address,
                                 int present, int writable,
                                 int user_accessible) {
  entry->address = address;
  entry->present = present;
  entry->writable = writable;
  entry->user_accessible = user_accessible;
}

void initialize_page_table(X64PageTable *pageTable) {
  for (int i = 0; i < X64_PAGE_TABLE_ENTRIES; ++i) {
    initialize_page_table_entry(&(pageTable->entries[i]), 0, 0, 0, 0);
  }
}

void initialize_pdpt(X64PageDirectoryPointerTable *pdpt) {
  for (int i = 0; i < X64_PAGE_TABLE_ENTRIES; ++i) {
    pdpt->page_tables[i] = NULL;
  }
}

void initialize_pd(X64PageDirectory *pd) {
  for (int i = 0; i < X64_PAGE_TABLE_ENTRIES; ++i) {
    pd->page_tables[i] = NULL;
  }
}

void intialize_pt(X64PageTable *pt) {
  for (int i = 0; i < X64_PAGE_TABLE_ENTRIES; ++i) {
    pt->page_tables[i] = NULL;
  }
}

void initialize_pml4(X64PageMapLevel4 *pml4) {
  for (int i = 0; i < X64_PAGE_TABLE_ENTRIES; ++i) {
    pml4->pdpts[i] = NULL;
  }
}

uint64_t translate_virtual_address(X64PageMapLevel4 *pml4,
                                   VirtualX64PageTable *vpt) {
  x64_asm_translate_virtual_address(pml4, vpt->virtual_address);
  x64_map_pml4_to_virtual_page_table(vpt, pml4);
  return 0;
}
