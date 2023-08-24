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
  power = 0;
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
  power = 0;
  lights = "off";
  bass_booster = 0;
}

void StereoReceiver::print() {
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
  std::cout << "Bass booster: " << bass_booster << '\n';
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
  return std::all_of(s.begin(), s.end(), [](char ch) {
    return (isalpha(ch) || isspace(ch));
  }); 
}

bool is_valid_int(int x) {
  if (x > 0)
    return true;
  return false; 
}

bool is_valid_double(double x) {
  if (x > 0.0)
    return true;
  return false; 
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
  if (is_valid_int(setWattage)) 
    wattage = setWattage;
  else
    return 1; 
  return 0;
}

int StereoReceiver::setNumber_of_channels(int setNumber_of_channels) {
  if (is_valid_int(setNumber_of_channels))
    number_of_channels = setNumber_of_channels;
  else
    return 1;
  return 0;
}

int StereoReceiver::setBand(std::string setBand) {
  if (is_valid_string(setBand))
    band = setBand;
  else 
    return 1;
  return 0;
}

int StereoReceiver::setFrequency(double setFrequency) {
  if (is_valid_double(setFrequency)) 
    frequency = setFrequency; 
  else 
    return 1;
  return 0;
}

int StereoReceiver::setVolume(int setVolume) {
  if (is_valid_int(setVolume))
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
  if(is_valid_int(setBass_booster))
    bass_booster = setBass_booster;
  else
    return 1;
  return 0;
}