/* Auto-generated by genmsg_cpp for file /home/rosdev/fuerte_workspace/sandbox/tum_simulator/cvg_sim_msgs/msg/ControllerState.msg */
#ifndef CVG_SIM_MSGS_MESSAGE_CONTROLLERSTATE_H
#define CVG_SIM_MSGS_MESSAGE_CONTROLLERSTATE_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{
template <class ContainerAllocator>
struct ControllerState_ {
  typedef ControllerState_<ContainerAllocator> Type;

  ControllerState_()
  : header()
  , source(0)
  , mode(0)
  , state(0)
  {
  }

  ControllerState_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , source(0)
  , mode(0)
  , state(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _source_type;
  uint8_t source;

  typedef uint8_t _mode_type;
  uint8_t mode;

  typedef uint8_t _state_type;
  uint8_t state;

  enum { MOTORS = 1 };
  enum { ATTITUDE = 2 };
  enum { VELOCITY = 4 };
  enum { POSITION = 8 };
  enum { HEADING = 16 };
  enum { HEIGHT = 32 };
  enum { MOTORS_RUNNING = 1 };
  enum { AIRBORNE = 2 };

  typedef boost::shared_ptr< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cvg_sim_msgs::ControllerState_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ControllerState
typedef  ::cvg_sim_msgs::ControllerState_<std::allocator<void> > ControllerState;

typedef boost::shared_ptr< ::cvg_sim_msgs::ControllerState> ControllerStatePtr;
typedef boost::shared_ptr< ::cvg_sim_msgs::ControllerState const> ControllerStateConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::cvg_sim_msgs::ControllerState_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace cvg_sim_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::ControllerState_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a0f668496c9bbf505c01f59674f2a0c2";
  }

  static const char* value(const  ::cvg_sim_msgs::ControllerState_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa0f668496c9bbf50ULL;
  static const uint64_t static_value2 = 0x5c01f59674f2a0c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cvg_sim_msgs/ControllerState";
  }

  static const char* value(const  ::cvg_sim_msgs::ControllerState_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
uint8 source\n\
\n\
uint8 mode\n\
uint8 MOTORS = 1\n\
uint8 ATTITUDE = 2\n\
uint8 VELOCITY = 4\n\
uint8 POSITION = 8\n\
uint8 HEADING = 16\n\
uint8 HEIGHT = 32\n\
\n\
uint8 state\n\
uint8 MOTORS_RUNNING = 1\n\
uint8 AIRBORNE = 2\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::cvg_sim_msgs::ControllerState_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::cvg_sim_msgs::ControllerState_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.source);
    stream.next(m.mode);
    stream.next(m.state);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ControllerState_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cvg_sim_msgs::ControllerState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::cvg_sim_msgs::ControllerState_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "source: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.source);
    s << indent << "mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};


} // namespace message_operations
} // namespace ros

#endif // CVG_SIM_MSGS_MESSAGE_CONTROLLERSTATE_H

