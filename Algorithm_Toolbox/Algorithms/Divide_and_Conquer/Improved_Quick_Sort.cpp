#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
    int m1, m2;
    //int j_low = l;
    vector<int> mid(2);
    //mid[0] = mid[1] = j;
    m1=m2=l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] < x)
    {
        j++;
        //m1=m2=j;
        //mid[0] = j;
        swap(a[i], a[j]);
        
        //if m1 is not pointing at start, swap with most recent entry
        if(a[m1] == x)
        {
            swap(a[j], a[m1]);
            m1++;
        }
        //and increment m1
    }
    else if(a[i] == x)
    {
        j++;
        //mid[0] = j;
        swap(a[i], a[j]);
        //point both m1 & m2 here for first time
        if(m2 == l)
         m1=m2=j;
        else//else increment m2
         m2 = j;

    }
  }
    if(m1 != l)
    {
        swap(a[l], a[m1-1]);
        mid[0] = m1;
        mid[1] = m2;
    }
    else
    {
        swap(a[l], a[j]);
        mid[0] = j;
        mid[1] = j;
    }
    
    return mid;
  //return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[0] + 1, r);
}

int main_part3() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, (int)a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
    std::cout << std::endl;
    return 0;;
    //cout << std::endl;
}
