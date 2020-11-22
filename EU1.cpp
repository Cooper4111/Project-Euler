#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.*/

/* BASIC SOLUTION*/

int multi(int num1, int num2, int limit){
	int answ = 0;
	int i = num1;
	while(i < limit){
		answ += i;
		i += num1;
	}
	i = num2;
	while(i < limit){
		if(i%3 != 0)
			answ += i;
		i += num2;
	}
	return answ;
}

int main(){
	cout << multi(3,5,1000);
}