#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool compare(pair<string, int>&a, pair<string, int>&b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 각 장르별 총 재생수 계산
    map<string, int> total_plays_by_genres;
    unordered_set<string> unique_genres(genres.begin(), genres.end()); // 중복없는 장르 리스트
    for (auto genre: unique_genres) {
        for (int i=0; i<plays.size(); i++) {
            if (genre == genres[i])
                total_plays_by_genres[genre] += plays[i];
        }
    }

    // total_plays_by_genres의 value(총재생수)를 기준으로 내림차순 정렬하여 탐색할 장르의 우선순위 결정
    vector<pair<string, int>> ordered_unique_genres(total_plays_by_genres.begin(), total_plays_by_genres.end()); //map을 vector로 변경
    sort(ordered_unique_genres.begin(), ordered_unique_genres.end(), compare); //내림차순정렬

    // 장르별 {재생숫자, 고유번호}를 재생숫자의 내림차순으로 정렬하여 plays_by_genre map 생성
    //    ex1) plays_by_genre["classic"] = {{800,3}, {500,0}, {150,2}}
    //    ex2) plays_by_genre["pop"] = {{2500, 4}, {600, 1}}
    unordered_map<string, multimap<int, int, greater<int>>> plays_by_genre;
    for (auto i: ordered_unique_genres) {
        multimap<int, int, greater<int>> plays_with_unique_number;
        for (int j=0; j<plays.size(); j++) {
            if (i.first == genres[j]) {
                plays_with_unique_number.insert(make_pair(plays[j], j));
            }
        }
        plays_by_genre.insert(make_pair(i.first, plays_with_unique_number));
        
    }

    // 정렬된 장르별 재생수 map으로 정답 계산
    for (auto i: ordered_unique_genres) {
        for (auto play_info: plays_by_genre) {
            if (i.first == play_info.first) { // 검사할 장르별로 탐색하여
                int count = 0;
                for (auto j: play_info.second){
                    if (count < 2) { // {재생숫자, 고유번호}에서 고유번호 2개를 answer에 저장.
                        answer.push_back(j.second);
                        count++;
                    }
                }
            }
        }
    }

    return answer;
}