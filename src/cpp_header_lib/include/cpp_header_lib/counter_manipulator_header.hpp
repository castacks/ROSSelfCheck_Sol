
#ifndef __CPP_HEADER_LIB_COUNTER_MANIPULATOR_HEADER_HPP__
#define __CPP_HEADER_LIB_COUNTER_MANIPULATOR_HEADER_HPP__

namespace counter
{

template < typename T >
class CounterManipulatorHeader {
public:
    CounterManipulatorHeader() {};
    ~CounterManipulatorHeader() {};

    int get_increased_value(T& counter) const {
        return static_cast<int>( counter.count + 1 );
    }
};

} // namespace counter

#endif // __CPP_HEADER_LIB_COUNTER_MANIPULATOR_HEADER_HPP__
