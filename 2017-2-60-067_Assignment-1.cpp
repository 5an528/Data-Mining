#include<bits/stdc++.h>

using namespace std;

int bin, oper, n;
float arr[100];
double result;
float arr1[100][100];
string data;

void convert(string input)
{
    vector<float> v;
    stringstream clean(input);

    for (float i; clean >> i;)
    {
        v.push_back(i);
        if (clean.peek() == ',')
            clean.ignore();
        else if (clean.peek() == ' ')
            clean.ignore();
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
    int k = 0, sum = 0, m = 0, c = 0;
    cout<<endl<<"Smoothing by means"<<endl;
    for(int i = 0; i < result; i++)
    {
        for(int j = 0; j < bin && m < n; j++)
        {
            arr1[i][j] = arr[k];
            k++;
            m++;
        }

    }
    m = 0;
    int l = 0;
    for(int i = 0; i < result; i++)
    {
        cout<<"Bin "<<i+1<<": ";
        l = m;
        for(int j = 0; j < bin && m < n; j++)
        {
            sum+=arr1[i][j];
            c++;
            m++;
        }

        for(int j = 0; j < bin && l < n; j++)
        {
            if(j+1 == c)
                cout<<sum/(c+0.00);
            else
                cout<<sum/(c+0.00)<<", ";

            l++;

        }
        c = 0;
        cout<<endl;
        sum = 0;
    }

}

void smoothbound()
{
    int k = 0, l = 0;
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
        for(int j = 0; j < bin && l < n; j++)
        {
            if(j+1 == bin)
                cout<<arr1[i][j];
            else if(l+1 == n)
                cout<<arr1[i][j];
            else
                cout<<arr1[i][j]<<", ";
            l++;
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
