#include <bits/stdc++.h>
#include<map>

using namespace std;

int main() {
    
    map<string, int> mp;
    
    mp["jol78"] = 32;
    cout << mp["jol78"];

    return 0;
}

// in mp["invalid index"]
// if string it stores ""
// if int it stores 0

// #include <unordered_map>

// syntax unordered_map<key, value> hashMap;

// unordered_map<int, int> htmap;
// htmap[2] = 1;
