/*
    310. 最小高度树
        1、利用bfs算法，得出图的最长路径 maxPathSize，用数组保存该路径的所有节点 maxPath
            - 因为不确定图中的哪个节点是根节点，需要两次bfs
            - 第一次默认从0节点开始广搜，找到一个边界(根或叶子节点)
            - 第二次将所找到节点作为根节点进行广搜
        2、若 maxPathSize 为奇数，返回 maxPathSize/2 ; 偶数，返回 (maxPathSize)/2,(maxPathSize)/2+1
*/
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
#define maxn 100000
    // 定义 二维数组Edges，大小为10^5，数组中每个元素为 vector<int> *
    vector< int > Edges[ maxn ];
    // 使用pre记录每个节点的前驱节点（在最长路径中）
    int pre[ maxn ] = { -1 };
    // 初始化每个边节点
    void init( int n ) {
        for ( int i = 0; i < n; i++ ) {
            Edges[ i ].clear();
        }
    }
    // 将边节点加入Edge中
    void addEdge( int u, int v ) {
        Edges[ u ].push_back( v );
        Edges[ v ].push_back( u );
    }
    // 广搜算法，用n是总节点数，u是开始节点，flag为1：当前在寻找最长路径
    int bfs( int n, int u ) {
        // dist数组 记录每一个节点到当前u节点的距离，-1不通，0表示本节点
        int dist[ maxn ];
        int i;
        // 创建一个队列q，每次使用push(x)入队，用pop()出队；pop()不会返回元素值，要先用front()访问其值
        queue< int > q;
        // char型-1,机器码为 1111，即无符号数最大值；合并为int后结果仍为-1
        memset( dist, -1, sizeof( dist ) );
        dist[ u ] = 0;
        pre[ u ]  = -1;
        q.push( u );
        // 队列非空时进入循环
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            // 将当前u节点的所有相邻边入队q
            for ( i = 0; i < Edges[ u ].size(); i++ ) {
                int v = Edges[ u ][ i ];
                // 如果该节点本轮未被访问过
                if ( dist[ v ] == -1 ) {
                    dist[ v ] = dist[ u ] + 1;
                    // 若在寻找最长路径中，将v的前驱改为u
                    pre[ v ] = u;
                    q.push( v );
                }
            }
        }
        //通过dist数组寻找边界
        int edge = 0;
        for ( int i = 1; i < n; i++ ) {
            if ( dist[ i ] > dist[ edge ] ) {
                edge = i;
            }
        }
        return edge;
    }

public:
    // findMinHeightTrees() 返回一个元素为 int 的容器
    // 参数 edges 前的 & 表示引用
    vector< int > findMinHeightTrees( int n, vector< vector< int > >& edges ) {
        vector< int > maxPath;
        maxPath.clear();
        init( n );
        // 创建对应边
        for ( int i = 0; i < edges.size(); i++ ) {
            addEdge( edges[ i ][ 0 ], edges[ i ][ 1 ] );
        }
        // 从第0个节点开始遍历，找到第一个边界
        int x = bfs( n, 0 );
        // 从边界开始遍历，找到第二个边界
        int y = bfs( n, x );
        // 通过pre数组找到最长路径
        maxPath.push_back( y );
        while ( pre[ y ] != -1 ) {
            y = pre[ y ];
            maxPath.push_back( y );
        }
        // maxPathSize为奇数
        if ( maxPath.size() & 1 ) {
            return { maxPath[ maxPath.size() / 2 ] };
        }
        else {
            return { maxPath[ maxPath.size() / 2 - 1 ], maxPath[ maxPath.size() / 2 ] };
        }
    }
};