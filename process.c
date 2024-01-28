enum ProcessState {
   NEW,
   READY,
   RUNNING,
   WAITING,
   TERMINATED,
   ZOMBIE,
};

enum ProcessBondage {
   IOBound,
   CPUBound,
};

struct ProcessControlBlock {
   procid_t self_id;
   procid_t parent_id;
   pc_t program_counter;
   char process_name[MAX_PROCESS_NAME];
   threadid_t threads_id[MAX_THREAD_NUM];
   fileid_t open_files[MAX_OPEN_FILES];
   registerid_t allocated_registers[MAX_ARCH_REGISTER];
   ProcessState state;
   ProcessBondage bondage;
   MemoryInfo memory_info;
   SchedulingInfo sched_info;
};

ProcessControlBlock create_process_control_block(procid_t parent_id, 
		char name[MAX_PROCESS_NAME], ProcessBondage bondage) {
   ProcessControlBlock pcb; 
   pcb.self_id = parent_id + 1;
   pcb.parent_id = parent_id;
   pcb.program_counter = 0;

   for (int i = 0; i < MAX_PROCESS_NAME - 1 && name[i] != '\0'; ++i) {
      pcb.process_name[i] = name[i];
   }
   pcb.process_name[MAX_PROCESS_NAME - 1] = '\0';

   for (int i = 0; i < MAX_THREAD_NUM; ++i) {
      pcb.threads_id[i] = 0;
   }

   for (int i = 0; i < MAX_OPEN_FILES; ++i) {
      pcb.open_files[i] = 0;
   }

   for (int i = 0; i < MAX_ARCH_REGISTER; ++i) {
      pcb.allocated_registers[i] = 0;
   }

   pcb.state = NEW;
   pcb.bondage = bondage;

   pcb.memory_info = create_empty_memory_info();
   pcb.sched_info = create_empty_sched_info();

   return pcb;
}
