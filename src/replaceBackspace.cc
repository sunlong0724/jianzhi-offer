#include <string>
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
	cout << str << " " << str.size() << endl;
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

int main(int argc, char* argv[]){

	string str("We are happy!");	
	replaceBackspace(str);
	return 0;
}
