from typing import List

def new_island_char():
    i = 'a'
    while (i <= 'z'):
        yield i
        i = chr(ord(i) + 1)
        
LAND = '1'
SEA = '0'

class Solution:
    islands = []

    new_island = new_island_char()

    def numIslands(self, grid: List[List[str]]) -> int:
        for y, row in enumerate(grid):
            for x, point in enumerate(row):
                if point == LAND:
                    self.color_all_connected(grid, x, y, next(self.new_island))
        return len(self.islands)

    def try_to_color(self, grid, x, y, c):
        try:
            if grid[x][y] == c:
                return
            elif grid[x][y] == LAND:
                grid[x][y] = c
                self.color_all_connected(grid, x, y, c)
        except IndexError:
            pass

    def color_all_connected(self, grid, x, y, c):
        if c not in self.islands:
            self.islands.append(c)
        self.try_to_color(grid, x, y, c)
        self.try_to_color(grid, x+1, y, c)
        self.try_to_color(grid, x-1, y, c)
        self.try_to_color(grid, x, y+1, c)
        self.try_to_color(grid, x, y-1, c)

    def load_grid(self, filename):
        grid = []
        with open(filename, "r") as f:
            while (1):
                line = f.readline()
                if not line:
                    break
                grid.append(list(line.strip("\n")))
        return grid


    def print_grid(self, grid):
        for y, row in enumerate(grid):
            for x, point in enumerate(row):
                print(f"{point}", end="")
            print("")

if __name__ == "__main__":
    s = Solution()
    grid = s.load_grid("map1.txt")
    print(f"num islands: {s.numIslands(grid)}")
    print(s.islands)
    s.print_grid(grid)
