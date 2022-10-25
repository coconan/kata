#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct Term {
    int expo;
    double coef;
};

void addPoly(vector<Term> &p1, vector<Term> &p2, vector<Term> &q) {
    unsigned int i, j;
    for (i = 0, j = 0; i < p1.size() && j < p2.size(); ) {
        if (p1[i].expo < p2[j].expo) {
            q.push_back(p2[j++]);
        } else if (p1[i].expo > p2[j].expo) {
            q.push_back(p1[i++]);
        } else {
            int expo = p1[i].expo;
            double coef = p1[i++].coef + p2[j++].coef;
            if (fabs(coef) > 1e-5) {
                Term t;
                t.coef = coef;
                t.expo = expo;
                q.push_back(t);
            }
        }
    }
    while (i < p1.size()) { q.push_back(p1[i++]); }
    while (j < p2.size()) { q.push_back(p2[j++]); }
}

void multiplyPoly(vector<Term> &p1, vector<Term> &p2, vector<Term> &q) {
    for (unsigned i = 0; i < p1.size(); ++i) {
        vector<Term> partialSum;
        vector<Term> temp(p2);
        for (unsigned j = 0; j < p2.size(); ++j) {
            temp[j].expo += p1[i].expo;
            temp[j].coef *= p1[i].coef;
        }
        addPoly(q, temp, partialSum);
        q.swap(partialSum);
    }
}

int main() {
    //ifstream in("in.txt");
    //streambuf *cinbuf = cin.rdbuf();
    //cin.rdbuf(in.rdbuf());
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout.setf(ios::fixed);

    vector<Term> a, b;
    int k;
    cin >> k;
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].expo >> a[i].coef;
    }
    cin >> k;
    b.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i].expo >> b[i].coef;
    }

    vector<Term> q;
    multiplyPoly(a, b, q);
    cout << q.size() << " ";
    for (unsigned i = 0; i < q.size() - 1; ++i) {
        cout << q[i].expo << " " << q[i].coef << " ";
    }
    cout << q.back().expo << " " << q.back().coef << endl;
    //cin.rdbuf(cinbuf);
    return 0;
}
