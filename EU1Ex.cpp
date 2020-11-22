#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <list>
using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.*/
/* EXTENDED SOLUTION FOR
Find the sum of all the multiples of A1 or A2 ... or Ak below N.*/

list<int> normalize(list<int> L){	
	auto iterIn = L.begin();
	auto iterEx = L.begin();
	int lim = L.size();
	int lim2 = lim;
	for(int j = 0; j<lim; j++){
		iterIn = L.begin();
		lim = lim2;
		for(int i = 0; i<lim; i++){
			if(iterIn == iterEx){
				++iterIn;
				continue;
			}
			if(*iterIn % *iterEx == 0){
				iterIn = L.erase(iterIn);
				lim2--;
			}else{
				++iterIn;
			}
		}
		++iterEx;
	}
	return L;
}

// Gets array *int, where [0] - left2check;     [1] - divisorN;     [1+] - multipliers
bool chekDiv(int* li, int mult){
	if(li[0] > 0){
		if(mult % li[li[1]] == 0){
				return false;
		}
		else{
			li[0]--;
			li[1]++;
			return chekDiv(li, mult);
		}
	}
	else{
		return true;
	}
}

int multi(list<int> L, int limit){
	int result = 0;
	int subResult = 0;
	int* li = new int[L.size()+2];
	int g = 2;
	for(int k : L){
		li[g] = k;
		g++;
	}
	// opportunity for lib
	for(int i = 0; i < limit; i += li[2])
		result += i;
	for(int j = 1; j < L.size(); j ++){
		subResult = 0; // can't be 0 because of chekDiv
		for(int i = li[j+2]; i < limit; i += li[j+2]){
			li[0] = j;
			li[1] = 2;
			if(chekDiv(li, i)){
				subResult += i;
			}
		}
		result += subResult;
	}
	return result;
}
	
void processor(){
	list<int> nums{};
	int x = 0, lim = 0;
	char cntn = 'e';
	cout << "Welcome\nThis programm designed to find sum of natural numbers below B\nthat are multiples of A1 or ... An\n";
	while(true){
		cout << "Please, input the limiting B number\n";
		cin >> lim;
		cout << "Please, input multipliers A1...An separating by enter key\n(preferable small numbers first)\nTo end input enter 0\n";
		while(true){
			cin >> x;
			if(x >= lim){
				cout << "multiplier is bigger than limiting number, try again\n";
				continue;
			}
			if(x == 0)
				break;
			nums.push_back(x);
		}
		cout << "Your limiting number is " << lim << "\n";
		cout << "Your sequence is ";
		for(int k : nums)
			cout << k << " ";
		cout << "\nNow processing...\n\n";
		cout << "result is:\t" << multi(normalize(nums), lim) << "\n\nTo exit input \'e\'\nTo continue input anything :)\n";
		cin >> cntn;
		if(cntn == 'e')
			return;
		x = 0, lim = 0;
		nums.clear();
	}
}

int main(){
	processor();
}