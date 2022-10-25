#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    int n;
    cin >> n >> a >> b;
    int sa, sb;
    for (sa = 0; sa < a.size(); ++sa) {    // 去掉0
        if (a[sa] != '0') { break; }
    }
    for (sb = 0; sb < b.size(); ++sb) {
        if (b[sb] != '0') { break; }
    }
    a = a.substr(sa); b = b.substr(sb);
    //if (a.size() == 0) { a = "0"; }
    //if (b.size() == 0) { b = "0"; }
    int pa=0, pb=0;
    for (pa = 0; pa < a.size(); ++pa) {   // 找到小数点位置
        if (a[pa] == '.') { break; }
    }
    for (pb = 0; pb < b.size(); ++pb) {
        if (b[pb] == '.') { break;}
    }
    if (pa < a.size()) {
        a = a.substr(0, pa) + a.substr(pa+1);    //去掉小数点
    }
    if (pb < b.size()) {
        b = b.substr(0, pb) + b.substr(pb+1);
    }
    for (sa = 0; sa < a.size(); ++sa) {      //处理 0.001343的情况
        if (a[sa] != '0') { break; }
        else { pa--; }
    }
    for (sb = 0; sb < b.size(); ++sb) {
        if (b[sb] != '0') { break; }
        else { pb--; }
    }
    a = a.substr(sa); b = b.substr(sb);
    if (a.size()==0) pa = 0;        // 处理 0.00...0 的情况
    if (b.size()==0) pb = 0;
    string fa(""), fb("");
    if (pa < n) {
        for (int i = 0; i < n; ++i) {
            if (i < a.size()) {
                fa.push_back(a[i]);
            } else {
                fa.push_back('0');
            }
        }
    } else { fa = a.substr(0, n); }
    if (pb < n) {
        for (int i = 0; i < n; ++i) {
            if (i < b.size()) {
                fb.push_back(b[i]);
            } else {
                fb.push_back('0');
            }
        }
    } else { fb = b.substr(0, n); }
    if (fa == fb && pa == pb) {
        cout << "YES 0." << fa << "*10^" << pa << endl;;
    } else {
        cout << "NO 0." << fa << "*10^" << pa << " 0." << fb << "*10^" << pb << endl;
    }
    return 0;
}
