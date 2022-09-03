#include<iostream>
using namespace std;
void say_digits(string arr[], int n){
    if(n==0){
        return;
    }
    int rem = n%10;
    n = n/10;
    say_digits(arr, n);
    cout<<arr[rem]<<" ";
}
int main(){
    int n;
    cin>>n;
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    say_digits(arr, n);
    return 0;
}