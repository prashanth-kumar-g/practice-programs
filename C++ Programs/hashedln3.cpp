#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/* ------------------ Method 1: Pure Brute Force O(n^3) ------------------ */
int countSubarraysBruteForce(vector<int>& nums, int k)
{
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int distinct = 0;

            for(int p = i; p <= j; p++)
            {
                bool isDistinct = true;
                for(int q = i; q < p; q++)
                {
                    if(nums[p] == nums[q])
                    {
                        isDistinct = false;
                        break;
                    }
                }
                if(isDistinct)
                    distinct++;
            }

            if(distinct == k)
                count++;
        }
    }
    return count;
}

/* ------------------ Method 2: Using Set O(n^2) ------------------ */
int countSubarraysUsingSet(vector<int>& nums, int k)
{
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        unordered_set<int> st;

        for(int j = i; j < n; j++)
        {
            st.insert(nums[j]);

            if(st.size() == k)
                count++;

            if(st.size() > k)
                break;
        }
    }
    return count;
}

/* ------------------ Method 3: Using HashMap O(n) ------------------ */
int atMostK(vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    int left = 0, count = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        mp[nums[right]]++;

        while(mp.size() > k)
        {
            mp[nums[left]]--;
            if(mp[nums[left]] == 0)
                mp.erase(nums[left]);
            left++;
        }

        count += (right - left + 1);
    }
    return count;
}

int countSubarraysHashMap(vector<int>& nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

/* ------------------------------ MAIN ---------------------------------- */
int main()
{
    int n, choice, k;
    vector<int> vect;

    while(1)
    {
        cout<<"\n-------------------------------------------------------------";
        cout<<"\n   Subarrays with Exactly K Distinct Integers                ";
        cout<<"\n-------------------------------------------------------------";
        cout<<"\n  1) Input          2) Display";
        cout<<"\n  3) Brute Force    4) Using Set";
        cout<<"\n  5) HashMap        6) Exit";
        cout<<"\n-------------------------------------------------------------";

        cout<<"\n\n Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\n Enter array size : ";
                cin>>n;

                vect.resize(n);
                cout<<"\n Enter array elements : ";
                for(int i = 0; i < n; i++)
                    cin>>vect[i];

                cout<<"\n Enter value of k : ";
                cin>>k;
                break;

            case 2:
                cout<<"\n Array elements are : ";
                for(int x : vect)
                    cout<<x<<" ";
                cout<<"\n k = "<<k<<endl;
                break;

            case 3:
                cout<<"\n Brute Force Output : ";
                cout<<countSubarraysBruteForce(vect, k)<<endl;
                break;

            case 4:
                cout<<"\n Using Set Output : ";
                cout<<countSubarraysUsingSet(vect, k)<<endl;
                break;

            case 5:
                cout<<"\n Using HashMap Output : ";
                cout<<countSubarraysHashMap(vect, k)<<endl;
                break;

            case 6:
                cout<<"\n Exiting...\n";
                exit(0);

            default:
                cout<<"\n Invalid Choice, Try Again.\n";
        }
    }

    return 0;
}