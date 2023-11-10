#include <bits/stdc++.h> 

using namespace std;

/*
TO-DO:
--------------
- CHANGE N TO 9, MARK ALL BORDER EDGES AS BAD
- Implement custom measurements between zone 
- Add # of turns as a factor for ShortestPath 

*/

const int N = 7;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
// const char dir[] = {'R', 'D', 'L', 'U'};

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    /*
    Input Format:
    [Start Point Coordinate]
    [Target Point Coordinate]
    [# of Bonus Gate Zones]
    [Gate Zone 1] [Gate Zone 2] [Gate Zone 3] ... [Gate Zone N]
    [# of Wooden Blocks]
    [Wooden Block 1] [Wooden Block 2] [Wooden Block 3] ... [Wooden Block N]
    */

    // 7x7 grid, start point is outside of boundaries (we don't want to move along outer grid lines)

    // input
    pair<int, int> start, target;
    cin >> start.first >> start.second >> target.first >> target.second; 
    int n_bonus; 
    cin >> n_bonus;
    map<pair<int, int>, int> bonus_zones; 
    for(int i = 0; i < n_bonus; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        bonus_zones[p] = i;
    }
    int n_wood; 
    cin >> n_wood;
    bool wood_blocks[N][N];
    for(int i = 0; i < n_wood; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        char c; cin >> c;
        if(c == 'h') {
            wood_blocks[p.first][p.second] = true;
            if(p.first + 1 < N)
                wood_blocks[p.first + 1][p.second] = true;
            if(p.first - 1 >= 0)
                wood_blocks[p.first - 1][p.second] = true;
        }
        else {
            wood_blocks[p.first][p.second] = true;
            if(p.second + 1 < N)
                wood_blocks[p.first][p.second + 1] = true;
            if(p.second - 1 >= 0)
                wood_blocks[p.first][p.second - 1] = true;
        }
    }    

    // Graph Traversal
    
    // bool vis[N][N][1 << n_bonus];
    // memset(vis, false, sizeof(vis));
    
    auto valid_coordinate = [&](pair<int, int> coord) -> bool {
        return coord.first >= 0 && coord.first < N && coord.second >= 0 && coord.second < N && !wood_blocks[coord.first][coord.second];
    };  
    
    // Memory doesn't matter + Low Bounds, so I'm creating a huge multi-dimensional array to store paths
    
    vector<pair<int, int>> minimum_path[N][N][1 << n_bonus]; 
    
    // No cycles present, so brute-force BFS should work here
    
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(start.first, start.second), 0));
    while(q.size()) {
        pair<int, int> coord = q.front().first;
        int gates_visited = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            pair<int, int> ncoord = make_pair(coord.first + dx[i], coord.second + dy[i]);
            if(valid_coordinate(ncoord)) {
                int ngates_visited = gates_visited;
                if(bonus_zones.count(ncoord)) {
                    ngates_visited |= (1 << bonus_zones[ncoord]);
                }
                if(minimum_path[ncoord.first][ncoord.second][ngates_visited].size() == 0) {
                    if(valid_coordinate(coord)) {
                        for(pair<int, int> p : minimum_path[coord.first][coord.second][gates_visited]) {
                            minimum_path[ncoord.first][ncoord.second][ngates_visited].push_back(p);
                        }
                    }
                    else {
                        minimum_path[ncoord.first][ncoord.second][ngates_visited].push_back(coord);
                    }
                    minimum_path[ncoord.first][ncoord.second][ngates_visited].push_back(ncoord);
                    q.push(make_pair(ncoord, ngates_visited));
                }
            } 
        }
    }

    // Found shortest path to target point, going through bonus zones
    // Conversion to cardinal directions

    // Check if there exists a path containing all bonus zones (wood blocks may block off gate zones)
    for(int i = 0; i < (1 << n_bonus); i++){

    }

}