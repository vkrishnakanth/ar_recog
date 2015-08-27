/* Auto-generated by genmsg_cpp for file /home/rosdev/fuerte_workspace/sandbox/tum_simulator/cvg_sim_msgs/msg/Compass.msg */
#ifndef CVG_SIM_MSGS_MESSAGE_COMPASS_H
#define CVG_SIM_MSGS_MESSAGE_COMPASS_H
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
struct Compass_ {
  typedef Compass_<ContainerAllocator> Type;

  Compass_()
  : header()
  , magnetic_heading(0.0)
  , declination(0.0)
  {
  }

  Compass_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , magnetic_heading(0.0)
  , declination(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef float _magnetic_heading_type;
  float magnetic_heading;

  typedef float _declination_type;
  float declination;


  typedef boost::shared_ptr< ::cvg_sim_msgs::Compass_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cvg_sim_msgs::Compass_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Compass
typedef  ::cvg_sim_msgs::Compass_<std::allocator<void> > Compass;

typedef boost::shared_ptr< ::cvg_sim_msgs::Compass> CompassPtr;
typedef boost::shared_ptr< ::cvg_sim_msgs::Compass const> CompassConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::cvg_sim_msgs::Compass_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::cvg_sim_msgs::Compass_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace cvg_sim_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::Compass_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::cvg_sim_msgs::Compass_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::cvg_sim_msgs::Compass_<ContainerAllocator> > {
  static const char* value() 
  {
    return "69b5db73a2f794a5a815baf6b84a4be5";
  }

  static const char* value(const  ::cvg_sim_msgs::Compass_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x69b5db73a2f794a5ULL;
  static const uint64_t static_value2 = 0xa815baf6b84a4be5ULL;
};

template<class ContainerAllocator>
struct DataType< ::cvg_sim_msgs::Compass_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cvg_sim_msgs/Compass";
  }

  static const char* value(const  ::cvg_sim_msgs::Compass_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::cvg_sim_msgs::Compass_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
float32 magnetic_heading\n\
float32 declination\n\
\n\
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

  static const char* value(const  ::cvg_sim_msgs::Compass_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::cvg_sim_msgs::Compass_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::cvg_sim_msgs::Compass_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::cvg_sim_msgs::Compass_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.magnetic_heading);
    stream.next(m.declination);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Compass_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cvg_sim_msgs::Compass_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::cvg_sim_msgs::Compass_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "magnetic_heading: ";
    Printer<float>::stream(s, indent + "  ", v.magnetic_heading);
    s << indent << "declination: ";
    Printer<float>::stream(s, indent + "  ", v.declination);
  }
};


} // namespace message_operations
} // namespace ros

#endif // CVG_SIM_MSGS_MESSAGE_COMPASS_H

