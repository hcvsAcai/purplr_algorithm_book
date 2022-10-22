#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
typedef struct cr{
    int col;
    int row;
    cr(int col = 0, int row = 0): col(col), row(row) {}
}CR;
stack<CR> s;
int n;
char name;
string str;
CR cc[26];
int main(){
    cin >> n;
    if (!n) return 0;
    while (n--) 
        cin >> name, cin >> cc[name - 'A'].col >> cc[name - 'A'].row;
    while (cin >> str){
        int res = 0;
        int len = str.length();
        for (int i = 0; i < len; i++){
            if (isalpha(str[i])) s.push(cc[str[i] - 'A']);
            else if (str[i] == ')'){
                CR a = s.top(); s.pop(); // second
                CR b = s.top(); s.pop(); // first
                //cout << a.row << " " << b.col << endl;
                if (a.col ^ b.row){ // first.col != second.row
                    cout << "error\n"; break;
                }
                res += b.col * b.row * a.row;
                s.push(CR(b.col, a.row)); 
            }
            if (i == len - 1) cout << res << endl;
        }
    }
}
