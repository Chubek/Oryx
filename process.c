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

enum ProcessPriority {
  SUPER_HIGH = 10,
  VERY_HIGH = 8,
  HIGH = 6,
  MEDIUM = 4,
  LOW = 2,
  SUPER_LOW = 0,
};

enum ProcessEagerness {
  SUPER_EAGER = 11,
  VERY_EAGER = 9,
  EAGER = 7,
  SOME_EAGER = 5,
  SMALL_EAGER = 3,
  NOT_EAGER = 1,
};

struct ProcessControlBlock {
  procid_t self_id;
  procid_t parent_id;
  pc_t program_counter;
  char process_name[MAX_PROCESS_NAME];
  threadid_t threads_id[MAX_THREAD_NUM];
  fileid_t open_files[MAX_OPEN_FILES];
  exitcode_t exit_code;
  registerid_t allocated_registers[MAX_ARCH_REGISTER];
  ProcessState state;
  ProcessBondage bondage;
  ProcessPriority prio;
  ProcessEagerness eagerness;
  MemoryInfo memory_info;
  SchedulingInfo sched_info;
};

struct ShortTermScheduler {
  procid_t io_queue[MAX_SHORT_TERM_QUEUE];
  procid_t cpu_queue[MAX_SHORT_TERM_QUEUE];
  procid_t waiting[MAX_SHORT_TERM_WAITING];
  procid_t ready[MAX_SHORT_TERM_READY];
  procid_t dispatched[MAX_SHORT_TERM_DISPATCHED];
  queueindex_t io_queue_index;
  queueindex_t cpu_queue_index;
  processnum_t last_waiting_index;
  processnum_t last_ready_index;
  processnum_t last_dispatched_index;
};

struct LongTermScheduler {
  procid_t io_queue[MAX_LONG_TERM_QUEUE];
  procid_t cpu_quue[MAX_LONG_TERM_QUEUE];
  pcocid_t waiting[MAX_LONG_TERM_WAIING];
  procid_t ready[MAX_LONG_TERM_READY];
  procid_t dispatched[MAX_LONG_TERM_DISPATCHED];
  queueindex_t io_queue_index;
  queueindex_t cpu_queue_index;
  processnum_t last_waiting_index;
  processnum_t last_ready_index;
  processnum_t last_dispatched_index;
};

struct ProcessScheduler {
  ProcessControlBlock *processes[MAX_PROCESS_NUM];
  ShortTermSchedular short_term_scheduler;
  LongTermScheduler long_term_scheduler;
  processnum_t last_process_index;
};

ProcessControlBlock create_process_control_block(procid_t parent_id,
                                                 char name[MAX_PROCESS_NAME],
                                                 ProcessBondage bondage) {
  ProcessControlBlock pcb;
  pcb.self_id = parent_id + 1;
  pcb.parent_id = parent_id;
  pcb.program_counter = 0;
  pcb.exit_code = 0;

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

ShortTermScheduler create_short_term_scheduler(void) {
  ShortTermScheduler stsched;

  for (int i = 0; i < MAX_SHORT_TERM_QUEUE; i++) {
    stsched.io_queue[i] = 0;
  }

  for (int i = 0; i < MAX_SHORT_TERM_QUEUE; i++) {
    stsched.cpu_queue[i] = 0;
  }

  for (int i = 0; i < MAX_SHORT_TERM_WITING; i++) {
    stsched.waiting[i] = 0;
  }

  for (int i = 0; i < MAX_SHORT_TERM_READY; i++) {
    stsched.ready[i] = 0;
  }

  for (int i = 0; i < MAX_SHORT_TERM_DISPATCHED; i++) {
    stsched.dispatched[i] = 0;
  }

  return stsched;
}

ShortTermScheduler create_long_term_scheduler(void) {
  LongTermScheduler ltsched;

  for (int i = 0; i < MAX_LONG_TERM_QUEUE; i++) {
    ltsched.io_queue[i] = 0;
  }

  for (int i = 0; i < MAX_LONG_TERM_QUEUE; i++) {
    ltsched.cpu_queue[i] = 0;
  }

  for (int i = 0; i < MAX_LONG_TERM_WITING; i++) {
    ltsched.waiting[i] = 0;
  }

  for (int i = 0; i < MAX_LONG_TERM_READY; i++) {
    ltsched.ready[i] = 0;
  }

  for (int i = 0; i < MAX_LONG_TERM_DISPATCHED; i++) {
    ltsched.dispatched[i] = 0;
  }

  return ltsched;
}

ProcessScheduler create_process_scheduler(void) {
  ProcessScheduler sched;

  for (processnum_t i = 0; i < MAX_PROCESS_NUM; i++) {
    sched.processes[i] = NULL;
  }

  sched.short_term_scheduler = create_short_term_scheduler();
  sched.long_term_scheduler = create_long_term_scheduler();
  sched.last_process_index = 0;
}

void process_schedular_add_pcb(ProcessScheduler *sched,
                               ProcessControlBlock *pcb) {
  sched.processes[sched.last_process_index++] = pcb;
}
