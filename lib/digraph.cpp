#include "digraph.h"

DiGraph::DiGraph(ctci::string label):
    m_nodes(),
    m_label(label)
{
}

void DiGraph::connect(DiGraph *pNode)
{
    m_nodes.push_back(pNode);
}

const ctci::vector<DiGraph *> &DiGraph::getConnectedNodes() const
{
    return m_nodes;
}

bool DiGraph::getPathTo(DiGraph* pTarget, std::deque<DiGraph*>& path, ctci::vector<DiGraph*>& visited)
{
    for (int i = 0; i < (int)m_nodes.size(); i++)
    {
        DiGraph* pOther = m_nodes[i];

        for (int j = 0; j < (int)visited.size(); j++)
            if (visited[j] == pOther)
                return false;

        visited.push_back(pOther);

        if (pOther == pTarget)
        {
            return true;
        }
        bool found = pOther->getPathTo(pTarget, path, visited);

        if (found)
        {
            path.push_front(pOther);
            return true;
        }
    }
    return false;
}
