#ifndef assert_hh_INCLUDED
#define assert_hh_INCLUDED

#include "exception.hh"

namespace Kakoune
{

struct assert_failed : logic_error
{
    assert_failed(const std::string& message);
    std::string description() const;

private:
    std::string m_message;
};

}

#define STRINGIFY(X) #X
#define TOSTRING(X) STRINGIFY(X)

#ifdef assert
#undef assert
#endif

#define assert(condition) \
    if (not (condition)) \
        throw assert_failed("assert failed \"" #condition "\" at " __FILE__ ":" TOSTRING(__LINE__))

#endif // assert_hh_INCLUDED
