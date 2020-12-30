
#include "fftable.h"
#include "parent_set.h"

class ParentScore {
private:
    std::vector<IntegerVector> y_maps_;
    std::vector<NumericVector> z_maps_;

    const int sign_;

public:
    // If is_flip is true, the sign of scores is flipped.
    ParentScore(bool is_flip = false) : sign_(is_flip ? -1 : 1) { }

    void importTable(List parent_set_list)
    {
        for (int i = 0; i < parent_set_list.size(); ++i) {
            DataFrame df = as<DataFrame>(parent_set_list[i]);

            y_maps_.push_back(df["y"]);
            z_maps_.push_back(df["z"]);
        }
    }

    void computeParentScore(NumericMatrix matrix, int tree_width = 0, int proc = 0,
                            double s=0, int n=0, int ss=0)
    {
        int ncol = matrix.ncol();

        IntegerVector kind_vec;
        IntegerVector bit_pos_vec;

        IntegerMatrix imat = normalize_table(matrix, kind_vec, bit_pos_vec);

        for (int i = 0; i < ncol; ++i) {
            DataFrame df = parent_i(imat, i, tree_width, proc, n, ss, kind_vec, bit_pos_vec);

            y_maps_.push_back(df["y"]);
            z_maps_.push_back(df["z"]);
        }
    }

    score_t getBestScore(int x, vset u_vset)
    {
        try {
            vset mask = (static_cast<vset>(1) << x) - 1;
            vset u = (u_vset & mask) | ((u_vset & ~mask) >> 1);
            score_t v = z_maps_.at(x).at(u);
            return sign_ * v;
        } catch (...) {
            stop("not found %d at z_maps[%d]", u_vset, x);
        }
    }

    vset getBestParent(int x, vset u_vset)
    {
        try {
            vset mask = (static_cast<vset>(1) << x) - 1;
            vset u = (u_vset & mask) | ((u_vset & ~mask) >> 1);
            vset vs = y_maps_.at(x).at(u);
            return (vs & mask) | ((vs & ~mask) << 1);
        } catch (...) {
            stop("not found %d at y_maps[%d]", u_vset, x);
        }
    }
};

