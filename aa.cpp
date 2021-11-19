#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;



bool compare(pair<string, int>& a, 
         pair<string, int>& b) 
{ 
    return a.second < b.second; 
}

void popularitem(multimap<string,pair<vector<int>,string>>m)
{
    map<string,int>pop;

    for(auto itr = m.begin(); itr != m.end(); itr++)
    {
        pop[itr->second.second]++;
    }
    for(auto x: pop)
    cout<<x.first << " "<< x.second<<endl;

  sort(pop.begin(),pop.end(),compare);

}

int main()
{
    fstream f;
    string dummy;
    f.open("a.csv",ios::in);
    getline(f,dummy);
    string line;
    string ddate,dname;
    int dprice,dquantity,dtotalprice;
    
    int i=0;
vector<string>date;
vector<string>name;
vector<int>units;
vector<int>price;
vector<int>quantity;
vector<int>total;
string d2;
int ppp;
int qqq;
int ttt;

multimap<string,pair<vector<int>,string>>m;

vector<int>a;
    while(getline(f,line))
    {
        istringstream tokenizer(line);
        getline(tokenizer,ddate,',');
        date.push_back(ddate);
        // cout<<ddate;


        getline(tokenizer,dname,',');
        name.push_back(dname);
        //  cout<<dname;


        getline(tokenizer,d2,',');
        istringstream int_iss(d2);
        int_iss>>ppp;
        price.push_back(ppp);
        // cout<<ppp;
        
        
        getline(tokenizer,d2,',');
        istringstream int_issq(d2);
        int_issq>>qqq;
        quantity.push_back(qqq);
        // cout<<qqq;
        
         getline(tokenizer,d2,',');
        istringstream int_isst(d2);
        int_isst>>ttt;
        total.push_back(ttt);
        // cout<<ttt;

        a={price[i],quantity[i],total[i]};
        m.insert({ddate,{a,dname}});
        i++;
        
    }
int totalsales=0;
int l=0;

for(auto itr = m.begin(); itr != m.end(); itr++)
{
totalsales+=itr->second.first[2];
}

cout<<totalsales;

// **************************Monthly Sales***************************

int sumarr[3]={0,0,0};

for(auto itr = m.begin(); itr != m.end(); itr++)
{
    for(int i=1;i<=3;i++){

    if(stoi(itr->first.substr(5,2))==i)
    {
        sumarr[i-1]+=itr->second.first[2];
    } 

    }
}

cout<<endl;

for(int i=0;i<3;i++)
cout<<"sales of month "<<i+1<< " is " << sumarr[i]<<endl;



//*****Popular item**************

popularitem(m);



}
