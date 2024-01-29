import std.bitmanip;

enum PAGE_SIZE = 4096;


struct PML4Entry {
    ulong present : 1;
    ulong readWrite : 1;
    ulong userSupervisor : 1;
    ulong writeThrough : 1;
    ulong cacheDisable : 1;
    ulong accessed : 1;
    ulong reserved1 : 1;
    ulong size : 1;
    ulong reserved2 : 3;
    ulong physicalAddress : 40;
    ulong reserved3 : 11;
    ulong executeDisable : 1;

    ulong getPhysicalAddress() {
        return physicalAddress << 12;
    }
}

struct PDPTEntry {
    ulong present : 1;
    ulong readWrite : 1;
    ulong userSupervisor : 1;
    ulong writeThrough : 1;
    ulong cacheDisable : 1;
    ulong accessed : 1;
    ulong reserved1 : 1;
    ulong largePage : 1;
    ulong reserved2 : 3;
    ulong physicalAddress : 40;
    ulong reserved3 : 11;
    ulong executeDisable : 1;

    ulong getPhysicalAddress() {
        return physicalAddress << 12;
    }
}

struct PDEntry {
    ulong present : 1;
    ulong readWrite : 1;
    ulong userSupervisor : 1;
    ulong writeThrough : 1;
    ulong cacheDisable : 1;
    ulong accessed : 1;
    ulong reserved1 : 1;
    ulong largePage : 1;
    ulong reserved2 : 3;
    ulong physicalAddress : 40;
    ulong reserved3 : 11;
    ulong executeDisable : 1;

    ulong getPhysicalAddress() {
        return physicalAddress << 12;
    }
}

struct PTEntry {
    ulong present : 1;
    ulong readWrite : 1;
    ulong userSupervisor : 1;
    ulong writeThrough : 1;
    ulong cacheDisable : 1;
    ulong accessed : 1;
    ulong dirty : 1;
    ulong size : 1;
    ulong reserved1 : 4;
    ulong physicalAddress : 40;
    ulong reserved2 : 11;
    ulong executeDisable : 1;

    ulong getPhysicalAddress() {
        return physicalAddress << 12;
    }
}

struct VirtualAddress {
    ulong pml4Index : 9;
    ulong pdptIndex : 9;
    ulong pdIndex : 9;
    ulong ptIndex : 9;
    ulong offset : 12;

    ulong toPhysicalAddress(PTEntry ptEntry) {
        return (ptEntry.getPhysicalAddress() & ~0xFFFULL) | offset;
    }
}

