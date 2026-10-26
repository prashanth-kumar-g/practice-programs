import java.util.*;

public class IWSExam2
{
	public static int findStripsBruteForce(int n, int[][] clips, int L, int W)
	{
		boolean[] visited = new boolean[n];
		ArrayList<ArrayList<Integer>> groups = new ArrayList<>();

		for(int i = 0; i < n; i++)
		{
			if(visited[i])
			{
				continue;
			}

			ArrayList<Integer> group = new ArrayList<>();

			for(int j = i; j < n; j++)
			{
				if(clips[i][0] == clips[j][0])
				{
					visited[j] = true;
					group.add(clips[j][1]);
				}
			}

			groups.add(group);
		}

		int strips = 0;
		int currentCount = 0;
		int currentWidth = 0;

		for(ArrayList<Integer> group : groups)
		{
			int groupCount = group.size();
			int groupWidth = 0;

			for(int width : group)
			{
				groupWidth += width;
			}

			if(groupCount <= L && groupWidth <= W)
			{
				if(currentCount + groupCount > L ||
				   currentWidth + groupWidth > W)
				{
					currentCount = 0;
					currentWidth = 0;
				}

				if(currentCount == 0)
				{
					strips++;
				}

				currentCount += groupCount;
				currentWidth += groupWidth;
			}
			else
			{
				for(int width : group)
				{
					if(width > W || L < 1)
					{
						return -1;
					}

					if(currentCount + 1 > L ||
					   currentWidth + width > W)
					{
						currentCount = 0;
						currentWidth = 0;
					}

					if(currentCount == 0)
					{
						strips++;
					}

					currentCount++;
					currentWidth += width;
				}
			}
		}

		return strips;
	}
	
    public static int findStripsOptimised(int n, int[][] clips, int L, int W)
	{
		LinkedHashMap<Integer, ArrayList<Integer>> groups = new LinkedHashMap<>();

		for(int i = 0; i < n; i++)
		{
			groups.putIfAbsent(clips[i][0], new ArrayList<>());
			groups.get(clips[i][0]).add(clips[i][1]);
		}

		int strips = 0;
		int currentCount = 0;
		int currentWidth = 0;

		for(ArrayList<Integer> group : groups.values())
		{
			int groupCount = group.size();
			int groupWidth = 0;

			for(int width : group)
			{
				groupWidth += width;
			}

			if(groupCount <= L && groupWidth <= W)
			{
				if(currentCount + groupCount > L ||
				   currentWidth + groupWidth > W)
				{
					currentCount = 0;
					currentWidth = 0;
				}

				if(currentCount == 0)
				{
					strips++;
				}

				currentCount += groupCount;
				currentWidth += groupWidth;
			}
			else
			{
				for(int width : group)
				{
					if(width > W || L < 1)
					{
						return -1;
					}

					if(currentCount + 1 > L ||
					   currentWidth + width > W)
					{
						currentCount = 0;
						currentWidth = 0;
					}

					if(currentCount == 0)
					{
						strips++;
					}

					currentCount++;
					currentWidth += width;
				}
			}
		}

		return strips;
	}

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		
		System.out.println();

        int n = sc.nextInt();

        int[][] clips = new int[n][2];
		
		System.out.println();

        for(int i = 0; i < n; i++)
        {
            clips[i][0] = sc.nextInt();
            clips[i][1] = sc.nextInt();
        }

        int L = sc.nextInt();
        int W = sc.nextInt();

        // int result = findStripsBruteForce(n, clips, L, W);

        int result = findStripsOptimised(n, clips, L, W);
		
		System.out.println();

        System.out.println(result);

        sc.close();
    }
}

/*
PROBLEM: Minimum Number of Strips

PROBLEM STATEMENT:

You are given N clips.

Each clip is represented by two integers stored in a two-dimensional
array named clips.

clips[i][0] represents the position of the clip.
clips[i][1] represents the width of the clip.

The clips must be arranged into strips.

Each strip must satisfy these two conditions:

1. The number of clips in a strip must not exceed L.
2. The combined width of the clips in a strip must not exceed W.

Clips having the same position must be grouped together whenever
the entire group satisfies both the L and W conditions.

The groups are processed in the order in which their positions
first appear in the input.

If a complete group cannot fit within the limits L and W by itself,
its individual clips are processed separately.

If adding a group or an individual clip exceeds either limit,
a new strip must be started.

The objective is to find the minimum number of strips required.

INPUT FORMAT:

The first line contains an integer N, representing the number of clips.

The next N lines contain two integers:
The first integer represents the position.
The second integer represents the width.

The next line contains an integer L, representing the maximum number
of clips allowed in a strip.

The final line contains an integer W, representing the maximum
combined width allowed in a strip.

INPUT:

4
1 6
2 3
2 3
3 6
5
9

INPUT EXPLANATION:

N = 4, meaning there are four clips.

The clips are:

Clip 1: Position = 1, Width = 6
Clip 2: Position = 2, Width = 3
Clip 3: Position = 2, Width = 3
Clip 4: Position = 3, Width = 6

L = 5, meaning a strip can contain at most five clips.

W = 9, meaning the combined width of a strip cannot exceed 9.

EXPLANATION:

Step 1: Group clips with the same position.

Position 1:
Number of clips = 1
Combined width = 6

Position 2:
Number of clips = 2
Combined width = 3 + 3 = 6

Position 3:
Number of clips = 1
Combined width = 6

All three groups individually satisfy L = 5 and W = 9.

Step 2: Place the first group.

The first group has one clip with width 6.

Strip 1:
Number of clips = 1
Combined width = 6

Step 3: Consider the second group.

The second group contains two clips with a combined width of 6.

If both groups were placed in the same strip:

Total number of clips = 1 + 2 = 3
Total width = 6 + 6 = 12

The clip count satisfies L = 5, but the width exceeds W = 9.

Therefore, the second group must be placed in Strip 2.

Strip 2:
Number of clips = 2
Combined width = 6

Step 4: Consider the third group.

The third group has one clip with width 6.

Combining it with the second group would give:

Total number of clips = 2 + 1 = 3
Total width = 6 + 6 = 12

The combined width exceeds W = 9.

Therefore, the third group must be placed in Strip 3.

FINAL ARRANGEMENT:

Strip 1: Position 1, width 6
Strip 2: Position 2, widths 3 and 3
Strip 3: Position 3, width 6

OUTPUT:

3

BRUTE-FORCE METHOD:

The brute-force method uses a boolean array named visited to identify
clips that have already been grouped.

For every unvisited clip, it checks the remaining clips to find those
having the same position.

The widths of the clips belonging to each group are stored in an
ArrayList.

After creating the groups, the algorithm processes them in order.

If a group satisfies both L and W by itself, the algorithm attempts
to place the entire group in the current strip.

If the group does not fit in the current strip, a new strip is started.

If the group itself exceeds L or W, its clips are processed individually.

Before placing an individual clip, the algorithm checks whether adding
it would exceed the clip count or combined width limit.

If either limit would be exceeded, a new strip is started.

The total number of strips is returned.

TIME AND SPACE COMPLEXITY:

Time Complexity: O(N^2)
Auxiliary Space Complexity: O(N)

OPTIMISED METHOD:

The optimised method uses a LinkedHashMap to group clips by position.

Each key represents a distinct clip position.

Each value stores the widths of the clips having that position.

LinkedHashMap preserves the order in which distinct positions first
appear in the input.

This avoids repeatedly comparing every clip with every other clip
to identify groups.

After grouping the clips, the algorithm processes each group.

If the group satisfies both limits, it is kept together.

If the group exceeds either limit by itself, its individual clips
are processed separately.

Before adding a group or individual clip, the algorithm checks
whether the current strip would exceed L or W.

If a limit would be exceeded, it starts a new strip.

Finally, it returns the total number of strips.

TIME AND SPACE COMPLEXITY:

Average Time Complexity: O(N)
Auxiliary Space Complexity: O(N)

CONCLUSION:

The brute-force method identifies groups using nested loops,
resulting in O(N^2) time complexity.

The optimised method uses a LinkedHashMap to group clips efficiently,
resulting in O(N) average time complexity.

Both methods use additional space to store the groups.

The optimised method is preferable for larger inputs.
*/
