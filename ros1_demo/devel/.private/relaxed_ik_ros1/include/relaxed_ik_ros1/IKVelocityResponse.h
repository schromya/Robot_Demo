// Generated by gencpp from file relaxed_ik_ros1/IKVelocityResponse.msg
// DO NOT EDIT!


#ifndef RELAXED_IK_ROS1_MESSAGE_IKVELOCITYRESPONSE_H
#define RELAXED_IK_ROS1_MESSAGE_IKVELOCITYRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace relaxed_ik_ros1
{
template <class ContainerAllocator>
struct IKVelocityResponse_
{
  typedef IKVelocityResponse_<ContainerAllocator> Type;

  IKVelocityResponse_()
    : joint_state()  {
    }
  IKVelocityResponse_(const ContainerAllocator& _alloc)
    : joint_state(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _joint_state_type;
  _joint_state_type joint_state;





  typedef boost::shared_ptr< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> const> ConstPtr;

}; // struct IKVelocityResponse_

typedef ::relaxed_ik_ros1::IKVelocityResponse_<std::allocator<void> > IKVelocityResponse;

typedef boost::shared_ptr< ::relaxed_ik_ros1::IKVelocityResponse > IKVelocityResponsePtr;
typedef boost::shared_ptr< ::relaxed_ik_ros1::IKVelocityResponse const> IKVelocityResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator1> & lhs, const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator2> & rhs)
{
  return lhs.joint_state == rhs.joint_state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator1> & lhs, const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace relaxed_ik_ros1

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b66d62d17824da488405b2423b7ccb24";
  }

  static const char* value(const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb66d62d17824da48ULL;
  static const uint64_t static_value2 = 0x8405b2423b7ccb24ULL;
};

template<class ContainerAllocator>
struct DataType< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "relaxed_ik_ros1/IKVelocityResponse";
  }

  static const char* value(const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[] joint_state\n"
;
  }

  static const char* value(const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joint_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IKVelocityResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::relaxed_ik_ros1::IKVelocityResponse_<ContainerAllocator>& v)
  {
    s << indent << "joint_state[]" << std::endl;
    for (size_t i = 0; i < v.joint_state.size(); ++i)
    {
      s << indent << "  joint_state[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.joint_state[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RELAXED_IK_ROS1_MESSAGE_IKVELOCITYRESPONSE_H
