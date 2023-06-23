/*
    拓扑排序
    实现思路:1.用栈来记录所有当前入度为0的点,
            2.栈中顶点依次出栈并打印，并用count记录打印结点的数量
            3.将当前顶点所对应的邻接点的入度-1，如入度-1后，此邻接点的1入度为1，则将其入栈
            4.重复2，3操作直至栈为空
            5.若count=G.vexNum，则排序成功 否则排序失败，证明图中存在回路
*/

bool TopologicalSort(Graph G) {
    initStack(S);
    int i;
    for(i=0;i<G.vexNum;i++) {//初始化
        if(indegree[i] == 0) {//所有入度为0的点进栈
            Push(S,i);
        }
    }
    int count = 0; //计数 记录当前已经输出的顶点数
    while(!isEmpty(S)) {
        Pop(S,i);
        print[count++] = i;
        for(p=G.vertices[i].firstarc;p;p=p->nextarc) {//将当前顶点的所有邻接点的入度-1
            v = p->adjvex;
            if(!(--indegree[v])) Push(S,v);
        }
    }
    if(count <G.vexNum) return false//排序失败 有向图中有回路
    else return true;
}