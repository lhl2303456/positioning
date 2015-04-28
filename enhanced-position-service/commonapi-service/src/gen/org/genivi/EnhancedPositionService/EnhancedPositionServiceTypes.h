/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.6.v20140519.
* Used org.franca.core 0.8.11.201401091023.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef ORG_GENIVI_ENHANCEDPOSITIONSERVICE_Enhanced_Position_Service_Types_H_
#define ORG_GENIVI_ENHANCEDPOSITIONSERVICE_Enhanced_Position_Service_Types_H_



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.h>
#include <CommonAPI/OutputStream.h>
#include <CommonAPI/SerializableStruct.h>
#include <CommonAPI/SerializableVariant.h>
#include <CommonAPI/types.h>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace org {
namespace genivi {
namespace EnhancedPositionService {

namespace EnhancedPositionServiceTypes {
    typedef uint64_t Timestamp;
    /**
     * bitmask obtained as a result of an OR operation on enum values of type
     *  PositionInfoKey
     */
    /**
     * bitmask obtained as a result of an OR operation on enum values of type
     *  PositionInfoKey
     */
    typedef uint64_t Bitmask;
    /**
     * version
     */
    /**
     * version
     */
    struct Version: CommonAPI::SerializableStruct {
        /**
         * when the major changes, then backward compatibility with previous releases is
         *  not granted
         */
         uint16_t maj;
        /**
         * when the minor changes, then backward compatibility with previous releases is
         *  granted, but something changed in the implementation of the API (e.g. new
         *  methods may have been added)
         */
         uint16_t min;
        /**
         * when the micro changes, then backward compatibility with previous releases is
         *  granted (bug fixes or documentation modifications)
         */
         uint16_t mic;
        /**
         * release date (e.g. 21-06-2011)
         */
         std::string date;
    
        Version() = default;
        Version(const uint16_t& maj, const uint16_t& min, const uint16_t& mic, const std::string& date);
    
    
        virtual void readFromInputStream(CommonAPI::InputStream& inputStream);
        virtual void writeToOutputStream(CommonAPI::OutputStream& outputStream) const;
    
        static inline void writeToTypeOutputStream(CommonAPI::TypeOutputStream& typeOutputStream) {
            typeOutputStream.writeUInt16Type();
            typeOutputStream.writeUInt16Type();
            typeOutputStream.writeUInt16Type();
            typeOutputStream.writeStringType();
        }
    };
    /**
     * Value = generic value (mapped to a dbus variant ('v') data type)
     */
    /**
     * Value = generic value (mapped to a dbus variant ('v') data type)
     */
    typedef CommonAPI::Variant<uint64_t, double, float, std::string>  Value;
    enum class PositionInfoKey: int32_t {
        LATITUDE = 0x1,
        LONGITUDE = 0x2,
        ALTITUDE = 0x4,
        HEADING = 0x8,
        SPEED = 0x10,
        CLIMB = 0x20,
        ROLL_RATE = 0x40,
        PITCH_RATE = 0x80,
        YAW_RATE = 0x100,
        PDOP = 0x200,
        HDOP = 0x400,
        VDOP = 0x800,
        USED_SATELLITES = 0x1000,
        TRACKED_SATELLITES = 0x2000,
        VISIBLE_SATELLITES = 0x4000,
        SIGMA_HPOSITION = 0x8000,
        SIGMA_ALTITUDE = 0x10000,
        SIGMA_HEADING = 0x20000,
        SIGMA_SPEED = 0x40000,
        SIGMA_CLIMB = 0x80000,
        GNSS_FIX_STATUS = 0x100000,
        DR_STATUS = 0x200000,
        RELIABILTY_INDEX = 0x400000
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct PositionInfoKeyComparator;
    /**
     * PositionInfo = array of tuples (key,value)
                key = enumeration
     *  PositionInfoKey
                key = LATITUDE, value = value of type 'Double',
     *  that expresses the latitude of the current position. Range [-90:+90]. Example:
     *  48.053250
                key = LONGITUDE, value = value of type 'Double', that
     *  expresses the longitude of the current position. Range [-180:+180]. Example:
     *  8.324500
                key = ALTITUDE, value = value of type 'Double', that
     *  expresses the altitude above the sea level of the current position in meters
    
     *             key = HEADING, value = value of type 'Double', that expresses the
     *  course angle in degree. Range [0:360]. 0 = north, 90 = east, 180 = south, 270
     *  = west
                key = SPEED, value = value of type 'Double', that
     *  expresses speed measured in m/s. A negative value indicates that the vehicle
     *  is moving backwards
                key = CLIMB, value = value of type 'Double',
     *  that expresses the road gradient in degrees
                key = ROLL_RATE,
     *  value = value of type 'Double', rotation rate around the X-axis in degrees/s.
     *  Range [-100:+100]
                key = PITCH_RATE, value = value of type
     *  'Double', rotation rate around the Y-axis in degrees/s. Range [-100:+100]
       
     *          key = YAW_RATE, value = value of type 'Double', rotation rate around
     *  the Z-axis in degrees/s. Range [-100:+100]
                key = PDOP, value =
     *  value of type 'Double', that represents the positional (3D) dilution of
     *  precision
                key = HDOP, value = value of type 'Double', that
     *  represents the horizontal (2D) dilution of precision
                key = VDOP,
     *  value = value of type 'Double', that represents vertical (altitude) dilution
     *  of precision
                key = USED_SATELLITES, value = value of type
     *  'UInt8', that represents the number of used satellites
                key =
     *  TRACKED_SATELLITES, value = value of type 'UInt8', that represents the number
     *  of tracked satellites 
                key = VISIBLE_SATELLITES, value = value of
     *  type 'UInt8', that represents the number of visible satellites
               
     *  key = SIGMA_HPOSITION, value = value of type 'Double', that represents the
     *  standard deviation for the horizontal position in m
                key =
     *  SIGMA_ALTITUDE, value = value of type 'Double', that represents the standard
     *  deviation for altitude in m
                key = SIGMA_HEADING, value = value of
     *  type 'Double', that represents the standard deviation for altitude in
     *  degrees
                key = SIGMA_SPEED, value = value of type 'Double', that
     *  represents the standard error estimate of the speed in m/s</line>
               
     *  key = SIGMA_CLIMB, value = value of type 'Double', that represents the
     *  standard error estimate of the climb in degrees</line>
                key =
     *  GNSS_FIX_STATUS, value = value of type 'UInt16', that represents an
     *  enum(NO_FIX(0x01),TIME_FIX(0x01),2D_FIX(0x02),3D_FIX(0x03), ... )
               
     *  key = DR_STATUS, value = value of type 'Boolean', where TRUE means that a
     *  dead-reckoning algorithm has been used to calculate the current position
     */
    /**
     * PositionInfo = array of tuples (key,value)
                key = enumeration
     *  PositionInfoKey
                key = LATITUDE, value = value of type 'Double',
     *  that expresses the latitude of the current position. Range [-90:+90]. Example:
     *  48.053250
                key = LONGITUDE, value = value of type 'Double', that
     *  expresses the longitude of the current position. Range [-180:+180]. Example:
     *  8.324500
                key = ALTITUDE, value = value of type 'Double', that
     *  expresses the altitude above the sea level of the current position in meters
    
     *             key = HEADING, value = value of type 'Double', that expresses the
     *  course angle in degree. Range [0:360]. 0 = north, 90 = east, 180 = south, 270
     *  = west
                key = SPEED, value = value of type 'Double', that
     *  expresses speed measured in m/s. A negative value indicates that the vehicle
     *  is moving backwards
                key = CLIMB, value = value of type 'Double',
     *  that expresses the road gradient in degrees
                key = ROLL_RATE,
     *  value = value of type 'Double', rotation rate around the X-axis in degrees/s.
     *  Range [-100:+100]
                key = PITCH_RATE, value = value of type
     *  'Double', rotation rate around the Y-axis in degrees/s. Range [-100:+100]
       
     *          key = YAW_RATE, value = value of type 'Double', rotation rate around
     *  the Z-axis in degrees/s. Range [-100:+100]
                key = PDOP, value =
     *  value of type 'Double', that represents the positional (3D) dilution of
     *  precision
                key = HDOP, value = value of type 'Double', that
     *  represents the horizontal (2D) dilution of precision
                key = VDOP,
     *  value = value of type 'Double', that represents vertical (altitude) dilution
     *  of precision
                key = USED_SATELLITES, value = value of type
     *  'UInt8', that represents the number of used satellites
                key =
     *  TRACKED_SATELLITES, value = value of type 'UInt8', that represents the number
     *  of tracked satellites 
                key = VISIBLE_SATELLITES, value = value of
     *  type 'UInt8', that represents the number of visible satellites
               
     *  key = SIGMA_HPOSITION, value = value of type 'Double', that represents the
     *  standard deviation for the horizontal position in m
                key =
     *  SIGMA_ALTITUDE, value = value of type 'Double', that represents the standard
     *  deviation for altitude in m
                key = SIGMA_HEADING, value = value of
     *  type 'Double', that represents the standard deviation for altitude in
     *  degrees
                key = SIGMA_SPEED, value = value of type 'Double', that
     *  represents the standard error estimate of the speed in m/s</line>
               
     *  key = SIGMA_CLIMB, value = value of type 'Double', that represents the
     *  standard error estimate of the climb in degrees</line>
                key =
     *  GNSS_FIX_STATUS, value = value of type 'UInt16', that represents an
     *  enum(NO_FIX(0x01),TIME_FIX(0x01),2D_FIX(0x02),3D_FIX(0x03), ... )
               
     *  key = DR_STATUS, value = value of type 'Boolean', where TRUE means that a
     *  dead-reckoning algorithm has been used to calculate the current position
     */
    typedef std::unordered_map<PositionInfoKey, Value, CommonAPI::EnumHasher<PositionInfoKey>> PositionInfo;
    enum class SatelliteSystem: int32_t {
        GPS = 0x1,
        GLONASS = 0x2,
        GALILEO = 0x3,
        COMPASS = 0x4
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct SatelliteSystemComparator;
    /**
     * SatelliteInfo = array(struct(system,satelliteId,azimuth,elevation,snr,inUse))
    
     *             system = enum(GPS, GLONASS, GALILEO, COMPASS, ... )
               
     *  satelliteId = satellite ID. This ID is unique within one satellite system
       
     *          azimuth = satellite azimuth in degrees. Value range 0..359
              
     *   elevation = satellite elevation in degrees. Value range 0..90
               
     *  snr = SNR (C/No) in dBHz. Range 0 to 99, null when not tracking
               
     *  inUse = flag indicating if the satellite is used for the fix (inUse=true)
     */
    /**
     * SatelliteInfo = array(struct(system,satelliteId,azimuth,elevation,snr,inUse))
    
     *             system = enum(GPS, GLONASS, GALILEO, COMPASS, ... )
               
     *  satelliteId = satellite ID. This ID is unique within one satellite system
       
     *          azimuth = satellite azimuth in degrees. Value range 0..359
              
     *   elevation = satellite elevation in degrees. Value range 0..90
               
     *  snr = SNR (C/No) in dBHz. Range 0 to 99, null when not tracking
               
     *  inUse = flag indicating if the satellite is used for the fix (inUse=true)
     */
    struct SatelliteInfo: CommonAPI::SerializableStruct {
         SatelliteSystem system;
         uint32_t satellitId;
         uint32_t azimuth;
         uint32_t elevation;
         uint32_t snr;
         bool inUse;
    
        SatelliteInfo() = default;
        SatelliteInfo(const SatelliteSystem& system, const uint32_t& satellitId, const uint32_t& azimuth, const uint32_t& elevation, const uint32_t& snr, const bool& inUse);
    
    
        virtual void readFromInputStream(CommonAPI::InputStream& inputStream);
        virtual void writeToOutputStream(CommonAPI::OutputStream& outputStream) const;
    
        static inline void writeToTypeOutputStream(CommonAPI::TypeOutputStream& typeOutputStream) {
            typeOutputStream.writeInt32Type();
            typeOutputStream.writeUInt32Type();
            typeOutputStream.writeUInt32Type();
            typeOutputStream.writeUInt32Type();
            typeOutputStream.writeUInt32Type();
            typeOutputStream.writeBoolType();
        }
    };
    enum class TimeInfoKey: int32_t {
        YEAR = 0x1000000,
        MONTH = 0x2000000,
        DAY = 0x4000000,
        HOUR = 0x8000000,
        MINUTE = 0x10000000,
        SECOND = 0x20000000,
        MS = 0x40000000
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct TimeInfoKeyComparator;
    /**
     * TimeInfo = array of tuples (key,value)
              key = enumeration
     *  TimeInfoKey
              key = YEAR, value = value of type 'UInt16', 4 digits
     *  number that indicates the year. Example: 2012
              key = MONTH, value =
     *  value of type 'UInt8', 2 digits number that indicates the month. Example: 03
     *  means March
              key = DAY, value = value of type 'UInt8', 2 digits
     *  number that indicates the day. Range [0:31]. Example: 07
              key =
     *  HOUR, value = value of type 'UInt8', 2 digits number that indicates the hour.
     *  Range [0:23].  Example: 01
              key = MINUTE, value = value of type
     *  'UInt8', 2 digits number that represents the minutes. Range [0:59]. Example:
     *  01
              key = SECOND, value = value of type 'UInt8', 2 digits number
     *  that represents the seconds. Range [0:59]. Example: 01
              key = MS,
     *  value = value of type 'UInt16', 3 digits number that represents the
     *  milliseconds. Range [0:999]. Example: 007
     */
    /**
     * TimeInfo = array of tuples (key,value)
              key = enumeration
     *  TimeInfoKey
              key = YEAR, value = value of type 'UInt16', 4 digits
     *  number that indicates the year. Example: 2012
              key = MONTH, value =
     *  value of type 'UInt8', 2 digits number that indicates the month. Example: 03
     *  means March
              key = DAY, value = value of type 'UInt8', 2 digits
     *  number that indicates the day. Range [0:31]. Example: 07
              key =
     *  HOUR, value = value of type 'UInt8', 2 digits number that indicates the hour.
     *  Range [0:23].  Example: 01
              key = MINUTE, value = value of type
     *  'UInt8', 2 digits number that represents the minutes. Range [0:59]. Example:
     *  01
              key = SECOND, value = value of type 'UInt8', 2 digits number
     *  that represents the seconds. Range [0:59]. Example: 01
              key = MS,
     *  value = value of type 'UInt16', 3 digits number that represents the
     *  milliseconds. Range [0:999]. Example: 007
     */
    typedef std::unordered_map<TimeInfoKey, Value, CommonAPI::EnumHasher<TimeInfoKey>> TimeInfo;
    enum class PositionFeedbackKey: int32_t {
        LATITUDE = 0x1,
        LONGITUDE = 0x2,
        ALTITUDE = 0x4,
        HEADING = 0x8,
        SPEED = 0x10,
        CLIMB = 0x20,
        RELIABILTY_INDEX = 0x400000
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct PositionFeedbackKeyComparator;
    enum class PositionFeedbackType: int32_t {
        MAP_MATCHED_FEEDBACK = 0x1,
        TEST_FEEDBACK = 0x2
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct PositionFeedbackTypeComparator;

bool operator==(const Version& lhs, const Version& rhs);
inline bool operator!=(const Version& lhs, const Version& rhs) {
    return !(lhs == rhs);
}
inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, PositionInfoKey& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const PositionInfoKey& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct PositionInfoKeyComparator {
    inline bool operator()(const PositionInfoKey& lhs, const PositionInfoKey& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, SatelliteSystem& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const SatelliteSystem& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct SatelliteSystemComparator {
    inline bool operator()(const SatelliteSystem& lhs, const SatelliteSystem& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

bool operator==(const SatelliteInfo& lhs, const SatelliteInfo& rhs);
inline bool operator!=(const SatelliteInfo& lhs, const SatelliteInfo& rhs) {
    return !(lhs == rhs);
}
inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, TimeInfoKey& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const TimeInfoKey& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct TimeInfoKeyComparator {
    inline bool operator()(const TimeInfoKey& lhs, const TimeInfoKey& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, PositionFeedbackKey& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const PositionFeedbackKey& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct PositionFeedbackKeyComparator {
    inline bool operator()(const PositionFeedbackKey& lhs, const PositionFeedbackKey& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, PositionFeedbackType& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const PositionFeedbackType& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct PositionFeedbackTypeComparator {
    inline bool operator()(const PositionFeedbackType& lhs, const PositionFeedbackType& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};



static inline const char* getTypeCollectionName() {
    static const char* typeCollectionName = "org.genivi.EnhancedPositionService.EnhancedPositionServiceTypes";
    return typeCollectionName;
}


} // namespace EnhancedPositionServiceTypes

} // namespace EnhancedPositionService
} // namespace genivi
} // namespace org

namespace CommonAPI {

    template<>
    struct BasicTypeWriter<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey> {
        inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
            typeStream.writeInt32EnumType();
        }
    };
    
    template<>
    struct InputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey> {
        static void beginReadVector(InputStream& inputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey>& vectorValue) {
            inputStream.beginReadInt32EnumVector();
        }
    };
    
    template <>
    struct OutputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey> {
        static void beginWriteVector(OutputStream& outputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey>& vectorValue) {
            outputStream.beginWriteInt32EnumVector(vectorValue.size());
        }
    };
    template<>
    struct BasicTypeWriter<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem> {
        inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
            typeStream.writeInt32EnumType();
        }
    };
    
    template<>
    struct InputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem> {
        static void beginReadVector(InputStream& inputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem>& vectorValue) {
            inputStream.beginReadInt32EnumVector();
        }
    };
    
    template <>
    struct OutputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem> {
        static void beginWriteVector(OutputStream& outputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem>& vectorValue) {
            outputStream.beginWriteInt32EnumVector(vectorValue.size());
        }
    };
    template<>
    struct BasicTypeWriter<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey> {
        inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
            typeStream.writeInt32EnumType();
        }
    };
    
    template<>
    struct InputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey> {
        static void beginReadVector(InputStream& inputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey>& vectorValue) {
            inputStream.beginReadInt32EnumVector();
        }
    };
    
    template <>
    struct OutputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey> {
        static void beginWriteVector(OutputStream& outputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey>& vectorValue) {
            outputStream.beginWriteInt32EnumVector(vectorValue.size());
        }
    };
    template<>
    struct BasicTypeWriter<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey> {
        inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
            typeStream.writeInt32EnumType();
        }
    };
    
    template<>
    struct InputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey> {
        static void beginReadVector(InputStream& inputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey>& vectorValue) {
            inputStream.beginReadInt32EnumVector();
        }
    };
    
    template <>
    struct OutputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey> {
        static void beginWriteVector(OutputStream& outputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey>& vectorValue) {
            outputStream.beginWriteInt32EnumVector(vectorValue.size());
        }
    };
    template<>
    struct BasicTypeWriter<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType> {
        inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
            typeStream.writeInt32EnumType();
        }
    };
    
    template<>
    struct InputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType> {
        static void beginReadVector(InputStream& inputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType>& vectorValue) {
            inputStream.beginReadInt32EnumVector();
        }
    };
    
    template <>
    struct OutputStreamVectorHelper<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType> {
        static void beginWriteVector(OutputStream& outputStream, const std::vector<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType>& vectorValue) {
            outputStream.beginWriteInt32EnumVector(vectorValue.size());
        }
    };

}


namespace std {
    //Hash for PositionInfoKey
    template<>
    struct hash<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey> {
        inline size_t operator()(const org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionInfoKey& positionInfoKey) const {
            return static_cast<int32_t>(positionInfoKey);
        }
    };
    //Hash for SatelliteSystem
    template<>
    struct hash<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem> {
        inline size_t operator()(const org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::SatelliteSystem& satelliteSystem) const {
            return static_cast<int32_t>(satelliteSystem);
        }
    };
    //Hash for TimeInfoKey
    template<>
    struct hash<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey> {
        inline size_t operator()(const org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::TimeInfoKey& timeInfoKey) const {
            return static_cast<int32_t>(timeInfoKey);
        }
    };
    //Hash for PositionFeedbackKey
    template<>
    struct hash<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey> {
        inline size_t operator()(const org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackKey& positionFeedbackKey) const {
            return static_cast<int32_t>(positionFeedbackKey);
        }
    };
    //Hash for PositionFeedbackType
    template<>
    struct hash<org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType> {
        inline size_t operator()(const org::genivi::EnhancedPositionService::EnhancedPositionServiceTypes::PositionFeedbackType& positionFeedbackType) const {
            return static_cast<int32_t>(positionFeedbackType);
        }
    };
}

#endif // ORG_GENIVI_ENHANCEDPOSITIONSERVICE_Enhanced_Position_Service_Types_H_
