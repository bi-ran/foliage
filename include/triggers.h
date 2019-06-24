#ifndef TRIGGERS_H
#define TRIGGERS_H

#include "foliage.h"

#include "TTree.h"

#include <string>
#include <vector>

#define B_ARR_TRG(ACTION, ...)                                              \
    ACTION(int32_t,         accepts,                    ## __VA_ARGS__)     \

class triggers {
  public:
    triggers(TTree* t, std::vector<std::string> const& paths);

    triggers(triggers const&) = delete;
    triggers& operator=(triggers const&) = delete;
    ~triggers() = default;

    int64_t size() const { return _count; }

    B_ARR_TRG(DECLPTR)

  private:
    void read(TTree* t);

    int64_t _count;
    std::vector<std::string> _paths;
};

#endif  /* TRIGGERS_H */
