class Robot 
{
    public:
        int grid[105][105], w, h;
        string dir;
        pair<int, int> pos;
        int oneRound;
        Robot(int width, int height)
        {
            for(int i = 0; i < height; i++)
                for(int j = 0; j < width; j++)
                    grid[i][j] = 0;
            w = width;
            h = height;
            dir = "East";
            pos = {0, 0};
            oneRound = (height - 1) * 2 + (width - 1) * 2;
        }
        
        void move(int num)
        {
            int totMoves = num % oneRound;
            if(num > oneRound)
            {
                if(pos.first == 0 && pos.second == 0)
                    dir = "South";
                else if(pos.first == w - 1 && pos.second == 0)
                    dir = "East";
                else if(pos.first == w - 1 && pos.second == h - 1)
                    dir = "North";
                else if(pos.first == 0 && pos.second == h - 1)
                    dir = "West";
            
            }
            while(totMoves--)
            {
                if(dir == "East")
                {
                    if(pos.first + 1 == w)
                    {
                        pos.second += 1;
                        dir = "North";
                    }
                    else
                        pos.first += 1;
                }
                else if(dir == "West")
                {
                    if(pos.first - 1 == -1)
                    {
                        pos.second -= 1;
                        dir = "South";
                    }
                    else
                        pos.first -= 1;
                }
                else if(dir == "North")
                {
                    if(pos.second + 1 == h)
                    {
                        pos.first -= 1;
                        dir = "West";
                    }
                    else
                        pos.second += 1;
                }
                else
                {
                    if(pos.second - 1 == -1)
                    {
                        pos.first += 1;
                        dir = "East";
                    }
                    else
                        pos.second -= 1;
                }
            }
        }
    
        vector<int> getPos()
        {
            vector<int> ans;
            ans.push_back(pos.first);
            ans.push_back(pos.second);
            return ans;
        }
        
        string getDir()
        {
            return dir;
        }
};