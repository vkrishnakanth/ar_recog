/* Auto-generated by genmsg_cpp for file /home/rosdev/fuerte_workspace/sandbox/tum_simulator/cvg_sim_msgs/msg/PositionXYCommand.msg */
#ifndef CVG_SIM_MSGS_MESSAGE_POSITIONXYCOMMAND_H
#define CVG_SIM_MSGS_MESSAGE_POSITIONXYCOMMAND_H
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
struct PositionXYCommand_ {
  typedef PositionXYCommand_<ContainerAllocator> Type;

  PositionXYCommand_()
  : header()
  , x(0.0)
  , y(0.0)
  {
  }

  PositionXYCommand_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , x(0.0)
  , y(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef float _x_type;
  float x;

  typedef float _y_type;
  float y;


  typedef boost::shared_ptr< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct PositionXYCommand
typedef  ::cvg_sim_msgs::PositionXYCommand_<std::allocator<void> > PositionXYCommand;

typedef boost::shared_ptr< ::cvg_sim_msgs::PositionXYCommand> PositionXYCommandPtr;
typedef boost::shared_ptr< ::cvg_sim_msgs::PositionXYCommand const> PositionXYCommandConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace cvg_sim_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "7b4d52af2aa98221d9bb260976d6a201";
  }

  static const char* value(const  ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x7b4d52af2aa98221ULL;
  static const uint64_t static_value2 = 0xd9bb260976d6a201ULL;
};

template<class ContainerAllocator>
struct DataType< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cvg_sim_msgs/PositionXYCommand";
  }

  static const char* value(const  ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
float32 x\n\
float32 y\n\
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

  static const char* value(const  ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.x);
    stream.next(m.y);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct PositionXYCommand_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::cvg_sim_msgs::PositionXYCommand_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
  }
};


} // namespace message_operations
} // namespace ros

#endif // CVG_SIM_MSGS_MESSAGE_POSITIONXYCOMMAND_H

