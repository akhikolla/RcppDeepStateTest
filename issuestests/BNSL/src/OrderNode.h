
class OrderNode {
private:
    vset vs_;
    score_t score_;
    score_t estimated_score_;
    int parent_pos_; // parent_pos_ == -1 means no parent

public:
    // for the initial node
    OrderNode(score_t estimated_score) :
        vs_(0), score_(0.0), estimated_score_(estimated_score), parent_pos_(-1) { }

    OrderNode(vset vs, score_t score, score_t estimated_score, int parent_pos) :
        vs_(vs), score_(score), estimated_score_(estimated_score), parent_pos_(parent_pos) { }

    vset getVset() const
    {
        return vs_;
    }

    score_t getScore() const
    {
        return score_;
    }

    score_t getEstimatedScore() const
    {
        return estimated_score_;
    }

    int getParentPos() const
    {
        return parent_pos_;
    }

    void setScore(score_t score)
    {
        score_ = score;
    }

    void setEstimatedScore(score_t score)
    {
        estimated_score_ = score;
    }

    void setParentPos(int parent_pos)
    {
        parent_pos_ = parent_pos;
    }

    bool isGoal(int n)
    {
        return vs_ == ((ONE_LLU << n) - 1);
    }

    std::string toString(int n)
    {
        std::ostringstream oss;
        for (int i = 0; i < n; ++i) {
            oss << (((vs_ >> i) & ONE_LLU) != 0 ? '1' : '0');
        }
        oss << ", " << score_ << ", " << estimated_score_ << ", " << parent_pos_;
        return oss.str();
    }
};

bool operator< (const OrderNode& node1, const OrderNode& node2)
{
    return node1.getEstimatedScore() < node2.getEstimatedScore();
}

bool operator> (const OrderNode& node1, const OrderNode& node2)
{
    return node1.getEstimatedScore() > node2.getEstimatedScore();
}
