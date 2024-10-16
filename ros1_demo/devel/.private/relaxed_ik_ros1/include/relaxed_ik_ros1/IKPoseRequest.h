// Generated by gencpp from file relaxed_ik_ros1/IKPoseRequest.msg
// DO NOT EDIT!


#ifndef RELAXED_IK_ROS1_MESSAGE_IKPOSEREQUEST_H
#define RELAXED_IK_ROS1_MESSAGE_IKPOSEREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>

namespace relaxed_ik_ros1
{
template <class ContainerAllocator>
struct IKPoseRequest_
{
  typedef IKPoseRequest_<ContainerAllocator> Type;

  IKPoseRequest_()
    : ee_poses()
    , tolerances()  {
    }
  IKPoseRequest_(const ContainerAllocator& _alloc)
    : ee_poses(_alloc)
    , tolerances(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Pose_<ContainerAllocator> >> _ee_poses_type;
  _ee_poses_type ee_poses;

   typedef std::vector< ::geometry_msgs::Twist_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Twist_<ContainerAllocator> >> _tolerances_type;
  _tolerances_type tolerances;





  typedef boost::shared_ptr< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> const> ConstPtr;

}; // struct IKPoseRequest_

typedef ::relaxed_ik_ros1::IKPoseRequest_<std::allocator<void> > IKPoseRequest;

typedef boost::shared_ptr< ::relaxed_ik_ros1::IKPoseRequest > IKPoseRequestPtr;
typedef boost::shared_ptr< ::relaxed_ik_ros1::IKPoseRequest const> IKPoseRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator1> & lhs, const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator2> & rhs)
{
  return lhs.ee_poses == rhs.ee_poses &&
    lhs.tolerances == rhs.tolerances;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator1> & lhs, const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace relaxed_ik_ros1

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2a4fc3a9f910b358f7b293c46553865c";
  }

  static const char* value(const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2a4fc3a9f910b358ULL;
  static const uint64_t static_value2 = 0xf7b293c46553865cULL;
};

template<class ContainerAllocator>
struct DataType< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "relaxed_ik_ros1/IKPoseRequest";
  }

  static const char* value(const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose[] ee_poses\n"
"geometry_msgs/Twist[] tolerances\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ee_poses);
      stream.next(m.tolerances);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IKPoseRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::relaxed_ik_ros1::IKPoseRequest_<ContainerAllocator>& v)
  {
    s << indent << "ee_poses[]" << std::endl;
    for (size_t i = 0; i < v.ee_poses.size(); ++i)
    {
      s << indent << "  ee_poses[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "    ", v.ee_poses[i]);
    }
    s << indent << "tolerances[]" << std::endl;
    for (size_t i = 0; i < v.tolerances.size(); ++i)
    {
      s << indent << "  tolerances[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "    ", v.tolerances[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RELAXED_IK_ROS1_MESSAGE_IKPOSEREQUEST_H
