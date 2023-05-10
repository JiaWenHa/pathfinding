/*
 * @Author: jia
 * @Date: 2023-05-10 17:30:06
 * @LastEditors: jia
 * @LastEditTime: 2023-05-10 18:37:42
 * @Description: 带网格图的广度优先算法
 */
#include "implementation.cpp"

template<typename Location, typename Graph>
std::unordered_map<Location, Location>
breadth_first_search(Graph graph, Location start){
    std::queue<Location> frontier; //frontier是指当前位置智能体可以移动到的位置
    frontier.push(start);

    // path A->B is stored as came_from[B] == A
    std::unordered_map<Location, Location> came_from; //用来记录当前位置的前一个位置
    came_from[start] = start;
    
    while (! frontier.empty())
    {
        Location current = frontier.front();
        frontier.pop();

        for(Location next : graph.neighbors(current)){
            if(came_from.find(next) == came_from.end()){
                frontier.push(next);
                came_from[next] = current;
            }
        }
    }
    return came_from;
}

int main(){
    SquareGrid grid = make_diagram1();
    GridLocation start{7, 8};
    auto parents = breadth_first_search(grid, start);
    draw_grid(grid, nullptr, &parents, nullptr, &start);
}
