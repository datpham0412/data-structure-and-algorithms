def calculateMaxProcessingThroughput(serverTasks):
    n = len(serverTasks)
    visited = [False] * n
    max_throughput = 0

    def process_component(start):
        stack = []
        current = start
        component_nodes = []
        cycle_detected = False
        cycle_nodes = []

        # Traverse the component
        while not visited[current]:
            visited[current] = True
            stack.append(current)
            component_nodes.append(current)
            current = serverTasks[current]

            # If we encounter a node in the stack, we found a cycle
            if current in stack:
                cycle_detected = True
                cycle_start = stack.index(current)
                cycle_nodes = stack[cycle_start:]
                break

        if cycle_detected:
            # Add the maximum node in the cycle
            max_cycle_node = max(cycle_nodes)
            print(f"Cycle detected: {cycle_nodes}, Max Node: {max_cycle_node}")
            return max_cycle_node
        else:
            # No cycle detected, return the maximum node in the entire component
            print(f"No cycle: Component Nodes: {component_nodes}, Max Node: {max(component_nodes)}")
            return max(component_nodes)

    # Iterate through all nodes
    for i in range(n):
        if not visited[i]:
            max_throughput += process_component(i)

    print(f"Final Throughput: {max_throughput}")
    return max_throughput



# Test cases
def test_specific_case():
    # Test case 1: [0,4,2,1,3] should return 9
    test1 = [0, 4, 2, 1, 3]
    result1 = calculateMaxProcessingThroughput(test1)
    print(f"Input: {test1}")
    print(f"Output: {result1}")
    print(f"Expected: 9")
    
    # Test case 2: [3,0,1,2] should return 6
    test2 = [3, 0, 1, 2]
    result2 = calculateMaxProcessingThroughput(test2)
    print(f"\nInput: {test2}")
    print(f"Output: {result2}")
    print(f"Expected: 6")

if __name__ == "__main__":
    test_specific_case()
