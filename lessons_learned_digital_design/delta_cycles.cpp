#include <systemc.h>

SC_MODULE(Testbench) {
    sc_event trigger_event;

    void process1() {
        wait(trigger_event);  // wartet auf das Ereignis
        cout << "Process 1 reagiert bei Zeit: " << sc_time_stamp() << endl;
    }

    void process2() {
        wait(trigger_event);  // wartet ebenfalls
        cout << "Process 2 reagiert bei Zeit: " << sc_time_stamp() << endl;
    }

    void starter() {
        cout << "Starter löst Ereignis aus bei Zeit: " << sc_time_stamp() << endl;
        trigger_event.notify();  // löst das Ereignis aus
    }

    SC_CTOR(Testbench) {
        SC_THREAD(process1);
        SC_THREAD(process2);
        SC_THREAD(starter);
    }
};

int sc_main(int argc, char* argv[]) {
    Testbench tb("tb");
    sc_start();  // startet die Simulation
    return 0;
}
