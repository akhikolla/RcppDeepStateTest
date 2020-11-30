
class ASterQueue {
private:
    const int n_;
    const int tree_width_;
    std::vector<vset> heap_; // for the priority queue
    std::map<vset, OrderNode*> node_map_;
    std::map<vset, int> pos_map_;
    std::vector<std::map<vset, score_t> > cache_map_;
    ParentScore& ps_;

public:
    ASterQueue(int n, int tree_width, ParentScore& ps) : n_(n),
        tree_width_((tree_width != 0) ? tree_width : n),
        cache_map_(n),
        ps_(ps)
    { }

    void addNode(OrderNode* node)
    {
        node_map_[node->getVset()] = node;
        heap_.push_back(node->getVset());
        int index = static_cast<int>(heap_.size()) - 1;
        pos_map_[node->getVset()] = index;
        upHeap(index);
    }

    void addOrUpdateNode(vset vs, score_t score, score_t estimated_score, int parent_pos)
    {
        std::map<vset, OrderNode*>::iterator itor = node_map_.find(vs);
        if (itor != node_map_.end()) { // found
            if (estimated_score < itor->second->getEstimatedScore()) { // update
                itor->second->setScore(score);
                itor->second->setEstimatedScore(estimated_score);
                itor->second->setParentPos(parent_pos);
                upHeap(pos_map_[vs]);
            }
        } else { // not found
            OrderNode* node = new OrderNode(vs, score, estimated_score, parent_pos);
            node_map_[node->getVset()] = node;
            heap_.push_back(node->getVset());
            int index = static_cast<int>(heap_.size()) - 1;
            pos_map_[node->getVset()] = index;
            upHeap(index);
        }
    }

    OrderNode* pop()
    {
        assert(heap_.size() > 0);
        int last_index = static_cast<int>(heap_.size()) - 1;
        swapPos(0, last_index);

        vset vs = heap_.back();
        OrderNode* node = node_map_[vs];
        heap_.pop_back();
        pos_map_.erase(vs); // vs of the keys in node_map_ is not erased
                            // because it will be used later
        downHeap(0);
        return node;
    }

    size_t size() const
    {
        return heap_.size();
    }

    bool empty() const
    {
        return heap_.empty();
    }

    OrderNode* getNode(vset vs) const
    {
        return node_map_.at(vs);
    }

    score_t getBestScore(int x, vset u_vset)
    {
        if (__builtin_popcountll(u_vset) <= tree_width_) {
            score_t v = ps_.getBestScore(x, u_vset);
            return v;
        } else {
            score_t cand_score = -99999999.9;
            for (int y = 0; y < n_; ++x) {
                if (((u_vset >> y) & ONE_LLU) != 0) {
                    vset u_minus_y_vset = u_vset & ~(ONE_LLU << y);
                    score_t v;
                    std::map<vset, score_t>::iterator itor =
                        cache_map_[x].find(u_minus_y_vset);
                    if (itor != cache_map_[x].end()) { // element found
                        v = itor->second;
                    } else {
                        v = getBestScore(x, u_minus_y_vset);
                    }
                    if (v > cand_score) {
                        cand_score = v;
                    }
                }
            }
            cache_map_[x][u_vset] = cand_score;
            return cand_score;
        }
    }

    void print()
    {
        std::vector<vset>::iterator itor = heap_.begin();
        while (itor != heap_.end()) {
            cerr << *itor << ", ";
            ++itor;
        }
        cerr << "\n";
    }

    void printheap(int n)
    {
        std::vector<vset>::iterator itor = heap_.begin();
        while (itor != heap_.end()) {
            cerr << *itor << ": " << node_map_[*itor]->toString(n) << std::endl;
            ++itor;
        }
    }

private:
    void swapPos(int index1, int index2)
    {
        pos_map_[heap_[index1]] = index2;
        pos_map_[heap_[index2]] = index1;
        std::swap(heap_[index1], heap_[index2]);
    }

    void upHeap(int index)
    {
        if (index > 0) {
            int parent = (index - 1) / 2;
            if (node_map_[heap_[parent]]->getEstimatedScore() >
                node_map_[heap_[index]]->getEstimatedScore()) {
                swapPos(parent, index);
                upHeap(parent);
            }
        }
    }

    void downHeap(int index)
    {
        int child = -1;
        int n = static_cast<int>(heap_.size());

        if (index * 2 + 2 < n) {
            child = (node_map_[heap_[index * 2 + 1]]->getEstimatedScore() <
                     node_map_[heap_[index * 2 + 2]]->getEstimatedScore() ?
                     index * 2 + 1 : index * 2 + 2);
        } else if (index * 2 + 2 == n) {
            child = index * 2 + 1;
        }
        if (child >= 0) { // a child exists
            if (node_map_[heap_[child]]->getEstimatedScore() <
                node_map_[heap_[index]]->getEstimatedScore()) {
                swapPos(child, index);
                downHeap(child);
            }
        }
    }

    void update(vset vs)
    {
        int index = pos_map_[vs];
        int parent = (index - 1) / 2;
        if (node_map_[heap_[parent]]->getEstimatedScore() >
            node_map_[heap_[index]]->getEstimatedScore()) {
            upHeap(index);
        } else {
            downHeap(index);
        }
    }
};
