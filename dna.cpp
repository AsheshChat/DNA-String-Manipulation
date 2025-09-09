
#include <bits/stdc++.h>
using namespace std;
int gc_count(const string&s){
    int c=0; for(char ch:s) if(ch=='G'||ch=='C') c++; return c;
}
vector<int> kmp_table(const string&p){
    int n=p.size(); vector<int>t(n+1); t[0]=-1; int pos=1,cnd=0;
    while(pos<n){ if(p[pos]==p[cnd]) t[pos]=t[cnd]; else { t[pos]=cnd; cnd=t[cnd]; while(cnd>=0&&p[pos]!=p[cnd]) cnd=t[cnd]; } pos++; }
    t[pos]=cnd; return t;
}
vector<int> kmp_search(const string&s,const string&p){
    int i=0,j=0; vector<int>res; auto t=kmp_table(p);
    while(i<s.size()){
        if(p[j]==s[i]){i++;j++; if(j==p.size()){res.push_back(i-j); j=t[j];}}
        else { j=t[j]; if(j<0){i++; j++;} }
    }
    return res;
}
int main(){
    string s="AGCTGCGCAGCT";
    cout<<gc_count(s)<<"
";
    auto pos=kmp_search(s,"GCG");
    for(int x:pos) cout<<x<<" ";
    cout<<"
";
    return 0;
}
