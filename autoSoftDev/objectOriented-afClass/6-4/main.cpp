#include <iostream>
using namespace std;

/* 请在这里填写答案 */

int main()
{
    Vector<int> vint;
    int n,m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        //    add() can inflate the vector automatically
        vint.add(i);    
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size()-1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}
