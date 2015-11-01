#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <time.h>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
  string str = "";
  char ch;
  int n;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> ch;
    str += ch;
  }
  
  int cnt = 0;

  while(str != ""){
    string rstr = str;
    reverse(rstr.begin(), rstr.end());

    if(str < rstr){
      cout << str[0];
      str.erase(str.begin());
    }else{
      cout << str[str.size()-1];
      str.erase(str.begin()+str.size()-1);
    }

    cnt += 1;

    if(cnt % 80 == 0){
      cout << endl;
    }
  }

  return 0;
}
