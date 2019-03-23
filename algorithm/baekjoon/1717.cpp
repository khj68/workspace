#include <stdio.h>
#include <iostream>

using namespace std;

int parent[1000001];
int Find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        parent[y] = x;
}
int main() {
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    while (m--)
    {
        int c, a, b;
        cin >> c;
        cin >> a;
        cin >> b;

        if (c == 0)//a,b를 합침
        {
            Union(a, b);
        }
        else//a,b가 같은 원소인가
        {
            
            if (Find(a) == Find(b))
                cout << "YES\n" ;
            else
                cout << "NO\n";
        }
    }
}
