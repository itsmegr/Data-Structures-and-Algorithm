#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
int *dp;
void takeArrayInput(int arr[], int n)
{
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
int minSwap(vi arr)
{
    vi temp;
    temp = arr; //copied
    sort(temp.begin(), temp.end());
    int ans=0;

    //using hasmap to store the index
    unordered_map<int, int> h;

    for (int i = 0; i < arr.size(); i++)
    {
        h[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]!=temp[i]){
            int init = arr[i];
            ans++;
            //swaping the real ele at pos i in arr
            swap(arr[i], arr[h[temp[i]]]);
            //update the index
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}

void solve()
{
    int i, j, n, m;
}