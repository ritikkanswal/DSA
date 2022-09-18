#include <iostream>

using namespace std;

int main()
{
    int n,b,x=-1,y;
    cin>>n;

    y=-1;
    
    int a[n];
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    cin>>b;

    int temp[n]={0};

    for(int i=1;i<n;i++){

        if(abs(a[i-1]-a[i])>b)
        {
            if(i+1<n){

                if(abs(a[i-1]-a[i+1])<abs(a[i]-a[i+1]))
                {
                    temp[i]=-1;
                    a[i]=a[i-1];
                }
                else{

                    temp[i-1]=-1;
                    a[i-1]=a[i];
                }

            }
            else{
                    temp[i-1]=-1;
                    a[i-1]=a[i];
            }
           
        }
    }

    for(int i=0;i<n;i++){

    //    cout<<temp[i]<<" ";
    }
    // cout<<endl;

    int i=0;
    while(i<n)
    {
        if(temp[i]==-1)
        {
            x=i;
            break;
        }
        i++;
    }
    i=n-1;
    while(i>=0)
    {
        if(temp[i]==-1)
        {
            y=i;
            break;
        }
        i--;
    }

    // cout<<x<<" "<<y<<endl;

    if(x==-1 and y==-1){
        cout<<0<<endl;
        return 0;
    }
    cout<<(y-x+1)<<endl;
    
    
    
    

    return 0;
}