/*#include <bits/stdc++.h> 
using namespace std;
bool checknumber(string phone){
    if(phone.length()!=10){
        return false;
    }
    for(char c: phone){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}
int getDuration(string from,string to){
	int start =   ((from[0] -'0')*10+ (from[1] -'0'))*3600 + ((from[3] -'0')*10+ (from[4] -'0'))*60+((from[6] -'0')*10+ (from[7] -'0'));
		int end =   ((to[0] -'0')*10+ (to[1] -'0'))*3600 + ((to[3] -'0')*10+ (to[4] -'0'))*60+((to[6] -'0')*10+ (to[7] -'0'));
		return end-start;
}
int main() 
{ 
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
int cnt = 0;
map<string,int> callCount,durationCount;
int check =0;
string input;
cin>>input;
do{
    cnt++;
    string from,to,date,start,end;
    cin>>from>>to>>date>>start>>end;
  
    callCount[from]+=1;
    durationCount[from]+= getDuration(start,end);

    if(!checknumber(from)|| !checknumber(to)){
    	check++;
	}
    cin>>input;
}while(input!="#");

cin >>input;
do{
    if(input=="#"){
        break;
    }else if(input=="?check_phone_number"){
    	if(check!=0){
    		cout <<0<<endl;
		}else{
			cout <<1<<endl;
		}
        
    }else if(input=="?number_calls_from"){
    	string fphone;cin>>fphone;
    	cout << callCount[fphone] <<endl;
	}else if(input=="?number_total_calls"){
    	cout <<cnt  <<endl;
	}else{
    		string fphone;cin>>fphone;
    	cout << durationCount[fphone] <<endl;
    	
	}
	cin>>input;
}while(input!="#");

return 0;
}*/




//C++ 
#include <bits/stdc++.h> 
using namespace std;
bool check(string phone){
    if(phone.length()!=10) return false;
    for(char c:phone){
        if(!isdigit(c)){
            
            return false;
        }
    }
    return true;
}
int getTime(string start,string end){
    int t1= 3600*((start[0]-'0')*10+(start[1]-'0'))+
            60*((start[3]-'0')*10+(start[4]-'0'))+
            ((start[6]-'0')*10+(start[7]-'0'));
            int t2 = 3600*((end[0]-'0')*10+(end[1]-'0'))+
            60*((end[3]-'0')*10+(end[4]-'0'))+
            ((end[6]-'0')*10+(end[7]-'0'));
            return t2-t1;
}
int main() 
{ 
    map<string,int> CallCount,CallDuration;
string input;
cin>>input;
int cnt=0;
int err=0;
do{
    cnt++;
    string from,to,date,start,end;
    cin>>from>>to>>date>>start>>end;
    if(!check(from)||!check(to)){
        err++;
    }
    CallCount[from]++;
    CallDuration[from]+= getTime(start,end);
    cin>>input;
}while(input!="#");
cin>>input;
do{
    if(input=="#"){
        break;
    }else if(input=="?check_phone_number"){
        if(err){
            cout <<0<<endl;
        }else{
             cout <<1<<endl;
        }
    }else if(input=="?number_calls_from"){
        string from;cin>>from;
        cout << CallCount[from]<<endl;
    }else if(input=="?number_total_calls"){
        cout <<cnt<<endl;
    }else{
         string from;cin>>from;
        cout << CallDuration[from]<<endl;
    }
    cin>>input;
}while(input!="#");
return 0;
}
