#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::endl;
using std::cout;

void print_arr(int* arr, int len) {
	for (int i =0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert_sort(int* arr, int len) {
	int temp, j;
	for (int i = 1; i < len; ++i) {
		temp = arr[i];
		for (j = i-1;j >= 0 && temp < arr[j];--j) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}

void shell_sort(int* arr, int len) {
	int d = len>>1;
	int temp, j;
	while(d > 0) {
		for (int i = d; i < len; ++i) {
			for (j = i-d; j >= 0 && arr[j+d] < arr[j]; j -=d) {
				temp = arr[j+d];
				arr[j+d] = arr[j];
				arr[j] = temp;
			}
		}

		d >>= 1;
	}
}

void bubble_sort(int* arr, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = len-1; j > i; --j) {
			if (arr[j] < arr[j-1]) {
				std::swap(arr[j], arr[j-1]);
			}
		}
	}
}

void quick_sort(int* arr, int start, int end) {
	int s = start;
	int t = end;
	if (s < t) {
		int tmp = arr[s];
		while(s != t ) {
			while( t > s && arr[t] > tmp) {
				t--;
			}
			if (t > s) {
				arr[s] = arr[t];
				s++;
			}

			while( t > s && arr[s] <tmp) {
				s++;
			}

			if (t > s) {
				arr[t] = arr[s];
				t--;
			}
		}
		arr[s] = tmp;
		quick_sort(arr, start, s-1);
		quick_sort(arr, s+1, end);
	}
}


void select_sort(int* arr, int len) {
	int index;
	for (int i = 0 ; i < len-1; ++i){
		index = i;
		for (int j = i+1; j < len; ++j) {
			if ( arr[j] < arr[index]) {
				index = j;
			}
		}
		if (index != i)
			std::swap(arr[i], arr[index]);
	}
}

int main(){
	int arr[] = {6,23,1,4,5,2,5};
	print_arr(arr, 	sizeof(arr)/sizeof(int));
	//insert_sort(arr, sizeof(arr)/sizeof(int));
	//shell_sort(arr, sizeof(arr)/sizeof(int));
	//bubble_sort(arr, sizeof(arr)/sizeof(int));
	//quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);
	select_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, 	sizeof(arr)/sizeof(int));
	cout << "main " << endl;
}
