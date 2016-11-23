// Generated by gencpp from file serial_node/ResetAngleResponse.msg
// DO NOT EDIT!


#ifndef SERIAL_NODE_MESSAGE_RESETANGLERESPONSE_H
#define SERIAL_NODE_MESSAGE_RESETANGLERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace serial_node
{
template <class ContainerAllocator>
struct ResetAngleResponse_
{
  typedef ResetAngleResponse_<ContainerAllocator> Type;

  ResetAngleResponse_()
    {
    }
  ResetAngleResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }






  typedef boost::shared_ptr< ::serial_node::ResetAngleResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::serial_node::ResetAngleResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ResetAngleResponse_

typedef ::serial_node::ResetAngleResponse_<std::allocator<void> > ResetAngleResponse;

typedef boost::shared_ptr< ::serial_node::ResetAngleResponse > ResetAngleResponsePtr;
typedef boost::shared_ptr< ::serial_node::ResetAngleResponse const> ResetAngleResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::serial_node::ResetAngleResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::serial_node::ResetAngleResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace serial_node

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'serial_node': ['/home/tony/catkin_ws/src/serial_node/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::serial_node::ResetAngleResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::ResetAngleResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::ResetAngleResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::serial_node::ResetAngleResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "serial_node/ResetAngleResponse";
  }

  static const char* value(const ::serial_node::ResetAngleResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::serial_node::ResetAngleResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ResetAngleResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::serial_node::ResetAngleResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::serial_node::ResetAngleResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // SERIAL_NODE_MESSAGE_RESETANGLERESPONSE_H
