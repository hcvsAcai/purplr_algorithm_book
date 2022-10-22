#include<iostream>
#include<stack>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
const int MAX = 2000;
int n, q[MAX];
int main(){
    ifstream fin("f.in");
    ofstream fout("f.out");
    while (cin >> n && n){
        int i;
        memset(q, 0, sizeof(q));
        int A = 1, B = 0;
        while(cin >> q[0] && q[0]){
            for (int i = 1; i < n; i++) cin >> q[i];
            stack<int> s;   
            A = 1, B = 0;
            bool ok = true;
            while (B < n){ //判斷組合
                if (A == q[B]) A++, B++;
                else if (!s.empty() && s.top() == q[B]) {s.pop(); B++;}
                else if (A <= n) s.push(A++);
                else {ok = 0; break;}
            }
            cout << (ok?"Yes\n" : "No\n");
        }
        cout << endl;
    }
}
