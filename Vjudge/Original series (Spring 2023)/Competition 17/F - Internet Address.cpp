#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    // string protocol = s.substr(0, max(s.find("http",0), s.find("ftp",0)));
    string protocol;
    string domain;
    string context;
    string ru;
    int p, d, r;
    if (s.find("http", 0) < s.find("ftp", 0)){
        protocol = "http";
    }
    else{
        protocol = "ftp";
    }
    // cout << protocol;

    p = protocol.size();
    domain = s.substr(p, s.find("ru", p) - p);
    // cout << domain;

    d = domain.size();
    ru = s.substr(p + d, s.find("ru", p + d) - p - d + 2);
    // cout << ru;

    r = ru.size();
    if (s.size() > (p + d + r)){
        context = s.substr(p + d + r, s.size() - p - d - r);
    }
    // cout << context;
    string address = protocol + "://" + domain + "." + ru;
    if (context.size() > 0){
        address += "/";
        address += context;
    }
    // cout << context;
    cout << address;

    return 0;
}