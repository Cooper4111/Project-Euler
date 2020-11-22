#include <iostream>
#include <list>
#include <math.h>
using namespace std;
#define long unsigned long long

/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

class primeFinder{
	
	private:
	
	list <long> *primeSeq;
	list <long> primeSeqEntity;
	
	void primer(long num2f){
		bool prFlag = true;
		long N = sqrt(num2f);
		for(int i = N; i > 0; i--){
			if(N == 1){
				primeSeq->push_back(num2f);
				return;
			}
			if(num2f % N == 0){
				prFlag = false;
				primer(num2f/N);
				primer(N);
			}
			if(!prFlag)
				return;
			N--;
		}
	}
	
	long* sort(){ // bubble sort
		long* seq = new long[primeSeq->size()];
		long j = 0;
		for(long k : *primeSeq){
			seq[j] = k;
			j++;
		}
		j = 0;
		bool sorted = false;
		while(!sorted){
			sorted = true;
			for(int i = 1; i < primeSeq->size(); i++){
				if(seq[i] > seq[i-1]){
					sorted = false;
					j = seq[i];
					seq[i] = seq[i-1];
					seq[i-1] = j;
				}
			}
		}
		return seq;
	}
	
	bool checkSum(long num2f){
		long sum = 1;
		for(int j : *primeSeq)
			sum = sum * j;
		if((sum - num2f) == 0)
			return true;
		else
			return false;
	}
		
	public:
	
	primeFinder(){
		primeSeqEntity = {};
		primeSeq = &primeSeqEntity;
	}		
			
	void factorizeNum(long num2f){
		primer(num2f);
		if(!checkSum(num2f)){
			cout << "ERROR. Checksum is wrong.";
			return;
		}
		long* seq = sort();
		cout << "Sequence is: ";
		for(int i = 0; i < primeSeq->size(); i++)
			cout << seq[i] << " ";
	}
};


int main(){
	
	primeFinder *PF = new primeFinder();
	long input = 600851475143;
	//cin >> input;
	PF->factorizeNum(input);

}