#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MaxAreaBruteForce(vector<int> &vect)
{
    int maxArea = 0;

    for(int i = 0; i < vect.size() - 1; i++)
    {
        for(int j = i + 1; j < vect.size(); j++)
        {
            int distance = j - i;
            int minHeight = min(vect[i], vect[j]);
            int area = distance * minHeight;

            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int MaxAreaTwoPointers(vector<int> &vect)
{
    int left = 0, right = vect.size();
    int maxArea = 0;

    while(left < right)
    {
        int distance = right - left;
        int minHeight = min(vect[left], vect[right]);
        int area = distance * minHeight;

        maxArea = max(maxArea, area);

        if(vect[left] < vect[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main()
{
    int n;
    cout<<"\n Enter the size of array  : ";
    cin>>n;

    vector<int> vect(n);
    cout<<"\n Enter the array elements (height) : ";
    for(int i = 0; i < n; i++)
    {
        cin>>vect[i];
    }

    int max_area = MaxAreaBruteForce(vect);

    // int max_area = MaxAreaTwoPointers(vect);

    cout<<"\n The maximum area is : "<<max_area<<"\n"<<endl;

    return 0;
}