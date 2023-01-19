#include <iostream>
#include <vector>
using namespace std;

int get_round(vector<int> players, int a, int b, int round) {
    vector<int> next_players;
    for (int i=0; i<players.size(); i+=2) {
        if (players[i] == a) next_players.push_back(a);
        else if (players[i] == b) next_players.push_back(b);
        else if (players[i+1] == a) next_players.push_back(a);
        else if (players[i+1] == b) next_players.push_back(b);
        else next_players.push_back(-1);

        if ((players[i] == a && players[i+1] == b) || players[i] == b && players[i+1] == a)
            return round;
    }
    
    return get_round(next_players, a, b, round+1);
}

int solution(int n, int a, int b)
{
    int answer = 0;
    vector<int> players;
    for (int i=1; i<=n; i++) {
        players.push_back(i);
    }
    
    answer = get_round(players, a, b, 1);

    return answer;
}