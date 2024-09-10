#include<bits/stdc++.h>

using namespace std;

#define LENGTH_D_REZ 1000000
#define LENGTH_TARGET 100000
#define LENGTH_P 100000

vector <int> divizori(int n)
{   vector <int> v;
    for (int j=1; j*j <= n; j++)
    if ( n%j == 0)
    {   v.push_back(j);
        v.push_back(n/j);
    }
    return v;
}
int maxim(int v[], int n)
{   int max = 0;
    for (int i=0; i < n; i++)
    {   if ( v[i] > max)
            max = v[i];
    }
    return max;
}
int mini(int a, int b) {
	if ( a < b )
	    return a;
	return b;
}

int  d_rez[LENGTH_D_REZ];
int target[LENGTH_TARGET], p[LENGTH_P];

int main()
{   int N, K;
    ifstream in("prinel.in");
    ofstream out("prinel.out");

    in >> N >> K;
    for (int i=0; i < N; i++)
    {   in >> target[i];
    }
    for (int i=0; i < N; i++)
    {   in >> p[i];
    }

    int maximm = maxim(target, N);
    for ( int i = 2; i <= maximm; i++)
        d_rez[i] = 1000000;
    for ( int i=1; i <= maximm ; i++)
    {   vector <int> d;
        d = divizori(i);
        for (int j=0; j < d.size(); j++)
        {   d_rez[i + d[j]] = mini(d_rez[i + d[j]], 1 + d_rez[i]);
            // vedem nr min de parcurgeri pt a obtinbe val i
        }
    }
    // am folosit problema rucsac din laborator pentru afisare
    vector<vector<int>> afisare(N + 1, vector<int>(K + 1, 0));
    for (int i=1; i <= N; i++)
    {   int j = 0;
        while ( j <= K)
        {   if (d_rez[target[i - 1]] <= j) {
                afisare[i][j] = max(p[i-1] +
                                afisare[i-1][j-d_rez[target[i - 1]]],
                                afisare[i-1][j]);
            } else {
                afisare[i][j] = afisare[i-1][j];
            }
            j++;
        }
    }

    out << afisare[N][K];
    in.close();
    out.close();
    return 0;
}
