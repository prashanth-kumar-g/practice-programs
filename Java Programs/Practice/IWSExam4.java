import java.util.Scanner;

public class IWSExam4
{
    public static long countBruteForce(int N, String P, int A)
    {
        long total = 0;
        long limit = 1;

        for (int i = 0; i < A; i++)
        {
            limit *= N;
        }

        for (long num = 0; num < limit; num++)
        {
            long temp = num;
            char[] str = new char[A];

            for (int i = A - 1; i >= 0; i--)
            {
                str[i] = (char) ('a' + temp % N);
                temp /= N;
            }

            if (new String(str).contains(P) == false)
            {
                total++;
            }
        }

        return total;
    }

    public static long countOptimized(int N, String P, int A)
    {
        int M = P.length();

        int[] prefix = new int[M];

        for (int i = 1, j = 0; i < M; i++)
        {
            while (j > 0 && P.charAt(i) != P.charAt(j))
            {
                j = prefix[j - 1];
            }

            if (P.charAt(i) == P.charAt(j))
            {
                j++;
            }

            prefix[i] = j;
        }

        int[][] transition = new int[M][N];

        for (int state = 0; state < M; state++)
        {
            for (int c = 0; c < N; c++)
            {
                char ch = (char) ('a' + c);
                int j = state;

                while (j > 0 && P.charAt(j) != ch)
                {
                    j = prefix[j - 1];
                }

                if (P.charAt(j) == ch)
                {
                    j++;
                }

                transition[state][c] = (j == M) ? -1 : j;
            }
        }

        long[][] dp = new long[A + 1][M];

        dp[0][0] = 1;

        for (int length = 0; length < A; length++)
        {
            for (int state = 0; state < M; state++)
            {
                if (dp[length][state] == 0)
                {
                    continue;
                }

                for (int c = 0; c < N; c++)
                {
                    int nextState = transition[state][c];

                    if (nextState != -1)
                    {
                        dp[length + 1][nextState] += dp[length][state];
                    }
                }
            }
        }

        long total = 0;

        for (int state = 0; state < M; state++)
        {
            total += dp[A][state];
        }

        return total;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		
		System.out.println();

        int N = sc.nextInt();
        String P = sc.next();
        int A = sc.nextInt();

        // long result = countBruteForce(N, P, A);
		
        long result = countOptimized(N, P, A);
		
		System.out.println();

        System.out.println(result);

        sc.close();
    }
}

/*
PROBLEM STATEMENT

Title:
Count Valid Strings Without a Forbidden Pattern

Problem Description:
You are given an integer N, a string P, and an integer A.

The available alphabet consists of the first N lowercase English letters,
starting from 'a'.

For example:
N = 2 means the alphabet is {a, b}.
N = 3 means the alphabet is {a, b, c}.

You must construct strings of exactly length A using only these letters.

A string is valid if the forbidden pattern P does not occur anywhere
inside it as a contiguous substring.

Your task is to calculate the total number of valid strings of length A.

Input Format:
The first line contains integer N, representing the number of available
letters in the alphabet.

The second line contains string P, representing the forbidden pattern.

The third line contains integer A, representing the required length of
each generated string.

Output Format:
Print the total number of strings of length A that do not contain P
as a contiguous substring.

EXAMPLE 1

Input:
2
ab
3

Output:
4

Explanation:
The available alphabet is {a, b}, and the required length is 3.

All possible strings are:
aaa
aab
aba
abb
baa
bab
bba
bbb

The forbidden pattern is "ab".

The strings containing "ab" are:
aab
aba
abb
bab

The valid strings are:
aaa
baa
bba
bbb

Therefore, the answer is 4.

EXAMPLE 2

Input:
2
aa
3

Output:
5

Explanation:
The available alphabet is {a, b}, and the required length is 3.

All possible strings are:
aaa
aab
aba
abb
baa
bab
bba
bbb

The forbidden pattern is "aa".

The strings containing "aa" are:
aaa
aab
baa

The valid strings are:
aba
abb
bab
bba
bbb

Therefore, the answer is 5.

EXAMPLE 3

Input:
2
aa
30

Output:
2178309

Explanation:
The available alphabet is {a, b}, and the required length is 30.

A valid string must not contain two consecutive 'a' characters,
because "aa" is the forbidden pattern.

The character 'b' can appear any number of times, while each 'a'
must be separated from another 'a' by at least one 'b'.

Using dynamic programming, the number of valid strings of length 30
is 2178309.

BRUTE-FORCE APPROACH

Generate every possible string of length A using the N available
letters. Check whether each string contains the forbidden pattern P.
Count the strings that do not contain P.

Time Complexity:
O(N^A * A * M), where M is the length of P.

Auxiliary Space Complexity:
O(A), excluding input storage.

OPTIMIZED APPROACH

Use dynamic programming with the KMP prefix-matching technique.

Each state represents the length of the longest prefix of P that matches
the suffix of the string constructed so far.

First, calculate the KMP prefix array for P. Then build a transition
table that determines the next state when a character is added.

If a transition completes the forbidden pattern, reject that transition.

Let dp[length][state] represent the number of valid strings of a given
length that finish in a particular matching state.

Initialize dp[0][0] = 1.

For each length and each state, try every available character.
Update the next state only if the forbidden pattern is not completed.

Finally, sum the counts of all states after constructing A characters.

Time Complexity:
O(M^2 * N + A * M * N), where M is the length of P.

Auxiliary Space Complexity:
O(A * M + M * N).

NOTE:
The brute-force method is intended for small inputs because it generates
all N^A possible strings.

The optimized method is suitable for larger inputs, provided the answer
fits within Java's long data type.
*/
