// Auto-generated. Do not edit!

// (in-package relaxed_ik_ros1.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class EEPoseGoals {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.ee_poses = null;
      this.tolerances = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('ee_poses')) {
        this.ee_poses = initObj.ee_poses
      }
      else {
        this.ee_poses = [];
      }
      if (initObj.hasOwnProperty('tolerances')) {
        this.tolerances = initObj.tolerances
      }
      else {
        this.tolerances = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EEPoseGoals
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [ee_poses]
    // Serialize the length for message field [ee_poses]
    bufferOffset = _serializer.uint32(obj.ee_poses.length, buffer, bufferOffset);
    obj.ee_poses.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Pose.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [tolerances]
    // Serialize the length for message field [tolerances]
    bufferOffset = _serializer.uint32(obj.tolerances.length, buffer, bufferOffset);
    obj.tolerances.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Twist.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EEPoseGoals
    let len;
    let data = new EEPoseGoals(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [ee_poses]
    // Deserialize array length for message field [ee_poses]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.ee_poses = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ee_poses[i] = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [tolerances]
    // Deserialize array length for message field [tolerances]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.tolerances = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.tolerances[i] = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 56 * object.ee_poses.length;
    length += 48 * object.tolerances.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'relaxed_ik_ros1/EEPoseGoals';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '53bcbdf6cd22e9cc87da1de741a651ce';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    geometry_msgs/Pose[] ee_poses
    geometry_msgs/Twist[] tolerances
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EEPoseGoals(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.ee_poses !== undefined) {
      resolved.ee_poses = new Array(msg.ee_poses.length);
      for (let i = 0; i < resolved.ee_poses.length; ++i) {
        resolved.ee_poses[i] = geometry_msgs.msg.Pose.Resolve(msg.ee_poses[i]);
      }
    }
    else {
      resolved.ee_poses = []
    }

    if (msg.tolerances !== undefined) {
      resolved.tolerances = new Array(msg.tolerances.length);
      for (let i = 0; i < resolved.tolerances.length; ++i) {
        resolved.tolerances[i] = geometry_msgs.msg.Twist.Resolve(msg.tolerances[i]);
      }
    }
    else {
      resolved.tolerances = []
    }

    return resolved;
    }
};

module.exports = EEPoseGoals;
