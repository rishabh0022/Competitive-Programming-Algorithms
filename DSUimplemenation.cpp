class dsu {
public:
    vector<int> parent;
    vector<int> size;
 
    dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
 
    int find(int a) {
        if (parent[a] ==a)return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
 // union by size 
    void union_size(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return;
        if (size[par1] < size[par2]) {
            parent[par1] = par2;
            size[par2] += size[par1];
        } else {
            parent[par2] = par1;
            size[par1] += size[par2];
        }
    }
};
