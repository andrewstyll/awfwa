#include "GraphNode.hpp"

GraphNode::GraphNode(int const &node_id, int const &dist):
node_id_(node_id), dist_(dist) {
}

bool GraphNode::operator<(const GraphNode &g) const {
    return dist_ < g.Dist();
}

bool GraphNode::operator>(const GraphNode &g) const {
    return dist_ > g.Dist();
}

bool GraphNode::operator==(const GraphNode &g) const {
    return node_id_ == g.Id();
}

bool GraphNode::operator!=(const GraphNode &g) const {
    return node_id_ != g.Id();
}

int GraphNode::Id() const {
    return node_id_;
}

int GraphNode::Dist() const {
    return dist_;
}

void GraphNode::UpdateDist(int const &new_dist) {
    dist_ = new_dist;
}
