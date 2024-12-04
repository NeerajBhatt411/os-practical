// pseduocode 
// Banker's Algorithm(Available, Max, Allocation, Need, n, m)
//     Work = Available
//     Finish = [false for i in range(n)]

//     while True:
//         found = False
//         for i in range(n):
//             if not Finish[i] and Need[i] <= Work:
//                 Work = Work + Allocation[i]
//                 Finish[i] = True
//                 found = True

//         if not found:
//             break

//     if all(Finish):
//         return "System is in a safe state"
//     else:
//         return "System is in an unsafe state"


 // algorithm 

//  the Banker’s Algorithm for deadlock avoidance:

// Input:

// n: Number of processes.
// m: Number of resource types
// .
// Available: Vector of size m indicating available resources of each type.

// Max: Matrix of size n x m where Max[i][j] is the maximum demand of process i for resource type j.

// Allocation: Matrix of size n x m where Allocation[i][j] is the number of resources of type j currently allocated to process i.

// Need: Matrix of size n x m calculated as Need[i][j] = Max[i][j] - Allocation[i][j].
// Initialization:

// Work = Available (work represents available resources).
// Finish[i] = false for all i (indicating that no process is initially finished).
// Safety Algorithm:

// While there exists an unfinished process i such that Need[i] <= Work:

// Set Work = Work + Allocation[i] (release resources).

// Set Finish[i] = true (mark process as finished).
// If Finish[i] = true for all i, then the system is in a safe state; otherwise, it is not.
// Request Algorithm:

// If Request[i] <= Need[i] for process i, proceed.

// If Request[i] <= Available, temporarily allocate the resources:

// Set Available = Available - Request[i].

// Set Allocation[i] = Allocation[i] + Request[i].
// Set Need[i] = Need[i] - Request[i].
// Check if the system is in a safe state using the Safety Algorithm.
// If the system is safe, grant the request.
// If the system is not safe, revert to the previous state.
