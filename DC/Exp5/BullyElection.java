
import java.util.*;

class Process {

    int id;
    boolean active;

    Process(int id, boolean active) {
        this.id = id;
        this.active = active;
    }
}

public class BullyElection {

    static List<Process> processes = new ArrayList<>();
    static int coordinator = -1;

    static void startElection(int initiatorId) {
        boolean higherAlive = false;

        for (Process p : processes) {
            if (p.id > initiatorId && p.active) {
                higherAlive = true;
                break;
            }
        }

        if (!higherAlive) {
            coordinator = initiatorId;
            System.out.println("Process " + coordinator + " becomes Coordinator");
        } else {
            for (Process p : processes) {
                if (p.id > initiatorId && p.active) {
                    startElection(p.id);
                    return;
                }
            }
        }
    }

    public static void main(String[] args) {
        processes.add(new Process(1, true));
        processes.add(new Process(2, true));
        processes.add(new Process(3, true));
        processes.add(new Process(4, true));
        processes.add(new Process(5, true));

        coordinator = 5;
        System.out.println("Initial Coordinator: " + coordinator);

        for (Process p : processes) {
            if (p.id == 5) {
                p.active = false;
            }
        }

        System.out.println("Coordinator 5 fails");
        startElection(2);
    }
}
