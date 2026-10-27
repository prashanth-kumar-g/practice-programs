import java.util.*;

public class IWSExam3
{
	public static int findWaysBruteForceBitMask(int n, String s, int k)
	{
		int ways = 0;

		int total = 1 << (n - 1);

		for (int mask = 0; mask < total; mask++)
		{
			int start = 0;
			boolean valid = true;

			for (int i = 0; i < n; i++)
			{
				if (i == n - 1 || (mask & (1 << i)) != 0)
				{
					int len = i - start + 1;

					if (len > k)
					{
						valid = false;
						break;
					}

					for (int j = 0; j < len; j++)
					{
						if (s.charAt(start + j) != s.charAt(j))
						{
							valid = false;
							break;
						}
					}

					if (!valid)
					{
						break;
					}

					start = i + 1;
				}
			}

			if (valid)
			{
				ways++;
			}
		}

		return ways;
	}
	
    public static int findWaysBruteForceRecursion(int n, String s, int k)
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

        // int result = findWaysBruteForceBitMask(n, s, k);
		
		// int result = findWaysBruteForceRecursion(n, s, k);

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
2. The length of each piece must not exceed K.
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

EXAMPLE 1:

Input:
3
aaa
2

Output:
3

Explanation:

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

EXAMPLE 2:

Input:
3
aaa
3

Output:
4

Explanation:

The original string is "aaa", and K = 3.

The valid partitions are:

1. "a" | "a" | "a"
2. "a" | "aa"
3. "aa" | "a"
4. "aaa"

The entire string "aaa" is also a prefix of itself, and its length
does not exceed K = 3.

Therefore, the answer is 4.

EXAMPLE 3:

Input:
3
aab
3

Output:
1

Explanation:

The original string is "aab", and K = 3.

The only valid partition is:

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


============================================================
METHOD 1: BRUTE FORCE USING BITMASK
============================================================

The bitmask method generates every possible arrangement of
boundaries between adjacent characters of the string.

A string of length N has N - 1 possible positions where a
partition boundary can be placed.

Each boundary has two choices:
1. Place a boundary.
2. Do not place a boundary.

Therefore, the total number of possible boundary arrangements is:

2^(N - 1)

The expression:

1 << (N - 1)

calculates this number using a bit shift.

For example, consider S = "aaa".

There are two possible boundary positions:

a _ a _ a

The four boundary arrangements are:

1. 00: "aaa"
2. 01: "a" | "aa"
3. 10: "aa" | "a"
4. 11: "a" | "a" | "a"

Each arrangement represents one possible partition.

The outer loop iterates through every bitmask.

The inner loop identifies the positions where pieces end.

For each piece, the method checks:

1. Whether its length exceeds K.
2. Whether the piece matches the corresponding prefix
   of the original string.

If any piece violates either condition, the partition is invalid.

If every piece satisfies both conditions, increment the answer.

For S = "aaa" and K = 2, the partition "aaa" is invalid,
while the other three partitions are valid.

Therefore, the answer is 3.

TIME COMPLEXITY:

There are 2^(N - 1) possible boundary arrangements.

For each arrangement, the method examines the string and may
compare characters for each piece.

Worst-case Time Complexity: O(2^N * N^2)

A tighter bound for this implementation is O(2^N * N),
because the total number of characters compared across all
pieces of one partition is at most N, and each partition is
processed in O(N) time.

Auxiliary Space Complexity: O(1)


============================================================
METHOD 2: BRUTE FORCE USING RECURSION
============================================================

The recursive method explores every possible valid piece length
at the current position.

The function countWays receives the current index of the string.

BASE CASE:

If index reaches the length of the string, a complete valid
partition has been found, so return 1.

RECURSIVE CASE:

Try every possible piece length from 1 to K, provided that
the piece does not extend beyond the end of the string.

For every candidate piece, compare its characters with the
corresponding prefix of the original string.

If the candidate matches the prefix, it is a valid piece.

Recursively count the valid partitions of the remaining suffix
starting at index + len.

Add the results of all valid choices and return the total.

For S = "aaa" and K = 2:

First choice: "a"
The remaining suffix is "aa", which has two valid partitions:
"a" | "a"
"aa"

Second choice: "aa"
The remaining suffix is "a", which has one valid partition:
"a"

Total valid partitions = 2 + 1 = 3.

The initial call starts at index 0.

TIME COMPLEXITY:

Exponential in the worst case because the same remaining suffix
may be solved repeatedly.

A safe upper bound is O(2^N * N * K), including the character
comparisons performed for candidate pieces.

Auxiliary Space Complexity: O(N) for the recursion stack.


============================================================
METHOD 3: OPTIMIZED Z-ALGORITHM AND DYNAMIC PROGRAMMING
============================================================

The optimized method avoids enumerating every possible partition.

It uses two techniques:

1. Z-algorithm to find valid piece lengths.
2. Dynamic programming with a difference array to count partitions.


PART 1: Z-ALGORITHM

The Z-array stores the length of the longest prefix match
starting at each index of the original string.

For S = "aaa":

Index:  0  1  2
Z:      3  2  1

At index 0, the entire string matches its prefix.

At index 1, the suffix "aa" matches the prefix "aa".

At index 2, the suffix "a" matches the prefix "a".

Therefore, Z[i] tells us the maximum possible length of a piece
starting at index i that is a prefix of S.

The maximum permitted piece length at index i is:

min(K, Z[i])


PART 2: DYNAMIC PROGRAMMING

Let dp[i] represent the number of valid ways to partition
the first i characters of the string.

INITIALIZATION:

dp[0] = 1

There is one way to partition an empty prefix: choose no pieces.

TRANSITION:

Suppose a valid partition reaches index i.

Let:

maxLength = min(K, Z[i])

A valid piece can have any length from 1 to maxLength.

Therefore, dp[i] contributes to the following positions:

dp[i + 1]
dp[i + 2]
...
dp[i + maxLength]

These contributions count the partitions obtained by adding
one valid piece to an existing partition.

Instead of updating every position individually, the algorithm
uses a difference array to apply the contribution to an entire
range efficiently.

After processing all positions, dp[N] contains the total number
of valid partitions.

TIME COMPLEXITY:

Z-algorithm: O(N)

Dynamic programming with the difference array: O(N)

Total Time Complexity: O(N)

Auxiliary Space Complexity: O(N)


============================================================
COMPARISON OF THE THREE METHODS
============================================================

1. Brute Force Using Bitmask

Explores every possible arrangement of partition boundaries.

Time Complexity: O(2^N * N)
Auxiliary Space Complexity: O(1)

2. Brute Force Using Recursion

Tries every valid piece length and recursively explores
the remaining suffix.

Time Complexity: Exponential in the worst case.
Auxiliary Space Complexity: O(N)

3. Optimized Z-Algorithm and Dynamic Programming

Uses the Z-array to determine valid piece lengths and dynamic
programming to count partitions efficiently.

Time Complexity: O(N)
Auxiliary Space Complexity: O(N)


IMPORTANT NOTE ABOUT INTEGER OVERFLOW:

All three methods return int, and the DP array also uses int.

Java int supports values from -2,147,483,648 to 2,147,483,647.

If the number of valid partitions exceeds this range, integer
overflow may occur.

The input constraints must be checked before relying on int
for large inputs.


CONCLUSION:

The bitmask method enumerates every possible boundary arrangement.

The recursive method explores possible partitions through
recursive choices.

Both are brute-force methods because they explore individual
possibilities rather than reusing previously calculated results.

The optimized method combines the Z-algorithm and dynamic
programming to calculate the answer in linear time.

For larger inputs, the optimized method is preferable.
*/
