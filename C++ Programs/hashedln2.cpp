#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ---------------- Method 1: Brute Force O(n^2) ---------------- */
int countPairsBruteForce(vector<string>& input)
{
    int n = input.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = input[i][0] - 48;   // (or) int a = int(input[i]);
            int b = input[j][0] - 48;   // (or) int b = int(input[j]);

            if (a > 3 * b)
                count++;
        }
    }
    return count;
}

/* ---------------- Merge Sort Helper Functions ---------------- */
int mergeAndCount(vector<int>& arr, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (j <= high && arr[i] > 3LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return count;
}

int mergeSortCount(vector<int>& arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int count = 0;

    count += mergeSortCount(arr, low, mid);
    count += mergeSortCount(arr, mid + 1, high);
    count += mergeAndCount(arr, low, mid, high);

    return count;
}

/* ---------------- Method 2: Optimized (Merge Sort) O(n log n) ---------------- */
int countPairsOptimized(vector<string>& input)
{
    vector<int> arr;
    for (string s : input)
        arr.push_back(s[0] - 48);

    return mergeSortCount(arr, 0, arr.size() - 1);
}

/* ------------------------------- MAIN ------------------------------- */
int main()
{
    int n, choice;
    vector<string> input;

    while (1)
    {
        cout << "\n-------------------------------------------------------------";
        cout << "\n   HashedIn Q2 : Count Pairs (i < j, a[i] > 3*a[j])           ";
        cout << "\n-------------------------------------------------------------";
        cout << "\n  1) Input";
        cout << "\n  2) Display";
        cout << "\n  3) Brute Force";
        cout << "\n  4) Optimized (Merge Sort)";
        cout << "\n  5) Exit";
        cout << "\n-------------------------------------------------------------";

        cout << "\n\n Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n Enter size : ";
                cin >> n;

                input.resize(n);
                cout << " Enter elements : ";
                for (int i = 0; i < n; i++)
                    cin >> input[i];
                break;

            case 2:
                cout << "\n Elements are : ";
                for (string x : input)
                    cout << x << " ";
                cout << endl;
                break;

            case 3:
                cout << "\n Brute Force Output : ";
                cout << countPairsBruteForce(input) << endl;
                break;

            case 4:
                cout << "\n Optimized Output : ";
                cout << countPairsOptimized(input) << endl;
                break;

            case 5:
                cout << "\n Exiting...\n";
                return 0;

            default:
                cout << "\n Invalid choice, try again.\n";
        }
    }
}