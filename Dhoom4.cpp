#include <bits/stdc++.h>
#define ll long long
#define f(a,b) for(ll a = 0; a < b; a++)
using namespace std;



int main(){
    ll ownedKey, targetKey, n;

    cin >> ownedKey >> targetKey;
    cin >> n;

    ll array[n+5];
    for(ll i = 0; i < n; i++){
        cin >> array[i];
    }
    
    ll ans[100005];
    memset(ans, -1, sizeof(ans));
  
    ans[ownedKey] = 0;
    queue<ll> Q;
    Q.push(ownedKey);
    while(!Q.empty()){
        ll top = Q.front();
        Q.pop();
        if(top == targetKey) break;
        for(ll i = 0; i < n; i++){
            ll temp = array[i];
            temp = temp*top;
            temp%= 100000;
            if(ans[temp] == -1){
                ans[temp] = ans[top]+1;
                Q.push(temp);
            }
        }
    }

    cout << ans[targetKey] << endl;
}