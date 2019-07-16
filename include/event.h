#ifndef EVENT_H
#define EVENT_H

#include "foliage.h"

#include "TTree.h"

#include <vector>

#define B_VAL_EVT_RECO(ACTION, ...)                                         \
    ACTION(int32_t,         hiBin,                      ## __VA_ARGS__)     \
    ACTION(float,           hiHF,                       ## __VA_ARGS__)     \

#define B_VAL_EVT_GEN(ACTION, ...)                                          \
    ACTION(float,           Ncoll,                      ## __VA_ARGS__)     \

class event {
  public:
    event(TTree* t, bool gen);

    event(event const&) = delete;
    event& operator=(event const&) = delete;
    ~event() = default;

    B_VAL_EVT_RECO(DECLVAL)
    B_VAL_EVT_GEN(DECLVAL)

  private:
    void read(TTree* t);

    bool _gen;
};

#endif  /* EVENT_H */
