#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 함수로 정답을 계산하는 부분
void calculateAnswers(vector<string>& dictionary, vector<string>& puzzles) {
    // 각 퍼즐판에 대한 정답을 저장할 벡터
    vector<pair<string, int>> answers;

    // 사전을 해시 맵으로 변환하여 더 효율적으로 검색 가능하게 함
    unordered_map<string, int> dictMap;
    for (const string& word : dictionary) {
        dictMap[word] = 1;
    }

    // 모든 퍼즐판에 대한 정답 계산
    for (const string& puzzle : puzzles) {
        int maxScore = 0;
        string maxChars;

        // 가운데 글자를 선택
        for (char center : puzzle) {
            string chars = "";
            int score = 0;

            // 가운데 글자와 다른 글자들로 단어 조합 생성
            for (char c : puzzle) {
                if (c != center) {
                    chars += c;
                }
            }

            // 가능한 모든 조합을 생성하고 사전에 있는지 확인
            do {
                if (dictMap.find(chars) != dictMap.end()) {
                    score++;
                }
            } while (next_permutation(chars.begin(), chars.end()));

            // 최대 점수와 그 때의 문자열 저장
            if (score > maxScore) {
                maxScore = score;
                maxChars = center;
            }
        }

        // 결과를 정답 벡터에 추가
        answers.push_back({ maxChars, maxScore });
    }

    // 정답 출력
    for (const pair<string, int>& answer : answers) {
        cout << answer.first << " " << answer.second << "\n";
    }
}

int main() {
    // 사전을 저장할 벡터
    vector<string> dictionary;
    string word;

    // 사전 입력 받기
    while (true) {
        cin >> word;
        if (word == "-") {
            break;
        }
        dictionary.push_back(word);
    }

    // 퍼즐판을 저장할 벡터
    vector<string> puzzles;
    
    // 여러 개의 퍼즐 입력 받기
    while (true) {
        cin >> word;
        if (word == "#") {
            break;
        }
        puzzles.push_back(word);
    }

    // 정답 계산 및 출력
    calculateAnswers(dictionary, puzzles);

    return 0;
}

