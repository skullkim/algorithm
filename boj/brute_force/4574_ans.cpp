#include <iostream> 
#include <vector> 
using namespace std; 
const int N = 9; 
int dr_x[] = {0, 1}; 
int dr_y[] = {1, 0}; 
vector<vector<bool>> vert; 
vector<vector<bool>> hori; 
vector<vector<bool>> box; 
vector<vector<bool>> domino; 
vector<vector<int>> sdoku; 
void print_sdoku() { 
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) { 
            cout << sdoku[i][j]; 
            
        } cout << '\n'; 
        
    } 
    
} 
int inline bx(int x, int y) { 
    return (x / 3) * 3 + (y / 3); 
    
} 
void inline change_flag(int x, int y, int order, bool flag) { 
    vert[x][order] = hori[y][order] = box[bx(x, y)][order] = flag; 
    
} 
bool inline possible(int x, int y, int order) { 
    return !(vert[x][order] || hori[y][order] || box[bx(x, y)][order]); 
    
} 
bool sdominoku(int num) { 
    // 마지막 칸을 채우면 출력 후 종료 
    if (num == N * N) { 
        print_sdoku(); return true; 
        
    } 
    // 스도쿠 판의 행/렬 구하기
	int x = num / N; int y = num % N; 
    // 칸이 비어있지 않을 때 : 다음 칸으로 sdominoku재귀함수 호출 
    if (sdoku[x][y] != 0) { 
        return sdominoku(num + 1); 
        
    } 
    // 칸이 비어있을 때 
    else { 
        // 도미노 가로 세로 2방향 탐색 
        for (int i = 0; i < 2; ++i) { 
            int x2 = x + dr_x[i]; 
            int y2 = y + dr_y[i]; 
            // 범위 밖이거나 도미노 2번째 칸이 0이 아니면 continue 
            if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || sdoku[x2][y2] != 0) { 
                continue; 
            } 
            // 가능한 도미노 조합을 자리에 저장하기 
            for (int fst = 1; fst <= N; ++fst) { 
                for (int snd = 1; snd <= N; ++snd) { 
                    // 도미노의 두 숫자가 같거나 이미 써버린 도미노 조합이면 continue 
					if (fst == snd || domino[fst][snd]) { 
                        continue; 
                    } 
                    // 각 자리의 각 숫자가 스도쿠에서 가능할 때 
                    if (possible(x, y, fst) && possible(x2, y2, snd)) { 
                        // 숫자 저장 및 스도쿠, 도미노 bool벡터 true 체크 
                        sdoku[x][y] = fst; sdoku[x2][y2] = snd; 
                        change_flag(x, y, fst, true); 
                        change_flag(x2, y2, snd, true);
                        domino[fst][snd] = domino[snd][fst] = true; 
                        // 한번이라도 성공시키면 리턴 
                        if (sdominoku(num + 1)) return true;
                        // 숫자 원복 및 스도쿠, 도미노 bool벡터 false 체크 
                        sdoku[x][y] = sdoku[x2][y2] = 0; 
                        change_flag(x, y, fst, false); 
                        change_flag(x2, y2, snd, false); 
                        domino[fst][snd] = domino[snd][fst] = false; 
                        
                    } 
                    
                } 
                
            } 
            
        } 
        
    } 
    return false; 
    
} 
int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int puzzle = 0; 
    while (true) { 
        int cnt; 
        cin >> cnt; 
        if (cnt == 0) {
            break; 
        } 
        // 각 벡터 초기화 
        domino = vector<vector<bool>>(N + 1, vector<bool>(N + 1)); 
        vert = vector<vector<bool>>(N, vector<bool>(N + 1)); 
        hori = vector<vector<bool>>(N, vector<bool>(N + 1));
        box = vector<vector<bool>>(N, vector<bool>(N + 1));
        sdoku = vector<vector<int>>(N, vector<int>(N)); 
        // 입력 - 도미노 & 스도쿠 
        while (cnt--) { 
            int n1, n2; 
            string p1, p2; 
            cin >> n1 >> p1 >> n2 >> p2;
            // 스도쿠 판에 숫자 입력 
            int x1 = p1[0] - 'A', x2 = p2[0] - 'A'; 
            int y1 = p1[1] - '1', y2 = p2[1] - '1'; 
            sdoku[x1][y1] = n1; 
            sdoku[x2][y2] = n2; 
            // 스도쿠, 도미노 bool벡터에 true 체크
            vert[x1][n1] = vert[x2][n2] = true;
            hori[y1][n1] = hori[y2][n2] = true; 
            box[(x1 / 3) * 3 + (y1 / 3)][n1] = true; 
            box[(x2 / 3) * 3 + (y2 / 3)][n2] = true;
            domino[n1][n2] = domino[n2][n1] = true; 
            
        } 
        // 입력 - 스도쿠 
        for (int i = 1; i <= N; ++i) { 
            string pos; cin >> pos;
            // 스도쿠 판에 숫자 입력 
            int x = pos[0] - 'A'; 
            int y = pos[1] - '1'; 
            sdoku[x][y] = i; 
            // 스도쿠 bool벡터에 true 체크 
            vert[x][i] = hori[y][i] = true; 
            box[(x / 3) * 3 + (y / 3)][i] = true;
        } 
            // 스도미노쿠 완성 후 출력 
        cout << "Puzzle " << ++puzzle << '\n'; 
        sdominoku(0); 
        
    } 
    return 0;
}

