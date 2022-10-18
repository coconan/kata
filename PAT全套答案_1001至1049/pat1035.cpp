#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Account
{
    string Name;
    string Password;
};

int main()
{
    int N;
    cin>>N;
    vector<Account> accounts(N);
    for(int i=0;i<N;i++)
    {
        cin>>accounts[i].Name;
        cin>>accounts[i].Password;
    }

    vector<Account*> mod;
    for(int i=0;i<N;i++)
    {
        bool change=false;
        for(int j=0;j<accounts[i].Password.size();j++)
        {
            switch(accounts[i].Password[j])
            {
            case '1':
                accounts[i].Password[j]='@';
                change=true;
                break;
            case '0':
                accounts[i].Password[j]='%';
                change=true;
                break;
            case 'l':
                accounts[i].Password[j]='L';
                change=true;
                break;
            case 'O':
                accounts[i].Password[j]='o';
                change=true;
                break;
            default:
                break;
            }
        }
        if(change == true)
        {
            mod.push_back(&accounts[i]);
        }
    }
    if(mod.size() == 0)
    {
        if(accounts.size() == 1)
        {
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else
        {
            cout<<"There are "<<accounts.size()<<" accounts and no account is modified"<<endl;
        }
    }
    else
    {
        cout<<mod.size()<<endl;
        for(int i=0;i<mod.size();i++)
        {
            cout<<mod[i]->Name<<" "<<mod[i]->Password<<endl;
        }
    }

    return 0;
}

