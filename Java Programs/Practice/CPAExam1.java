import java.util.*;

public class CPAExam1 
{
    public static void main(String[] args) 
    {

        Scanner sc = new Scanner(System.in);

        System.out.println();

        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> soldiers = new ArrayList<>();

        for (int i = 1; i <= n; i++) 
        {
            soldiers.add(i);
        }

        System.out.println();

        if (n == 1) 
        {
            System.out.println("NONE");
            System.out.println(soldiers.get(0));
            sc.close();
            return;
        }

        List<Integer> removed = new ArrayList<>();

        int index = 0;

        while (soldiers.size() > 1) 
        {

            index = (index + k - 1) % soldiers.size();

            removed.add(soldiers.remove(index));
        }

        for (int i = 0; i < removed.size(); i++) 
        {
            System.out.print(removed.get(i) + " ");
        }

        System.out.println();

        System.out.println(soldiers.get(0));

        sc.close();
    }
}

/*
PROBLEM: Circular Soldier Elimination (Josephus Problem)

PROBLEM STATEMENT:

There are N soldiers numbered from 1 to N, seated around a circular
table.

Starting from soldier 1, count the soldiers in a clockwise direction.
Every K-th soldier is eliminated from the circle.

After a soldier is eliminated, counting resumes from the next remaining
soldier. This process continues until only one soldier remains.

Write a program to:
1. Print the soldiers in the order in which they are eliminated.
2. Print the number of the last surviving soldier.

If N = 1, print NONE for the elimination order because no soldier
is eliminated.

INPUT FORMAT:

The first line contains an integer N, representing the number of soldiers.

The second line contains an integer K, representing the counting interval
used to determine which soldier is eliminated.

INPUT:

5
2

INPUT EXPLANATION:

N = 5, meaning there are five soldiers numbered from 1 to 5.

K = 2, meaning every second soldier is eliminated.

Initially, the circle contains:
1 2 3 4 5

Start counting from soldier 1 in the clockwise direction.
Eliminate every second soldier and resume counting from the next
remaining soldier after each elimination.

EXPLANATION:

The elimination process is shown in the following table:

+-------+----------------+---------------------+----------+
| Round | Circle         | Count Starts At     | Removed  |
+-------+----------------+---------------------+----------+
| 1     | 1 2 3 4 5      | 1                   | 2        |
| 2     | 1 3 4 5        | 3                   | 4        |
| 3     | 1 3 5          | 5                   | 1        |
| 4     | 3 5            | 3                   | 5        |
+-------+----------------+---------------------+----------+

Round 1:
The circle contains 1, 2, 3, 4, 5.
Counting starts from soldier 1.
Soldier 1 is counted first, and soldier 2 is the second soldier.
Therefore, soldier 2 is eliminated.

Remaining soldiers: 1 3 4 5

Round 2:
Counting resumes from soldier 3.
Soldier 3 is counted first, and soldier 4 is the second soldier.
Therefore, soldier 4 is eliminated.

Remaining soldiers: 1 3 5

Round 3:
Counting resumes from soldier 5.
Soldier 5 is counted first, and counting continues circularly.
Soldier 1 is the second soldier.
Therefore, soldier 1 is eliminated.

Remaining soldiers: 3 5

Round 4:
Counting resumes from soldier 3.
Soldier 3 is counted first, and soldier 5 is the second soldier.
Therefore, soldier 5 is eliminated.

Remaining soldier: 3

Only soldier 3 remains in the circle.

The order of eliminated soldiers is:
2 4 1 5

The last surviving soldier is:
3

OUTPUT:

2 4 1 5
3

SPECIAL CASE:

If N = 1, no soldier is eliminated.

In this case, print:
NONE

Then print the only surviving soldier's number:
1
*/
