import java.util.*;

public class IWSExam3
{
    public static int findWaysBruteForce(int n, String s, int k)
    {
        return countWays(s, k, 0);
    }

    public static int countWays(String s, int k, int index)
    {
        if(index == s.length())
        {
            return 1;
        }

        int ways = 0;

        int maxLength = Math.min(k, s.length() - index);

        for(int len = 1; len <= maxLength; len++)
        {
            boolean valid = true;

            for(int j = 0; j < len; j++)
            {
                if(s.charAt(index + j) != s.charAt(j))
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
            {
                ways += countWays(s, k, index + len);
            }
        }

        return ways;
    }

    public static int findWaysOptimised(int n, String s, int k)
    {
        int[] z = new int[n];

        z[0] = n;

        int left = 0;
        int right = 0;

        for(int i = 1; i < n; i++)
        {
            if(i <= right)
            {
                z[i] = Math.min(right - i + 1, z[i - left]);
            }

            while(i + z[i] < n &&
                  s.charAt(z[i]) == s.charAt(i + z[i]))
            {
                z[i]++;
            }

            if(i + z[i] - 1 > right)
            {
                left = i;
                right = i + z[i] - 1;
            }
        }

        int[] difference = new int[n + 2];

        int[] dp = new int[n + 1];

        dp[0] = 1;

        int current = 0;

        for(int i = 0; i < n; i++)
        {
            current += difference[i];

            dp[i] = current;

            if(i == 0)
            {
                dp[i] = 1;
            }

            int maxLength = Math.min(k, z[i]);

            if(maxLength > 0)
            {
                int start = i + 1;
                int end = Math.min(n, i + maxLength);

                difference[start] += dp[i];

                difference[end + 1] -= dp[i];
            }
        }

        current += difference[n];

        dp[n] = current;

        return dp[n];
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		
		System.out.println();

        int n = sc.nextInt();
        String s = sc.next();
        int k = sc.nextInt();

        // int result = findWaysBruteForce(n, s, k);

        int result = findWaysOptimised(n, s, k);
		
		System.out.println();

        System.out.println(result);

        sc.close();
    }
}

/*
PROBLEM: Count Valid Song Partitions

PROBLEM STATEMENT:

A song is represented by a string S of length N.

The song must be divided into one or more non-empty, contiguous pieces.

Every piece must satisfy the following conditions:

1. The piece must be a prefix of the original string S.
2. The length of the piece must not exceed K.
3. Every character of the original string must belong to exactly
   one piece.
4. The pieces must remain in their original order.

A prefix is a substring that starts at the first character of a string.

For example, the prefixes of "aab" are:
"a", "aa", "aab"

The strings "b" and "ab" are not prefixes of "aab".

Find the total number of valid ways to divide the original string
into pieces satisfying all the conditions.

INPUT FORMAT:

The first line contains an integer N, representing the length
of the original string.

The second line contains the string S.

The third line contains an integer K, representing the maximum
permitted length of each piece.

INPUT 1:

3
aaa
2

OUTPUT 1:

3

EXPLANATION:

The original string is "aaa", and K = 2.

The valid partitions are:

1. "a" | "a" | "a"
2. "a" | "aa"
3. "aa" | "a"

Every piece is a prefix of the original string, and every piece
has a length no greater than 2.

The partition "aaa" is not permitted because its length is 3,
which exceeds K = 2.

Therefore, the answer is 3.

INPUT 2:

3
aaa
3

OUTPUT 2:

4

EXPLANATION:

The original string is "aaa", and K = 3.

The valid partitions are:

1. "a" | "a" | "a"
2. "a" | "aa"
3. "aa" | "a"
4. "aaa"

The entire string "aaa" is also a prefix of itself and its length
does not exceed K = 3.

Therefore, the answer is 4.

INPUT 3:

3
aab
3

OUTPUT 3:

1

EXPLANATION:

The original string is "aab", and K = 3.

The valid partition is:

"aab"

The other possible partitions are invalid:

"a" | "a" | "b":
The piece "b" is not a prefix of "aab".

"a" | "ab":
The piece "ab" is not a prefix of "aab".

"aa" | "b":
The piece "b" is not a prefix of "aab".

Therefore, only one valid partition exists.

The answer is 1.

BRUTE-FORCE METHOD:

The brute-force method uses recursion to explore all valid partitions.

The recursive function receives the current index of the string.

If the current index reaches the end of the string, one complete
valid partition has been found, so the function returns 1.

Otherwise, the function tries every possible piece length from
1 to K, provided that the piece does not extend beyond the string.

For each candidate piece, it compares the characters against
the corresponding prefix of the original string.

If every character matches, the piece is a valid prefix.

The function then recursively counts the valid partitions
of the remaining suffix.

The results from all valid choices are added together.

The initial call starts at index 0.

TIME AND SPACE COMPLEXITY:

Time Complexity: Exponential in the worst case.

Auxiliary Space Complexity: O(N), excluding integer overflow
and the recursion's returned values.

OPTIMISED METHOD:

The optimised method uses the Z-algorithm and dynamic programming.

PART 1: Z-ALGORITHM

The Z-array stores the length of the longest prefix match
starting at each index of the original string.

For example, for S = "aaa":

Index 0: Z[0] = 3
Index 1: Z[1] = 2
Index 2: Z[2] = 1

These values indicate how many consecutive characters starting
at each index match the original string's prefix.

At index i, the maximum valid piece length is:

min(K, Z[i])

This determines the valid piece lengths at that position.

PART 2: DYNAMIC PROGRAMMING

Let dp[i] represent the number of valid ways to partition
the first i characters of the string.

Initially:

dp[0] = 1

There is one way to partition an empty prefix: choose no pieces.

If a valid piece can start at index i and have a length between
1 and maxLength, it can extend a valid partition to endpoints
from i + 1 through i + maxLength.

Therefore, dp[i] contributes to every endpoint in that range.

The optimised method uses a difference array to add this
contribution to an entire range efficiently.

The final answer is dp[N].

WHY INT IS USED:

The answer is stored using Java's int data type.

An int can store values from -2,147,483,648 to 2,147,483,647.

If the number of valid partitions exceeds this range, integer
overflow can occur. The maximum input constraint must therefore
be checked before using int for every possible input.

TIME AND SPACE COMPLEXITY:

Z-Algorithm Time Complexity: O(N)

Dynamic Programming Time Complexity: O(N)

Total Time Complexity: O(N)

Auxiliary Space Complexity: O(N)

CONCLUSION:

The brute-force method explores all possible valid partitions
using recursion.

The optimised method uses the Z-algorithm to determine valid
piece lengths and dynamic programming to count the partitions.

The optimised method avoids exploring every partition separately
and runs in linear time, provided integer arithmetic remains
within the supported range.
*/
