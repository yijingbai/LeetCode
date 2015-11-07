#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solver{
public:
    bool rearrageString(string& s){
        if(s.empty()) return true;
        vector<int> charNums(52, 0);

        int maxNums=0, maxIdx=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            charNums[ s[i]-'a' ]++;
            if(maxNums<charNums[ s[i]-'a' ]){
                maxNums = charNums[ s[i]-'a' ];
                maxIdx = i;
            }
        }

        if(maxNums>(n+1)/2) return false;
        string t;
        int count=0;
        //append the max occurrence char first
        t.append(maxNums, s[maxIdx]);
        count +=maxNums;
        charNums[ s[maxIdx]-'a' ] =0;
        for(int i=0; i<n; i++){
            if(charNums[ s[i]-'a' ] > 0){
                t.append(charNums[ s[i]-'a' ], s[i]);
                count +=charNums[ s[i]-'a' ];
                charNums[ s[i]-'a' ] =0;
                if(count==n) break;
            }
        }

        int halfCount= (n+1)/2;
        for(int i=0; i<halfCount; i++){
            s[i*2]= t[i];
            s[i*2+1]= t[halfCount+i];
        }
        if(n%2!=0) s[n-1]=t[halfCount];

        return true;
    }
};

int main() {
    Solver s;
    string t("aaabc");
    s.rearrageString(t);
    cout << t << endl;
}
