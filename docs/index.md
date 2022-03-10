# Arduino I2C Device Scanner <sup>V1.0</sup>

![GitHub release (latest by date)](https://img.shields.io/github/v/release/akkoyun/I2C_Scanner) ![arduino-library-badge](https://www.ardu-badge.com/badge/I2C_Scanner.svg?) ![Visits Badge](https://badges.pufler.dev/visits/akkoyun/I2C_Scanner) ![GitHub stars](https://img.shields.io/github/stars/akkoyun/I2C_Scanner?style=flat&logo=github) ![Updated Badge](https://badges.pufler.dev/updated/akkoyun/I2C_Scanner) ![PlatformIO Registry](https://badges.registry.platformio.org/packages/akkoyun/library/I2C_Scanner.svg) 
[![Check Arduino](https://github.com/akkoyun/I2C_Scanner/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/akkoyun/I2C_Scanner/actions/workflows/check-arduino.yml) [![Compile Examples](https://github.com/akkoyun/I2C_Scanner/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/akkoyun/I2C_Scanner/actions/workflows/compile-examples.yml) [![Spell Check](https://github.com/akkoyun/I2C_Scanner/actions/workflows/spell-check.yml/badge.svg)](https://github.com/akkoyun/I2C_Scanner/actions/workflows/spell-check.yml)

	Build - 01.00.08

---

This very simple sketch scans the I2C-bus for devices. If a device is found, it is reported to the Arduino serial monitor.

This sketch is the first step to get the I2C communication working.

The sketch shows the 7-bit addresses of the found devices as hexadecimal values. That value can be used for the "Wire.begin" function which uses the 7-bit address. Some datasheets use the 8-bit address and some example sketches use decimal addresses.

This scanner supports I2C multiplexer and can be used for channel selection.

![I2C Scanner](/Documents/ScreenShot.png)

---

[![Support me](https://img.shields.io/badge/Support-PATREON-GREEN.svg)](https://www.patreon.com/bePatron?u=62967889) ![Twitter Follow](https://img.shields.io/twitter/follow/gunceakkoyun?style=social) ![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCIguQGdaBT1GnnVMz5qAZ2Q?style=social) ![Repos Badge](https://badges.pufler.dev/repos/akkoyun) [![E-Mail](https://img.shields.io/badge/E_Mail-Mehmet_Gunce_Akkoyun-blue.svg)](mailto:akkoyun@me.com) ![GitHub](https://img.shields.io/github/license/akkoyun/Statistical) 