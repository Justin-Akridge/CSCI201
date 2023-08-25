#include <iostream>
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
  std::cout << "Bass booster: " << bass_booster << '\n\n';
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
  std::cout << "Bass booster: " << bass_booster << '\n\n';
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

int StereoReceiver::setManufacturer(std::string& setManufacturer) {
  if (is_valid_string(setManufacturer))
    manufacturer = setManufacturer;
  else
    return 1;
  return 0;
}

int StereoReceiver::setModel(std::string setModel) {
  if (is_valid_string(setModel))
    model = setModel;
  else
    return 1;
  return 0;
}

int StereoReceiver::setSerial_number(std::string setSerial_number) {
  if (is_valid_string(setSerial_number)) 
    serial_number = setSerial_number;
  else
    return 1;
  return 0;
}

int StereoReceiver::setWattage(int setWattage) {
  if (setWattage > 0 && setWattage < 100) 
    wattage = setWattage;
  else
    return 1; 
  return 0;
}

int StereoReceiver::setNumber_of_channels(int setNumber_of_channels) {
  if (setNumber_of_channels > 0 && setNumber_of_channels < 110)
    number_of_channels = setNumber_of_channels;
  else
    return 1;
  return 0;
}

int StereoReceiver::setBand(std::string setBand) {
  if (is_valid_string(setBand) && setBand == "AM" || setBand == "PM")
    band = setBand;
  else 
    return 1;
  return 0;
}

int StereoReceiver::setFrequency(double setFrequency) {
  if (setFrequency >= 0 && setFrequency <= 50)
    frequency = setFrequency; 
  else 
    return 1;
  return 0;
}

int StereoReceiver::setVolume(int setVolume) {
  if (setVolume >= 0 && setVolume <= 50)
    volume = setVolume;
  else 
    return 1;
  return 0;
}

int StereoReceiver::setPower(bool setPower) {
  if (setPower || !setPower)
    power = setPower;
  else 
    return 1;
  return 0;
}

int StereoReceiver::setLights(std::string setLights) {
  if (is_valid_string(setLights))
    lights = setLights;
  else
    return 1;
  return 0;
}

int StereoReceiver::setBass_booster(int setBass_booster) {
  if (bass_booster >= 0 && bass_booster <= 10)
    bass_booster = setBass_booster;
  else
    return 1;
  return 0;
}