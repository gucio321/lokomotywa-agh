# Intro

TODO

# Setup

1. run `git clone https://github.com/espressif/esp-idf.git ~/esp/esp-idf`
2. in the repo folder run `git checkout v5.5.1` (this is the version used in this project for arduino compatibility reasons)
3. run `git submodule update --init --recursive`
4. run `./install.sh`

Then, whenever you want to use `idf.py` in your terminal, run `. ~/esp/esp-idf/export.sh` to set up the environment variables for the current terminal session.
Run `idf.py build` in projects directory to build the project.

# Reference

- Arudino IDE Board: `ESP32-WROOM-DA Module`
- esp32 WiFi + Bluetooth 4.2 - Platform z modułem ESP wroom 32 kompatybilne z esp32 devkit:
   * Kolorowany pinout: https://lastminuteengineers.com/esp32-pinout-reference/
   * Dokładny datasheet: https://www.mouser.com/datasheet/2/891/esp-wroom-32_datasheet_en-1223836.pdf
- Iduino l298 N: https://asset.conrad.com/media10/add/160267/c1/-/en/001525437ML01/upute-za-rukovanje-1525437-iduino-st-1112-pogon-za-motor-1-st.pdf
- L298N Dual H-Bridge Motor Driver: https://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf
- Pinout naszego pociągu znajduje się tutaj: [pinout pociągu](./doc/pociag_pinout.png)
- Laser sensor: ToF VL53L0X: https://www.st.com/resource/en/datasheet/vl53l0x.pdf
- ESP-IDF (our preffered ESP toolkit) documentation: https://docs.espressif.com/projects/esp-idf/en/release-v3.3/index.html

