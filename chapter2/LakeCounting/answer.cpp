/*
 * POJ 2386: Lake Counting
 */
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

const int MAX_W = 110;
const int MAX_H = 110;

const int DY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int g_width;
int g_height;

char g_field[MAX_H][MAX_W];

bool inside(int y, int x){
  return (0 <= y && y < g_height && 0 <= x && x < g_width);
}

void fillDot(int y, int x){
  g_field[y][x] = '.';

  for(int i = 0; i < 8; i++){
    int ny = y + DY[i];
    int nx = x + DX[i];

    if(inside(ny,nx) && g_field[ny][nx] == 'W'){
      fillDot(ny,nx);
    }
  }
}

int main(){
  char ch;
  cin >> g_height >> g_width;

  for(int y = 0; y < g_height; y++){
    for(int x = 0; x < g_width; x++){
      cin >> ch;
      g_field[y][x] = ch;
    }
  }

  int lakeCount = 0;

  for(int y = 0; y < g_height; y++){
    for(int x = 0; x < g_width; x++){
      if(g_field[y][x] == 'W'){
        lakeCount += 1;
        fillDot(y,x);
      }
    }
  }

  cout << lakeCount << endl;

  return 0;
}
