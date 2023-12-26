class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        // dfs
        dfs(0, rooms, visited);
        int roomsVisited = count(visited.begin(), visited.end(), true);
        return roomsVisited == n;
    }
private:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        if (visited[room]) return;
        visited[room] = true;
        for (int key : rooms[room]) {
            dfs(key, rooms, visited);
        }
    }
};