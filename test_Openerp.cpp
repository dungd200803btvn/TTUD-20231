//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
int n,L;cin>>n>>L;
for(int i=0;i<n;i++){
    string input;cin>>input;
    string res=input;
    while(res.size()<L){
        res='0'+res;
    }
    cout<<res<<endl;
}
return 0;
}
