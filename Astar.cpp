/*
 * @Author: jia
 * @Date: 2023-05-10 19:47:13
 * @LastEditors: jia
 * @LastEditTime: 2023-05-10 19:47:13
 * @Description: A star 算法
 */
#include "implementation.cpp"

int main() {
  GridWithWeights grid = make_diagram4();
  GridLocation start{1, 4}, goal{8, 3};
  std::unordered_map<GridLocation, GridLocation> came_from;
  std::unordered_map<GridLocation, double> cost_so_far;
  a_star_search(grid, start, goal, came_from, cost_so_far);
  draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);
  std::cout << '\n';
  std::vector<GridLocation> path = reconstruct_path(start, goal, came_from);
  draw_grid(grid, nullptr, nullptr, &path, &start, &goal);
  std::cout << '\n';
  draw_grid(grid, &cost_so_far, nullptr, nullptr, &start, &goal);
}