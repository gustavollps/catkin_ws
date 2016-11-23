// Generated by gencpp from file serial_node/In_out.msg
// DO NOT EDIT!


#ifndef SERIAL_NODE_MESSAGE_IN_OUT_H
#define SERIAL_NODE_MESSAGE_IN_OUT_H


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
struct In_out_
{
  typedef In_out_<ContainerAllocator> Type;

  In_out_()
    : input(0.0)
    , output(0.0)  {
    }
  In_out_(const ContainerAllocator& _alloc)
    : input(0.0)
    , output(0.0)  {
  (void)_alloc;
    }



   typedef float _input_type;
  _input_type input;

   typedef float _output_type;
  _output_type output;




  typedef boost::shared_ptr< ::serial_node::In_out_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::serial_node::In_out_<ContainerAllocator> const> ConstPtr;

}; // struct In_out_

typedef ::serial_node::In_out_<std::allocator<void> > In_out;

typedef boost::shared_ptr< ::serial_node::In_out > In_outPtr;
typedef boost::shared_ptr< ::serial_node::In_out const> In_outConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::serial_node::In_out_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::serial_node::In_out_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::serial_node::In_out_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::serial_node::In_out_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::In_out_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::In_out_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::In_out_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::In_out_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::serial_node::In_out_<ContainerAllocator> >
{
  static const char* value()
  {
    return "46f3fd29c4f8033525b878269a5aed96";
  }

  static const char* value(const ::serial_node::In_out_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x46f3fd29c4f80335ULL;
  static const uint64_t static_value2 = 0x25b878269a5aed96ULL;
};

template<class ContainerAllocator>
struct DataType< ::serial_node::In_out_<ContainerAllocator> >
{
  static const char* value()
  {
    return "serial_node/In_out";
  }

  static const char* value(const ::serial_node::In_out_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::serial_node::In_out_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 input\n\
float32 output\n\
";
  }

  static const char* value(const ::serial_node::In_out_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::serial_node::In_out_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.input);
      stream.next(m.output);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct In_out_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::serial_node::In_out_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::serial_node::In_out_<ContainerAllocator>& v)
  {
    s << indent << "input: ";
    Printer<float>::stream(s, indent + "  ", v.input);
    s << indent << "output: ";
    Printer<float>::stream(s, indent + "  ", v.output);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SERIAL_NODE_MESSAGE_IN_OUT_H
