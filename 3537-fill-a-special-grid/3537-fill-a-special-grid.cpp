class Solution {
public:
    vector<vector<int>> grid;
    void fillGrid(int x, int y, int size, int offset){
        if(size==1){
            grid[x][y] = offset;
            return;
        }
        int half = size/2;
        int blockSize = half*half;
        fillGrid(x,y,half,offset + 3 * blockSize);
        fillGrid(x,y+half,half,offset);
        fillGrid(x+half,y+half, half, offset + blockSize);
        fillGrid(x+half,y,half,offset+2*blockSize);
    }
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        grid.assign(size,vector<int>(size));
        fillGrid(0,0,size,0);
        return grid;
    }
};