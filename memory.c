struct VirtualMemoryPage {
   pageid_t self_id;
   pageflag_t flags;
   physaddr_t physical_address;
   pagesize_t self_size;
   pageoffs_t self_offset;
   acctime_t last_access_epoch;
   fault_t faulted;
   mapaddr_t mapped_addresses[MAX_MAP_ADDRESS];
};

struct PageTable {
   VirtualMemoryPage pages[MAX_TABLE_PAGE];
   avail_t num_available_pges;
};


VirtualMemoryPage create_virtual_page(pageid_t id, 
		pageflag_t flags, 
		physaddr_t physical_addr,
		pagesize_t size,
		pageoffs_t offset) {
   VirtualMemoryPage vpage;
   vpage.self_id = id;
   vpage.flags = flags;
   vpage.physical_address = physical_addr;
   vpage.self_size = size;
   vpage.self_offset = offset;
   vpage.last_accessed_epoch = 0;
   vpage.faulted = NOT_FAULTED;

   for (int i = 0; i < MAX_TABLE_PAGE; i++) {
	vpage.mapped_addresses[i] = ADDRESS_UNMAPPED;
   }

   return vpage;
}
