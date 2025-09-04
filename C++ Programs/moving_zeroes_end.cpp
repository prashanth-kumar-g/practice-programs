#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void MovingZeroesBruteForce(vector<int> &vect)
{
    for(int i = 0; i < vect.size(); i++)
    {
        int curr_ele = vect[i];

        if(curr_ele == 0)
        {
            int j = i;

            while(j < vect.size() - 1)
            {
                vect[j] = vect[j + 1];
                j++;
            }

            vect[j] = curr_ele;
        }
    }
}

void MovingZeroesTwoPointers(vector<int> &vect)
{
    int left = 0;

    for(int right = 0; right < vect.size(); right++)
    {
        if(vect[right] != 0)
        {
            swap(vect[left], vect[right]);
            left++;
        }
    }
}

int main()
{
    int n;
    cout<<"\n Enter the size of array  : ";
    cin>>n;

    vector<int> vect(n);
    cout<<"\n Enter the array elements : ";
    for(int i = 0; i < n; i++)
    {
        cin>>vect[i];
    }

    MovingZeroesBruteForce(vect);

    // MovingZeroesTwoPointers(vect);

    cout<<"\n The array elements after moving zeroes are : ";
    for(int i = 0; i < n; i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n"<<endl;

    return 0;
}