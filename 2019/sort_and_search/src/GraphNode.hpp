#ifndef ANDREW_SEARCHSORT_GRAPHNODE_H
#define ANDREW_SEARCHSORT_GRAPHNODE_H

class GraphNode {
    private:
        int node_id_;
        int dist_;

    public:
        GraphNode(int const &, int const &);
        
        bool operator<(const GraphNode &) const;
        bool operator>(const GraphNode &) const;
        bool operator==(const GraphNode &) const;
        bool operator!=(const GraphNode &) const;
        
        int Id() const;
        int Dist() const;

        void UpdateDist(int const &);
};

#endif // ANDREW_SEARCHSORT_GRAPHNODE_H
