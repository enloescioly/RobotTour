#include <bits/stdc++.h> 

using namespace std;

/*
TO-DO:
--------------
- Implement custom measurements between zone 
- Add # of turns as a factor for ShortestPath 

*/

const int N = 7;
const int GATES = 6;

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
    vector<pair<pair<int, int>, char>> wood_blocks(n_wood);
    for(auto pp : wood_blocks) {
        cin >> p.first >> p.second.first >> p.second.second;
    }

    // Graph Traversal
    bool vis[N][N][1 << GATES];
    memset(vis, false, sizeof(vis));
    auto valid_coordinate = [&](pair<int, int> coord) -> bool {
        return coord.first >= 0 && coord.first < N && coord.second >= 0 && coord.second < N;
    };  
    // Memory doesn't matter + Low Bounds, so I'm creating a huge multi-dimensional array to store paths
    vector<pair<int, int>> minimum_path[N][N][1 << GATES]; 
    // No cycles present, so brute-force BFS should work here
    queue<pair<pair<int, int>, int> q;
    q.push(make_pair(make_pair(start.first, start.second), 0));
    while(q.size()) {
        
    }
}