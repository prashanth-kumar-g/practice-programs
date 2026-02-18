#include <iostream>
#include <string>
using namespace std;

/* ---------------- Method 1 : Pure Brute Force O(n^3) ---------------- */
int findIndexBruteForce(string s, int L, int K)
{
    int n = s.length();

    for (int i = 0; i <= n - L; i++)
    {
        int uniqueCount = 0;

        for (int j = i; j < i + L; j++)
        {
            bool isUnique = true;
            for (int k = i; k < j; k++)
            {
                if (s[j] == s[k])
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique)
                uniqueCount++;
        }

        if (uniqueCount == K)       // -> for exactly K, (uniqueCount >= K) if atleast K
            return i;
    }
    return -1;
}

/* ---------------- Method 2 : Optimized Brute Force O(n^2) ---------------- */
int findIndexFreq(string s, int L, int K)
{
    int n = s.length();

    for (int i = 0; i <= n - L; i++)
    {
        int freq[26] = {0};
        int uniqueCount = 0;

        for (int j = i; j < i + L; j++)
        {
            if (freq[s[j] - 'a'] == 0)
                uniqueCount++;
            freq[s[j] - 'a']++;
        }

        if (uniqueCount == K)      // -> for exactly K, (uniqueCount >= K) if atleast K
            return i;
    }
    return -1;
}

/* ---------------- Method 3 : Sliding Window O(n) ---------------- */
int findIndexSlidingWindow(string s, int L, int K)
{
    int n = s.length();
    if (L > n) return -1;

    int freq[26] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < L; i++)
    {
        if (freq[s[i] - 'a'] == 0)
            uniqueCount++;
        freq[s[i] - 'a']++;
    }

    if (uniqueCount == K)
        return 0;

    for (int i = L; i < n; i++)
    {
        freq[s[i - L] - 'a']--;
        if (freq[s[i - L] - 'a'] == 0)
            uniqueCount--;

        if (freq[s[i] - 'a'] == 0)
            uniqueCount++;
        freq[s[i] - 'a']++;

        if (uniqueCount == K)  // -> for exactly K, (uniqueCount >= K) if atleast K
            return i - L + 1;
    }

    return -1;
}

/* ------------------------------- MAIN ------------------------------- */
int main()
{
    int choice, L, K;
    string s;

    while (1)
    {
        cout << "\n-------------------------------------------------------------";
        cout << "\n   HashedIn Q1 : Substring with Exactly K Unique Characters   ";
        cout << "\n-------------------------------------------------------------";
        cout << "\n  1) Input";
        cout << "\n  2) Display";
        cout << "\n  3) Brute Force";
        cout << "\n  4) Optimized Brute Force";
        cout << "\n  5) Sliding Window (Optimized)";
        cout << "\n  6) Exit";
        cout << "\n-------------------------------------------------------------";

        cout << "\n\n Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n Enter the string : ";
                cin >> s;
                cout << " Enter segment length (L) : ";
                cin >> L;
                cout << " Enter required unique count (K) : ";
                cin >> K;
                break;

            case 2:
                cout << "\n String : " << s;
                cout << "\n L = " << L << ", K = " << K << endl;
                break;

            case 3:
                cout << "\n Brute Force Output : ";
                cout << findIndexBruteForce(s, L, K) << endl;
                break;

            case 4:
                cout << "\n Optimized Brute Force Output : ";
                cout << findIndexFreq(s, L, K) << endl;
                break;

            case 5:
                cout << "\n Sliding Window Output : ";
                cout << findIndexSlidingWindow(s, L, K) << endl;
                break;

            case 6:
                cout << "\n Exiting...\n";
                return 0;

            default:
                cout << "\n Invalid choice, try again.\n";
        }
    }
}