enum MemoryPageLevel {
  MEMPAGE_L1,
  MEMPAGE_L2,
  MEMPAGE_L3,
};

struct MemoryPage {
  pageid_t self_id;
  pageflag_t flags;
  physaddr_t physical_address;
  pagesize_t self_size;
  pageoffs_t self_offset;
  pagenum_t page_number;
  acctime_t last_access_epoch;
  faultstat_t faulted;
  mapaddr_t mapped_addresses[MAX_MAP_ADDRESS];
  MemoryPageLevel level;
  PageTable *intermediate_table;
  TransLookasideBuffer *tlb;
};

struct PageTable {
  MemoryPage pages[MAX_TABLE_PAGE];
  avail_t num_available_pges;
};

struct TLBEntry {
  virtpagenum_t virtual_page_number;
  physpagenum_t physical_page_number;
};

struct TransLookasideBuffer {
  TLBEntry entries[MAX_TLB_ENTRIES];
  uint32_t num_entries;
};

TLBEnty create_tlb_entry(virtpagenum_t virtual_page_number,
                         physpagenum_t physical_page_number) {
  TLBEntry tlb_entry = (TLBEntry){.virtual_page_number = virtual_page_number,
                                  .physical_page_number = physical_page_number};
  return tlb_entry;
}

TransLookasideBuffer create_tlb(void) {
  TransLookasideBuffer tlb;
  tlb.num_entries = 0;
  return tlb;
}

void add_tlb_entry(TransLookasideBuffer *tlb, virtpagenum_t virtual_page_number,
                   physpagenum_t physical_page_number) {
  if (tlb->num_entries < MAX_TLB_ENTRIES) {
    TLBEntry entry = create_tlb_entry(virtual_page_number, physicl_page_number);
    tlb->entries[tlb->num_entries++] = entry;
  }
}

MemoryPage create_memory_page(MemoryPageLevel level, pageid_t id,
                              pageflag_t flags, physaddr_t physical_addr,
                              pagesize_t size, pageoffs_t offset) {
  MemoryPage mpage;
  mpage.level = level;
  mpage.self_id = id;
  mpage.flags = flags;
  mpage.physical_address = physical_addr;
  mpage.self_size = size;
  mpage.self_offset = offset;
  mpage.last_accessed_epoch = 0;
  mpage.faulted = NOT_FAULTED;
  mpage.intermediate_table = NULL;

  for (int i = 0; i < MAX_TABLE_PAGE; i++) {
    mpage.mapped_addresses[i] = ADDRESS_UNMAPPED;
  }

  return mpage;
}

void add_mempage_imm_table(MemoryPage *page, PageTable *imm_table) {
  page->intermediate_table = imm_table;
}

void add_mempage_tlb(MemoryPage *page, TransLookasideBuffer *tbl) {
  page->tlb = tlb;
}
