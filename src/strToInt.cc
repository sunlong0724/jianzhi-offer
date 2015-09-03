#include <string>
#include <iostream>
#include <signal.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int strToInt(const string& str){
	if (str.empty())
		return -1;
	int res = 0;
	for (int i = 0; i < str.size(); ++i) {
		res = (res*10 + str[i]-'0' );
	}

	return res;
}

int g_running = 1;
static void sig_int(int sig_no){
	g_running = 0;
}

int main(int argc, char* argv[]){
	signal(SIGINT,sig_int);
	while(g_running){
		string str;
		getline(cin, str);
		cout << strToInt(str) << endl;
	}

	cout << "main exited!" << endl;
}
