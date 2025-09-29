idf_component_register(SRCS "./src/Adafruit_VL53L0X.cpp" "./src/core/src/vl53l0x_api.cpp" "./src/core/src/vl53l0x_api_calibration.cpp" "./src/core/src/vl53l0x_api_core.cpp" "./src/core/src/vl53l0x_api_ranging.cpp" "./src/core/src/vl53l0x_api_strings.cpp" "./src/platform/src/vl53l0x_i2c_comms.cpp" "./src/platform/src/vl53l0x_platform.cpp"
                      INCLUDE_DIRS "./src/"
                      REQUIRES arduino-esp32
                      )
