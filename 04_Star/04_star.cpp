/*
1
2 
1 2 3
1 2 3 4

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    for (int i = 1; i <=n; i++)
    {
    int val=i;
        for (int j = 1; j <=i; j++)
        {
            cout<<val<<" ";
            val+=1;
        }
        cout<<endl;
    }
    
    



}