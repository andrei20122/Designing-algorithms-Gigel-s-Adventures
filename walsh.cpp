#include<bits/stdc++.h>
using namespace std;

int recursiv_inv(int n, int x, int y, int inv)
{	if (x == 0 && y == 0) {
    	if(inv % 2 == 0)
        {   return 0;
        } else {
            return 1;
        }
    }
    if (x < n/2 && y < n/2)
        return recursiv_inv(n/2, x, y, inv);
    if (x < n/2 && y >= n/2)
        return recursiv_inv(n/2, x, y-n/2, inv);
    if (x >= n/2 && y < n/2)
        return recursiv_inv(n/2, x-n/2, y, inv);
    if (x >= n/2 && y >= n/2)
        return recursiv_inv(n/2, x-n/2, y-n/2, inv+1);
    return 0;
}

int main()
{   int N, K, x, y;
    ifstream in("walsh.in");
    ofstream out("walsh.out");

    in >> N;
    in >> K;
    for (int i = 0; i < K; i++)
    {	in >> x >> y;
        out << recursiv_inv(N, x-1, y-1, 0) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
