#include "../include/triggers.h"

triggers::triggers(TTree* t, std::vector<std::string> const& paths)
        : accepts(new int32_t[paths.size()]),
          _count(static_cast<int64_t>(paths.size())),
          _paths(paths) {
    if (t != nullptr) { read(t); }
}

void triggers::read(TTree* t) {
    for (int64_t i = 0; i < static_cast<int64_t>(_paths.size()); ++i) {
        t->SetBranchStatus(_paths[i].data(), 1);
        t->SetBranchAddress(_paths[i].data(), accepts + i);
    }
}
