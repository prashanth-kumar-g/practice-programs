import java.util.*;

public class IWSExam1
{
    public static int findDepthLevelBruteForce(int n, String[] ops)
    {
        Stack<String> directories = new Stack<>();

        for(int i = 0; i < n; i++)
        {
            if(ops[i].equals("../"))
            {
                if(!directories.isEmpty())
                {
                    directories.pop();
                }
            }
            else if(ops[i].equals("./"))
            {
                continue;
            }
            else if(ops[i].equals("~/"))
            {
                directories.clear();
            }
            else
            {
                directories.push(ops[i]);
            }
        }

        return directories.size();
    }

    public static int findDepthLevelOptimised(int n, String[] ops)
    {
        int result = 0;

        for(int i = 0; i < n; i++)
        {
            if(ops[i].equals("../"))
            {
                if(result > 0)
                {
                    result--;
                }
            }
            else if(ops[i].equals("./"))
            {
                continue;
            }
            else if(ops[i].equals("~/"))
            {
                result = 0;
            }
            else
            {
                result++;
            }
        }

        return result;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		
		System.out.println();

        int n = sc.nextInt();
        sc.nextLine();

        String[] ops = new String[n];
		
		System.out.println();

        for(int i = 0; i < n; i++)
        {
            ops[i] = sc.nextLine().trim();
        }
		
		// int depthLevel = findDepthLevelBruteForce(n, ops);

        int depthLevel = findDepthLevelOptimised(n, ops);
		
		System.out.println();

        System.out.println(depthLevel);

        sc.close();
    }
}

/*
PROBLEM: Directory Depth

PROBLEM STATEMENT:

A user starts in the home directory and performs N directory navigation
operations. Calculate the final directory depth after all operations.

OPERATIONS:

1. Directory name such as d1/:
   Enter a subdirectory and increase the depth by 1.

2. ../:
   Move to the parent directory. Decrease the depth by 1 only if the
   current depth is greater than 0.

3. ~/:
   Return to the home directory. Set the depth to 0.

4. ./:
   Remain in the current directory. The depth does not change.

INPUT FORMAT:

The first line contains an integer N, representing the number of operations.

The next N lines contain the directory navigation operations.

INPUT:

5
d1/
d2/
../
d21/
./

INPUT EXPLANATION:

N = 5, meaning five directory navigation operations are performed.

Initially, the user is in the home directory at depth 0.

EXPLANATION:

Operation 1: d1/
Enter directory d1/. Depth becomes 1.

Operation 2: d2/
Enter directory d2/. Depth becomes 2.

Operation 3: ../
Move to the parent directory. Depth becomes 1.

Operation 4: d21/
Enter directory d21/. Depth becomes 2.

Operation 5: ./
Remain in the current directory. Depth remains 2.

OUTPUT:

2

BRUTE-FORCE METHOD:

The stack-based method stores the directory names representing the current
path. Entering a directory pushes its name onto the stack. The ../
operation removes the top directory if the stack is not empty. The ~/
operation clears the stack, and ./ does nothing.

The final stack size gives the directory depth.

OPTIMISED METHOD:

The optimised method maintains only an integer variable named result.

Initially, result is 0.

Entering a directory increases result by 1.

The ../ operation decreases result by 1 only if result is greater than 0.

The ~/ operation resets result to 0.

The ./ operation does not change result.

The final value of result gives the directory depth.

TIME AND SPACE COMPLEXITY:

Stack-Based Method:
Time Complexity: O(N)
Auxiliary Space Complexity: O(N)

Optimised Method:
Time Complexity: O(N)
Auxiliary Space Complexity: O(1)

CONCLUSION:

The optimised method uses less auxiliary space because it stores only the
current depth instead of maintaining the directory names.
*/
