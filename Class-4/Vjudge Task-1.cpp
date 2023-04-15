
///   ***   ---   ||         In the name of ALLAH        |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

const int mx = 1e7+123;
bitset<mx> isPrime;
vector<int> primes;
int cntPrime[mx];

void primeGen ( int n )
{
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int sq = sqrt(n);
    for ( int i = 3; i <= sq; i += 2 ) {
        if(isPrime[i]) {
            for ( int j = i*i; j <= n; j += i ) {
                isPrime[j] = 0;
            }
        }
    }

    isPrime[2] = 1;
    primes.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
}

vector<int> primeFactors ( int n ) /// n = 40131
{
    vector<int> factors;
    /// primes = 2, 3, 5, 7, 11, 13, 17, 19, 23
    for ( auto p : primes ) {/// p = 11

        if( 1LL * p * p > n ) break;

        if( n % p == 0 ) { /// n = 13, p = 7
            while ( n % p == 0 ) {/// n = 13, p = 7
                factors.push_back(p); /// factors = { 3, 3, 7, 7, 7 }
                n /= p; /// n = 13
            }
        }
    }

    if(n > 1) {
        factors.push_back(n);/// factors = { 3, 3, 7, 7, 7, 13 }
    }

    return factors;
}

int main()
{
    optimize();

    int lim = 1e7;
    primeGen(lim);

    int n;

    while ( cin >> n ) {
        if ( n == 0 ) break;

        bool isNeg = false;
        if ( n < 0 ) {
            isNeg = true;
            n *= -1;
        }

        vector<int> factors = primeFactors(n);
        if ( isNeg ) {
            n *= -1;
            factors.insert(factors.begin(), -1);
        }

        cout << n << " = " << factors[0];
        for ( int i = 1; i < factors.size(); i++ ) cout << " x " << factors[i];
        cout << endl;
    }

    return 0;
}














