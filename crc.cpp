#include<bits/stdc++.h>
using namespace std;

void division(int temp[],int divisor[],int msg_size,int div_size)
{
    for(int i=0; i<msg_size; i++)
    {
        int k = i;
        if (divisor[0]==temp[i])
        {

            for(int j=0; j<div_size+1; j++)
            {

                if((temp[k]^divisor[j])==0)
                    temp[k]=0;
                else
                    temp[k]=1;
                k++;
            }
        }
    }
}

int main()
{
    int msg_size,div_size,message[50],divisor[50],temp[50];
    string str_msg,str_div;
    cout<<"Enter the Message : ";
    cin>>str_msg;
    cout<<"Enter the divisor : ";
    cin>>str_div;

    msg_size = str_msg.length();
    div_size = str_div.length();

    for(int i=0; i<msg_size; ++i)
    {
        message[i] = str_msg[i]-48;
    }

    for(int i=0; i<div_size; ++i)
    {
        divisor[i] = str_div[i]-48;
    }

    div_size--;

    for(int i=0; i<div_size; i++) message[msg_size+i] = 0; ///temp er value nilam
    for(int i=0; i<msg_size+div_size; i++) temp[i] = message[i];

    division(temp,divisor,msg_size,div_size);
    cout<<"\n\nFrame check sequence : ";
    for(int i=0; i<div_size; i++)
    {
        cout<<temp[msg_size+i]<<" ";
        message[msg_size+i] = temp[msg_size+i];
    }
    cout<<"\nFrame : ";
    for(int i=0; i<msg_size+div_size; i++) cout<<message[i]<<" ";

    cout<< "\n\nNow Randomly changing 4 bits::"<<endl; ///Rand starts
    int msgdiv = msg_size+div_size;
    srand(time(NULL));
    int  a = rand() % msgdiv;
    int b,c;
    while(1)
    {
        b = rand() % msgdiv;
        if(a!=b) break;
    }
    while(1)
    {
        c = rand() % msgdiv;
        if(c!=a&&c!=b) break;
    }
    cout<<"Randomly changing bits of indexes are: "<<a<<", "<<b<<", "<<c<<endl;
    if (message[a]==1) message[a]=0;
    else message[a]=1;
    if (message[b]==1) message[b]=0;
    else message[b]=1;
    if (message[c]==1) message[c]=0;
    else message[c]=1;
    cout<<endl;
    for(int i=0; i<msg_size+div_size; i++) cout<<message[i]<<" ";
    for(int i=0; i<msg_size+div_size; i++) temp[i] = message[i];
    division(temp,divisor,msg_size,div_size);

    for(int i=0; i<div_size; i++)
    {
        if(temp[msg_size+i]==1)
        {
            cout<<"\n\nRemainder is : "<< " ";
            for(int i=0; i<div_size; i++)
            {
                cout<<temp[msg_size+i]<< " ";
                message[msg_size+i] = temp[msg_size+i];
            }
            cout<<"\nERROR detected in the Received message!! \n";
            return 0;
        }
    }
    cout<<"\n\nNo ERROR in the Received Message. \n";
    cout<<"\nReceived Message : ";

    for(int i=0; i<msg_size; i++) cout<<message[i]<<" ";

    return 0;
}
