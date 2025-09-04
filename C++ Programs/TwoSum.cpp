#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& nums, int target) 
{
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int j = i + 1; j < nums.size(); j++) 
            {
                if (nums[i] + nums[j] == target) 
                {
                    return {i, j};
                }
            }
        }

        return {};
}

vector<int> twoSumTwoPointers(vector<int>& nums, int target) 
{
        vector<pair<int, int>> arr_pair;
        for(int i = 0; i < nums.size(); i++)
        {
            arr_pair.push_back({nums[i],i});
        }

        sort(arr_pair.begin(), arr_pair.end());

        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int sum = arr_pair[left].first + arr_pair[right].first;

            if(sum == target)
                return {arr_pair[left].second, arr_pair[right].second};
            else if(sum < target)
                left++;
            else
                right--;
        }

        return {};
}

vector<int> twoSumHashmap(vector<int>& nums, int target) 
{
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end())
            {
                return {mp[complement],i};
            }

            mp[nums[i]] = i;
        }

        return {};
}

int main()
{
    int n, choice, target;

    vector<int> vect;
    vector<int> sol;

    while(1)
    {
        cout<<"\n-------------------------------------------------------------";
        cout<<"\n                     TwoSum Problem                          ";
        cout<<"\n                    ----------------                         ";
        cout<<"\n  1) Input           2) Display    3) Brute Force            ";
        cout<<"\n  4) Two Pointers    5) Hashmap    6) Exit                   ";
        cout<<"\n-------------------------------------------------------------";

        cout<<"\n\n Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"\n Enter the size of array : ";
                    cin>>n;

                    vect.resize(n);
                    cout<<"\n Enter the array elements : ";
                    for(int i = 0; i < n; i++)
                    {
                        cin>>vect[i];
                    }

                    cout<<"\n Enter the target sum : ";
                    cin>>target;
                    break;

            case 2: cout<<"\n The Elements are : ";
                    for(int i = 0; i < n; i++)
                    {
                        cout<<vect[i]<<" ";
                    }
                    cout<<"\n\n The target sum is : "<<target<<endl;
                    break;

            case 3: cout<<"\n Solution using brute force is : ";
                    sol = twoSumBruteForce(vect, target);
                    cout<<sol[0]<<" "<<sol[1]<<endl;
                    break;
            
            case 4: cout<<"\n Solution using two pointers is : ";
                    sol = twoSumTwoPointers(vect, target);
                    cout<<sol[0]<<" "<<sol[1]<<endl;
                    break;

            case 5: cout<<"\n Solution using hashmap is : ";
                    sol = twoSumHashmap(vect, target);
                    cout<<sol[0]<<" "<<sol[1]<<endl;
                    break;

            case 6: cout<<"\n Exiting... \n\n";
                    exit(0);

            default: cout<<"\n Invalid Choice, Select Again. \n";
                     break;
        }
    }

    return 0;
}