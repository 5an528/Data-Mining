#include<bits/stdc++.h>

using namespace std;

int bin, oper, n;
float arr[100];
double result;
float arr1[100][100];
string data;

void convert(string str)
{
    vector<float> v;
    stringstream ss(str);

    for (float i; ss >> i;)
    {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
        else if (ss.peek() == ' ')
            ss.ignore();
    }
    n = v.size();
    result = n*1.00/(bin+0.00);
    result = ceil(result);

    for (int i = 0; i < n; i++)
        arr[i] = v[i];
    sort(arr, arr + n);

}

void smoothmean()
{
    int k = 0, sum = 0;
    cout<<endl<<"Smoothing by means"<<endl;
    for(int i = 0; i < result; i++)
    {
        for(int j = 0; j < bin; j++)
        {
            arr1[i][j] = arr[k];
            k++;
        }
    }
    for(int i = 0; i < result; i++)
    {
        cout<<"Bin "<<i+1<<": ";
        for(int j = 0; j < bin; j++)
        {
            sum+=arr1[i][j];
        }
        for(int j = 0; j < bin; j++)
        {
            if(j+1 == bin)
                cout<<sum/(bin+0.00);
            else
                cout<<sum/(bin+0.00)<<", ";
        }
        cout<<endl;
        sum = 0;
    }

}

void smoothbound()
{
    int k = 0;
    float sub1, sub2;
    cout<<endl<<"Smoothing by boundary"<<endl;
    for(int i = 0; i < result; i++)
    {
        for(int j = 0; j < bin; j++)
        {
            arr1[i][j] = arr[k];
            k++;
        }
    }
    for(int i = 0; i < result; i++)
    {
        cout<<"Bin "<<i+1<<": ";
        for(int j = 1; j < bin; j++)
        {
            if(j+1 < bin)
            {
                sub1=arr1[i][j]-arr1[i][j-1];
                sub2=arr1[i][j+1]-arr1[i][j];

                if(sub1 < sub2)
                    arr1[i][j] = arr1[i][j-1];
                else
                    arr1[i][j] = arr1[i][j+1];
            }
            else
                break;
        }
        for(int j = 0; j < bin; j++)
        {
            if(j+1 == bin)
                cout<<arr1[i][j];
            else
                cout<<arr1[i][j]<<", ";
        }
        cout<<endl;

    }
}
int main()
{
    getline(cin,data);
    cout << "Bin size = ";
    cin >> bin;

    while(1)
    {
        cout << "Choice = ";
        cin >> oper;

        if(oper == 1)
        {
            convert(data);
            smoothmean();
            cout<<endl;
        }
        else if(oper == 2)
        {
            convert(data);
            smoothbound();
            cout<<endl;
        }
        else
            break;
    }

    return 0;
}
