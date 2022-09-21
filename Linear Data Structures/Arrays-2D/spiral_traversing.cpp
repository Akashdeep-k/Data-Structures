//For spiral traversing of an array 
//   1 2 3
//   4 5 6       =>      1 2 3 6 9 8 7 4 5
//   7 8 9
#include<iostream>
using namespace std;
int main(){
	int m, n;
	cin>>m>>n;
	int arr[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
 
	cout<<"Non-spiral traversing : "<<endl;
		for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
 
	cout<<"Spiral traversing : "<<endl;
 
	int total = m*n;
	int count = 0;
 
		int starting_row = 0;
		int ending_column = n;
		int ending_row = m;
		int starting_column = 0;
 
	while(count < total){
 
		for(int i = starting_column; (i < ending_column)&&(count < total); i++){
			cout<<arr[starting_row][i]<<" ";
			count++;
		}
		starting_row++;
 
		for(int i = starting_row; (i < ending_row)&&(count < total); i++){
			cout<<arr[i][ending_column-1]<<" ";
			count++;
		}
 
		ending_column--;
 
		for(int i = ending_column-1; (i >= starting_column)&&(count < total); i--){
			cout<<arr[ending_row-1][i]<<" ";
			count++;
		}
 
		ending_row--;
 
		for(int i = ending_row-1; (i >= starting_row)&&(count < total); i--){
			cout<<arr[i][starting_column]<<" ";
			count++;
		}
 
		starting_column++;
	}
	return 0;
}