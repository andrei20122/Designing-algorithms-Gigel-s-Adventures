#include<bits/stdc++.h>

using namespace std;
int nr_aparitii(string s)
{   int max;
    max = 0;
    char res;
    for (int i = 0; i < s.length(); i++)
    {   int count = 0;
        for (int j = 0; j < s.length(); j++)
        {   if (s[j] == s[i])
                count++;
        }
        if (count >  max)
        {   max = count;
            res = s[i];
        }
    }
    return res;
}

bool desc(int a, int b) {return a > b;}
int main()
{   int N;
    ifstream in("statistics.in");
    ofstream out("statistics.out");
    vector <string> cuv;  // vectorul de cuvinte
    in >> N;
    string unCuv;
    for (int i = 0; i < N; i++)
    {  in >> unCuv;
        cuv.push_back(unCuv);
    }

    int max_ok = 0;
    for ( int j=0; j < 26; j++)  // merg de la a-z
    {   vector <int> v_scor;
       for (int i = 0; i < cuv.size(); i++)  // iau fiecare cuv
       {   int word_ok = 0;
            // practic retin cumva in variabila asta "scorul" cuvantului ^^
           for (int k=0; k < cuv[i].length(); k++)
           // parcurg fiecare litera din cuv
           {    if ( j + 'a' == cuv[i][k] ) {
               word_ok++;
            } else {
                 word_ok --;
            }
           }
            v_scor.push_back(word_ok);
       }
       sort(v_scor.begin(), v_scor.end(), desc);
       int ok = 0, sum_scor = 0;
       for (int i = 0; i < v_scor.size(); i++)
       {   sum_scor += v_scor[i];
           if (sum_scor > 0) {
                ok++;
           } else {
               ok += 0;  // cred ca else ul asta nu face nimic
           }
       }
       max_ok = max(ok, max_ok);
    }
    if (max_ok == 0)
        out << -1;
    else
         out << max_ok;
    in.close();
    out.close();

    return 0;
}
