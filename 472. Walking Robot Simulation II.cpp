class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    vector<string> dirs = {"East", "North", "West", "South"};
    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        cycle = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= cycle;
        
        // Special case: if num == 0, robot still may change direction
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }
        
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        while (num--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // If out of bounds → turn CCW
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};
