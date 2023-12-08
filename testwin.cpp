#include<windows.h>
int main(int argc,char* agrv[]){
	ExitWindowsEx(EWX_LOGOFF,0);
	return 0;
}
