#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define nl cout << endl
#define ll long long
#define ull unsigned long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define PB push_back

#define REP(i, a, b)  for (int i = a; i <= b; i++)
#define REPR(i, b, a) for (int i = b; i >= a; i--)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define debug(x) cout << #x << " = " << x << endl
#define countSetBits __builtin_popcountll
#define gcd __gcd
#define lcm(a,b) ((a * b) / gcd(a,b))

#define int long long
using namespace std;

const int MOD_v1 =  1e9+7;
const int MOD = MOD_v1;
vi fact; // factoreals array 
// libraries and macros definations ends here



// mostly used functions
namespace modularAethmetic
{
    int add(int a, int b, int MOD = MOD_v1) { return (a + b) % MOD; }

    int sub(int a, int b, int MOD = MOD_v1) { return (a - b + MOD) % MOD; }

    int mul(int a, int b, int MOD = MOD_v1) { return (1LL * a * b) % MOD; }


    // calculate a^b % MOD using binary expo.
    int power(int a, int b, int MOD = MOD_v1)
    {
    	a = a % MOD;
        int res = 1;
        while (b)
        {
            if (b & 1)
                res = mul(res, a, MOD);
            a = mul(a, a, MOD);
            b >>= 1;
        }
        return res;
    }

    int modularInverse(int a,int MOD = MOD_v1) 
    	{ return power(a, MOD - 2, MOD); }

    vector<int> factorials(int n, int MOD = MOD_v1)
    {
        vector<int> facts(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            facts[i] = mul(facts[i - 1], i, MOD);
        }
        return facts;
    }

    int nCrMod(int n, int r, int MOD = MOD_v1)
    {
      if(r>n) return 0;
      else
        return mul(
        	mul(fact[n],modularInverse(fact[r], MOD), MOD) ,
	        	 modularInverse(fact[n-r],MOD), MOD );
    }

}

using namespace modularAethmetic;
// mostly used functions ends here


int32_t main()
{
    // fact = factorials(1e5+10);
    fastIO;


    int t=1;
    cin >> t;
    while (t--)
    {



    }



    return 0;
}










namespace LargeExponentiation
{
	// LARGE a,m <= 1e18 and b>=1e18

	int binMultiply(int a, int b){	
	  int res =0;
	  while(b){
	    if(b&1)
	      res = (0LL+res+a) % MOD;
	    a = (0LL+a+a) %MOD;
	    b>>=1;
	  }
	  return res;
	}

	int power_LargeM(int a, int b)
	{
	  // when MOD <= 1e18
	  a = a % MOD; //when a<=1e18
	  int res =1;
	  while(b){
	    if(b&1)
	      res = binMultiply(res,a);
	    a = binMultiply(a,a);
	    b>>=1;
	  }
	  return res;
	}

	/*
	  // ========== WHEN LARGE b IS GIVEN IN FORM OF c^d ==========
		 //  if b is given in form ex. 64^32 (c^d)
		 //  	->(obviously 64 and 32 are given as seperate integers)
		 //  use eulers theorem and replace b = b % (MOD-1)  
		 //    ->(ex 64^32 % MOD-1) this is power(c,d, MOD-1)
		 //  then just call power(a,b, MOD);

	int k = power(c,d,MOD-1); // (ex. k = 64^32 % MOD-1)
	int ans = power(a,k, MOD); // k is new b

	*/

	/* //======= WHEN LARGE b IS GIVEN IN FORM OF array >= 1e18 =======
	 	//-> leetcode 372 (modify as needed)
	    
	    // 1337 is the MOD given in quesition
	    int superPow(int a, vector<int>& b) {
	        int etf = 1140; // etf of 1337 

	        // B = b[] % etf
	        int B = 0, p = 1; 
	        for(int i = b.size()-1; i>=0; i--){
	            int num = b[i];
	            int t = (num*p) % etf;
	            B = (B+t) % etf;
	            p = (p*10) % etf;
	        }
	        // cout<<B<<"\n";
	        return power(a,B, 1337);
	    }
	*/
}


namespace someGeneralFunctions
{

    //---------------------------------------------
    // calculate (n,r) or nCr value
    ull nCr(ull n, ull r) 
    {
        if (r > n)
        {
            cout << "\nerror: n<r returning: ";
            return 0;
        }
        r = min({r, n - r});
        ull ans = 1, k = 1;
        while (k <= r)
        {
            ans = ans * (n--);
            ans = ans / (k++);
        }
        return ans;
    }
    //---------------------------------------------
    // calculate x^n  , x can be double or ll canusing binary expo.
    template <class T>
    T binpower(T x, ll n) 
    {
        T ans = 1;
        if (n < 0)
        {
            x = 1 / x;
            n *= -1;
        }
        while (n > 0)
        {
            if (n & 1)
                ans = (ans * x);
            x = (x * x);
            n /= 2;
        }
        return ans;
    }
    //---------------------------------------------
}




namespace divisors_primes_one_number
{
	// O(sqrt(n))
	vector<int> divisors(int n)  
	{	
		vector<int> ans;
		for(int i=1; i*i<=n; i++){
			if(n%i==0)
			  if(i == n/i) ans.push_back(i);
			  else ans.push_back(i), ans.push_back(n/i);
		}
		return ans;
	}

  	// O(sqrt(n))
	bool isPrime(int n)
	{
	  bool ans = true;
	  for(int i=2; i*i<=n; i++)
	    if(n%i==0) {ans = false; break;}
	  return ans;
	}

	// O(sqrt(n))
	vector<int> primeFactors(int n)
	{
	  vector<int> ans;
	  for(int i=2; i*i<=n; i++){
	    while(n%i==0){
	      ans.push_back(i);
	      n/=i;
	    }
	  }
	  // if after continuously dividing, at the end n is a prime number
	  // ex 24 = 2 2 2 3 , when i==3 , n==3 also so 3 wont be added to the ans. 
	  // bc agar prime number nahi hota to divide hota hi kisi prime se.
	  if(n>1) ans.push_back(n);
	  return ans;
	  
	    // smallest divisor of a number is a prime number, all numbers can be represented as
	    // "product of powers of prime numbers".
	    
	}
}

namespace seive_primes_divisors_range_of_numbers
{
	// ############# Pre-Calculations O(n log(log n)) #################
	const int SIZE = 1e5+10;
	vector<bool> primeArr(SIZE,true); 
	vector<int> lp(SIZE,0),hp(SIZE,0);
	// primeArr[k] = true-> k is prime, false-> k is not prime.  
	// lp[k],hp[k] => lowest and highest prime factor of k

	void primeArr_seive()
	{
	  auto &n = SIZE; auto &arr = primeArr;
	  for(int i=2; i<n; i++){
	    if(arr[i]){
	    	lp[i] = hp[i] = i; //a prime itself is its lp and hp.
	      	for(int j=2*i; j<=n; j+=i) {
	        	arr[j]=false;
	       		hp[j] = i; // the last i encounterd is lp[j].
	       		if(lp[j] == 0) lp[j] =i; // the first i encounterd is lp[j].
	    	}
	    }
	  }
	}
	// Copy above code above main() and 
	// call primeArr_seive() in main() before question's code. 
	// ############# Pre-Calculations O(n log(log n)) ENDS #############


	//###### prime Factors of n,  O(log n) => improved from sqrt(n)
	vector<int> primeFactors_seive(int n)
	{
	  // lp is precalculated, so we keep adding it to ans.
	  // after inner while ends n is changed to something else.
	  // and we again take prime_factor = lp[n]. 
	  vi ans;
	  while(n > 1){
	    int prime_factor = lp[n];
	    while(n % prime_factor ==0)
	      { ans.push_back(prime_factor); n/=prime_factor;}
	  }
	  return ans;
	}

	
	// ######### divisors of all numbers bw [1,1e5+10) ########
	// ######### ex. divisors[36] = {2, 3, 4, 6, 9, 12, 18, 36}
	// const int SIZE = 1e5+10;
	vector<int> divisors[SIZE]; // vector of divisors for all nums.
	void divisors_seive()
	{
	  // use i=2 when 1 is not needed as divisor. ex = 4 => 1 2 4 => 2 4
	  for(int i=1; i<SIZE; i++){  
	    for(int j=i; j<SIZE; j+=i){
	      divisors[j].push_back(i); 
	      // for all multiples of i, i is a divisor
	    }
	  } 
	//############ MOST IMP. => in main() -> divisors_seive();
	}
}