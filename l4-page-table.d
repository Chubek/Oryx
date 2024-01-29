enum uint PAGE_SIZE = 4096;  


struct PML4Entry {
    uint64_t present : 1;      
    uint64_t readWrite : 1;    
    uint64_t userSupervisor : 1; 
    uint64_t writeThrough : 1;  
    uint64_t cacheDisable : 1;  
    uint64_t accessed : 1;      
    uint64_t reserved1 : 1;     
    uint64_t size : 1;          
    uint64_t reserved2 : 3;     
    uint64_t physicalAddress : 40;  
    uint64_t reserved3 : 11;    
    uint64_t executeDisable : 1;   
}


struct PDPTEntry {
    uint64_t present : 1;
    uint64_t readWrite : 1;
    uint64_t userSupervisor : 1;
    uint64_t writeThrough : 1;
    uint64_t cacheDisable : 1;
    uint64_t accessed : 1;
    uint64_t reserved1 : 1;
    uint64_t largePage : 1;     
    uint64_t reserved2 : 3;
    uint64_t physicalAddress : 40;
    uint64_t reserved3 : 11;
    uint64_t executeDisable : 1;
}


struct PDEntry {
    uint64_t present : 1;
    uint64_t readWrite : 1;
    uint64_t userSupervisor : 1;
    uint64_t writeThrough : 1;
    uint64_t cacheDisable : 1;
    uint64_t accessed : 1;
    uint64_t reserved1 : 1;
    uint64_t largePage : 1;
    uint64_t reserved2 : 3;
    uint64_t physicalAddress : 40;
    uint64_t reserved3 : 11;
    uint64_t executeDisable : 1;
}


struct PTEntry {
    uint64_t present : 1;
    uint64_t readWrite : 1;
    uint64_t userSupervisor : 1;
    uint64_t writeThrough : 1;
    uint64_t cacheDisable : 1;
    uint64_t accessed : 1;
    uint64_t dirty : 1;         
    uint64_t size : 1;          
    uint64_t reserved1 : 4;
    uint64_t physicalAddress : 40;
    uint64_t reserved2 : 11;
    uint64_t executeDisable : 1;
}
