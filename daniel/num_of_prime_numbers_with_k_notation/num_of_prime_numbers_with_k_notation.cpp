#include <cmath>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isPrimeNumber(long long n) {
    if( n <= 1 )
        return false;
         
    if( n%2 == 0) 
        return n==2 ? true : false;
         
    for(int i=3; i<=sqrt(n); i += 2) { 
        if( n % i == 0) return false;
    }
    
    return true; 
}

vector<long long> split(string input, char delimiter) {
    vector<long long> ret;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delimiter)) if(temp.length()>0) ret.push_back(stoll(temp));
    
    return ret;
}

string getNotationString(int n, int k) {
    string ret = "";
    
    while (n>0) {
        ret = to_string(n%k) + ret;
        n/=k;
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    string notationString = getNotationString(n,k);
    vector<long long> splitNumbers = split(notationString, '0');

    for(auto i:splitNumbers) {
        if (isPrimeNumber(i)) answer++;
    }
    
    return answer;
}