#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v){
  for(int n : v){
    cout << n << endl;
  }
}

int main(){

  std::vector<int> v = {5,4,1,2,3,4,1,2,3,4,5,6,7,8};

  v.push_back(25);
  v.push_back(13);

  printVector(v);

  return 0;
}