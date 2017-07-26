/*
Bit strings of n bits which doesn't have any contiguous zero, can be generated as
n=1 : 1      //count = 1
n=2 : 11, 10, 01      //count = 3
n=3 : 111, 110, 101, 011      //count = 5
n=4 : 1111, 1110, 1101, 1011, 0111, 1010, 0101, 0110      //count = 8
n=5 : 11111, 11110, 11101, 11011, 10111, 01111, 11010, 10110, 01101, 01011, 01110, 10101, 01010      //count = 13
n=6 : 111111, 111110, 111101, 111011, 110111, 101111, 011111, 111010, 110110, 101110, 011110, 110101, 101101, 010111, 011011, 101011 011101, 
	  101010, 010101, 011010, 010110      //count = 21
	  
	3,5,8,13,21...... gives the pattern of Finonacci series where,
	Therefore, Bit strings of n bits which doesn't have any contiguous zero can be calculated as:
	count(n) = Fib(n+3) where Fibonacci series is: 0, 1, 1, 2, 3, 5, 8, 13, 21........
		where, Fib(m) = Fib(m-1) + Fib(m-2)
		
	Here, as we need to find Fibonacci term for a very large number, we use the formula which solves the problem in O(log n) time:
		If n is even then k = n/2:
			F(n) = F(k)*F(k) + F(k-1)*F(k-1)
		If n is odd then k = (n + 1)/2
			F(n) = F(k)*F(k+1) + F(k-1)*F(k)
*/



#include <map>
#define ll long long
#include <iostream>
using namespace std;

map<ll, ll> mapF;

ll f(ll n) {
	if (mapF.count(n)) return mapF[n];
	ll k=n/2;
	if (n%2==0)
		return mapF[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % 1000000007;
	else
		return mapF[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % 1000000007;
}

main(){
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		ll n;
		cin >> n;
		mapF[0]=mapF[1]=1;
		if(n==1)
			cout << 1 << endl;
		else
			cout << f(n+1) << endl;
	}
	
}
