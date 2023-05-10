/*
 * @Author: jia
 * @Date: 2023-05-10 16:40:23
 * @LastEditors: jia
 * @LastEditTime: 2023-05-10 17:15:58
 * @Description: 简单的图的广度优先算法
 */
#include "implementation.cpp"

void breadth_first_search(SimpleGraph graph, char start){
    std::queue<char> frontier; //frontier是指当前位置智能体可以移动到的位置
    frontier.push(start);

    std::unordered_set<char> reached; //reached是机器人已经到达过的位置
    reached.insert(start);

    while (! frontier.empty() ){
        char current = frontier.front();
        frontier.pop();

        std::cout << " Visiting " << current << std::endl;
        for(char next : graph.neighbors(current)){
            // 如果下一个节点没有到达过
            if (reached.find(next) == reached.end()){
                frontier.push(next);
                reached.insert(next);
            }
        }
    }
}

int main(){
    std::cout << "Reachable from A: " << std::endl;
    breadth_first_search(example_graph, 'A');
    std::cout << "Reachable from E: " << std::endl;
    breadth_first_search(example_graph, 'E');
}
