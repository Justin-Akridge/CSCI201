#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include "StereoReceiver.h"

StereoReceiver::StereoReceiver() {
  manufacturer = "";
  model = "";
  serial_number = "";
  wattage = 0;
  number_of_channels = 0;
  band = "";
  frequency = 0.0;
  volume = 0;
  power = false;
  lights = "";
  bass_booster = 0;
}

StereoReceiver::StereoReceiver(std::string setManufacturer, std::string setModel, 
                               std::string setSerial_number, int setWattage, 
                               int setNumber_of_channels) {
  manufacturer = setManufacturer;
  model = setModel;
  serial_number = setSerial_number;
  wattage = setWattage;
  number_of_channels = setNumber_of_channels;
  band = "AM";
  frequency = 0.0;
  volume = 0;
  power = false;
  lights = "off";
  bass_booster = 0;
}

void StereoReceiver::print_controls() {
  std::cout << '\n' << "----------- Controls ----------\n";
  std::cout << "Band: " << band << '\n';
  std::cout << "Frequency: " << frequency << '\n';
  std::cout << "Volume: " << volume << '\n';
  std::cout << "Power: " << power << '\n';
  std::cout << "Lights: " << lights << '\n';
  std::cout << "Bass booster: " << bass_booster << "\n\n";
}

void StereoReceiver::print() {
  std::cout << '\n' << "----------- All Settings -----------\n";
  std::cout << "Manufacturer: " << manufacturer << '\n';
  std::cout << "Model: " << model << '\n';
  std::cout << "Serial Number: " << serial_number << '\n';
  std::cout << "Wattage: " << wattage << '\n';
  std::cout << "Number of channels: " << number_of_channels << '\n';
  std::cout << "Band: " << band << '\n';
  std::cout << "Frequency: " << frequency << '\n';
  std::cout << "Volume: " << volume << '\n';
  std::cout << "Power: " << power << '\n';
  std::cout << "Lights: " << lights << '\n';
  std::cout << "Bass booster: " << bass_booster << "\n\n";
}

std::string StereoReceiver::getManufacturer() const {
  return manufacturer;
}

std::string StereoReceiver::getModel() const {
  return model;
}

std::string StereoReceiver::getSerial_number() const {
  return serial_number;
}

int StereoReceiver::getWattage() const {
  return wattage;
}

int StereoReceiver::getNumber_of_channels() const {
  return number_of_channels;
}

std::string StereoReceiver::getBand() const {
  return band;
}

double StereoReceiver::getFrequency() const {
  return frequency;
}

int StereoReceiver::getVolume() const {
  return volume;
}

bool StereoReceiver::getPower() const {
  return power;
}

std::string StereoReceiver::getLights() const {
  return lights;
}

int StereoReceiver::getBass_booster() const {
  return bass_booster;
}

bool is_valid_string(std::string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!isspace(s[i]) || !isalpha(s[i] || s[i] == '-')) {
      return false;
    }
  }
  return true;
}

void StereoReceiver::setManufacturer(std::string& setManufacturer) {
  do {
    try {
      if (is_valid_string(setManufacturer))
        manufacturer = setManufacturer;
      else
        throw std::runtime_error("manufacturer is not a valid input");
    } catch (std::runtime_error& e) {
      std::cout << "Runtime error: " << e.what() << '\n';
    }
  } while (!is_valid_string(setManufacturer));
}

void StereoReceiver::setModel(std::string setModel) {
  do {
    try {
      if (is_valid_string(setModel))
        model = setModel;
      else
        throw std::runtime_error("model is not a valid input");
    } catch (std::runtime_error& e) {
      std::cout << "Runtime error: " << e.what() << '\n';
    }
  } while (!is_valid_string(setModel));
}

void StereoReceiver::setSerial_number(std::string setSerial_number) {
  do {
    try {
      if (is_valid_string(setSerial_number)) 
        serial_number = setSerial_number;
      else
        throw std::runtime_error("serial number is an invalid input");
    } catch (std::runtime_error& e) {
      std::cout << "Runtime error: " << e.what() << '\n';
    }
  } while (!is_valid_string(setSerial_number));
}

void StereoReceiver::setWattage(int setWattage) {
  do {
    try {
      if (setWattage > 0 && setWattage < 100) 
        wattage = setWattage;
      else
        throw std::out_of_range("value is out of range");
    } catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << '\n';
    }
  } while (setWattage <= 0 && setWattage >= 100);
}

void StereoReceiver::setNumber_of_channels(int setNumber_of_channels) {
  do {
    try {
      if (setNumber_of_channels > 0 && setNumber_of_channels < 110)
        number_of_channels = setNumber_of_channels;
      else
        throw std::out_of_range("value is out of range");
    } catch(std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << '\n';
    }
  } while (setNumber_of_channels <= 0 && setNumber_of_channels >= 110);
}

void StereoReceiver::setBand(std::string setBand) {
  do {
    try {
      for (auto i : setBand) 
        i = std::tolower(i);
      if (!is_valid_string(setBand))
        throw std::invalid_argument("band must be a string");
      if (setBand == "am" || setBand == "fm")
        band = setBand;
      else 
        throw std::runtime_error("value is not am or fm");
    } catch (std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << '\n';
    } catch (std::invalid_argument const& e) {
        std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  } while (setBand != "am" && setBand != "fm");
}

void StereoReceiver::setFrequency(double setFrequency) {
  do {
    try {
      if (setFrequency >= 0.0 && setFrequency <= 50.0)
        frequency = setFrequency; 
      else 
        throw std::out_of_range("value is out of range");
    } catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << '\n';
    }
  } while (setFrequency < 0.0 && setFrequency > 50.0);
}

void StereoReceiver::setVolume(int setVolume) {
  do {
    try {
      if (setVolume >= 0 && setVolume <= 50)
        volume = setVolume;
      else 
        throw std::out_of_range("value is out of range");
    } catch (std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << '\n';
    }
  } while (setVolume < 0 && setVolume > 50);
}

void StereoReceiver::setPower(bool setPower) {
  try {
    if (setPower || !setPower)
      power = setPower;
    else
      throw std::runtime_error("Value is not equal to true or false");
  } catch (std::runtime_error& e) {
    std::cout << "Runtime error: " << e.what() << '\n';
  }
}

void StereoReceiver::setLights(std::string setLights) {
  do {
    try {
      for (auto i : setLights)
        i = std::tolower(i);
      if (setLights == "on" || setLights == "false")
        lights = setLights;
      else
        throw std::runtime_error("Value is not a valid string");
    } catch (std::runtime_error& e) {
      std::cout << "Runtime error: " << e.what() << '\n';
    }
  } while (setLights != "on" && setLights != "false");
}

void StereoReceiver::setBass_booster(int setBass_booster) {
  do {
    try {
      if (bass_booster >= 0 && bass_booster <= 10)
        bass_booster = setBass_booster;
      else
        throw std::out_of_range("Value is out of range");
    } catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << '\n';
    }
  } while (bass_booster < 0 && bass_booster > 10);
}
