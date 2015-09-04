#include <string>
#include <string.h>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 * @brief replaceBackspace replace backspaces in the string by '%20'
 *
 * @param str
 */
void replaceBackspace(string& str){
	if (str.empty()) return;
	int i = 0;
	int j = 0;
	int backspace_count = 0;
	while(i < str.size()){
		if (str[i] == ' ')
			++backspace_count;
		++i;
	}
	int len = str.size();
	str.resize(backspace_count*2+str.size(), '0');

	i = len;
	j = str.size();
	while(i>= 0) {
		if (str[i] == ' '){
			str[j--]='0';
			str[j--]='2';
			str[j--]='%';
			--i;
		}else{
			str[j--] = str[i--];
		}
	}
	cout << str << " " << str.size() << endl;
}

//not good!!!
string mergeTwoString(string &str1,string &str2){
	if (str1.empty()) return str2;
	if (str2.empty()) return str1;

	int len1 = str1.length();
	str1.resize(str2.size()+str1.size(), '0');

	strcpy(&(str1[len1]), str2.c_str());


	return str1;

}

int main(int argc, char* argv[]){

	string str1("We are family!");
	string str2("We are happy!");	
	cout << "The merged string is \"" <<	mergeTwoString(str1,str2) << "\"" << endl;
	replaceBackspace(str1);
	return 0;
}
