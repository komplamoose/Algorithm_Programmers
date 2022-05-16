#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(long long int n) {
    if (n<2) return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<bool> comb(nums.size(), true);
    for (int i=0; i<comb.size()-3; i++) {
        comb[i]=false; // 3개만 뽑을거임
    }
    
    
    do {
        long long int sum=0;
        for (int i=0; i<nums.size(); i++) {
            if (comb[i]==true) sum+=nums[i]; 
        }
        if (isPrime(sum)){
            answer++;
        }
    }while (next_permutation(comb.begin(), comb.end()));

    return answer;
}