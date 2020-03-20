#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
      freopen ("e_so_many_books (1).txt","r",stdin);
      freopen ("output5.txt","w",stdout);
	int no_books,librarys,days;
	cin >> no_books >> librarys >> days;
	ll score[no_books];
	multimap<int , int ,greater<int> > mp;
	for(int i=0;i<no_books;i++)
	{
	    cin >> score[i];
	    mp.insert(pair<int,int>(score[i],i));
	}
	int flag[no_books]={0};
	map<int,vector<int> > ans;
	int initdays=days;
	multimap<int , map<int,vector<int> >,greater<int> > data;
	ll no_lib_books[librarys],signupdays[librarys],per_day_ship[librarys];
	for(int i=0;i<librarys;i++)
	{
		days=initdays;
		int scoreval=0;
	    cin >> no_lib_books[i] >> signupdays[i] >> per_day_ship[i];
	    ll lib_books[no_lib_books[i]];
	    map<int,int,greater<int> > books_set;
	    for(int j=0;j<no_lib_books[i] ;j++)
	    {
	        cin >> lib_books[j];
	        books_set[score[lib_books[j]]]=lib_books[j];
	    }
	    if(signupdays[i] > days)
	    {
	        continue;
	    }
	    days-=signupdays[i];
	    int count=0;
	    vector<int> vec;
		multimap<int,int,greater<int> > :: iterator j;
	    for(j=mp.begin();j!=mp.end();j++)
	    {
	        if(days<=0)break;
	            vec.push_back(j->second);
	            scoreval+=score[j->second];
	            count++;
	        if(count==per_day_ship[i]){
	            count=0;
	            days--;
	        }
	    }
	    map<int,vector<int> > mp1;
	    mp1[i] = vec ;
	    data.insert(pair<int,map<int,vector<int> > >(scoreval,mp1));
	}
	multimap<int,map<int,vector<int> >,greater<int> > :: iterator i;
	days=initdays;
	int pre=0;
	for(i=data.begin();i!=data.end();i++)
	{
	    int no_lib=no_lib_books[i->second.begin()->first],signupd=signupdays[i->second.begin()->first],perday=per_day_ship[i->second.begin()->first];
	    set<int,greater<int> > books_set;
	    for(int j=0;j<i->second.begin()->second.size() ;j++)
	    {
	        books_set.insert(i->second.begin()->second[j]);
	    }
	    if(signupd > days)
	    {
	        continue;
	    }
	    if(signupd>pre)
	    days-=(signupd-pre);
	    int count=0;
	    vector<int> vec;
	    int currdays=0;
	    multimap<int,int,greater<int> > :: iterator j;
	    for(j=mp.begin();j!=mp.end();j++)
	    {
	        if(days<=0)break;
	        if(books_set.find(j->second)!=books_set.end() && flag[j->second]==0)
	        {
	            ans[i->second.begin()->first].push_back(j->second);
	            count++;
	            flag[j->second]=1;
	        }
	        if(count==perday){
	            count=0;
	            days--;
	            currdays++;
	        }
	    }
	    pre=currdays;
	}
	cout << ans.size()<<"\n";
	map<int,vector<int> > :: iterator ii;
	for(ii=ans.begin();ii!=ans.end();ii++)
	{
	    cout << ii->first <<" "<< ii->second.size() << "\n";
	    for(int j=0;j<ii->second.size();j++)
	    {
	        cout << ii->second[j] <<" ";
	    }
	    cout<<"\n";
	}
	
}
